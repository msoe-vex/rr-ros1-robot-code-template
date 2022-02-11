#include "nodes/LiftNode.h"

LiftNode::LiftNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, MotorNode* left_motor, MotorNode* right_motor)
: ILiftNode(node_manager, handle_name), 
m_controller(controller->getController()),
m_left_motor(left_motor),
m_right_motor(right_motor)
{

}

void initialize() {

};

void setLiftVoltage(int voltage) {
    
};

void setLiftVelocity(int velocity) {

};

void setLiftPosition(int position) {

};

void teleopPeriodic() {

};

void autonPeriodic() {

};

~ILiftNode();
}