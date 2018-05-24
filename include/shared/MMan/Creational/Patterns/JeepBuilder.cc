
#include "./Builder/Builder.hpp"

#include "./Builder/headers/head.hpp"

/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Middleware::Builder
{
    public:
        Internal::Wheel* getWheel()
        {
            Internal::Wheel* wheel = new Internal::Wheel();
            wheel->size = 22;
            return wheel;
        }

        Internal::Engine* getEngine()
        {
            Internal::Engine* engine = new Internal::Engine();
            engine->horsepower = 400;
            return engine;
        }

        Internal::Body* getBody()
        {
            Internal::Body* body = new Internal::Body();
            body->shape = "SUV";
        }
};