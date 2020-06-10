#include "uploadcommand.h"

#include <string.h>

#include "QFileDialog"
#include "defines.h"

UploadCommand::UploadCommand() {}

UploadCommand::UploadCommand(const char *nameOfFile)
{
    if (strlen(nameOfFile) < FILE_NAME_LEN)
        strcpy(this->fileName, nameOfFile);
}
