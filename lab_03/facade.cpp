#include "facade.h"
#include "Drawer/drawingfactorybase.h"

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

template <>
void Facade::execute(const DrawCommand &command)
{
    std::shared_ptr<Component> currentScene;
    std::shared_ptr<Component> currentCamera;
    try
    {
        currentScene = SceneMan.getComponent(SCENE);
        currentCamera = SceneMan.getComponent(CAMERA);
    }
    catch (SceneException &err)
    {
        return;
    }
}

template<>
void Facade::execute(const UploadCommand &command)
{
    SceneMan.addComponent(UploadMan.uploadScene(command), SCENE);
}
