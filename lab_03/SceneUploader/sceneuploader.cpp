#include "sceneuploader.h"
//#include <iostream>
#include <string.h>

#include "defines.h"

SceneUploader::SceneUploader() {}

SceneUploader::SceneUploader(char *name) {
    if (!name) {
        // Exception
    }
    if (strlen(name) > FILE_NAME_LEN) {
        // Exception, который поймает манагер и выпишет QDialog
    }
    strcpy(this->fileName, name);
}
