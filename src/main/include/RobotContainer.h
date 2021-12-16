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

 private:
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;


  Drivetrain m_drivetrain;
  frc::XboxController m_xbox{0};


  void ConfigureButtonBindings();
};
