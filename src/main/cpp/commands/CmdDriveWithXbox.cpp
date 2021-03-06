#include "commands/CmdDriveWithXbox.h"
#include "GamepadMap.h"
#include "frc/smartdashboard/SmartDashboard.h"


//Local Prototypes
void Drive_Tank(Drivetrain *drivetrain, float left, float right); 
void Drive_Test1(Drivetrain *drivetrain, float l_y, float l_x, float r_x);
void Drive_Test2(Drivetrain *drivetrain, float l_y, float l_x, float r_x);
void Drive_Test3(Drivetrain *drivetrain, float l_y, float l_x, float r_x);

CmdDriveWithXbox::CmdDriveWithXbox(Drivetrain *drivetrain, frc::XboxController *xbox ) 
{
  m_drivetrain = drivetrain;
  m_xbox = xbox;

  AddRequirements({m_drivetrain});
}

// Called when the command is initially scheduled.
void CmdDriveWithXbox::Initialize() 
{
  std::cout<<"Starting CmdDriveWithXbox"<<std::endl;
}

void CmdDriveWithXbox::Execute() 
{

  const float DEADBAND = 0.05;


  //Get joystick axis
  float left_y_axis  = -m_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_Y);  //Negate Y joystick so positive is forward
  float left_x_axis  =  m_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_X); 
  float right_y_axis = -m_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_Y);  //Negate Y joystick so positive is forward
  float right_x_axis =  m_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_X); 


  //Control DeadBand
  if ( fabs(left_x_axis)  <= DEADBAND ) left_x_axis  = 0.0;
  if ( fabs(left_y_axis)  <= DEADBAND ) left_y_axis  = 0.0;
  if ( fabs(right_x_axis) <= DEADBAND ) right_x_axis = 0.0;
  if ( fabs(right_y_axis) <= DEADBAND ) right_y_axis = 0.0;


  //ONLY PICK ONE!!!!
  //Drive_Tank(m_drivetrain, left_y_axis, right_y_axis); 
  //Drive_Test1(m_drivetrain, left_y_axis, left_x_axis, right_x_axis);    //Testing only
  //Drive_Test2(m_drivetrain, left_y_axis, left_x_axis, right_x_axis);    //Tylers Code
  Drive_Test3(m_drivetrain, left_y_axis, left_x_axis, right_x_axis);      //Kris' Code
 


}

void CmdDriveWithXbox::End(bool interrupted) {}

bool CmdDriveWithXbox::IsFinished() {
  return false;
}

//**************************************************************
void Drive_Tank(Drivetrain *drivetrain, float left, float right)
{
  drivetrain->TankDrive(left,right);
}

//**************************************************************
// Test1 is to work out the math to make sure signs are right
// while the robot is sitting on a bench
void Drive_Test1(Drivetrain *drivetrain, float l_y, float l_x, float r_x)
{
  const float LX_PERCENT = 0.33;   //LX = left x axis
  const float LY_PERCENT = 0.33;   //LY = left y axis
  const float RX_PERCENT = 0.33;   //RX = right x axis

  //Update powers
  l_y *= LY_PERCENT;
  l_x *= LX_PERCENT;
  r_x *= RX_PERCENT;

  //Do the math!
  float lf = (  l_x + l_y + r_x );
  float lr = ( -l_x + l_y + r_x );
  float rf = ( -l_x + l_y - r_x );
  float rr = (  l_x + l_y - r_x );

  drivetrain->Drive(lf,rf,lr,rr);
}



//**************************************************************
//  Tylers code
void Drive_Test2(Drivetrain *drivetrain, float l_y, float l_x, float r_x)
{


  const float DEADBAND = 0.05;

// wanted power is the length between x and y 
  float wantedPower = sqrt((l_x*l_x)) + ((l_y*l_y))/sqrt(2); //Pythagorean theorem 

  if(wantedPower > 1)// This shouldn't happen
  { 
    wantedPower = 1.0;
  }
  else if((fabs(r_x) > DEADBAND) && (fabs(r_x) > wantedPower))//Gives power to rotation if it is the largest 
  {
    wantedPower = r_x;
  }
  else if(wantedPower < DEADBAND)
  {
    wantedPower = 0.0;
  }
  
  
  //Do the math! (copied from Test1)
  float lf = (  l_x + l_y + r_x );
  float lr = ( -l_x + l_y + r_x );
  float rf = ( -l_x + l_y - r_x );
  float rr = (  l_x + l_y - r_x );



  float greatestPower = lf;
  if(fabs(greatestPower) < fabs(lr))
  {
    greatestPower = lr;
  }
  if(fabs(greatestPower) < fabs(rf))
  {
    greatestPower = rf;
  }
  if(fabs(greatestPower) < fabs(rr))
  {
    greatestPower = rr;
  }
  

  //greatest * ratio = wanted
  //ratio is used to make the power on the moters equal to wanted
  float powerRatio = 0;
  if(fabs(greatestPower) > DEADBAND) powerRatio = fabs(wantedPower/greatestPower); // stops division by zero

  drivetrain->Drive((lf * powerRatio) , (rf * powerRatio) , (lr * powerRatio) , (rr * powerRatio));

  //DEBUG
  frc::SmartDashboard::PutNumber("wanted power", wantedPower);
  frc::SmartDashboard::PutNumber("power ratio",   powerRatio);

}


//**************************************************************
//  Kris' code
void Drive_Test3(Drivetrain *drivetrain, float l_y, float l_x, float r_x)
{  
  
  //Do the math! (copied from Test1)
  float lf = (  l_x + l_y + r_x );
  float lr = ( -l_x + l_y + r_x );
  float rf = ( -l_x + l_y - r_x );
  float rr = (  l_x + l_y - r_x );


  //Find the largest number greater than 1.0
  float greatestPower = 1.00;         //Set at 1.0
  if(fabs(greatestPower) < fabs(lf))
  {
    greatestPower = lr;
  }
  if(fabs(greatestPower) < fabs(lr))
  {
    greatestPower = lr;
  }
  if(fabs(greatestPower) < fabs(rf))
  {
    greatestPower = rf;
  }
  if(fabs(greatestPower) < fabs(rr))
  {
    greatestPower = rr;
  }
  

  //Divide all powers by greatestPower to normalize to 1.0
  drivetrain->Drive((lf/greatestPower) , (rf/greatestPower) , (lr/greatestPower) , (rr/greatestPower) );

}



