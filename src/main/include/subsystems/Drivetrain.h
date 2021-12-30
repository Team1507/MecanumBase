#pragma once
#include <frc/Spark.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/RobotDrive.h>


class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  
  void Periodic() override;

  //void MecDrive( float x, float y, float z);<<<<<<<<<<<

  void Drive( float lf,  float rf,  float lr,  float rr );
  void TankDrive( float left,  float right );
  void Stop(void);




 private:

  frc::Spark m_lf_motor{0};
  frc::Spark m_lr_motor{1};
  
  frc::Spark m_rf_motor{2};
  frc::Spark m_rr_motor{3};

};
