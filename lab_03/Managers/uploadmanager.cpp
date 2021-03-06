#include "UploadManager.hpp"

#include <QDebug>

#include "SceneUploader/scenebuilderbase.hpp"
#include "SceneUploader/sceneuploader.hpp"
#include "string.h"

std::shared_ptr<Component> UploadManager::uploadScene(UploadCommand &command)
{
    std::shared_ptr<ObjectBuilderBase> modelBuilder(new TXTModelBuilder());
    std::shared_ptr<ObjectBuilderBase> cameraBuilder(new TXTCameraBuilder());
    ObjectUploader cameraUploader(cameraBuilder);
    ObjectUploader modelUploader(modelBuilder);
    std::shared_ptr<SceneBuilderBase> sceneBuilder(new TXTSceneBuilder(cameraUploader, modelUploader));
    SceneUploader loader(sceneBuilder, command.getFileName());
    qDebug("uploadScene");
    return loader.getComponent();
}
