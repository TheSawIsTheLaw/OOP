#ifndef DEFINES_H
#define DEFINES_H

#define DEBUG 1

#if DEBUG == 1
#define QDEB(s) qDebug("%s",s);
#elif DEBUG == 0
#define QDEB(s) {};
#endif

//! Errors
#define FILE_ERROR -1
#define FILE_FORMAT_ERROR -2
#define FILE_STRUCTURE_ERROR -3
#define INVALID_DIRECTION_ERROR -4
#define INVALID_EDGE_NUM_ERROR -5
#define INVALID_FILE_NAME -6
#define INVALID_NODES -7
#define INVALID_NODE_NUM_ERROR -8
#define MEMORY_ALLOCATION_ERROR -9
#define MODEL_IS_NOT_INITED_ERROR -10
#define OUT_OF_CHOICE_ERROR -11
#define UI_POINTER_ERROR -12
#define SCENE_ERROR -13
//< End

#define SUCCESS 0
#define MODEL_IS_EMPTY 1

//! Task manager commands
#define DRAW_MODEL 0
#define LOAD_MODEL 1
#define MOVEMENT 2
#define ROTATION 3
#define SCALE 4

//! In commands
#define GO_X 0
#define GO_Y 1
#define ROTATE_X 2
#define ROTATE_Y 3
#define ROTATE_Z 4
#define SCALE_PLUS 5
#define SCALE_MINUS 6
//< End

//! Scene center
#define X_CENTER_SCENE 490
#define Y_CENTER_SCENE 200
#define Z_CENTER_SCENE 100
//< End

//! Scene rect
#define X_RECT_START 0
#define Y_RECT_START 0
#define X_RECT_END 980
#define Y_RECT_END 400
//< End

// Another defs
#define ROTATION_UNIT 0.17453292519
#define EMPTY 0
#define BASE 1
#define SCALE_UNIT_MINUS 0.9
#define SCALE_UNIT_PLUS 1.1
#define MOVE_UNIT 10


#endif
