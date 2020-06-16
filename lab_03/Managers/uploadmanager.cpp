#include "UploadManager.h"

#include <QDebug>

#include "SceneUploader/scenebuilderbase.h"
#include "SceneUploader/sceneuploader.h"
#include "string.h"

std::shared_ptr<Component> UploadManager::uploadScene(UploadCommand &command)
{
    std::shared_ptr<ObjectBuilderBase> modelBuilder(new ModelBuilder());
    std::shared_ptr<ObjectBuilderBase> cameraBuilder(new CameraBuilder());
    ObjectUploader cameraUploader(cameraBuilder);
    ObjectUploader modelUploader(modelBuilder);
    std::shared_ptr<SceneBuilderBase> sceneBuilder(new SceneBuilder(cameraUploader, modelUploader));
    SceneUploader loader(sceneBuilder, command.getFileName());
    return loader.getComponent();
}
