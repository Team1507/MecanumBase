// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithXbox.h"
#include "GamepadMap.h"


//Local Prototypes
void Drive_Tank(Drivetrain *drivetrain, float left, float right); 
void Drive_Test1(Drivetrain *drivetrain, float l_y, float l_x, float r_x);
void Drive_Test2(Drivetrain *drivetrain, float l_y, float l_x, float r_x);



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

// Called repeatedly when this Command is scheduled to run
void CmdDriveWithXbox::Execute() 
{

  const float DEADBAND = 0.05;


  //Get joystick axis
  float left_y_axis  = -m_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_Y);  //Negate y-axis so positive is forward
  float left_x_axis  =  m_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_X);
  float right_y_axis = -m_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_Y);  //Negate y-axis so positive is forward
  float right_x_axis =  m_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_X);


  //Control DeadBand
  if ( fabs(left_x_axis)  <= DEADBAND ) left_x_axis  = 0.0;
  if ( fabs(left_y_axis)  <= DEADBAND ) left_y_axis  = 0.0;
  if ( fabs(right_x_axis) <= DEADBAND ) right_x_axis = 0.0;
  if ( fabs(right_y_axis) <= DEADBAND ) right_y_axis = 0.0;


  //ONLY PICK ONE!!!!
  //Drive_Tank(m_drivetrain, left_y_axis, right_y_axis);
  Drive_Test1(m_drivetrain, left_y_axis, left_x_axis, right_x_axis);
  //Drive_Test2(m_drivetrain, left_y_axis, left_x_axis, right_x_axis);
 


}

// Called once the command ends or is interrupted.
void CmdDriveWithXbox::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveWithXbox::IsFinished() {
  return false;
}

//**************************************************************
void Drive_Tank(Drivetrain *drivetrain, float left, float right)
{
  drivetrain->TankDrive(left,right);
}

//**************************************************************
void Drive_Test1(Drivetrain *drivetrain, float l_y, float l_x, float r_x)
{
  const float LX_PERCENT = 0.4;   //LX = left x axis
  const float LY_PERCENT = 0.4;   //LY = left y axis
  const float RX_PERCENT = 0.2;   //RX = right x axis I thought turning should not get as much power

  //Update powers
  l_y *= LY_PERCENT;
  l_x *= LX_PERCENT;
  r_x *= RX_PERCENT;

  //Do the math!
  float lf = (  l_x - l_y - r_x );
  float lr = ( -l_x - l_y - r_x );
  float rf = (  l_x + l_y + r_x );
  float rr = ( -l_x + l_y + r_x );


//drivetrain->Drive(lf,lr,rf,rr);     //This is wrong
  drivetrain->Drive(lf,rf,lr,rr);     //Fixed order

}



//**************************************************************
void Drive_Test2(Drivetrain *drivetrain, float l_y, float l_x, float r_x)
{


}