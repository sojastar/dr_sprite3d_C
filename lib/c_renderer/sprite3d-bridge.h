#include <stdlib.h>

#ifndef _CAMERA_DEFINED
#define _CAMERA_DEFINED
typedef struct SCamera {
  float   position[4];
  float   forward[4];
  float   right[4];
  float   up[4];
  float   view_matrix[4][4];
  uint8_t view_matrix_status;
} SCamera;
#endif

extern SCamera* bridge_new_camera(float* p, float* f, float* u);
