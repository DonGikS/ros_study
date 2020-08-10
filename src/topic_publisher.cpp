#include "ros/ros.h"                            //ROS basic header file.
#include "ros_cpp_study_pkg/MsgTutorial.h"      //MsgTutorial message file header(will generate after build).

int main(int argc, char **argv){                //Node main().
    ros::init(argc, argv, "topic_publisher");   //Node name initialize.
    ros::NodeHandle nh;                         //Node Handler declare for communicate with ROS system.


    //Publisher declare, Publisher ros_tutorial_pub write down to use 
    //ros_cpp_study_pkg package's MsgTutorial message file.
    //The topic name is "ros_tutorial_pub", Publisher's queue size is setting to 100.
    ros::Publisher ros_tutorial_pub = nh.advertise<ros_cpp_study_pkg::MsgTutorial>("ros_tutorial_msg", 100);

    ros::Rate loop_rate(10);                    //setting loop period, '10' means 10hz, it will process 0.1 sec repeat.

    ros_cpp_study_pkg::MsgTutorial msg;         //MsgTutorial message file form declare as msg.
    int count = 0;

    while(ros::ok()){
        msg.stamp = ros::Time::now();           //Present time insert to msg.stamp message.
        msg.data = count;                       //put count in msg.data.

        ROS_INFO("send msg = %d", msg.stamp.sec);   ////////////////////
        ROS_INFO("send msg = %d", msg.stamp.nsec);  ////print msg//////
        ROS_INFO("send msg = %d", msg.data);        //////////////////

        ros_tutorial_pub.publish(msg);          //publish msg

        loop_rate.sleep();                      //into sleep as setting loop period

        ++count;                                //count up
    }
    return 0;
}