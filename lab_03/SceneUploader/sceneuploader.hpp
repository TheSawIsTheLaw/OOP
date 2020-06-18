#ifndef SCENEUPLOADER_H
#define SCENEUPLOADER_H

#include "Composite/component.hpp"
#include "defines.hpp"
#include "scenebuilderbase.hpp"

#include <memory>

class SceneUploader
{
public:
    explicit SceneUploader(std::shared_ptr<SceneBuilderBase> build, const char name[FILE_NAME_LEN]);
    std::shared_ptr<Component> getComponent();

private:
    std::shared_ptr<SceneBuilderBase> builder;
    char fileName[FILE_NAME_LEN] = {0};
};

#endif // SCENEUPLOADER_H
