#include<ros/ros.h>
#include<mid_msgs/mid_msg.h>

void show(const mid_msgs::mid_msg::ConstPtr& mid_msg)
{
    ROS_INFO("stranger : %s", mid_msg->String.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscribe_msg_node");
    ros::NodeHandle n;

    ros::Subscriber subscriber_msg;
    subscriber_msg = n.subscribe("mid_msg",1000, show); 
    ros::Rate loop_rate(60);

    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();

    }
    return 0;
}