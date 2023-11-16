#include "CollisionBox.h"

CollisionBox::CollisionBox(const Vector3f &position, const Vector3f &size)
        : position(position), size(size) {}

Vector3f CollisionBox::getPosition() const {
    return position;
}

Vector3f CollisionBox::getSize() const { return size; }

Vector3f CollisionBox::getEnd() const { return position + size; }

bool CollisionBox::isColliding(const CollisionBox &other) {
    Vector3f thisEnd = getEnd();
    Vector3f otherEnd = other.getEnd();

    return (position.getX() <= otherEnd.getX() && thisEnd.getX() >= other.position.getX()) &&
           (position.getY() <= otherEnd.getY() && thisEnd.getY() >= other.position.getY()) &&
           (position.getZ() <= otherEnd.getZ() && thisEnd.getZ() >= other.position.getZ());
}
