#include<ros/ros.h>
#include<mid_msgs/mid_msg.h>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publish_msg_node");
    ros::NodeHandle n;
    mid_msgs::mid_msg mid_msg;
    ros::Publisher publisher_msg = n.advertise<mid_msgs::mid_msg>("mid_msg",1000);
    ros::Rate loop_rate(60);

    while(ros::ok()){
        string str;
        cout << "send message : ";
        cin >> str;
        mid_msg.String = str;
        publisher_msg.publish(mid_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}