# ====== Legal notices
#
# Copyright 2017 Jacques de Hooge, GEATEC engineering, www.geatec.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import serial as sr
import time as tm

def writeSerial (value):
    serial.reset_input_buffer ()        
    serial.write ((str (value) + ' ') .encode ('ascii'))
    
    while serial.out_waiting:
        pass
        
    return value
                
def readSerial ():
    sleepCount = 0
    while not serial.in_waiting and sleepCount < 5000:
        tm.sleep (0.01)
        sleepCount += 1

    buffer = ''
    while serial.in_waiting:
        aByte = serial.read ()
        aChar = aByte.decode ('ascii')
        if aChar in '\n\v ':
            break
        else:
            buffer += aChar
    try:        
        return int (buffer)
    except:
        return 0
        
commands = [
    [99, 99, 99, 90],
    [-45, 99, 99, 99],
    [99, 99, 50, 99],
    [99, 45, 99, 99],
    [99, 99, 99, 0],
    [99, 99, 0, 99],
    [99, 0, 99, 99],
    [45, 99, 99, 99],
    [99, 99, 50, 99],
    [99, 45, 99, 99],
    [99, 99, 99, 90],
    [99, 0, 99, 99],
    [99, 99, 0, 99]
]

commandIndex = 0
        
with sr.Serial ('COM5', 9600, timeout = 3) as serial:
    tm.sleep (5)
    while True:
        angles = commands [commandIndex]
        commandIndex = (commandIndex + 1) % len (commands)
        
        '''
        angles = [
            int (input (name + ' angle: '))
            for name in ('Base',  'Arm', 'Wrist', 'Hand')
        ]
        '''

        print ('Command:', [writeSerial (angle) for angle in angles])
        print ('Echo:   ', [readSerial () for angle in angles])
        print ()
        
        tm.sleep (1)
