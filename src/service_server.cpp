#include "ros/ros.h"
#include "ros_cpp_study_pkg/SrvTutorial.h"

bool calculation(ros_cpp_study_pkg::SrvTutorial::Request &req,
                 ros_cpp_study_pkg::SrvTutorial::Response &res)
{
    res.result = req.a + req.b;

    ROS_INFO("request: x=%ld y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back respnse: %ld", (long int)res.result);

    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "service_server");
    ros::NodeHandle nh;

    ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv", calculation);

    ROS_INFO("read srv server!");

    ros::spin();

    return 0;
}