#include "nodes/TankDriveNode.h"

TankDriveNode::TankDriveNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, 
        TankEightMotors motors, TankDriveKinematics kinematics) : IDriveNode(node_manager), 
        m_controller(controller->getController()), 
        m_motors(motors), 
        m_kinematics(kinematics) {

    m_handle_name = handle_name.insert(0, "robot/");
}

void TankDriveNode::m_setLeftPosition(float distance, int max_velocity) {
    m_motors.left_1_motor->moveAbsolute(distance, max_velocity);
    m_motors.left_2_motor->moveAbsolute(distance, max_velocity);
    m_motors.left_3_motor->moveAbsolute(distance, max_velocity);
    m_motors.left_4_motor->moveAbsolute(distance, max_velocity);
}

void TankDriveNode::m_setRightPosition(float distance, int max_velocity) {
    m_motors.right_1_motor->moveAbsolute(distance, max_velocity);
    m_motors.right_2_motor->moveAbsolute(distance, max_velocity);
    m_motors.right_3_motor->moveAbsolute(distance, max_velocity);
    m_motors.right_4_motor->moveAbsolute(distance, max_velocity);
}

void TankDriveNode::m_setLeftVoltage(int voltage) {
    m_motors.left_1_motor->moveVoltage(voltage);
    m_motors.left_2_motor->moveVoltage(voltage);
    m_motors.left_3_motor->moveVoltage(voltage);
    m_motors.left_4_motor->moveVoltage(voltage);
}

void TankDriveNode::m_setRightVoltage(int voltage) {
    m_motors.right_1_motor->moveVoltage(voltage);
    m_motors.right_2_motor->moveVoltage(voltage);
    m_motors.right_3_motor->moveVoltage(voltage);
    m_motors.right_4_motor->moveVoltage(voltage);
}

void TankDriveNode::m_setLeftVelocity(float velocity) {
    m_motors.left_1_motor->moveVelocity(velocity);
    m_motors.left_2_motor->moveVelocity(velocity);
    m_motors.left_3_motor->moveVelocity(velocity);
    m_motors.left_4_motor->moveVelocity(velocity);
}

void TankDriveNode::m_setRightVelocity(float velocity) {
    m_motors.right_1_motor->moveVelocity(velocity);
    m_motors.right_2_motor->moveVelocity(velocity);
    m_motors.right_3_motor->moveVelocity(velocity);
    m_motors.right_4_motor->moveVelocity(velocity);
}

void TankDriveNode::resetEncoders() {
    m_motors.left_1_motor->resetEncoder();
    m_motors.left_2_motor->resetEncoder();
    m_motors.left_3_motor->resetEncoder();
    m_motors.left_4_motor->resetEncoder();
    m_motors.right_1_motor->resetEncoder();
    m_motors.right_2_motor->resetEncoder();
    m_motors.right_3_motor->resetEncoder();
    m_motors.right_4_motor->resetEncoder();
}

TankDriveNode::FourMotorDriveEncoderVals TankDriveNode::getIntegratedEncoderVals() {
    FourMotorDriveEncoderVals encoder_vals = {
        m_motors.left_1_motor->getPosition(),
        m_motors.left_2_motor->getPosition(),
        m_motors.left_3_motor->getPosition(),
        m_motors.left_4_motor->getPosition()
    };

    return encoder_vals;
}

void TankDriveNode::initialize() {
    resetEncoders();
}

void TankDriveNode::setDriveVoltage(int x_voltage, int theta_voltage) {
    IDriveKinematics::FourMotorPercentages motor_percentages = m_kinematics.inverseKinematics(x_voltage, 0, theta_voltage, MAX_MOTOR_VOLTAGE);

    
}

void TankDriveNode::setDriveVelocity(float x_velocity, float theta_velocity) { //incoming values should be in m/s so we convert to rpm here
    IDriveKinematics::FourMotorPercentages motor_percentages = 
        m_kinematics.inverseKinematics(x_velocity, 0, theta_velocity, MAX_VELOCITY);

    m_setLeftVelocity(motor_percentages.left_front_percent * MAX_VELOCITY);
    m_setRightVelocity(motor_percentages.right_front_percent * MAX_VELOCITY);
}

void TankDriveNode::teleopPeriodic() {
    int left_y = m_controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int right_x = m_controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    int left = left_y + right_x;
    int right = left_y - right_x;

    m_setLeftVoltage(copysign(max(min(fabs(left) / 127.0, 127.0), 0.0) * MAX_MOTOR_VOLTAGE, left));
    m_setRightVoltage(copysign(max(min(fabs(right) / 127.0, 127.0), 0.0) * MAX_MOTOR_VOLTAGE, right));
}

void TankDriveNode::autonPeriodic() {

}

TankDriveNode::~TankDriveNode() {
    
}