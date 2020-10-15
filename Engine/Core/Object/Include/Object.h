//
// Created by rayfalling on 2020/8/29.
//
#pragma once

#ifndef VISREAL_OBJECT_H
#define VISREAL_OBJECT_H

#include "FString.h"

namespace Engine::Core {
    using namespace Types;

    class Object {
    private:
        FString Name;
    protected:
        Object() = default;

        virtual ~Object() = default;
    };
}

#endif //VISREAL_OBJECT_H
