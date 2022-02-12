#include "nodes/LiftNode.h"

LiftNode::LiftNode(NodeManager* node_manager, std::string handle_name, 
        ControllerNode* controller, MotorNode* motor,  
        pros::controller_digital_e_t up_button, pros::controller_digital_e_t down_button) : 
        ILiftNode(node_manager, handle_name), 
        m_controller(controller),
        m_motor(motor),
        m_up_button(up_button),
        m_down_button(down_button),
        m_lift_pid(0.03, 0., 0., 2) {

}

void LiftNode::initialize() {
    m_motor->getMotor()->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
};

void LiftNode::setLiftVoltage(int voltage) {
    m_motor->moveVoltage(voltage);
};

void LiftNode::setLiftVelocity(int velocity) {
    m_motor->moveVelocity(velocity);
};

void LiftNode::setLiftPosition(int position) {
    // int currentPosition = m_potentiometer->getValue();
    // int errorPosition = position - currentPosition;
    // float lift_feedback = m_lift_pid->calculate(errorPosition);
    // problems: need to work logic into periodic loop that runs on the robot, allow the robot to run the pid periodically check and update the error
};

int LiftNode::getPosition() {
    return m_motor->getPosition();
}

void LiftNode::teleopPeriodic() {
    if (m_controller->getController()->get_digital(m_up_button) && 
            !m_controller->getController()->get_digital(m_down_button)) {
        m_motor->moveVoltage(MAX_MOTOR_VOLTAGE);
    } else if (m_controller->getController()->get_digital(m_down_button) && 
            !m_controller->getController()->get_digital(m_up_button)) {
        m_motor->moveVoltage(-MAX_MOTOR_VOLTAGE);
    } else {
        m_motor->moveVoltage(0);
    }
};

void LiftNode::autonPeriodic() {

};

LiftNode::~LiftNode() {

}