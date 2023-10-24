#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include<iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "circle_node");

  ROS_INFO("run circle");
  ros::NodeHandle n;

  geometry_msgs::Twist cmd_vel;
  ros::Publisher publisher_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(60);

  cmd_vel.linear.x = 1;
  cmd_vel.linear.y = 0;
  int i=0;
  int j=0;
  while (ros::ok())
  {
    
    if(i<100 && j == 0){
      cmd_vel.linear.x = 1;
      cmd_vel.linear.y = 0;
      i=i+1;
      ROS_INFO("right");
    }
    else if(i == 100 && j<100){
      cmd_vel.linear.x = 0;
      cmd_vel.linear.y = 1;
      j=j+1;
      ROS_INFO("up");
    }
    else if(i>0 && i<=100 && j == 100){
      cmd_vel.linear.x = -1;
      cmd_vel.linear.y = 0;
      i=i-1;
      ROS_INFO("left");
    }
    else if(i == 0 && j<=100){
      cmd_vel.linear.x = 0;
      cmd_vel.linear.y = -1;
      j=j-1;
      ROS_INFO("down");
    }
    publisher_cmd_vel.publish(cmd_vel);
    
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}