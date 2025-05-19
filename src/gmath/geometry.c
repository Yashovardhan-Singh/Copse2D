#include "geometry.h"
#include <math.h>

float LineLength(LineSeg line) {
    return Vec2Length(Vec2Sub(line.end, line.start));
}

float LineLengthSq(LineSeg line) {
    return Vec2LengthSq(Vec2Sub(line.end, line.start));
}

Vec2 LineDirection(LineSeg line) {
    return Vec2Normalize(Vec2Sub(line.end, line.start));
}

Vec2 LineMidpoint(LineSeg line) {
    return Vec2Scale(Vec2Add(line.start, line.end), 0.5f);
}

int32_t LineContainsPoint(LineSeg line, Point2D p) {
    float lenSq = LineLengthSq(line);
    float d1 = Vec2LengthSq(Vec2Sub(p, line.start));
    float d2 = Vec2LengthSq(Vec2Sub(p, line.end));
    return fabs((d1 + d2) - lenSq) < 1e-6f; // Small tolerance for precision errors
}

Point2D RayAt(Ray ray, float t) {
    return Vec2Add(ray.origin, Vec2Scale(ray.direction, t));
}

int32_t RayIntersectsCircle(Ray ray, Circle circle, float* outT) {
    Vec2 oc = Vec2Sub(ray.origin, circle.origin);
    float a = Vec2Dot(ray.direction, ray.direction);
    float b = 2.0f * Vec2Dot(oc, ray.direction);
    float c = Vec2Dot(oc, oc) - circle.radius * circle.radius;
    float discriminant = b * b - 4.0f * a * c;
    
    if (discriminant < 0.0f) {
        return 0; // No intersection
    } else {
        *outT = (-b - sqrtf(discriminant)) / (2.0f * a); // Smallest root
        return *outT >= 0.0f;
    }
}

int32_t RayIntersectsLine(Ray ray, LineSeg line, float* outT) {
    Vec2 lineDir = Vec2Sub(line.end, line.start);
    Vec2 lineNormal = Vec2Perpendicular(lineDir);
    float denominator = Vec2Dot(lineNormal, ray.direction);
    
    if (fabs(denominator) < 1e-6f) { 
        return 0; // Parallel
    }
    
    Vec2 diff = Vec2Sub(ray.origin, line.start);
    *outT = Vec2Dot(lineNormal, diff) / denominator;
    
    if (*outT < 0.0f) {
        return 0; // No intersection if t is negative
    }
    
    // Find the intersection point along the line
    Vec2 intersection = RayAt(ray, *outT);
    return LineContainsPoint(line, intersection);
}

int32_t RayIntersectsBox(Ray ray, BBox box, float* outT) {
    float tMin = -INFINITY, tMax = INFINITY;
    
    for (int i = 0; i < 2; i++) {
        float t1 = (i == 0 ? box.origin.x : box.origin.y) - (i == 0 ? ray.origin.x : ray.origin.y);
        float t2 = (i == 0 ? box.origin.x + box.dimensions.x : box.origin.y + box.dimensions.y) - (i == 0 ? ray.origin.x : ray.origin.y);
        
        if (fabs(ray.direction.x) > 1e-6f) {
            tMin = fmaxf(tMin, fminf(t1, t2));
            tMax = fminf(tMax, fmaxf(t1, t2));
        }
        
        if (tMin > tMax) {
            return 0; // No intersection
        }
    }
    
    *outT = tMin;
    return 1;
}

int32_t BBoxContainsPoint(BBox box, Point2D p) {
    return p.x >= box.origin.x && p.x <= box.origin.x + box.dimensions.x &&
           p.y >= box.origin.y && p.y <= box.origin.y + box.dimensions.y;
}

int32_t BBoxIntersects(BBox a, BBox b) {
    return a.origin.x < b.origin.x + b.dimensions.x && a.origin.x + a.dimensions.x > b.origin.x &&
           a.origin.y < b.origin.y + b.dimensions.y && a.origin.y + a.dimensions.y > b.origin.y;
}

BBox BBoxFromPoints(Point2D p1, Point2D p2) {
    return (BBox) {
        .origin = (Point2D){ fminf(p1.x, p2.x), fminf(p1.y, p2.y) },
        .dimensions = (Vec2){ fabsf(p2.x - p1.x), fabsf(p2.y - p1.y) }
    };
}

Point2D BBoxCenter(BBox box) {
    return (Point2D){ box.origin.x + box.dimensions.x / 2.0f, box.origin.y + box.dimensions.y / 2.0f };
}

Point2D BBoxMin(BBox box) {
    return box.origin;
}

Point2D BBoxMax(BBox box) {
    return (Point2D){ box.origin.x + box.dimensions.x, box.origin.y + box.dimensions.y };
}

int32_t CircleContainsPoint(Circle circle, Point2D p) {
    return Vec2LengthSq(Vec2Sub(p, circle.origin)) <= circle.radius * circle.radius;
}

int32_t CircleIntersectsCircle(Circle a, Circle b) {
    return Vec2LengthSq(Vec2Sub(a.origin, b.origin)) <= (a.radius + b.radius) * (a.radius + b.radius);
}

int32_t CircleIntersectsBox(Circle circle, BBox box) {
    Point2D closestPoint = (Point2D){
        fmaxf(box.origin.x, fminf(circle.origin.x, box.origin.x + box.dimensions.x)),
        fmaxf(box.origin.y, fminf(circle.origin.y, box.origin.y + box.dimensions.y))
    };
    return CircleContainsPoint(circle, closestPoint);
}