//
// Created by Papa Smerf on 10.11.2019.
//

#ifndef ROBOT_ROBOTDIMENSIONS_H
#define ROBOT_ROBOTDIMENSIONS_H


class RobotDimensions {
private:
    constexpr static const double wheelRadius{0.034};
    constexpr static const double robotRadius{0.0965};
public:
    static double getWheelRadius();
    static double getRobotRadius();
};


#endif //ROBOT_ROBOTDIMENSIONS_H
