#ifndef EXEPTIONS_H
#define EXEPTIONS_H

#include "exceptionBase.h"

class memoryException: public ExceptionBase{
public:
    memoryException(std::string fileName, std::string className,
                int currentLine, const char *errorTime,
                std::string information = "Memory Error"):
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
    virtual const char *what() const noexcept {
        return errorInformation.c_str();
    }
};

#endif // EXEPTIONS_H
