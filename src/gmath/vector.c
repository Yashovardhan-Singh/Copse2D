#include "vector.h"

#include <math.h>

Vec2 Vec2Add(Vec2 a, Vec2 b) {
    return (Vec2){ a.x + b.x, a.y + b.y };
}

Vec2 Vec2Sub(Vec2 a, Vec2 b) {
    return (Vec2){ a.x - b.x, a.y - b.y };
}

Vec2 Vec2Scale(Vec2 v, float s) {
    return (Vec2){ v.x * s, v.y * s };
}

float Vec2Dot(Vec2 a, Vec2 b) {
    return a.x * b.x + a.y * b.y;
}

float Vec2Length(Vec2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

float Vec2LengthSq(Vec2 v) {
    return v.x * v.x + v.y * v.y;
}

Vec2 Vec2Normalize(Vec2 v) {
    float len = Vec2Length(v);
    if (len == 0.0f) return (Vec2){ 0.0f, 0.0f };
    return Vec2Scale(v, 1.0f / len);
}

float Vec2Distance(Vec2 a, Vec2 b) {
    return Vec2Length(Vec2Sub(a, b));
}

Vec2 Vec2Lerp(Vec2 a, Vec2 b, float t) {
    return (Vec2){
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t
    };
}

Vec2 Vec2Clamp(Vec2 v, Vec2 min, Vec2 max) {
    return (Vec2){
        fmaxf(min.x, fminf(v.x, max.x)),
        fmaxf(min.y, fminf(v.y, max.y))
    };
}

Vec2 Vec2Perpendicular(Vec2 v) {
    return (Vec2){ -v.y, v.x };
}

float Vec2Angle(Vec2 a, Vec2 b) {
    float dot = Vec2Dot(a, b);
    float lenProduct = Vec2Length(a) * Vec2Length(b);
    if (lenProduct == 0.0f) return 0.0f;
    float cosTheta = fmaxf(-1.0f, fminf(dot / lenProduct, 1.0f));
    return acosf(cosTheta); // In radians
}

Vec2 Vec2Reflect(Vec2 v, Vec2 normal) {
    float dot = Vec2Dot(v, normal);
    return Vec2Sub(v, Vec2Scale(normal, 2.0f * dot));
}

Vec2i Vec2iAdd(Vec2i a, Vec2i b) {
    return (Vec2i){ a.x + b.x, a.y + b.y };
}

Vec2i Vec2iSub(Vec2i a, Vec2i b) {
    return (Vec2i){ a.x - b.x, a.y - b.y };
}

Vec2i Vec2iScale(Vec2i v, int32_t s) {
    return (Vec2i){ v.x * s, v.y * s };
}

int32_t Vec2iDot(Vec2i a, Vec2i b) {
    return a.x * b.x + a.y * b.y;
}

int32_t Vec2iLengthSq(Vec2i v) {
    return v.x * v.x + v.y * v.y;
}

Vec2i Vec2iClamp(Vec2i v, Vec2i min, Vec2i max) {
    Vec2i result;
    result.x = (v.x < min.x) ? min.x : (v.x > max.x) ? max.x : v.x;
    result.y = (v.y < min.y) ? min.y : (v.y > max.y) ? max.y : v.y;
    return result;
}

Vec3 Vec3Add(Vec3 a, Vec3 b) {
    return (Vec3){ a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec3 Vec3Sub(Vec3 a, Vec3 b) {
    return (Vec3){ a.x - b.x, a.y - b.y, a.z - b.z };
}

Vec3 Vec3Scale(Vec3 v, float s) {
    return (Vec3){ v.x * s, v.y * s, v.z * s };
}

float Vec3Dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float Vec3Length(Vec3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float Vec3LengthSq(Vec3 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

Vec3 Vec3Normalize(Vec3 v) {
    float len = Vec3Length(v);
    if (len == 0.0f) return (Vec3){ 0.0f, 0.0f, 0.0f };
    return Vec3Scale(v, 1.0f / len);
}

Vec3 Vec3Cross(Vec3 a, Vec3 b) {
    return (Vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

float Vec3Distance(Vec3 a, Vec3 b) {
    return Vec3Length(Vec3Sub(a, b));
}

Vec3 Vec3Lerp(Vec3 a, Vec3 b, float t) {
    return (Vec3){
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t,
        a.z + (b.z - a.z) * t
    };
}

Vec3 Vec3Clamp(Vec3 v, Vec3 min, Vec3 max) {
    return (Vec3){
        fmaxf(min.x, fminf(v.x, max.x)),
        fmaxf(min.y, fminf(v.y, max.y)),
        fmaxf(min.z, fminf(v.z, max.z))
    };
}

Vec3 Vec3Reflect(Vec3 v, Vec3 normal) {
    float dot = Vec3Dot(v, normal);
    return Vec3Sub(v, Vec3Scale(normal, 2.0f * dot));
}

Vec3i Vec3iAdd(Vec3i a, Vec3i b) {
    return (Vec3i){ a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec3i Vec3iSub(Vec3i a, Vec3i b) {
    return (Vec3i){ a.x - b.x, a.y - b.y, a.z - b.z };
}

Vec3i Vec3iScale(Vec3i v, int32_t s) {
    return (Vec3i){ v.x * s, v.y * s, v.z * s };
}

int32_t Vec3iDot(Vec3i a, Vec3i b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Discrete cross product (best effort, use only if you're sure it makes sense)
Vec3i Vec3iCross(Vec3i a, Vec3i b) {
    return (Vec3i){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

int32_t Vec3iLengthSq(Vec3i v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

Vec3i Vec3iClamp(Vec3i v, Vec3i min, Vec3i max) {
    Vec3i result;
    result.x = (v.x < min.x) ? min.x : (v.x > max.x) ? max.x : v.x;
    result.y = (v.y < min.y) ? min.y : (v.y > max.y) ? max.y : v.y;
    result.z = (v.z < min.z) ? min.z : (v.z > max.z) ? max.z : v.z;
    return result;
}

Vec4 Vec4Add(Vec4 a, Vec4 b) {
    return (Vec4){ a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec4 Vec4Sub(Vec4 a, Vec4 b) {
    return (Vec4){ a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z };
}

Vec4 Vec4Scale(Vec4 v, float s) {
    return (Vec4){ v.w * s, v.x * s, v.y * s, v.z * s };
}

float Vec4Dot(Vec4 a, Vec4 b) {
    return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

float Vec4Length(Vec4 v) {
    return sqrtf(v.w * v.w + v.x * v.x + v.y * v.y + v.z * v.z);
}

float Vec4LengthSq(Vec4 v) {
    return v.w * v.w + v.x * v.x + v.y * v.y + v.z * v.z;
}

Vec4 Vec4Normalize(Vec4 v) {
    float len = Vec4Length(v);
    if (len == 0.0f) return (Vec4){ 0.0f, 0.0f, 0.0f, 0.0f };
    return Vec4Scale(v, 1.0f / len);
}

Vec4 Vec4Lerp(Vec4 a, Vec4 b, float t) {
    return (Vec4){
        a.w + (b.w - a.w) * t,
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t,
        a.z + (b.z - a.z) * t
    };
}

Vec4 Vec4Clamp(Vec4 v, Vec4 min, Vec4 max) {
    return (Vec4){
        fmaxf(min.w, fminf(v.w, max.w)),
        fmaxf(min.x, fminf(v.x, max.x)),
        fmaxf(min.y, fminf(v.y, max.y)),
        fmaxf(min.z, fminf(v.z, max.z))
    };
}

Vec4i Vec4iAdd(Vec4i a, Vec4i b) {
    return (Vec4i){ a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec4i Vec4iSub(Vec4i a, Vec4i b) {
    return (Vec4i){ a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z };
}

Vec4i Vec4iScale(Vec4i v, int32_t s) {
    return (Vec4i){ v.w * s, v.x * s, v.y * s, v.z * s };
}

int32_t Vec4iDot(Vec4i a, Vec4i b) {
    return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

int32_t Vec4iLengthSq(Vec4i v) {
    return v.w * v.w + v.x * v.x + v.y * v.y + v.z * v.z;
}

Vec4i Vec4iClamp(Vec4i v, Vec4i min, Vec4i max) {
    Vec4i result;
    result.w = (v.w < min.w) ? min.w : (v.w > max.w) ? max.w : v.w;
    result.x = (v.x < min.x) ? min.x : (v.x > max.x) ? max.x : v.x;
    result.y = (v.y < min.y) ? min.y : (v.y > max.y) ? max.y : v.y;
    result.z = (v.z < min.z) ? min.z : (v.z > max.z) ? max.z : v.z;
    return result;
}