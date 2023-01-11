/***************************************************************************/    
//            Hardware: RadioShack Tricolor LED Strip
//            Arduino IDE: Arduino-1.0
//            Date:      April 17, 2013
//            Author: RadioShack Corporation
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, see <http://www.gnu.org/licenses/>
//
/*****************************************************************************/

#include <avr/pgmspace.h>

// ******** DEBUG ==== should auto config to adapt different mother board *********
//#define DATA_1 (PORTF |=  0X01)    // DATA 1    // for ATMEGA
//#define DATA_0 (PORTF &=  0XFE)    // DATA 0    // for ATMEGA
//#define STRIP_PINOUT DDRF=0xFF  // for ATMEGA
#define DATA_1 (PORTC |=  0X01)    // DATA 1    // for UNO
#define DATA_0 (PORTC &=  0XFE)    // DATA 0    // for UNO
#define STRIP_PINOUT (DDRC=0xFF)    // for UNO

PROGMEM const unsigned long pattern_off[10][10]={
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
};

PROGMEM const unsigned long pattern_test_red[10][10]={
  {0xff0000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0xff0000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0xff0000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0xff0000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0xff0000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0xff0000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xff0000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xff0000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xff0000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xff0000},
};

PROGMEM const unsigned long pattern_test_blue[10][10]={
  {0x00ff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x00ff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x00ff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x00ff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x00ff00,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x00ff00,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x00ff00,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x00ff00,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x00ff00,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x00ff00},
};

PROGMEM const unsigned long pattern_test_green[10][10]={
  {0x0000ff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x0000ff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x0000ff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x0000ff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x0000ff,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x0000ff,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x0000ff,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x0000ff,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x0000ff,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x0000ff},
};

PROGMEM const unsigned long pattern_test_white[10][10]={
  {0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0xffffff,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffffff,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffffff,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffffff,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffffff},
};

PROGMEM const unsigned long pattern_test_comet1[][10]={
  {0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff},
};

PROGMEM const unsigned long pattern_test_comet2[][10]={
  {0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000},
  {0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000},
  {0x111111,0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000},
  {0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000},
  {0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff},
  {0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000},
  {0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000},
  {0x111111,0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000},
  {0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000},
  {0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x111111,0x444444,0xffffff},
};

PROGMEM const unsigned long pattern_test_comet3[][10]={
  {0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffffff},
  {0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffffff,0x444444},
  {0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0xffffff,0x444444,0x111111},
  {0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0xffffff,0x444444,0x111111,0x000000},
  {0x000000,0x000000,0x111111,0x444444,0xffffff,0xffffff,0x444444,0x111111,0x000000,0x000000},
  {0x000000,0x000000,0x111111,0x444444,0xffffff,0xffffff,0x444444,0x111111,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0xffffff,0x444444,0x444444,0xffffff,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0xffffff,0x444444,0x111111,0x111111,0x444444,0xffffff,0x000000,0x000000},
  {0x000000,0xffffff,0x444444,0x111111,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000},
  {0xffffff,0x444444,0x111111,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff},
};

PROGMEM const unsigned long pattern_test_rainbow[10][10]={
  {0xff0000,0xff7f00,0xffff00,0x00ff00,0x0000ff,0x6f00ff,0x8f00ff,0x000000,0x000000,0x000000},
  {0x000000,0xff0000,0xff7f00,0xffff00,0x00ff00,0x0000ff,0x6f00ff,0x8f00ff,0x000000,0x000000},
  {0x000000,0x000000,0xff0000,0xff7f00,0xffff00,0x00ff00,0x0000ff,0x6f00ff,0x8f00ff,0x000000},
  {0x000000,0x000000,0x000000,0xff0000,0xff7f00,0xffff00,0x00ff00,0x0000ff,0x6f00ff,0x8f00ff},
  {0x8f00ff,0x000000,0x000000,0x000000,0xff0000,0xff7f00,0xffff00,0x00ff00,0x0000ff,0x6f00ff},
  {0x6f00ff,0x8f00ff,0x000000,0x000000,0x000000,0xff0000,0xff7f00,0xffff00,0x00ff00,0x0000ff},
  {0x0000ff,0x6f00ff,0x8f00ff,0x000000,0x000000,0x000000,0xff0000,0xff7f00,0xffff00,0x00ff00},
  {0x00ff00,0x0000ff,0x6f00ff,0x8f00ff,0x000000,0x000000,0x000000,0xff0000,0xff7f00,0xffff00},
  {0xffff00,0x00ff00,0x0000ff,0x6f00ff,0x8f00ff,0x000000,0x000000,0x000000,0xff0000,0xff7f00},
  {0xff7f00,0xffff00,0x00ff00,0x0000ff,0x6f00ff,0x8f00ff,0x000000,0x000000,0x000000,0xff0000},
};


