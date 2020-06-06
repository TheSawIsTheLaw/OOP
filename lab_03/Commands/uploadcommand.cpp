#include "uploadcommand.h"
#include <string.h>
#include "defines.h"

#include "QFileDialog"

UploadCommand::UploadCommand() { }

UploadCommand::UploadCommand(const char *nameOfFile) {
    if (strlen(nameOfFile) < FILE_NAME_LEN)
        strcpy(this->fileName, nameOfFile);
}
