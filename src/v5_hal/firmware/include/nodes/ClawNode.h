#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/nodes/subsystems/IClawNode.h"

class ClawNode : public IClawNode {
public:
    ClawNode(NodeManager* node_manager, std::string handle_name);

    virtual void initialize();

    virtual void openClaw();

    virtual void closeClaw();

    virtual void teleopPeriodic();

    virtual void autonPeriodic();

    virtual ~ClawNode();
};