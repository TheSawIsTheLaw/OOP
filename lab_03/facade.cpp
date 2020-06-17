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

QGraphicsScene *Facade::execute(DrawCommand &command)
{
    std::shared_ptr<Component> currentScene;
    std::shared_ptr<Component> currentCamera;

    currentScene = SceneMan.getComponent(SCENE);
    currentCamera = SceneMan.getComponent(CAMERA);

    shared_ptr<DrawerBase> drawer = command.getFactory()->createDrawer();
    std::shared_ptr<CameraBase> camera = dynamic_cast<CameraComponent *>(currentCamera.get())->getCamera();
    return DrawMan.drawScene(currentScene, camera, drawer);
}

QGraphicsScene *Facade::execute(UploadCommand &command)
{
    SceneMan.addComponent(UploadMan.uploadScene(command), SCENE);
    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *newScene = new QGraphicsScene(Q_NULLPTR);
    newScene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(newScene));
    qDebug("Ну ходют и ходют...");
    DrawCommand comm = DrawCommand(factoryPtr);
    return this->execute(comm);
}

QGraphicsScene *Facade::execute(TransformModelMoveCommand &command)
{
    auto component = SceneMan.getComponent(MODEL);
    std::shared_ptr<ComponentVisitorBase> visitor(new MoveVisitor(command.getDX(), command.getDY(), command.getDZ()));
    TransformMan.transformComponent(component, visitor);
    qDebug("Двигаемся, чо...");
    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *newScene = new QGraphicsScene(Q_NULLPTR);
    newScene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(newScene));
    DrawCommand comm = DrawCommand(factoryPtr);
    return this->execute(comm);
}

QGraphicsScene *Facade::execute(TransformModelRotateCommand &command)
{
    auto component = SceneMan.getComponent(MODEL);
    std::shared_ptr<ComponentVisitorBase> visitor(new RotateVisitor(command.getAngle(), command.getAxis()));
    TransformMan.transformComponent(component, visitor);
    qDebug("Двигаемся, чо...");
    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *newScene = new QGraphicsScene(Q_NULLPTR);
    newScene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(newScene));
    DrawCommand comm = DrawCommand(factoryPtr);
    return this->execute(comm);
}
