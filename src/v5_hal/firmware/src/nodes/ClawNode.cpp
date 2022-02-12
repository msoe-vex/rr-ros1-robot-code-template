#include "nodes/ClawNode.h"

ClawNode::ClawNode(NodeManager* node_manager, std::string handle_name, 
		ControllerNode* controller, ADIDigitalOutNode* claw, pros::controller_digital_e_t open_button, pros::controller_digital_e_t close_button) : 
		IClawNode(node_manager, handle_name), 
		m_controller(controller),
		m_claw(claw),
		m_open_button(open_button),
		m_close_button(close_button) {

}

void ClawNode::initialize() {

}

void ClawNode::useClaw(bool opened) {
	if (opened) {
		m_claw->setValue(0);
	} else {
        m_claw->setValue(1);
	}
}
void ClawNode::teleopPeriodic() {
	if(m_controller->getController()->get_digital(m_open_button) && !m_controller->getController()->get_digital(m_close_button)) {
		m_claw->setValue(1);
	}else if (m_controller->getController()->get_digital(m_close_button) && !m_controller->getController()->get_digital(m_open_button)) {
		m_claw->setValue(0);
	}
}

void ClawNode::autonPeriodic() {

}

ClawNode::~ClawNode() {

}