#include "headers/head.hpp"

namespace Middleware{

    class Builder
    {
    public:
        virtual Internal::Wheel* getWheel() = 0;
        virtual Internal::Engine* getEngine() = 0;
        virtual Internal::Body* getBody() = 0;
    };
};
/* Builder is responsible for constructing the smaller parts */
