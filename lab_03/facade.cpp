#include "facade.h"

Facade::Facade()
{
    this->DrawMan = DrawManager();
    this->SceneMan = SceneManager();
    this->UploadMan = UploadManager();
    this->TransformMan = TransformManager();
}

template<typename Command>
void execute(const Command &)
{}

template<>
void Facade::execute(const UploadCommand &command)
{
    UploadMan.uploadScene(command);
}
