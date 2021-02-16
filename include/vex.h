#ifndef VEX_H
#define VEX_H
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "v5.h"
#include "v5_vcs.h"
vex::brain Brain;
vex::controller Controller = vex::controller();

//////////////////////////////motors////////////////////////////////
// wheel motors:
vex::motor LeftHand(vex::PORT4,vex::gearSetting::ratio6_1,true);  // 8个600rpm底盘马达
vex::motor RightHand(vex::PORT9,vex::gearSetting::ratio6_1,false);
vex::motor LeftWheel1(vex::PORT5,vex::gearSetting::ratio6_1,false);
vex::motor LeftWheel2(vex::PORT1,vex::gearSetting::ratio6_1,false);
vex::motor RightWheel1(vex::PORT8,vex::gearSetting::ratio6_1,true);
vex::motor RightWheel2(vex::PORT18,vex::gearSetting::ratio6_1,true);
vex::motor LeftOn(vex::PORT2,vex::gearSetting::ratio6_1,true);
vex::motor RightOn(vex::PORT3,vex::gearSetting::ratio6_1,false);
//vex::bumper PushBumper = vex::bumper(Brain.ThreeWirePort.F);
//vex::limit ChooseLimit = vex::limit(Brain.ThreeWirePort.D); 

#endif

