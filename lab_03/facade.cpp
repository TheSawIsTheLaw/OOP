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

void Facade::execute(DrawCommand &command)
{
    std::shared_ptr<Component> currentScene;
    std::shared_ptr<Component> currentCamera;

    currentScene = SceneMan.getComponent(SCENE);
    currentCamera = SceneMan.getComponent(CAMERA);

    shared_ptr<DrawerBase> drawer = command.getFactory()->createDrawer();
    std::shared_ptr<CameraBase> camera = dynamic_cast<CameraComponent *>(currentCamera.get())->getCamera();
    DrawMan.drawScene(currentScene, camera, drawer);
}

void Facade::execute(UploadCommand &command)
{
    SceneMan.addComponent(UploadMan.uploadScene(command), SCENE);
    std::shared_ptr<DrawingFactoryBase> factoryPtr;
}

void Facade::execute(TransformMoveCommand &command, ComponentName name)
{
    auto component = SceneMan.getComponent(name);
    std::shared_ptr<ComponentVisitorBase> visitor(new MoveVisitor(command.getDX(), command.getDY(), command.getDZ()));
    TransformMan.transformComponent(component, visitor);
}

void Facade::execute(TransformRotateCommand &command, ComponentName name)
{
    auto component = SceneMan.getComponent(name);
    std::shared_ptr<ComponentVisitorBase> visitor(new RotateVisitor(command.getAngle(), command.getAxis()));
    TransformMan.transformComponent(component, visitor);
}

void Facade::execute(TransformScaleCommand &command, ComponentName name)
{
    auto component = SceneMan.getComponent(name);
    std::shared_ptr<ComponentVisitorBase> visitor(new ScaleVisitor(command.getCoef()));
    TransformMan.transformComponent(component, visitor);
}

void Facade::execute(ChangeCurComponentCommand &command, ComponentName name)
{
    SceneMan.changeCurComp(command.getDirection(), name);
}
