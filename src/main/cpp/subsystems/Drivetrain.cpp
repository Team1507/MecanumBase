// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
{


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


void Drivetrain::Stop(void)
{
    m_lf_motor.Set(0.0);
    m_rf_motor.Set(0.0);
    m_lr_motor.Set(0.0);
    m_rr_motor.Set(0.0);
}