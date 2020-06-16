#include "facade.h"
#include "Drawer/drawingfactorybase.h"

Facade::Facade()
{
    this->DrawMan = DrawManager();
    this->SceneMan = SceneManager();
    this->UploadMan = UploadManager();
    this->TransformMan = TransformManager();
}

template <typename Command>
void execute(Command &)
{}

template <>
void Facade::execute(DrawCommand &command)
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

    shared_ptr<DrawerBase> drawer = command.getFactory()->createDrawer();
    drawer->clear();
    auto camera = dynamic_cast<CameraComponent *>(currentCamera.get())->getCamera();
    DrawMan.drawScene(currentScene, camera, drawer);
}

template <>
void Facade::execute(UploadCommand &command)
{
    SceneMan.addComponent(UploadMan.uploadScene(command), SCENE);
    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    factoryPtr.reset(new QTDrawingFactory(new QGraphicsScene));
    DrawCommand comm = DrawCommand(factoryPtr);
    this->execute(comm);
}
