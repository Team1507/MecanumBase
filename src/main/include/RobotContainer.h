#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"

#include "subsystems/Drivetrain.h"


class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  //We are cheating here by making these public - but we are OK with it as it ONLY allows
  //  top level Robot object to access them to make debugging easier.
  Drivetrain m_drivetrain;
  frc::XboxController m_xbox{0};

 private:
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;




  void ConfigureButtonBindings();
};
