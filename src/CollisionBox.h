#ifndef GRAPHICSASSIGNMENT2_COLLISIONBOX_H
#define GRAPHICSASSIGNMENT2_COLLISIONBOX_H

#include "Vector3f.h"

class CollisionBox {
protected:
    Vector3f position;
    Vector3f size;
public:
    CollisionBox(const Vector3f &position, const Vector3f &size);

    [[nodiscard]] Vector3f getPosition() const;

    [[nodiscard]] Vector3f getSize() const;

    [[nodiscard]] Vector3f getEnd() const;

    [[nodiscard]] bool isColliding(const CollisionBox &other);
};


#endif //GRAPHICSASSIGNMENT2_COLLISIONBOX_H
