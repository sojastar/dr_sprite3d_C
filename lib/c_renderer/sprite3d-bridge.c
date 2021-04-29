#include "sprite3d-bridge.h"
#include "camera.h"

SCamera* bridge_new_camera(float *p,float *f,float *u) {
    return new_camera(p, f, u);
}
