#include <ros/ros.h>
#include <vending_msgs/vending_msg.h>
void vend(const vending_msgs::vending_msg::ConstPtr& vending_msg)
{
    ROS_INFO("drink : %s", vending_msg->String.c_str());
    ROS_INFO("change :%d", vending_msg->Int16);
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "vending_subscribe_node");
  ros::NodeHandle n;

  ros::Subscriber subscriber_msg;
  subscriber_msg = n.subscribe("vending_msg",1000,vend);
  ros::Rate loop_rate(60);


   while(ros::ok()){
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
