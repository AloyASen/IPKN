#include "Builder.hpp"

#include "headers/Includes.hpp"

namespace Middleware {
/* Director is responsible for the whole process */
class Director
{
    Middleware::Builder* builder;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Util::Car* getCar()
        {
            Util::Car* car = new Util::Car();

            car->body = builder->getBody();

            car->engine = builder->getEngine();

            car->wheels[0] = builder->getWheel();
            car->wheels[1] = builder->getWheel();
            car->wheels[2] = builder->getWheel();
            car->wheels[3] = builder->getWheel();

            return car;
        }
};
};