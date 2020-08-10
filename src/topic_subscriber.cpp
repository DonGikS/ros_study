#include "ros/ros.h"                                //ROS basic header file.
#include "ros_cpp_study_pkg/MsgTutorial.h"          //MsgTutorial message file header(will generate after build).

//Message Callback function, to operate function when the topic called
//'ros_cpp_study_pkg' recieved.
//Input value message would be 'ros_cpp_study_pkg' package's MsgTutorial message.
void msgCallback(const ros_cpp_study_pkg::MsgTutorial::ConstPtr& msg){
    ROS_INFO("recieve msg = %d", msg->stamp.sec);   /////////////////
    ROS_INFO("recieve msg = %d", msg->stamp.nsec);  ///print msg/////
    ROS_INFO("recieve msg = %d", msg->data);         /////////////////
}

int main(int argc, char **argv){                    //Node main().
    ros::init(argc, argv, "topic_subscriber");      //Node name initialize.

    ros::NodeHandle nh;                             //Node Handler declare for communicate with ROS system.


    //Subscriber declare, Subscriber ros_tutorial_sub write down to use 
    //ros_cpp_study_pkg package's MsgTutorial message file.
    //The topic name is "ros_tutorial_msg", Subscriber's queue size is setting to 100.
    ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

    //As a function for called a Callback function, it will operate when messages are recieved.
    ros::spin();

    return 0;
}