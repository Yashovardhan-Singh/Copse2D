#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdint.h>
#include "vector.h"

typedef Vec2 Point2D;
typedef Vec2i Point2Di;

typedef Vec3 Point3D;
typedef Vec3i Point3Di;

typedef struct LineSeg {
    Point2D start, end;
} LineSeg;

typedef struct Ray {
    Point2D origin;
    Vec2 direction;
} Ray;

typedef struct BoundingBox {
    Point2D origin;
    Vec2 dimensions;
} BBox, Rect;

typedef struct Circle {
    Point2D origin;
    float radius;
} Circle;

float LineLength(LineSeg line);
float LineLengthSq(LineSeg line);
Vec2 LineDirection(LineSeg line);
Vec2 LineMidpoint(LineSeg line);
int32_t LineContainsPoint(LineSeg line, Point2D p);

Point2D RayAt(Ray ray, float t);
int32_t RayIntersectsCircle(Ray ray, Circle circle, float* outT);
int32_t RayIntersectsLine(Ray ray, LineSeg line, float* outT);
int32_t RayIntersectsBox(Ray ray, BBox box, float* outT);

int32_t BBoxContainsPoint(BBox box, Point2D p);
int32_t BBoxIntersects(BBox a, BBox b);
BBox BBoxFromPoints(Point2D p1, Point2D p2);
Point2D BBoxCenter(BBox box);
Point2D BBoxMin(BBox box);
Point2D BBoxMax(BBox box);

int32_t CircleContainsPoint(Circle circle, Point2D p);
int32_t CircleIntersectsCircle(Circle a, Circle b);
int32_t CircleIntersectsBox(Circle circle, BBox box);

#endif