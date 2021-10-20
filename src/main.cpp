#include <iostream>
#include "../include/rectangle.h"

int main(int argc, char** argv)
{
    Rectangle a {5.0f, 10.0f,5.0f, 10.0f};
    Rectangle b {8.0f, 8.0f,8.0f, 8.0f};

    if(a.Intersects(b))
        std::cout<<"Intersects"<<std::endl;  
    else
        std::cout<<"Not Intersects"<<std::endl;
    return 0;
}