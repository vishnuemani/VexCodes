#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftBack = motor(PORT11, ratio18_1, false);
motor RightBack = motor(PORT13, ratio18_1, false);
motor LeftFront = motor(PORT1, ratio18_1, false);
motor RightFront = motor(PORT15, ratio18_1, false);
motor Intake = motor(PORT17, ratio18_1, false);
motor Intake2 = motor(PORT19, ratio18_1, false);
motor Lift1 = motor(PORT9, ratio18_1, false);
motor roller = motor(PORT14, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
