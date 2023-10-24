#include <ros/ros.h>
#include "mid_srvs/midsrv.h"
#include <geometry_msgs/Twist.h>

ros::Publisher publisher_cmd_vel;
bool TutorialCommandServiceCallback(mid_srvs::midsrv::Request &req,
                                    mid_srvs::midsrv::Response &res)
{
    geometry_msgs::Twist cmd_vel;
  if(req.command == "go right")
  {
      ROS_INFO("command : go right");
      res.message = "Receive success";
      res.result = "true";
      cmd_vel.linear.x = 1.0;
      cmd_vel.linear.y = 0.0;
      publisher_cmd_vel.publish(cmd_vel);
  }
  else if(req.command == "go left")
  {
      ROS_INFO("command : go left");
      res.message = "Receive success";
      res.result = "true";
      cmd_vel.linear.x = -1.0;
      cmd_vel.linear.y = 0.0;
      publisher_cmd_vel.publish(cmd_vel);
  }
  else if(req.command == "go up")
  {
      ROS_INFO("command : go up");
      res.message = "Receive success";
      res.result = "true";
      cmd_vel.linear.x = 0.0;
      cmd_vel.linear.y = 1.0;
      publisher_cmd_vel.publish(cmd_vel);
  }
  else if(req.command == "go down")
  {
      ROS_INFO("command : go down");
      res.message = "Receive success";
      res.result = "true";
      cmd_vel.linear.x = 0.0;
      cmd_vel.linear.y = -1.0;
      publisher_cmd_vel.publish(cmd_vel);
  }
  else
  {
    ROS_INFO("command : non");
    res.message = "Receive fail";
    res.result = "false";
  }

  return true;

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server_node");
  ros::NodeHandle n;

  ROS_INFO("service_server_node Open");

  ros::ServiceServer service_server;
  service_server = n.advertiseService("command", TutorialCommandServiceCallback);

  publisher_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
  ros::Rate loop_rate(60);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("service_server_node Close");

  return 0;

}