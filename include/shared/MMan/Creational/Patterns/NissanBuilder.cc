
#include "./Builder/Builder.hpp"

#include "./Builder/headers/head.hpp"
/* Concrete builder for Nissan family cars */
class NissanBuilder : public Middleware::Builder
{
    public:
        Internal::Wheel* getWheel()
        {
            Internal::Wheel* wheel = new Internal::Wheel();
            wheel->size = 16;
            return wheel;
        }

        Internal::Engine* getEngine()
        {
            Internal::Engine* engine = new Internal::Engine();
            engine->horsepower = 85;
            return engine;
        }

        Internal::Body* getBody()
        {
            Internal::Body* body = new Internal::Body();
            body->shape = "hatchback";
        }
};