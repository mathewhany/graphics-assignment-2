#ifndef GRAPHICSASSIGNMENT2_CAMERA_H
#define GRAPHICSASSIGNMENT2_CAMERA_H

#include "Vector3f.h"

class Camera {
    Vector3f eye, center, up;
public:
    [[nodiscard]] const Vector3f &getEye() const;

    void setEye(const Vector3f &newEye);

    [[nodiscard]] const Vector3f &getCenter() const;

    void setCenter(const Vector3f &newCenter);

    [[nodiscard]] const Vector3f &getUp() const;

    void setUp(const Vector3f &newUp);

private:
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
};


#endif //GRAPHICSASSIGNMENT2_CAMERA_H