const unsigned long indigo = 0x33ff33;
const unsigned long mintgreen = 0x0022ff;
const unsigned long green = 0x0000ff;
const unsigned long cyan = 0x00ffff;
const unsigned long blue = 0x00ff00;
const unsigned long violet = 0x55ff00;
const unsigned long magenta = 0xffff00;
const unsigned long white = 0xffffff;

const unsigned long coral = 0xff2222;
const unsigned long pink = 0xff5555;
const unsigned long purple = 0x88ff00;

const unsigned long yellow = 0xff00ff;
const unsigned long orange = 0xff00bb;
const unsigned long campfire = 0xff0022;
const unsigned long sunset = 0xff0088;
const unsigned long red = 0xff0000;
const unsigned long myNum = 0xab0055;

PROGMEM const unsigned long pattern_rainbow[7][10]={ 
    {red,orange,yellow,green,blue,indigo,violet,red,orange,yellow},
    {orange,yellow,green,blue,indigo,violet,red,orange,yellow,green},
    {yellow,green,blue,indigo,violet,red,orange,yellow,green,blue},
    {green,blue,indigo,violet,red,orange,yellow,green,blue,indigo},
    {blue,indigo,violet,red,orange,yellow,green,blue,indigo,violet},
    {indigo,violet,red,orange,yellow,green,blue,indigo,violet,red,},
    {violet,red,orange,yellow,green,blue,indigo,violet,red,orange},
};

PROGMEM const unsigned long pattern_test[10][10]={ 
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
  {myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum,myNum},
};

PROGMEM const unsigned long pattern_warm_rainbow[10][10]={ 
  {yellow,orange,sunset,campfire,red,yellow,orange,sunset,campfire,red},
  {red,yellow,orange,sunset,campfire,red,yellow,orange,sunset,campfire},
  {campfire,red,yellow,orange,sunset,campfire,red,yellow,orange,sunset},
  {sunset,campfire,red,yellow,orange,sunset,campfire,red,yellow,orange},
  {orange,sunset,campfire,red,yellow,orange,sunset,campfire,red,yellow},
  {yellow,orange,sunset,campfire,red,yellow,orange,sunset,campfire,red},
  {red,yellow,orange,sunset,campfire,red,yellow,orange,sunset,campfire},
  {campfire,red,yellow,orange,sunset,campfire,red,yellow,orange,sunset},
  {sunset,campfire,red,yellow,orange,sunset,campfire,red,yellow,orange},
  {orange,sunset,campfire,red,yellow,orange,sunset,campfire,red,yellow}
};

/* Colors:
 *  Red
 *  Orange
 *  SunsetOrange
 *  Yellow
 *  mint green
 *  Green
 *  Cyan
 *  Blue
 *  Violet
 *  Magenta
 *  Pink
 *  White
 */ 





const unsigned long cool1 = violet;
const unsigned long cool2 = blue;
const unsigned long cool3 = 0x00ff55;
const unsigned long cool4 = cyan;
const unsigned long cool5 = 0x0099ff;

PROGMEM const unsigned long pattern_cool_rainbow[10][10]={ 
    {cool1,cool2,cool3,cool4,cool5,cool1,cool2,cool3,cool4,cool5},
    {cool5,cool1,cool2,cool3,cool4,cool5,cool1,cool2,cool3,cool4},
    {cool4,cool5,cool1,cool2,cool3,cool4,cool5,cool1,cool2,cool3},
    {cool3,cool4,cool5,cool1,cool2,cool3,cool4,cool5,cool1,cool2},
    {cool2,cool3,cool4,cool5,cool1,cool2,cool3,cool4,cool5,cool1},
    {cool1,cool2,cool3,cool4,cool5,cool1,cool2,cool3,cool4,cool5},
    {cool5,cool1,cool2,cool3,cool4,cool5,cool1,cool2,cool3,cool4},
    {cool4,cool5,cool1,cool2,cool3,cool4,cool5,cool1,cool2,cool3},
    {cool3,cool4,cool5,cool1,cool2,cool3,cool4,cool5,cool1,cool2},
    {cool2,cool3,cool4,cool5,cool1,cool2,cool3,cool4,cool5,cool1},
};

