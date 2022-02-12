#include "nodes/LiftNode.h"

LiftNode::LiftNode(NodeManager* node_manager, std::string handle_name, 
        ControllerNode* controller, MotorNode* left_motor, 
        MotorNode* right_motor, ADIDigitalInNode* bottom_limit_switch, 
        ADIDigitalInNode* top_limit_switch, ADIAnalogInNode* potentiometer, 
        pros::controller_digital_e_t up_button, pros::controller_digital_e_t down_button) : 
        ILiftNode(node_manager, handle_name), 
        m_controller(controller),
        m_left_motor(left_motor),
        m_right_motor(right_motor),
        m_bottom_limit_switch(bottom_limit_switch),
        m_top_limit_switch(top_limit_switch),
        m_potentiometer(potentiometer),
        m_up_button(up_button),
        m_down_button(down_button),
        m_lift_pid(0.03, 0., 0., 2) {

}

void LiftNode::initialize() {
    m_left_motor->getMotor()->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	m_right_motor->getMotor()->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
};

void LiftNode::setLiftVoltage(int voltage) {
    if (m_top_limit_switch->getValue() || m_bottom_limit_switch->getValue()) {
        m_left_motor->moveVoltage(0);
        m_right_motor->moveVoltage(0);
    } else {
        m_left_motor->moveVoltage(voltage);
        m_right_motor->moveVoltage(voltage);
    }
};

void LiftNode::setLiftVelocity(int velocity) {
    if (m_top_limit_switch->getValue() || m_bottom_limit_switch->getValue()) {
        m_left_motor->moveVelocity(0);
        m_right_motor->moveVelocity(0);
    } else {
        m_left_motor->moveVelocity(velocity);
        m_right_motor->moveVelocity(velocity);
    }
};

void LiftNode::setLiftPosition(int position) {
    // int currentPosition = m_potentiometer->getValue();
    // int errorPosition = position - currentPosition;
    // float lift_feedback = m_lift_pid->calculate(errorPosition);
    // problems: need to work logic into periodic loop that runs on the robot, allow the robot to run the pid periodically check and update the error
};

int LiftNode::getPosition() {
    return m_potentiometer->getValue();
}

void LiftNode::teleopPeriodic() {
    if (m_controller->getController()->get_digital(m_up_button) && 
            !m_controller->getController()->get_digital(m_down_button)) {
        m_left_motor->moveVoltage(MAX_MOTOR_VOLTAGE);
        m_right_motor->moveVoltage(-1 * MAX_MOTOR_VOLTAGE);
    } else if (m_controller->getController()->get_digital(m_up_button) && 
            !m_controller->getController()->get_digital(m_down_button)) {
        m_left_motor->moveVoltage(-1*MAX_MOTOR_VOLTAGE);
        m_right_motor->moveVoltage(MAX_MOTOR_VOLTAGE);
    } else {
        m_left_motor->moveVoltage(0);
		m_right_motor->moveVoltage(0);
    }
};

void LiftNode::autonPeriodic() {

};

LiftNode::~LiftNode() {

}