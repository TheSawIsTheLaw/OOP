#include "sceneuploader.h"
//#include <iostream>
#include <string.h>

#include "defines.h"

SceneUploader::SceneUploader() {}

SceneUploader::SceneUploader(const char name[FILE_NAME_LEN])
{
    if (!name) {
        // Exception
    }
    strcpy(fileName, name);
}
