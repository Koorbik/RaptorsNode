#include "ros/ros.h"
#include "std_msgs/String.h"

void raptorOutCallback(const std_msgs::String::ConstPtr& signedMsg) {
    ROS_INFO("Received message on RaptorOUT: %s", signedMsg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "RaptorOUT");

    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe("/RaptorOUT", 10, raptorOutCallback);

    ros::spin();

    return 0;
}


