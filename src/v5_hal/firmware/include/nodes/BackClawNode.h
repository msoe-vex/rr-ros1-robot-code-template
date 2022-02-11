#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/nodes/subsystems/IClawNode.h"
#include "pros/misc.h"

class BackClawNode : public IClawNode {
private:
    bool back_claw_open = false;
    bool a_previous_state = false;
public:
    ClawNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, ADIDIgitalOutNode* back_claw);

    virtual void initialize();

    virtual void useClaw(bool opened);

    virtual void teleopPeriodic();

    virtual void autonPeriodic();

    virtual ~ClawNode();
};