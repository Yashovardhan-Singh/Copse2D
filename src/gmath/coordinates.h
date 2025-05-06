#ifndef COORDINATES_H
#define COORDINATES_H

#include <stdint.h>
#include "vector.h"
#include "geometry.h"
#include <math.h>

typedef struct Polar {
    float r;
    float theta;
} Polar;

Point2D PolarToCartesian(Polar p);
Polar CartesianToPolar(Point2D p);

typedef struct Camera2D {
    Point2D position;
    float zoom;
    Vec2 screensize;
} Cam2D;

Point2D ScreenToWorld(Point2D screenPos, Cam2D cam);
Vec2 WorldToScreen(Point2D worldPos, Cam2D cam);
void CameraPan(Cam2D* cam, Vec2 delta);
void CameraZoom(Camera2D* cam, float zoomFactor, Point2D focusScreenPos);

#endif