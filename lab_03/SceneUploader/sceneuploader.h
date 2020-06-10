#ifndef SCENEUPLOADER_H
#define SCENEUPLOADER_H

#include "defines.h"
#include "scenebuilderbase.h"

class SceneUploader
{
public:
    SceneUploader();
    SceneUploader(char *name);

    ~SceneUploader() = default;

    //    Composite getComponents();

private:
    SceneBuilderBase builder;
    char fileName[FILE_NAME_LEN] = {0};
};

#endif // SCENEUPLOADER_H
