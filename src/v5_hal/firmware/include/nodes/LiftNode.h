#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/nodes/subsystems/ILiftNode.h"
#include "pros/misc.h"
#include "lib-rr/util/PID.h

class LiftNode : public ILiftNode {
private:
    PID m_lift_pid;
public:
    LiftNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, MotorNode* left_motor, MotorNode* right_motor, ADIDigitalIn* bottom_limit_switch, ADIDigitalIn* top_limit_switch, ADIAnalogIn* potentiometer);
    
     virtual void initialize() = 0;

    virtual void setLiftVoltage(int voltage) = 0;

    virtual void setLiftVelocity(int velocity) = 0;

    virtual void setLiftPosition(int position) = 0;

    virtual int getPosition() = 0;

    virtual void teleopPeriodic() {};

    virtual void autonPeriodic() {};

    virtual ~ILiftNode();
};