#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/nodes/subsystems/IClawNode.h"
#include "lib-rr/nodes/sensor_nodes/ControllerNode.h"
#include "lib-rr/nodes/actuator_nodes/ADIDigitalOutNode.h"
#include "pros/misc.h"

class PrimaryClawNode : public IClawNode {
private:
    bool claw_open = false;
    bool m_button_previous_state = false;
    ControllerNode* m_controller;
    ADIDigitalOutNode* m__claw;
    pros::controller_digital_e_t open_button;
    pros::controller_digital_e_t close_button;

    
public:
    PrimaryClawNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller,
    ADIDigitalOutNode* claw, pros::controller_digital_e_t open_button, pros::controller_digital_e_t close_button) ;

    void initialize();

    void useClaw(bool opened);

    void teleopPeriodic();

    void autonPeriodic();

    ~PrimaryClawNode();
};