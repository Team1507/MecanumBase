#include "RobotContainer.h"

#include "commands/CmdDriveWithXbox.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) 
{

  //Default Commands
  m_drivetrain.SetDefaultCommand(   CmdDriveWithXbox( &m_drivetrain, &m_xbox)  );

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{

}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  return &m_autonomousCommand;
}
