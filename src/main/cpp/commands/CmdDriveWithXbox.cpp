// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithXbox.h"
#include "GamepadMap.h"



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

  float left_x_axis  = m_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_X);
  float left_y_axis  = m_xbox->GetRawAxis(GAMEPADMAP_AXIS_L_Y);
  float right_x_axis = m_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_X);
  float right_y_axis = m_xbox->GetRawAxis(GAMEPADMAP_AXIS_R_Y);


  m_drivetrain->TankDrive(left_y_axis,right_y_axis);

}

// Called once the command ends or is interrupted.
void CmdDriveWithXbox::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveWithXbox::IsFinished() {
  return false;
}
