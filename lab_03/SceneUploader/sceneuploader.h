#ifndef SCENEUPLOADER_H
#define SCENEUPLOADER_H


class SceneUploader
{
public:
    SceneUploader();
    SceneUploader(char *name);

    ~SceneUploader() = default;

//    Composite getComponents();

private:
    char fileName[30] = { 0 };
};

#endif // SCENEUPLOADER_H
