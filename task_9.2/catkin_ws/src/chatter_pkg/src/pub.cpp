#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"sender");
    ros::NodeHandle ns;
    ros::Publisher sender = ns.advertise<std_msgs::String>("chat",1000);
    ros::Rate loop_rate(1);
    int counter = 0;
    while(ros::ok())
    {
        std_msgs::String msg;
        msg.data = "Hello! counter = " + std::to_string(counter);
        sender.publish(msg);
        ros::spinOnce;
        loop_rate.sleep();
        counter++;
    }
    return 0;
}