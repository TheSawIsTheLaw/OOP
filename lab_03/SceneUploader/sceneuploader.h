#ifndef SCENEUPLOADER_H
#define SCENEUPLOADER_H

#include "defines.h"

class SceneUploader
{
public:
    SceneUploader();
    SceneUploader(char *name);

    ~SceneUploader() = default;

    //    Composite getComponents();

private:
    char fileName[FILE_NAME_LEN] = {0};
};

#endif // SCENEUPLOADER_H
