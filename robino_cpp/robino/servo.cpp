// ====== Legal notices
//
// Copyright 2017 Jacques de Hooge, GEATEC engineering, www.geatec.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cantino.h>

#include "servo.h"

using namespace cantino;

Servo::Servo (int pinIndex, int aMin, int aMax, int initial, int offset, bool invert):
    pinIndex (pinIndex), aMin (aMin), aMax (aMax), initial (initial), offset (offset), invert (invert), angle (1000)
{
    standardServo.attach (pinIndex);
    void rotateTo (initial);
}

Servo::rotateTo (int angle) {
    if (aMin <= angle && angle <= aMax && angle != this->angle) {
        this->angle = angle;
        standardServo.write ((invert ? -(this->angle + offset) : (this->angle + offset)) + 90);
    }
}
