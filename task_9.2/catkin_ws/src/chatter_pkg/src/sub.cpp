#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int64.h"

void chatterCallBack(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("New Message : %s",msg->data.c_str());
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"reciever");
    ros::NodeHandle nr;
    ros::Subscriber reciever = nr.subscribe("chat",1000,chatterCallBack);
    ros::spin();
    return 0;
} 