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

void TankDriveNode::initialize() {
    resetEncoders();
}

void TankDriveNode::setDriveVoltage(int x_voltage, int theta_voltage) {
    IDriveKinematics::FourMotorPercentages motor_percentages = m_kinematics.inverseKinematics(x_voltage, 0, theta_voltage, MAX_MOTOR_VOLTAGE);

    
}

void TankDriveNode::setDriveVelocity(float x_velocity, float theta_velocity) { //incoming values should be in m/s so we convert to rpm here
    // 
}

void TankDriveNode::teleopPeriodic() {
    m_setLeftVoltage(((m_controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) / 127.0) * MAX_MOTOR_VOLTAGE);
    m_setRightVoltage(((m_controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)) / 127.0) * MAX_MOTOR_VOLTAGE);
}

void TankDriveNode::autonPeriodic() {

}

TankDriveNode::~TankDriveNode() {
    
}