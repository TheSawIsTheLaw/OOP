#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Camera/camerabase.h"
#include "../Composite/component.h"
#include "../Model/modelbase.h"

class Scene {
   public:
    Scene();
    ~Scene() = default;

    Component &getComponent();
    void addComponent();
    void delComponent();
    void setScene();
    void resetScene();

   private:
    std::vector<Component> components;
};

#endif // SCENE_H
