#include "nodes/ClawNode.h"

ClawNode::ClawNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, ADIDIgitalOutNode* primary_claw, ADIDIgitalOutNode* back_claw)
: IClawNode(node_manager, handle_name), 
m_controller(controller->getController()),
m_primary_claw(primary_claw),
m_back_claw(back_claw)
 {

}

void ClawNode::initialize() {

}

void ClawNode::openClaw() {

}

void ClawNode::closeClaw() {

}

void ClawNode::teleopPeriodic() {
    bool front_claw_open = false;
	bool back_claw_open = false;
	bool l1_current_state = m_controller->get_digital(pros::E_CONTROLLER_DIGITAL_L1);
	bool l1_previous_state = false;
	bool a_current_state = m_controller->get_digital(pros::E_CONTROLLER_DIGITAL_A);
	bool a_previous_state = false;

    if (l1_current_state == 1 && l1_previous_state == 0) {
			front_claw_open->!front_claw_open;
		}

	if (a_current_state == 1 && a_previous_state == 0) {
			back_claw_open = !back_claw_open;
		}

	l1_previous_state = l1_current_state;
	a_previous_state = a_current_state;
}

void ClawNode::autonPeriodic() {

}

ClawNode::~ClawNode() {

}