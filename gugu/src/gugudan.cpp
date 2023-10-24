#include <ros/ros.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "gugudan");
    ros::NodeHandle nh;

    for(int i =2; i<10;i++){
        for(int j=1; j<10; j++){
            ROS_INFO("%d * %d = %d", i,j,i*j);
        }
        ROS_INFO("\n");
    }
}

