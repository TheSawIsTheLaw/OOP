#include "modelScale.h"

#include "defines.h"


//! Wrap
int scaleModelWrap(modelT &model, const scaleRequestT scaleRequest) {
    if (areNodesLegit(model.nodes, model.numOfEdges))
        return INVALID_NODES;

    scaleModel(model.nodes, scaleRequest.scaleCoef,
               scaleRequest.xCenterScene, scaleRequest.yCenterScene,
               scaleRequest.zCenterScene, model.numOfNodes);
    return SUCCESS;
}
//< End

//! Scale
void scaleModel(nodeT *const nodes, const float scaleCoef,
                const int xCenterScene, const int yCenterScene,
                const int zCenterScene, const int numOfnodes) {
    qDebug("scale");

    for (int i = 0; i < numOfnodes; i++) {
        nodes[i].xCoord =
            nodes[i].xCoord * scaleCoef + (1 - scaleCoef) * xCenterScene;
        nodes[i].yCoord =
            nodes[i].yCoord * scaleCoef + (1 - scaleCoef) * yCenterScene;
        nodes[i].zCoord =
            nodes[i].zCoord * scaleCoef + (1 - scaleCoef) * zCenterScene;
    }
}
// End
