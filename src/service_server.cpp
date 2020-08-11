#include "ros/ros.h"                        //ROS basic header file
#include "ros_cpp_study_pkg/SrvTutorial.h"  //SrvTutorial Service file header

#define PLUS            1   //sum
#define MINUS           2   //sub
#define MULTIPLICATION  3   //mult
#define DIVISION        4   //div

int g_operator = PLUS;       //default operator is sum.

//This service processed following code, when you had requested service.
//Service Request is req, and Service Response is res.
bool calculation(ros_cpp_study_pkg::SrvTutorial::Request &req,
                 ros_cpp_study_pkg::SrvTutorial::Response &res)
{
    //Operating setting is changed by parameter value(sum, sub, etc...)
    //values of a and b will calculate with each setting.
    //After calculating, it will save service response value.
    switch(g_operator)
    {
        case PLUS:
            res.result = req.a + req.b; break;
        case MINUS:
            res.result = req.a - req.b; break;
        case MULTIPLICATION:
            res.result = req.a * req.b; break;
        case DIVISION:
            if(req.b == 0) {
                ROS_INFO("Can't divide by 0.");
                res.result = 0; break;
            }
            else res.result = req.a / req.b; break;
        default:
            res.result = req.a + req.b; break;
    }


    //Using a, b values and result value by using Service Request display
    ROS_INFO("request: x=%ld y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: %ld", (long int)res.result);

    return true;
}

int main(int argc, char **argv){                    //Node main()
    ros::init(argc, argv, "service_server");        //Node name initialize
    ros::NodeHandle nh;                             //Node Handle initialize

    nh.setParam("calculation_method", PLUS);         //Parameter init setting

    //Service server declare, 'service_server' write to use 
    //ros_cpp_study_pkg package's SrvTutorial service file.
    //The service name is "ros_tutorial_srv", it will calculate when you request service.

    ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv", calculation);

    ROS_INFO("Calculation is ready!");

    ros::Rate r(10); //10hz

    while(1){
        //Operator modified a given value from parameter value
        nh.getParam("calculation_method", g_operator);
        ros::spinOnce();                           //Callback function process rootine.
        r.sleep();                                 //sleep process for rootine looped.
    }
    return 0;
}