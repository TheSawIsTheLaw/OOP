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
#define MODEL_IS_NOT_INITED_ERROR -2
#define FILE_FORMAT_ERROR -3
#define MEMORY_ALLOCATION_ERROR -4
#define FILE_STRUCTURE_ERROR -5
#define OUT_OF_CHOICE_ERROR -6
#define UI_POINTER_ERROR -7
#define INVALID_DIRECTION_ERROR -8
#define INVALID_EDGE_NUM_ERROR -9
#define INVALID_NODE_NUM_ERROR -10
#define INVALID_NODES -11
//< End

#define SUCCESS 0
#define MODEL_IS_EMPTY 1

//! Task manager commands
#define SHOW_MODEL 0
#define MOVEMENT 1
#define ROTATION 2
#define SCALE 3
#define LOAD_MODEL 4

//! In commands
#define GO_X 0
#define GO_Y 1
#define ROTATE_X 4
#define ROTATE_Y 6
#define ROTATE_Z 8
#define SCALE_PLUS 10
#define SCALE_MINUS 11
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
#define ROTATION_UNIT 0.174533
#define EMPTY 0
#define BASE 1
#define REVERSED -1
#define SCALE_UNIT_MINUS 0.9
#define SCALE_UNIT_PLUS 1.1
#define MOVE_UNIT 10


#endif
