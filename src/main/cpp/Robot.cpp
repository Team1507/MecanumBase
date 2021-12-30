#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include "GamepadMap.h"

void Robot::RobotInit() 
{
    //*************************** INIT ******************************
    std::cout<<"RobotInit"<<std::endl;
    std::cout<<"FRC2021: MecanumBase Test Code"<<std::endl;

    std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 

}

void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
  WriteToSmartDashboard();
}

void Robot::DisabledInit() 
{
  std::cout<<"Disabled Init"<<std::endl;
  m_container.m_drivetrain.Stop();
}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() 
{
  std::cout<<"Teleop Init"<<std::endl;

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}


void Robot::WriteToSmartDashboard(void)
{

  //Joystick Test
  frc::SmartDashboard::PutNumber("LeftXAxis",  (double)m_container.m_xbox.GetRawAxis( GAMEPADMAP_AXIS_L_X ) ); 
  frc::SmartDashboard::PutNumber("LeftYAxis",  (double)m_container.m_xbox.GetRawAxis( GAMEPADMAP_AXIS_L_Y ) );
  frc::SmartDashboard::PutNumber("RightXAxis", (double)m_container.m_xbox.GetRawAxis( GAMEPADMAP_AXIS_R_X ) );
  frc::SmartDashboard::PutNumber("RightYAxis", (double)m_container.m_xbox.GetRawAxis( GAMEPADMAP_AXIS_R_Y ) );


  //Motors
  frc::SmartDashboard::PutNumber("LF_Motor",  m_container.m_drivetrain.GetLeftFrontMotor()  );
  frc::SmartDashboard::PutNumber("LR_Motor",  m_container.m_drivetrain.GetLeftRearMotor()   );  
  frc::SmartDashboard::PutNumber("RF_Motor",  m_container.m_drivetrain.GetRightFrontMotor() );
  frc::SmartDashboard::PutNumber("RR_Motor",  m_container.m_drivetrain.GetRightRearMotor()  );

}



#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
