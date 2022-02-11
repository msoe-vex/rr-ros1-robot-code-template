#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/nodes/subsystems/IDriveNode.h"
#include "api.h"
#include "lib-rr/nodes/actuator_nodes/MotorNode.h"
#include "lib-rr/nodes/sensor_nodes/ControllerNode.h"
#include "lib-rr/kinematics/TankDriveKinematics.h"

class TankDriveNode : public IDriveNode {
public: 
    struct TankEightMotors {
        MotorNode* left_1_motor;
        MotorNode* left_2_motor;
        MotorNode* left_3_motor;
        MotorNode* left_4_motor;
        MotorNode* right_1_motor;
        MotorNode* right_2_motor;
        MotorNode* right_3_motor;
        MotorNode* right_4_motor;
    };

    TankDriveNode(NodeManager* node_manager, std::string handle_name, ControllerNode* controller, 
        TankEightMotors motors, TankDriveKinematics kinematics);

    virtual void initialize();

    virtual void resetEncoders();

    virtual FourMotorDriveEncoderVals getIntegratedEncoderVals();

    virtual void setDriveVoltage(int x_voltage, int theta_voltage);

    virtual void setDriveVoltage(int x_voltage, int y_voltage, int theta_voltage);

    virtual void setDriveVelocity(float x_velocity, float theta_velocity);

    virtual void setDriveVelocity(float x_velocity, float y_velocity, float theta_velocity);

    virtual void teleopPeriodic();

    virtual void autonPeriodic();

    ~TankDriveNode();

private:
    pros::Controller* m_controller;

    std::string m_handle_name;

    TankEightMotors m_motors;

    TankDriveKinematics m_kinematics;

};
