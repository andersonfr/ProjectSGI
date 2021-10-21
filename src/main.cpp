#include <rectangle.h>
#include <entity.h>
#include <healthComponent.h>
#include <movementComponent.h>
#include <attackComponent.h>
#include <quadtree.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
 
#define QUAD_CAP 4
#define QUAD_BOUND_X -1000
#define QUAD_BOUND_Y -1000

static unsigned int ENTITYID = 0;

int main(int argc, const char* argv[])
{
    std::string fstring = "./entityblueprints.txt";
    std::cout << "Running program against file: " << fstring.c_str() << "\n";
    std::ifstream file( fstring, std::ios::binary );
    if ( !file.is_open() )
    {
        std::cerr << "Failed to open file. Please add the file to the build folder.\n";
        return 2;
    }
    unsigned int numberOfEntities = 0;
    if ( !( file >> numberOfEntities ) )
    {
        std::cerr << "Failed to get number of Entities from file.\n";
        return 3;
    }
    
    std::vector<std::shared_ptr<Entity>> entities;

    for ( unsigned int i = 0; i < numberOfEntities; ++i )
    {
        float x = 0;
        float y = 0;
        float width = 0;
        float height = 0;

        if ( !( file >> x >> y >> width >> height ) )
        {
            std::cerr << "Error getting bounds on line " << i + 1 << ".\n";
            return 4;
        }
    
        // Not every Entity has Components.
        std::string componentTypes;
        const auto currentPos = file.tellg();
        file >> componentTypes;
        
        if ( !componentTypes.empty() && !std::isalpha( componentTypes.back() ) )
        {
            file.seekg( currentPos );
            componentTypes.clear();
        }

        Rectangle rect(x,y,width,height);
        auto entity = std::make_shared<Entity>(rect);
        
        entity->m_id = ENTITYID++;

        for ( const char type : componentTypes )
        {
            switch ( type )
            {
                case 'H':
                    entity->AddComponent(new HealthComponent());
                break;
                case 'A':
                    entity->AddComponent(new AttackComponent());
                break;
                case 'M':
                    entity->AddComponent(new MovementComponent());
                break;
                default:
                    std::cerr << "Unknown Component type: " << type << "\n";
                break;
            }
        }

        entities.push_back(entity);

    }

    file.close();
    const auto start = std::chrono::high_resolution_clock::now();
   
    Quadtree qt { QUAD_CAP, Rectangle(QUAD_BOUND_X, QUAD_BOUND_Y, 2 * 1000.0f, 2 * 1000.0f)};
    for(auto & e : entities)
    {
        qt.Insert(e.get());
    }

    int collisionCount = 0;

    for( auto& e : entities)
    {
        auto ents =  qt.Search(e->m_rectangle);
        for(auto& p : ents)
        {
            if(p != e.get() && e->m_rectangle.Contains(p->m_rectangle.m_x, p->m_rectangle.m_y))
            {
                if(e->m_intersecteds.insert(p->m_id).second)
                {
                    collisionCount++;
                    p->m_intersecteds.insert(e->m_id);
                }
            }
        }
    }

    std::cout<< "number of intersections " << collisionCount <<std::endl;
    const auto end = std::chrono::high_resolution_clock::now();
    const auto runMS =
    std::chrono::duration_cast<std::chrono::milliseconds>( end - start );
    std::cout << "Algorithm executed in " << runMS.count() << "ms.\n";

    return 0;
}