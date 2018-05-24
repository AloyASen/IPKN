#include <iostream>
#include <string>

namespace Internal{
    /* Car parts */
    class Wheel
    {
        public:
            int size;
    };

    class Engine
    {
        public:
            int horsepower;
    };

    class Body
    {
        public:
            std::string shape;
    };
};
