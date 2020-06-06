#ifndef UPLOADCOMMAND_H
#define UPLOADCOMMAND_H

#include "commandbase.h"
#include "defines.h"

class UploadCommand : CommandBase {
   public:
    UploadCommand();
    UploadCommand(const char *nameOfFile);

    ~UploadCommand() = default;

    char fileName[FILE_NAME_LEN] = {0};

   private:
};

#endif // UPLOADCOMMAND_H
