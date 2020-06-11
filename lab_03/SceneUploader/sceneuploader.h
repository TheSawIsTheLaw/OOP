#ifndef SCENEUPLOADER_H
#define SCENEUPLOADER_H

#include "defines.h"
#include "scenebuilderbase.h"

#include <memory>

class SceneUploader
{
public:
    SceneUploader();
    SceneUploader(char *name);

    ~SceneUploader() = default;

    //    Composite getComponents();

private:
    std::shared_ptr<SceneBuilderBase> builder;
    char fileName[FILE_NAME_LEN] = {0};
};

#endif // SCENEUPLOADER_H
