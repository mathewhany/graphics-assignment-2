#include "AnimatingValue.h"

AnimatingValue::AnimatingValue(float value, float max, float speed, bool twoWay)
        : value(value), max(max), speed(speed), twoWay(twoWay) {}

void AnimatingValue::animate() {
    if (animating) {
        value += speed * direction;

        if (value >= max) {
            value = max;
            direction = -1;
        } else {
            if (twoWay) {
                if (value <= -max) {
                    direction = 1;
                }
            } else {
                if (value <= 0) {
                    value = 0;
                    direction = 1;
                }
            }
        }
    }
}

void AnimatingValue::stop() {
    animating = false;
}

void AnimatingValue::start() {
    animating = true;
}

void AnimatingValue::toggle() {
    animating = !animating;
}

double AnimatingValue::getValue() {
    return value;
}
