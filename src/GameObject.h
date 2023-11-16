#ifndef GRAPHICSASSIGNMENT2_GAMEOBJECT_H
#define GRAPHICSASSIGNMENT2_GAMEOBJECT_H

#include "Vector3f.h"
#include "CollisionBox.h"

class GameObject : public CollisionBox {
protected:
    Vector3f targetPosition{0, 0, 0};

    Vector3f angle{0, 0, 0};
    Vector3f targetAngle{0, 0, 0};

    Vector3f scale{1, 1, 1};

    bool showing = true;
public:

public:
    explicit GameObject(Vector3f collisionBoxSize = {0, 0, 0});

    virtual ~GameObject() = default;

    virtual void draw() = 0;

    void setPosition(const Vector3f &newPosition);

    virtual void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    virtual void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    virtual void onIdle();

    [[nodiscard]] const Vector3f &getAngle() const;

    void setAngle(const Vector3f &newAngle);

    void rotateBy(const Vector3f &rotationAngle);

    void moveBy(const Vector3f &translation);

    void smoothMoveBy(const Vector3f &translation);

    void smoothRotateTo(const Vector3f &newAngle);

    [[nodiscard]] const Vector3f &getScale() const;

    void setScale(const Vector3f &newScale);

    GameObject *withScale(const Vector3f &newScale);

    GameObject *withPosition(const Vector3f &newPosition);

    GameObject *withAngle(const Vector3f &newAngle);

    void smoothRotateBy(const Vector3f &newAngle);

    virtual void onCollision(GameObject *&pObject);

    [[nodiscard]] bool isShowing() const;

    void setShowing(bool newShowing);
};


#endif //GRAPHICSASSIGNMENT2_GAMEOBJECT_H
