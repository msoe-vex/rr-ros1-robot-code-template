#pragma once

#include "lib-rr/nodes/NodeManager.h"
#include "lib-rr/auton/auton_routines/TestPathAuton.h"
#include "lib-rr/auton/auton_routines/TestPoseAuton.h"
#include "lib-rr/auton/auton_routines/TestTurnAuton.h"
#include "lib-rr/pathing/PathManager.h"

class AutonManagerNode : public Node {
private:
    Auton* m_test_path_auton;
    Auton* m_prog_skills;

public:
    AutonManagerNode(NodeManager* node_manager);

    Auton* selected_auton;

    void initialize();

    void autonPeriodic();
};
