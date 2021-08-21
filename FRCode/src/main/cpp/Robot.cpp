// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {
  joystick = new frc::Joystick(0);
  motor = new rev::CANSparkMax(1, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  double dz = 0.1;
  double RawX = joystick->GetRawAxis(1);
  double x = fabs(RawX);

  if(x > dz) {
    double y = (1/(1-dz))*(x) - (dz/(1-dz));
    if (RawX < 0) y = -y;
    motor->Set(y);
  } else motor->Set(0);

}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