PROGMEM const unsigned long pattern_constant_red[10][10]={ 
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
};

PROGMEM const unsigned long pattern_constant_sunset[10][10]={ 
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
};

PROGMEM const unsigned long pattern_constant_yellow[10][10]={ 
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow}
};


PROGMEM const unsigned long pattern_constant_mintgreen[10][10]={ 
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
};

PROGMEM const unsigned long pattern_constant_green[10][10]={ 
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
  {green,green,green,green,green,green,green,green,green,green},
};

PROGMEM const unsigned long pattern_constant_cyan[10][10]={ 
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan}
};

PROGMEM const unsigned long pattern_constant_blue[10][10]={ 
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue}
};


PROGMEM const unsigned long pattern_constant_violet[10][10]={ 
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet}
};

PROGMEM const unsigned long pattern_constant_magenta[10][10]={ 
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
};

PROGMEM const unsigned long pattern_constant_pink[10][10]={ 
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink}
};

PROGMEM const unsigned long pattern_constant_white[10][10]={ 
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white},
  {white,white,white,white,white,white,white,white,white,white}
};

PROGMEM const unsigned long pattern_cycle_colors[11][10]={ 
  {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000},
  {sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset,sunset},
  {yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow},
  {mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen,mintgreen},
  {green,green,green,green,green,green,green,green,green,green},
  {cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan,cyan},
  {blue,blue,blue,blue,blue,blue,blue,blue,blue,blue},
  {violet,violet,violet,violet,violet,violet,violet,violet,violet,violet},
  {magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta},
  {pink,pink,pink,pink,pink,pink,pink,pink,pink,pink},
  {white,white,white,white,white,white,white,white,white,white},
};




//solid color button pin - red
const int SCBP = 3;
//rainbow pattern button pin - green
const int RPBP = 4;
//individual pattern button pin - blue
const int IPBP = 5;
//potentiameter pin for brightness
const int potPin = A2;

int SCBS = 0;
int RPBS = 0;
int IPBS = 0;

int LedStripMode = 0;
int currTime = 0;

// ***********************************************************************************************************
// *
// *                            Power Up Init.
// *
// *
// ***********************************************************************************************************
void setup() {
  Serial.begin(9600);
  pinMode(SCBP, INPUT_PULLUP);
  pinMode(RPBP, INPUT_PULLUP);
  pinMode(IPBP, INPUT_PULLUP);

  STRIP_PINOUT;        // set output pin - DEBUG: should auto detect which mother board for use

  reset_strip();
  //noInterrupts();
}



// ***********************************************************************************************************
// *
// *                            Main Loop 
// *
// *
// ***********************************************************************************************************
int colorState = 0;
int rainbowState = 0;
int patternState = 0;

int state = 0;
bool power = true;

const int numColors = 11;
const int numRainbows = 3;
const int numPatterns = 4;

static const unsigned long REFRESH_INTERVAL = 7000; // ms
static unsigned long lastRefreshTime = 0;


