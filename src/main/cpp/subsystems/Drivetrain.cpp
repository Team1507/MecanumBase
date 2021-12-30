// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
{
    //Motors are set so POSITIVE power = FORWARD motion.
    m_lf_motor.SetInverted(true);
    m_lr_motor.SetInverted(false);
    m_rf_motor.SetInverted(false);
    m_rr_motor.SetInverted(false);

}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}



void Drivetrain::Drive( float lf,  float rf,  float lr,  float rr )
{
    m_lf_motor.Set(lf);
    m_rf_motor.Set(rf);
    m_lr_motor.Set(lr);
    m_rr_motor.Set(rr);
}


void Drivetrain::TankDrive( float left,  float right )
{
    m_lf_motor.Set(left);    
    m_lr_motor.Set(left);

    m_rf_motor.Set(right);
    m_rr_motor.Set(right);  
}


void Drivetrain::Stop(void)
{
    m_lf_motor.Set(0.0);
    m_rf_motor.Set(0.0);
    m_lr_motor.Set(0.0);
    m_rr_motor.Set(0.0);
}



  float Drivetrain::GetLeftFrontMotor(void)
  {
    return m_lf_motor.Get();
  }
  float Drivetrain::GetLeftRearMotor(void)
  {
    return m_lr_motor.Get();
  }
  float Drivetrain:: GetRightFrontMotor(void)
  {
    return m_rf_motor.Get();
  }
  float Drivetrain::GetRightRearMotor(void)
  {
    return m_rr_motor.Get();
  }
