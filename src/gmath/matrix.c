#include "matrix.h"
#include <math.h>

Point2D Translate(Point2D point, Point2D displacement) {
    return (Point2D){ point.x + displacement.x, point.y + displacement.y };
}

Point2D Rotate(Point2D point, float angle) {
    float cosA = cosf(angle);
    float sinA = sinf(angle);
    
    return (Point2D){
        point.x * cosA - point.y * sinA,
        point.x * sinA + point.y * cosA
    };
}

Mat3 RotationMatrix(float angle) {
    Mat3 mat = {
        .m00 = cosf(angle), .m01 = -sinf(angle), .m02 = 0.0f,
        .m10 = sinf(angle), .m11 = cosf(angle), .m12 = 0.0f,
        .m20 = 0.0f,        .m21 = 0.0f,        .m22 = 1.0f
    };
    return mat;
}

Point2D Scale(Point2D point, float sx, float sy) {
    return (Point2D){ point.x * sx, point.y * sy };
}

Mat3 ScalingMatrix(float sx, float sy) {
    Mat3 mat = {
        .m00 = sx, .m01 = 0.0f, .m02 = 0.0f,
        .m10 = 0.0f, .m11 = sy, .m12 = 0.0f,
        .m20 = 0.0f, .m21 = 0.0f, .m22 = 1.0f
    };
    return mat;
}

Mat3 MultiplyMatrices(Mat3 a, Mat3 b) {
    Mat3 result;
    result.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20;
    result.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21;
    result.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22;
    
    result.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20;
    result.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21;
    result.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22;
    
    result.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20;
    result.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21;
    result.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22;
    
    return result;
}

Point2D ApplyTransformation(Point2D point, Mat3 matrix) {
    Point2D result;
    result.x = point.x * matrix.m00 + point.y * matrix.m01 + matrix.m02;
    result.y = point.x * matrix.m10 + point.y * matrix.m11 + matrix.m12;
    return result;
}

Mat3 CreateCompositeTransformationMatrix(float angle, float sx, float sy, Point2D translation) {
    // Create individual transformation matrices
    Mat3 translationMat = {
        .m00 = 1.0f, .m01 = 0.0f, .m02 = translation.x,
        .m10 = 0.0f, .m11 = 1.0f, .m12 = translation.y,
        .m20 = 0.0f, .m21 = 0.0f, .m22 = 1.0f
    };
    
    Mat3 rotationMat = RotationMatrix(angle);
    Mat3 scalingMat = ScalingMatrix(sx, sy);
    
    // Combine them (Translation → Rotation → Scaling)
    Mat3 transformation = MultiplyMatrices(translationMat, rotationMat);
    transformation = MultiplyMatrices(transformation, scalingMat);
    
    return transformation;
}

Point2D TransformPoint2D(Point2D point, float angle, float sx, float sy, Point2D translation) {
    Mat3 compositeMatrix = CreateCompositeTransformationMatrix(angle, sx, sy, translation);
    return ApplyTransformation(point, compositeMatrix);
}