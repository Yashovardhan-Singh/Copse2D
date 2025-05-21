#ifndef CAMERA_H
#define CAMERA_H

typedef struct Camera {
    float x, y;
    float rotation;
    float zoom;
} Camera2D;

Camera2D CameraInit();

#endif //CAMERA_H
