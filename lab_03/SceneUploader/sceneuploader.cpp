#include "sceneuploader.h"
#include <fstream>
#include <iostream>
#include <string.h>

#include "defines.h"

SceneUploader::SceneUploader(std::shared_ptr<SceneBuilderBase> build, const char name[FILENAME_MAX])
    : builder(build)
{
    strcpy(fileName, name);
}

std::shared_ptr<Component> SceneUploader::getComponent()
{
    std::ifstream input(fileName);
    if (input)
        builder->buildComponent(input);
    input.close();

    std::shared_ptr<Component> component;
    if (builder->isBuilt())
        component = builder->getComponent();
    else
    {
        time_t curTime = time(NULL);
        throw BadFile(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return component;
}
