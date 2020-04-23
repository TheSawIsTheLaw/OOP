#include "modelScale.h"

#include "nodeActions.h"

#include "defines.h"


//! Wrap
int scaleModelWrap(modelT &model, const scaleRequestT scaleRequest) {
    if (areNodesLegit(model.nodes, model.numOfEdges))
        return INVALID_NODES;

    scaleModel(model.nodes, model.numOfNodes,
               scaleRequest.scaleCoef, scaleRequest.xCenterScene,
               scaleRequest.yCenterScene, scaleRequest.zCenterScene);
    return SUCCESS;
}
//< End

//! Scale
void scaleModel(nodeT *const nodes, const int numOfnodes,
                const float scaleCoef, const int xCenterScene,
                const int yCenterScene, const int zCenterScene) {
    for (int i = 0; i < numOfnodes; i++) {
        scaleNode(nodes[i], xCenterScene,
                  yCenterScene, zCenterScene,
                  scaleCoef);
    }
}
// End
