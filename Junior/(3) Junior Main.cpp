// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         12              
// RightBack            motor         14              
// LeftFront            motor         13              
// RightFront           motor         18              
// Intake               motor         20              
// Intake2              motor         19              
// Lift1                motor         10              
// roller               motor         15              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h" 
using namespace vex;
#include <cmath>
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void sleep(int time){
    vex::task::sleep(time);
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void stop(){
    RightBack.stop();
    RightFront.stop();
    LeftBack.stop();
    LeftFront.stop();
    
}
void auton_drive (int speed, int time){
    LeftBack.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::rev,speed,vex::velocityUnits::rpm);
    RightFront.spin(vex::directionType::rev,speed,vex::velocityUnits::rpm);
    sleep(time);
    stop();
    
}
void auton_rpm (int speed, float revs){
    

    LeftBack.rotateFor(revs,vex::rotationUnits::rev,speed,vex::velocityUnits::pct, false);
    LeftFront.rotateFor(revs,vex::rotationUnits::rev,speed,vex::velocityUnits::pct, false);
    RightBack.rotateFor(revs,vex::rotationUnits::rev,speed,vex::velocityUnits::pct, false);
    RightFront.rotateFor(revs,vex::rotationUnits::rev,speed,vex::velocityUnits::pct, false);
    //stop();
    
}



void turnCC (int speed, int time){
   
    LeftBack.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::fwd,-speed,vex::velocityUnits::rpm);
    RightFront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::rpm);
    sleep(time);
    stop();
}

void turnToRight (int speed, int speed2, int time){
   
    LeftBack.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::fwd,speed2,vex::velocityUnits::rpm);
    RightFront.spin(vex::directionType::fwd,speed2,vex::velocityUnits::rpm);
    sleep(time);
    //stop();
}
float topSpeed = 50.0;
float minSpeed = 0;
float maxAngle = -1391.0;
float minAngle = -41.0;

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

    
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



int deadzone(int num){
    
       return 0.5* num*pow(abs(num), 0.75)/(pow(127, 0.75));
       
    
}

void drive_forward() {
    LeftFront.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    RightFront.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    RightBack.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
}

void forward_turn(){
    RightBack.spin(vex::directionType::fwd, 0.4*deadzone(Controller1.Axis1.value()) - deadzone(Controller1.Axis3.value()), vex::velocityUnits::pct);
    LeftFront.spin(vex::directionType::fwd, 0.4*deadzone(Controller1.Axis1.value()) + deadzone(Controller1.Axis3.value()), vex::velocityUnits::pct);
    RightFront.spin(vex::directionType::fwd, 0.4*deadzone(Controller1.Axis1.value()) - deadzone(Controller1.Axis3.value()), vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::fwd, 0.4*deadzone(Controller1.Axis1.value()) + deadzone(Controller1.Axis3.value()), vex::velocityUnits::pct);
}

void forward_slow(){
    RightBack.spin(vex::directionType::fwd, 0.2*deadzone(Controller1.Axis3.value()) - 0.1*deadzone(Controller1.Axis1.value()), vex::velocityUnits::pct);
    LeftFront.spin(vex::directionType::fwd, 0.2*deadzone(Controller1.Axis3.value()) + 0.1*deadzone(Controller1.Axis1.value()), vex::velocityUnits::pct);
    RightFront.spin(vex::directionType::fwd, 0.2*deadzone(Controller1.Axis3.value()) - 0.1*deadzone(Controller1.Axis1.value()), vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::fwd, 0.2*deadzone(Controller1.Axis3.value()) + 0.1*deadzone(Controller1.Axis1.value()), vex::velocityUnits::pct);
}




void turn(){
    LeftFront.spin(vex::directionType::fwd, (-Controller1.Axis4.value()), vex::velocityUnits::pct);
    RightFront.spin(vex::directionType::fwd, (Controller1.Axis4.value()), vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::fwd, (-Controller1.Axis4.value()), vex::velocityUnits::pct);
    RightBack.spin(vex::directionType::fwd, (Controller1.Axis4.value()), vex::velocityUnits::pct);

}







void usercontrol( void ) {
  // User control code here, inside the loop
 
  while (1) {
    
    //Brain.Screen.print(speed);
    //wait(1, sec);
      
    //Brain.Screen.clearLine();
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks
     
    wait(5,msec);
      
    
    Drive_Left.spin(vex::directionType::fwd, 0.4*deadzone(Controller1.Axis1.value()) + deadzone(Controller1.Axis3.value()), vex::velocityUnits::pct);
    Drive_Right.spin(vex::directionType::fwd, 0.4*deadzone(Controller1.Axis1.value()) - deadzone(Controller1.Axis3.value()), vex::velocityUnits::pct);
    

    
      
      //THIS IS FOR Roller Motors::
      
      if(Controller1.ButtonR1.pressing()){

        roller.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        highRoller.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
          
          
      } else if(Controller1.ButtonR2.pressing()){
        roller.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
        highRoller.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
          
      } 
      else{
        roller.stop(vex::brakeType::hold);
        highRoller.stop(vex::brakeType::hold);
      }




      
      if(Controller1.ButtonUp.pressing()){

        index_roller.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        
          
          
      } else if(Controller1.ButtonDown.pressing()){
        index_roller.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
        
          
      } 
      else{
        index_roller.stop(vex::brakeType::hold);
      }
      
      
      
      
      
      

      ///
      ///Intake:
    
      
      
      if(Controller1.ButtonL1.pressing()){
          Intake.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
          Intake2.spin(vex::directionType::fwd, -80, vex::velocityUnits::pct);

      }
      else if(Controller1.ButtonL2.pressing()){
          Intake.spin(vex::directionType::fwd, -80, vex::velocityUnits::pct);
          Intake2.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);

      }
      else {
        Intake.stop(vex::brakeType::hold);
        Intake2.stop(vex::brakeType::hold);
      }
      
      
      
      if(Controller1.ButtonY.pressing()){
         //PLACE ANY AUTON CODE HERE FOR SKILLS
          
      }
      


    
         
}
      
      
    
      
      
      
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }



//
// Main will set up the competition functions and callbacks.
//
int main() {
    
    //Run the pre-autonomous function. 
    
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    


    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      wait(100,msec);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}
