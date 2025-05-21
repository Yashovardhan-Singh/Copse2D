#include "coordinates.h"
#include <math.h>

Point2D PolarToCartesian(Polar p) {
    return (Point2D) {
        .x = p.r * cosf(p.theta),
        .y = p.r * sinf(p.theta)
    };
}

Polar CartesianToPolar(Point2D p) {
    return (Polar) {
        .r = sqrtf(p.x * p.x + p.y * p.y),
        .theta = atan2f(p.y, p.x)
    };
}

Point2D ScreenToWorld(Point2D screenPos, Cam2D cam) {
    Vec2 halfScreen = { cam.screensize.x * 0.5, cam.screensize.y * 0.5 };

    return (Point2D) {
        .x = (screenPos.x - halfScreen.x) / cam.zoom + cam.position.x,
        .y = (screenPos.y - halfScreen.y) / cam.zoom + cam.position.y
    };
}

Vec2 WorldToScreen(Point2D worldPos, Cam2D cam) {
    Vec2 halfScreen = { cam.screensize.x * 0.5, cam.screensize.y * 0.5 };

    return (Vec2) {
        .x = (worldPos.x - cam.position.x) * cam.zoom + halfScreen.x,
        .y = (worldPos.y - cam.position.y) * cam.zoom + halfScreen.y
    };
}

void CameraPan(Cam2D* cam, Vec2 delta) {
    cam->position.x += delta.x / cam->zoom;
    cam->position.y += delta.y / cam->zoom;
}

void CameraZoom(Cam2D* cam, float zoomFactor, Point2D focusScreenPos) {
    Vec2 worldBefore = ScreenToWorld(focusScreenPos, *cam);

    cam->zoom *= zoomFactor;

    Vec2 worldAfter = ScreenToWorld(focusScreenPos, *cam);
    Vec2 delta = { worldBefore.x - worldAfter.x, worldBefore.y - worldAfter.y };

    cam->position.x += delta.x;
    cam->position.y += delta.y;
}