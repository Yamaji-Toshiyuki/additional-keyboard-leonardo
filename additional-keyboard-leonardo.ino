#include "Keyboard.h"

int i;
byte state;

void setup(){
    for(i=2; i<10; i++)
    {
        pinMode(i, INPUT);
    }
    Keyboard.begin();
    Serial.begin(9600);
}

void loop(){
    state = 0;
    for(i=9; i>=2; i--)
    {
        state |= digitalRead(i);
          if(i == 2){
              break;
          }
        state = state << 1;
    }
    Serial.println(state);
    switch(state)
    {
    case 0b00000001:
        Keyboard.press('3');
        Keyboard.releaseAll();
        while(digitalRead(2) == HIGH)
        {
            /* wait */
        }
        break;
    case 0b00000010:
        // Keyboard.press('0');
        // Keyboard.releaseAll();
        // while(digitalRead(3) == HIGH)
        // {
        //     /* wait */
        // }
        break;
    case 0b00000100:
        // Keyboard.press('0');
        // Keyboard.releaseAll();
        // while(digitalRead(4) == HIGH)
        // {
        //     /* wait */
        // }
        // break;
    case 0b00001000:
        Keyboard.press('4');
        Keyboard.releaseAll();
        while(digitalRead(5) == HIGH)
        {
            /* wait */
        }
        break;
    case 0b00010000:
        Keyboard.press('6');
        Keyboard.releaseAll();
        while(digitalRead(6) == HIGH)
        {
            /* wait */
        }
        break;
    case 0b00100000:
        Keyboard.press('5');
        Keyboard.releaseAll();
        while(digitalRead(7) == HIGH)
        {
            /* wait */
        }
        break;
    case 0b01000000:
        Keyboard.press('7');
        Keyboard.releaseAll();
        while(digitalRead(8) == HIGH)
        {
            /* wait */
        }
        break;
    case 0b10000000:
        Keyboard.press('0');
        Keyboard.releaseAll();
        while(digitalRead(9) == HIGH)
        {
            /* wait */
        }
        break;
    
    default:
        while(state != 0b00000000)
        {
            /* wait */
        }
        break;
    }
}
