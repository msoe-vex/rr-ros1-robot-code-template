#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/nodes/subsystems/IClawNode.h"
#include "lib-rr/nodes/sensor_nodes/ControllerNode.h"
#include "lib-rr/nodes/actuator_nodes/ADIDigitalOutNode.h"
#include "pros/misc.h"

class BackClawNode : public IClawNode {
private:
    bool back_claw_open = false;
    bool a_previous_state = false;
    
    ControllerNode* m_controller;
    ADIDigitalOutNode* m_back_claw;

public:
    BackClawNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, ADIDigitalOutNode* back_claw);

    virtual void initialize();

    virtual void useClaw(bool opened);

    virtual void teleopPeriodic();

    virtual void autonPeriodic();

    virtual ~BackClawNode();
};