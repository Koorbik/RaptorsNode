#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


void raptorCallback(const std_msgs::String::ConstPtr& msg) {
    std::string receivedMessage = msg->data;
    ROS_INFO("[%s]", msg->data.c_str());

    
    std::string author = "Hubert Szadkowski";
    std::stringstream signedMessage;
    signedMessage << author << " / " << ros::Time::now() << ": " << receivedMessage;

    
    ros::NodeHandle nh;
    ros::Publisher publisher = nh.advertise<std_msgs::String>("/RaptorOUT", 10);

    std_msgs::String signedMsg;
    signedMsg.data = signedMessage.str();
    publisher.publish(signedMsg);
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "raptorNode");


    ros::NodeHandle nh;

    
    ros::Subscriber subscriber = nh.subscribe("/RaptorIN", 10, raptorCallback);

    ros::spin();

    return 0;
}
