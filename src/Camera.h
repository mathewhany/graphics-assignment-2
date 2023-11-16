#ifndef GRAPHICSASSIGNMENT2_CAMERA_H
#define GRAPHICSASSIGNMENT2_CAMERA_H

#include "Vector3f.h"

class Camera {
    Vector3f eye, center, up;
    double aspectRatio;
public:
    Camera(Vector3f eye, Vector3f center, Vector3f up, double aspectRatio);

    void moveX(float d);

    void moveY(float d);

    void moveZ(float d);

    void rotateX(float a);

    void rotateY(float a);

    void look() const;

    void setup() const;

    void setEye(Vector3f newEye);
};


#endif //GRAPHICSASSIGNMENT2_CAMERA_H
