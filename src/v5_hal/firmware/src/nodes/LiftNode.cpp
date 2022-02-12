#include "nodes/LiftNode.h"

LiftNode::LiftNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, MotorNode* left_motor, MotorNode* right_motor, ADIDigitalIn* bottom_limit_switch, ADIDigitalIn* top_limit_switch, ADIAnalogIn* potentiometer)
: ILiftNode(node_manager, handle_name), 
m_controller(controller->getController()),
m_left_motor(left_motor),
m_right_motor(right_motor)
m_bottom_limit_switch(bottom_limit_switch),
m_top_limit_switch(top_limit_switch),
m_(bottom_limit_switch),
m_lift_pid(0.03, 0., 0.0, 2)
{

}

void LiftNode::initialize() {

};

void LiftNode::setLiftVoltage(int voltage) {
    if (m_top_bottom_switch->getValue() || m_bottom_limit_switch->getValue()) {
        m_left_motor->moveVoltage(0);
        m_right_motor->moveVoltage(0);
    } else {
        m_left_motor->moveVoltage(voltage);
        m_right_motor->moveVoltage(voltage);
    }
};

void LiftNode::setLiftVelocity(int velocity) {
    if (m_top_bottom_switch->getValue() || m_bottom_limit_switch->getValue()) {
        m_left_motor->moveVeloctiy(0);
        m_right_motor->moveVelocity(0);
    } else {
        m_left_motor->moveVeloctiy(velocity);
        m_right_motor->moveVelocity(velocity);
    }
};

void LiftNode::setLiftPosition(int position) {
    // int currentPosition = m_potentiometer->getValue();
    // int errorPosition = position - currentPosition;
    // float lift_feedback = m_lift_pid->calculate(errorPosition);
    // problems: need to work logic into periodic loop that runs on the robot, allow the robot to run the pid periodically check and update the error
};

int LiftNode::getPosition(); {
    return m_potentiometer->getValue();
}

void LiftNode::teleopPeriodic() {
    void LiftNode::setLiftVoltage(int voltage) {
    if (m_top_bottom_switch->getValue() || m_bottom_limit_switch->getValue()) {
        m_left_motor->moveVoltage(0);
        m_right_motor->moveVoltage(0);
    } else {
        if (m_controller->get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			m_left_motor->moveVoltage(MAX_MOTOR_VOLTAGE);
            m_right_motor->moveVoltage(-1*MAX_MOTOR_VOLTAGE);
		} else if (m_controller->get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			m_left_motor->moveVoltage(-1*MAX_MOTOR_VOLTAGE);
            m_right_motor->moveVoltage(MAX_MOTOR_VOLTAGE);
		} else {
			four_bar_left.move_velocity(0);
			four_bar_right.move_velocity(0);
		}
    }
};

void LiftNode::autonPeriodic() {

};

~ILiftNode();
}