void loop() 
{
 
  SCBS = digitalRead(SCBP);
  RPBS = digitalRead(RPBP);
  IPBS = digitalRead(IPBP);
  String toPrint = String("");
  Serial.println(toPrint + state + IPBS);
 

   if(millis() - lastRefreshTime >= REFRESH_INTERVAL)
   {
        lastRefreshTime += REFRESH_INTERVAL;
        state = 0;
   }

  if(SCBS == LOW && state == 0) {
    state = 1;
  }
 
  if(RPBS == LOW && state == 1) {
    state = 2;
  }
  if(IPBS == LOW && state == 2) {
    send_1M_pattern(pattern_off, 10, 70);
    state = 0;
    power = !power;

  }

  if (power == false) { return; }

  

  if(SCBS == LOW && LedStripMode == 0){
    colorState++;
  } else if(RPBS == LOW && LedStripMode == 1){
    rainbowState++;
  } else if(IPBS == LOW && LedStripMode == 2) {
    patternState++;
  } else if(SCBS == LOW){
    LedStripMode = 0;
  } else if(RPBS == LOW){
    LedStripMode = 1;
  } else if(IPBS == LOW){
    LedStripMode = 2;
  }

  if(LedStripMode == 0) {
    if(colorState >= numColors) {
      colorState = colorState % numColors;
    }

    if(colorState == 0) {
      send_1M_pattern(pattern_constant_red, 10, 70);
    } else if (colorState == 1) {
      send_1M_pattern(pattern_constant_sunset, 10, 70);
    } else if (colorState == 2) {
      send_1M_pattern(pattern_constant_yellow, 10, 70);
    } else if (colorState == 3) {
      send_1M_pattern(pattern_constant_mintgreen, 10, 70);
    } else if (colorState == 4) {
      send_1M_pattern(pattern_constant_green, 10, 70);
    } else if (colorState == 5) {
      send_1M_pattern(pattern_constant_cyan, 10, 70);
    } else if (colorState == 6) {
      send_1M_pattern(pattern_constant_blue, 10, 70);
    } else if (colorState == 7) {
      send_1M_pattern(pattern_constant_violet, 10, 70);
    } else if (colorState == 8) {
      send_1M_pattern(pattern_constant_magenta, 10, 70);
    } else if (colorState == 9) {
      send_1M_pattern(pattern_constant_pink, 10, 70);
    } else if (colorState == 10) {
      send_1M_pattern(pattern_constant_white, 10, 70);
    }
    
    
  } else if (LedStripMode == 1) {
    if (rainbowState >= numRainbows) {
      rainbowState = rainbowState % numRainbows;
    }
    if(rainbowState == 0) {
      send_1M_pattern(pattern_warm_rainbow, 10, 70);
    } else if (rainbowState == 1) {
      send_1M_pattern(pattern_rainbow, 7, 100);
    } else if (rainbowState == 2) {
      send_1M_pattern(pattern_cool_rainbow, 10, 90);
    }
       
  } else if (LedStripMode == 2) {

    if(patternState >= numPatterns) {
      patternState = patternState % numPatterns;
    }
    if(patternState == 0) {
      send_1M_pattern(pattern_test_comet3, 10, 70);
    } else if (patternState == 1){
      send_1M_pattern(pattern_test_comet2, 10, 70);
    } else if (patternState == 2){
      send_1M_pattern(pattern_test_comet1, 10, 70);
    } else if (patternState == 3){
      send_1M_pattern(pattern_cycle_colors, 11, 300);
    }
    
    
  }
  
}


/*******************************************************************************
 * Function Name  : send_1M_pattern
 * Description    : Transmit pattern to whole 1 meter strip
 *                  
 * Input          : pointer to ROM pattern; pattern length; frame rate
 *                  
 * Output         : None
 * Return         : None
 *******************************************************************************/
void send_1M_pattern(const unsigned long data[][10], int pattern_no, int frame_rate)
{
  int i=0;
  int j=0;
  uint32_t temp_data;

  for (i=0;i<pattern_no;i++)
  {
    noInterrupts();
    for (j=0;j<10;j++)
    {
      temp_data=pgm_read_dword_near(&data[i][j]);
      send_strip(temp_data);
    }
    interrupts();

    delay(frame_rate);

  }




}


/*******************************************************************************
 * Function Name  : send_strip
 * Description    : Transmit 24 pulse to LED strip
 *                  
 * Input          : 24-bit data for the strip
 *                  
 * Output         : None
 * Return         : None
 *******************************************************************************/
void send_strip(uint32_t data)
{
  int i;
  unsigned long j=0x800000;
  
 
  for (i=0;i<24;i++)
  {
    if (data & j)
    {
      DATA_1;
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");    
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      
/*----------------------------*/
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");  
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");  
      __asm__("nop\n\t");  
      __asm__("nop\n\t");        
/*----------------------------*/      
      DATA_0;
    }
    else
    {
      DATA_1;
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");    
      DATA_0;
/*----------------------------*/      
       __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");      
/*----------------------------*/         
    }

    j>>=1;
  }


  
}

/*******************************************************************************
 * Function Name  : reset_strip
 * Description    : Send reset pulse to reset all color of the strip
 *                  
 * Input          : None
 *                  
 * Output         : None
 * Return         : None
 *******************************************************************************/
void	reset_strip()
{
  DATA_0;
  delayMicroseconds(20);
}
