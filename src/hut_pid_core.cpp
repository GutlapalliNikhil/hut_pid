#include "hut_pid/hut_pid_core.h"

HutPID::HutPID()
{
}

HutPID::~HutPID()
{
}

void HutPID::publishMessage(ros::Publisher *pub_message)
{
  hut_msgs::PID msg;
  msg.p = p_;
  msg.d = d_;
  msg.i = i_;
  pub_message->publish(msg);
}

void HutPID::messageCallback(const hut_msgs::PID::ConstPtr &msg)
{
  p_ = msg->p;
  d_ = msg->d;
  i_ = msg->i;

  //echo P,I,D
  ROS_INFO("P: %f", p_);
  ROS_INFO("D: %f", d_);
  ROS_INFO("I: %f", i_);
}

void HutPID::configCallback(hut_pid::hutPIDConfig &config, double level)
{
  //for PID GUI
  p_ = config.p;
  d_ = config.d;
  i_ = config.i;

}
