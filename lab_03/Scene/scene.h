#ifndef SCENE_H
#define SCENE_H

#include "../Composite/component.h"
#include "../Model/modelbase.h"
#include "../Camera/camerabase.h"
#include <vector>

class Scene
{
public:
    Scene();
    ~Scene() = default;

    ModelBase &getModel();
    void addModel();
    void delModel();
    CameraBase &getCamera();
    void addCamera();
    void delCamera();
    Scene &getScene();
    void setScene();
    void resetScene();

private:
    std::vector<Component> components;
};

#endif // SCENE_H
