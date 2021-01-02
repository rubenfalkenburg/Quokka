#pragma once

#include "QuokkaEngine/Core/Application.h"

int main()
{
    auto application = QuokkaEngine::CreateApplication();

    application->Run();

    delete application;
}
