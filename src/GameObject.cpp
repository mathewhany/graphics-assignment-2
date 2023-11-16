#include <iostream>
#include "GameObject.h"

GameObject::GameObject(Vector3f position, Vector3f size, Vector3f scale)
        : position(position),
          targetPosition(position),
          size(size),
          scale(scale),
          CollisionBox(position - size / 2, size) {}

Vector3f GameObject::getPosition() const { return position; }

Vector3f GameObject::getSize() const { return size; }

void GameObject::setPosition(const Vector3f &newPosition) {
    position = newPosition;
}

void GameObject::moveBy(const Vector3f &translation) {
    position = position + translation;
}

void GameObject::smoothMoveBy(const Vector3f &translation) {
    targetPosition = position + translation;
}

void GameObject::onKeyPressed(unsigned char key, int mouseX, int mouseY) {}

void GameObject::onSpecialKeyPressed(int key, int mouseX, int mouseY) {}

void GameObject::onIdle() {
    if (targetPosition != position) {
        Vector3f translation = targetPosition - position;
        if (translation.length() < 0.1) {
            position = targetPosition;
            return;
        }
        translation = translation.unit() * 0.1;
        position = position + translation;
    }

    if (targetAngle != angle) {
        Vector3f rotation = targetAngle - angle;
        if (rotation.length() < 5) {
            angle = targetAngle;
            return;
        }

        float x = rotation.getX();
        float y = rotation.getY();
        float z = rotation.getZ();

        if (x > 180) {
            x -= 360;
        } else if (x < -180) {
            x += 360;
        }

        if (y > 180) {
            y -= 360;
        } else if (y < -180) {
            y += 360;
        }

        if (z > 180) {
            z -= 360;
        } else if (z < -180) {
            z += 360;
        }

        rotation = Vector3f(x, y, z);

        rotation = rotation.unit() * 5;
        angle = angle + rotation;
    }
}

const Vector3f &GameObject::getAngle() const {
    return angle;
}

void GameObject::setAngle(const Vector3f &newAngle) {
    this->angle = newAngle;
}

void GameObject::smoothRotateTo(const Vector3f &newAngle) {
    targetAngle = newAngle;
}

void GameObject::rotateBy(const Vector3f &rotationAngle) {
    angle = angle + rotationAngle;
}

const Vector3f &GameObject::getScale() const {
    return scale;
}

void GameObject::setScale(const Vector3f &scale) {
    GameObject::scale = scale;
}



