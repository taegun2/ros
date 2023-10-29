#include <ros/ros.h>
#include <vending_msgs/vending_msg.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "vending_publish_node");
  ros::NodeHandle n;
  vending_msgs::vending_msg vending_msg;
  ros::Publisher publisher_msg = n.advertise<vending_msgs::vending_msg>("vending_msg",1000);
  ros::Rate loop_rate(60);
  
  while(ros::ok()){
    string str;
    string drink;
    int money = 0;
    int change = 0;

    cout << "what's your choice? : ";
    cin >> drink;
    cout << "input money : " ;
    cin >> money;

    if(drink == "1"){
        if(money <1000){
            str = "not enough";
            change = money;
        }
        else{
            str = "coffee";
            change = money - 1000;
        }
    }
    else if(drink == "2"){
        if(money <500){
            str = "not enough";
            change = money;
        }
        else{
            str = "water";
            change = money - 500;
        }
    }
    else if(drink == "3"){
        if(money <1800){
            str = "not enough";
            change = money;
        }
        else{
            str = "Lemonade";
            change = money - 1800;
        }
    }
    else{
        str = "error";
        change = 0;

    }
    vending_msg.String = str;
    vending_msg.Int16 = change;
    publisher_msg.publish(vending_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}


