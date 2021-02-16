/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\wznmickey                                        */
/*    Created:      Sun Nov 08 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "move.h"
//#include"chassisControl.h"
using namespace vex;

vex::competition Competition;

void autonomous( void )
{
    int  chooseabc=1;   //zuo=1,you=2
    if (chooseabc==1)
    {
        int move_straight,turn,up,down,in,out,left_velocity,right_velocity;
        Brain.resetTimer();
        double t= Brain.timer(vex::timeUnits::msec);
        Brain.Screen.print("testA");

//直行，吸球，吐球
        move_straight=50;
        left_velocity=50;
        right_velocity=50;      //左侧abc

        robot.chassis.Down();
        vex::task::sleep(300);

        robot.chassis.Up();
        vex::task::sleep(300);

        robot.chassis.Stopupdown();
        vex::task::sleep(300);

        move(left_velocity,right_velocity);
        robot.chassis.In();
        vex::task::sleep(1300);
        robot.chassis.Brake("coast");

        vex::task::sleep(200);

        robot.chassis.StopInOut();
        robot.chassis.Up();
        vex::task::sleep(500);   //扔出预装

        robot.chassis.Stopupdown();
        vex::task::sleep(500);   //检查

        robot.chassis.In();
        vex::task::sleep(500);      //吸取到的第二个

        robot.chassis.StopInOut();
        vex::task::sleep(500);      //检查

        robot.chassis.Up();
        vex::task::sleep(500);   //扔出取到的第一个

        robot.chassis.Stopupdown();
        vex::task::sleep(500);     //检查




        robot.chassis.In();
        vex::task::sleep(600);     //吸进对方球

        robot.chassis.StopInOut();
        vex::task::sleep(500);    //检查

//后退
        robot.chassis.Out();
        move(-50,-50);

        vex::task::sleep(1000);
        robot.chassis.StopInOut();
        robot.chassis.Brake("coast");

//右转135度

        vex::task::sleep(100);

        move(50,-50);
        vex::task::sleep(1500);
        robot.chassis.Brake("coast");

//从下面扔出球
        vex::task::sleep(100);

        robot.chassis.Out();
        vex::task::sleep(400);
        robot.chassis.StopInOut();

//右转135度

        vex::task::sleep(500);
        robot.chassis.Brake("coast");
        move(50,-50);
        vex::task::sleep(550);
        robot.chassis.Brake("coast");

//直行
        vex::task::sleep(100);

        move(50,50);
        vex::task::sleep(2500);
        robot.chassis.Brake("coast");

//扔球
        vex::task::sleep(100);

        robot.chassis.Up();
        robot.chassis.In();
        vex::task::sleep(2000);
// robot.chassis.In();
        //vex::task::sleep(1000);
        robot.chassis.Stopupdown();
        robot.chassis.StopInOut();
    }
    else
    {


        int move_straight,turn,up,down,in,out,left_velocity,right_velocity;
        Brain.resetTimer();
        double t= Brain.timer(vex::timeUnits::msec);
        Brain.Screen.print("testA");

//直行，吸球，吐球
        move_straight=50;
        left_velocity=50;
        right_velocity=50;      //右侧abc

        robot.chassis.Down();
        vex::task::sleep(300);

        robot.chassis.Up();
        vex::task::sleep(300);

        robot.chassis.Stopupdown();
        vex::task::sleep(300);

        move(left_velocity,right_velocity);
        robot.chassis.In();
        vex::task::sleep(1300);
        robot.chassis.Brake("coast");

        vex::task::sleep(200);

        robot.chassis.StopInOut();
        robot.chassis.Up();
        vex::task::sleep(500);   //扔出预装

        robot.chassis.Stopupdown();
        vex::task::sleep(500);   //检查

        robot.chassis.In();
        vex::task::sleep(500);      //吸取到的第二个

        robot.chassis.StopInOut();
        vex::task::sleep(500);      //检查

        robot.chassis.Up();
        vex::task::sleep(500);   //扔出取到的第一个

        robot.chassis.Stopupdown();
        vex::task::sleep(500);     //检查




        robot.chassis.In();
        vex::task::sleep(600);     //吸进对方球

        robot.chassis.StopInOut();
        vex::task::sleep(500);    //检查

//后退
        robot.chassis.Out();
        move(-50,-50);

        vex::task::sleep(1000);
        robot.chassis.StopInOut();
        robot.chassis.Brake("coast");

//右转135度

        vex::task::sleep(100);

        move(-50,50);
        vex::task::sleep(1500);
        robot.chassis.Brake("coast");

//从下面扔出球
        vex::task::sleep(100);

        robot.chassis.Out();
        vex::task::sleep(400);
        robot.chassis.StopInOut();

//右转135度

        vex::task::sleep(500);
        robot.chassis.Brake("coast");
        move(-50,50);
        vex::task::sleep(550);
        robot.chassis.Brake("coast");

//直行
        vex::task::sleep(100);

        move(50,50);
        vex::task::sleep(2500);
        robot.chassis.Brake("coast");

//扔球
        vex::task::sleep(100);

        robot.chassis.Up();
        robot.chassis.In();
        vex::task::sleep(2000);
// robot.chassis.In();
        //vex::task::sleep(1000);
        robot.chassis.Stopupdown();
        robot.chassis.StopInOut();
    }
    return;
}




void usercontrol( void )
{
//important


    int C1,C2,C3,C4,L1,L2,R1,R2,X,Y,A,B,L,R,U,D,left_velocity,right_velocity,up,down,in,out; //定义遥控器遥感和按键
    //int C1,C3,left_velocity,right_velocity;
    double clamp_timer=0; //定义气动计时器
    double leave_timer, push_start_timer=0; //定义X按下的计时器
    int move_straight,turn,push_foward,push_back,cube_in,cube_out,clamp,score,leave;
    Brain.resetTimer();
    double t= Brain.timer(vex::timeUnits::msec);
    int turn_flag=1;
    while (1)
    {
        // 获取遥控器指令
        //if (Controller.ButtonLeft.pressing()){autonomous();}
        C1=Controller.Axis1.position(vex::percentUnits::pct);
        printf("C1:%d",C1);
        //C2=Controller.Axis2.position(vex::percentUnits::pct);
        C3=Controller.Axis3.position(vex::percentUnits::pct);
        printf("C3:%d",C3);
        //C4=Controller.Axis4.position(vex::percentUnits::pct);
        L1=Controller.ButtonL1.pressing();
        L2=Controller.ButtonL2.pressing();
        R1=Controller.ButtonR1.pressing();
        R2=Controller.ButtonR2.pressing();
        //X=Controller.ButtonX.pressing();
        Y=Controller.ButtonY.pressing();
        A=Controller.ButtonA.pressing();
        //B=Controller.ButtonB.pressing();
        if (Y) turn_flag=1;
        if (A) turn_flag=2;
        //L=Controller.ButtonLeft.pressing();
        //R=Controller.ButtonRight.pressing();
        //U=Controller.ButtonUp.pressing();
        //D=Controller.ButtonDown.pressing();
        //  遥感功能
        Brain.Screen.print("time:%lf C1:%d\n C3:%d\n",t,C1,C3);
        move_straight=C3;
        turn=C1;
        up=L1;
        down=L2;
        in=R1;
        out=R2;


        //if (R2)
        //turn{turn=100;left_velocity=move_straight+turn;right_velocity=move_straight-turn;move(left_velocity,right_velocity);vex::task::sleep(200);}
        //if (R1)
        //{turn=-100;left_velocity=move_straight+turn;right_velocity=move_straight-turn;move(left_velocity,right_velocity);vex::task::sleep(200);}


        //防止同时按2个键
        if ((up) &&(down)) down=0;
        if (up) robot.chassis.Up();
        if (down) robot.chassis.Down();
        if (!down && !up) robot.chassis.Stopupdown();
        if ((in) &&(out)) down=0;
        if (in) robot.chassis.In();
        if (out) robot.chassis.Out();
        if (!in && !out) robot.chassis.StopInOut();

        //clamp=A;
        //push_foward=X;
        //push_back=B;
        //score=L1;
        //leave=L2;
        //智能一键放方块,需要按住
        //if(score){
        //  Auto_Push();
        //  continue;
        //}
        //else if(leave){
        //  leave_timer=Brain.timer(timeUnits::msec);
        //  Auto_Leave(leave_timer,push_start_timer);
        //  continue;
        //}
        //else if(Brain.timer(timeUnits::msec)-score>500)push_start_timer=Brain.timer(timeUnits::msec);

        // 基本气动系统控制以及输出
        /*if(cube_in){  //吸方块时夹子夹紧
          pneumatics_close.set(true);
          pneumatics_open.set(false);
        }
        else if(clamp && Brain.timer(timeUnits::msec)-clamp_timer>500){
        clamp_timer = Brain.timer(timeUnits::msec);
          if(pneumatics_close.value()){ // 打开夹子
              pneumatics_close.set(false);
              pneumatics_open.set(true);
          }
          else {  // 关闭夹子
              pneumatics_close.set(true);
              pneumatics_open.set(false);
          }
        }
        */
        // 基本底座控制及输出
        //if(push_foward)PID_Push();
        //else if(push_back)Push(-13000);
        //else if(cube_in){
        //  if((RightPush.rotation(vex::rotationUnits::deg)+LeftPush.rotation(vex::rotationUnits::deg))/2>params.getValue("down_value")+25)Push(-6500);
        //else
        //if((RightPush.rotation(vex::rotationUnits::deg)+LeftPush.rotation(vex::rotationUnits::deg))/2<params.getValue("down_value")-25)Push(6500);
        //else Push(0);
        //}
        //else Push(0);

        // 底盘控制

        //误触保护
        //if(abs(turn)<1)turn=0;
        //if(abs(move_straight)<10)move_straight=0;

        //if (turn>0 && turn <30)turn=30-0.5*(30-turn);
        //else {
        //  if (turn<0 && turn>-30) turn=-(30-0.5*(30-abs(turn)));
        //}

        if (turn_flag==1)
        {
            turn=0.4*turn;
        }
        if (turn_flag==2)
        {
            if(turn>60)turn=60+0.5*(turn-60);
            if(turn<-60)turn=-(60+0.5*(abs(turn)-60));
        }
        //if(turn>60)turn=60+0.5*(turn-60);
        //if(turn<-60)turn=-(60+0.5*(abs(turn)-60));
        // 吸方块控制及输出
        //if(cube_in){ //吸的时候需要关闭夹子
        //  pneumatics_close.set(true);
        //  pneumatics_open.set(false);
        //  Intake(13000);
        //}
        //else if(cube_out) Intake(-13000);
        //else Intake(0);


        //底盘输出
        left_velocity=move_straight+turn;
        right_velocity=move_straight-turn;
        move(left_velocity,right_velocity);



        vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
    }
}

int main()
{
    // Initializing Robot Configuration. DO NOT REMOVE!
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    //vex::task t1(status);
    while(1)
    {
        vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }

}
