#include "CollisionBox.h"

CollisionBox::CollisionBox(const Vector3f& center, const Vector3f& size)
        : center(center), size(size) {}

Vector3f CollisionBox::getStart() const {
    return center - size / 2;
}

Vector3f CollisionBox::getSize() const { return size; }

Vector3f CollisionBox::getEnd() const { return center + size / 2; }

bool CollisionBox::isColliding(CollisionBox other) {
    Vector3f thisEnd = getEnd();
    Vector3f otherEnd = other.getEnd();

    return (center.getX() <= otherEnd.getX() && thisEnd.getX() >= other.center.getX()) &&
           (center.getY() <= otherEnd.getY() && thisEnd.getY() >= other.center.getY()) &&
           (center.getZ() <= otherEnd.getZ() && thisEnd.getZ() >= other.center.getZ());
}
