#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector.h"
#include "geometry.h"

typedef struct Matrix3x3 {
    float
    m00, m01, m02,
    m10, m11, m12,
    m20, m21, m22;
} Mat3;

Point2D Translate(Point2D point, Point2D displacement);
Point2D Rotate(Point2D point, float angle);
Mat3 RotationMatrix(float angle);
Point2D Scale(Point2D point, float sx, float sy);
Mat3 ScalingMatrix(float sx, float sy);
Mat3 MultiplyMatrices(Mat3 a, Mat3 b);
Point2D ApplyTransformation(Point2D point, Mat3 matrix);
Mat3 CreateCompositeTransformationMatrix(float angle, float sx, float sy, Point2D translation);
Point2D TransformPoint2D(Point2D point, float angle, float sx, float sy, Point2D translation);

#endif