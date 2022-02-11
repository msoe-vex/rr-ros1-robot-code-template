#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/nodes/subsystems/ILiftNode.h"
#include "pros/misc.h"

class LiftNode : public ILiftNode {

public:
    LiftNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, MotorNode* left_motor, MotorNode* right_motor);
    
     virtual void initialize() = 0;

    virtual void setLiftVoltage(int voltage) = 0;

    virtual void setLiftVelocity(int velocity) = 0;

    virtual void setLiftPosition(int position) = 0;

    virtual void teleopPeriodic() {};

    virtual void autonPeriodic() {};

    virtual ~ILiftNode();
};