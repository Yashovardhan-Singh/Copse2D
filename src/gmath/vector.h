#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>

typedef struct Vector2 {
    float x, y;
} Vec2;

Vec2 Vec2Add(Vec2 a, Vec2 b);
Vec2 Vec2Sub(Vec2 a, Vec2 b);
Vec2 Vec2Scale(Vec2 v, float s);
float Vec2Dot(Vec2 a, Vec2 b);
float Vec2Length(Vec2 v);
float Vec2LengthSq(Vec2 v);
Vec2 Vec2Normalize(Vec2 v);
float Vec2Distance(Vec2 a, Vec2 b);
Vec2 Vec2Lerp(Vec2 a, Vec2 b, float t);
Vec2 Vec2Clamp(Vec2 v, Vec2 min, Vec2 max);
Vec2 Vec2Perpendicular(Vec2 v);
float Vec2Angle(Vec2 a, Vec2 b);
Vec2 Vec2Reflect(Vec2 v, Vec2 normal);

typedef struct Vector2int {
    int32_t x, y;
} Vec2i;

Vec2i Vec2iAdd(Vec2i a, Vec2i b);
Vec2i Vec2iSub(Vec2i a, Vec2i b);
Vec2i Vec2iScale(Vec2i v, int32_t s);
int32_t Vec2iDot(Vec2i a, Vec2i b);
int32_t Vec2iLengthSq(Vec2i v);
Vec2i Vec2iClamp(Vec2i v, Vec2i min, Vec2i max);

typedef struct Vector3 {
    float x, y, z;
} Vec3;

Vec3 Vec3Add(Vec3 a, Vec3 b);
Vec3 Vec3Sub(Vec3 a, Vec3 b);
Vec3 Vec3Scale(Vec3 v, float s);
float Vec3Dot(Vec3 a, Vec3 b);
float Vec3Length(Vec3 v);
float Vec3LengthSq(Vec3 v);
Vec3 Vec3Normalize(Vec3 v);
Vec3 Vec3Cross(Vec3 a, Vec3 b);
float Vec3Distance(Vec3 a, Vec3 b);
Vec3 Vec3Lerp(Vec3 a, Vec3 b, float t);
Vec3 Vec3Clamp(Vec3 v, Vec3 min, Vec3 max);
Vec3 Vec3Reflect(Vec3 v, Vec3 normal);

typedef struct Vector3int {
    int32_t x, y, z;
} Vec3i;

Vec3i Vec3iAdd(Vec3i a, Vec3i b);
Vec3i Vec3iSub(Vec3i a, Vec3i b);
Vec3i Vec3iScale(Vec3i v, int32_t s);
int32_t Vec3iDot(Vec3i a, Vec3i b);
Vec3i Vec3iCross(Vec3i a, Vec3i b); // Discrete version
int32_t Vec3iLengthSq(Vec3i v);
Vec3i Vec3iClamp(Vec3i v, Vec3i min, Vec3i max);

typedef struct Vector4 {
    float w, x, y, z;
} Vec4;

Vec4 Vec4Add(Vec4 a, Vec4 b);
Vec4 Vec4Sub(Vec4 a, Vec4 b);
Vec4 Vec4Scale(Vec4 v, float s);
float Vec4Dot(Vec4 a, Vec4 b);
float Vec4Length(Vec4 v);
float Vec4LengthSq(Vec4 v);
Vec4 Vec4Normalize(Vec4 v);
Vec4 Vec4Lerp(Vec4 a, Vec4 b, float t);
Vec4 Vec4Clamp(Vec4 v, Vec4 min, Vec4 max);

typedef struct Vector4int {
    int32_t w, x, y, z;
} Vec4i;

Vec4i Vec4iAdd(Vec4i a, Vec4i b);
Vec4i Vec4iSub(Vec4i a, Vec4i b);
Vec4i Vec4iScale(Vec4i v, int32_t s);
int32_t Vec4iDot(Vec4i a, Vec4i b);
int32_t Vec4iLengthSq(Vec4i v);
Vec4i Vec4iClamp(Vec4i v, Vec4i min, Vec4i max);

#endif