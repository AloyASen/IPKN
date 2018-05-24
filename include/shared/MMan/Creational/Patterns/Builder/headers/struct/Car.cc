#pragma once
#include <iostream>
#include "../head.hpp"

namespace Util{
class Car
{
    public:
        Internal::Wheel*   wheels[4];
        Internal::Engine*  engine;
        Internal::Body* body;
    
        void specifications()
        {
            std::cout << "body:" << body->shape << std::endl;
            std::cout << "engine horsepower:" << engine->horsepower << std::endl;
            std::cout << "tire size:" << wheels[0]->size << "'" << std::endl;
        }
};
}
/* Final product -- a car 

which has
4 wheels an engine and a body

*/

