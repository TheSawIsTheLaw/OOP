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

class deletedObjectException: public ExceptionBase {
public:
    deletedObjectException(std::string fileName, std::string className,
               int currentLine, const char *errorTime,
               std::string information = "Object doesn't exsist") :
        ExceptionBase(fileName, className, currentLine, errorTime, information) {
    };
};

#endif // EXEPTIONS_H
