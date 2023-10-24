#include <ros/ros.h>
#include "mid_srvs/midsrv.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client_node");
  ros::NodeHandle n;

  ROS_INFO("service_server_node Open");

  ros::ServiceClient service_client_command;
  service_client_command = n.serviceClient<mid_srvs::midsrv>("command");
  mid_srvs::midsrv command;

  command.request.command = "go up";
  service_client_command.call(command);

  return 0;

}