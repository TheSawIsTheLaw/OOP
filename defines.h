#ifndef DEFINES_H
#define DEFINES_H

#define DEBUG 1

#if DEBUG == 1
#define QDEB(s) qDebug("%s",s);
#elif DEBUG == 0
#define QDEB(s) {};
#endif

#define DIRECTORY_ERROR -1
#define FILE_ERROR -2
#define MODEL_IS_NOT_INITED_ERROR -3
#define FILE_FORMAT_ERROR -4
#define MEMORY_ALLOCATION_ERROR -5
#define FILE_STRUCTURE_ERROR -6
#define MODEL_IS_NOT_READY_ERROR -7
#define WRONG_DIRECTION_ERROR -8
#define INVALID_NODES_MOVE_POINTER_ERROR -9
#define WRONG_NUMBER_OF_NODES_ERROR -10


#define SUCCESS 0


#define GO_LEFT 0
#define GO_DOWN 1
#define GO_UP 2
#define GO_RIGHT 3
#define ROTATE_Z_R 8
#define ROTATE_Z_L 9
#define ROTATE_Y_R 6
#define ROTATE_Y_L 7
#define ROTATE_X_R 4
#define ROTATE_X_L 5
#define SCALE_PLUS 10
#define SCALE_MINUS 11

#define X_CENTER_SCENE 490
#define Y_CENTER_SCENE 200
#define Z_CENTER_SCENE 100


#endif
