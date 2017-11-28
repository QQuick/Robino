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

int main () {
    cin.setecho (false);
    pinMode (LED_BUILTIN, OUTPUT);
    
    int baseAngle = 0;
    int armAngle = 0;
    int wristAngle = 0;
    int handAngle = 0;

    Servo baseServo (5, -90, 90, baseAngle, 0, true);
    Servo armServo (7, -90, 90, armAngle, 0, false);
    Servo wristServo (4, -90, 90, wristAngle, 0, true);
    Servo handServo (6, -90, 90, handAngle, 0, true); 
    
    while (true) {        
        cin >> baseAngle >> armAngle >> wristAngle >> handAngle;
        digitalWrite (LED_BUILTIN, true);

        baseServo.rotateTo (baseAngle);
        armServo.rotateTo (armAngle);
        wristServo.rotateTo (wristAngle);
        handServo.rotateTo (handAngle);
        
        cout << baseAngle << ' ' << armAngle << ' ' << wristAngle << ' ' << handAngle << endl;
        digitalWrite (LED_BUILTIN, false);
    }
}
