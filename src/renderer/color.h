#ifndef COLOR_H
#define COLOR_H

typedef struct Color {
    float r, g, b, a;
} Color;

#define WHITE (Color) { 1.0, 1.0, 1.0, 1.0 }
#define BLACK (Color) { 0.0, 0.0, 0.0, 1.0 }

#endif