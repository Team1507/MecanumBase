// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithXbox.h"



CmdDriveWithXbox::CmdDriveWithXbox(Drivetrain *drivetrain, frc::XboxController *xbox ) 
{
  m_drivetrain = drivetrain;
  m_xbox = xbox;

  AddRequirements({m_drivetrain});

}

// Called when the command is initially scheduled.
void CmdDriveWithXbox::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdDriveWithXbox::Execute() 
{

  //Add Tyler Code Here!!!!!
  float left_x_axis = m_xbox->GetRawAxis(0);
  float left_y_axis = m_xbox->GetRawAxis(1);


}

// Called once the command ends or is interrupted.
void CmdDriveWithXbox::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveWithXbox::IsFinished() {
  return false;
}
