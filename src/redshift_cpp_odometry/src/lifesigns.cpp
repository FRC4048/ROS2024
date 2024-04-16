#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int32.hpp"
//#include <ntcore/networktables/NetworkTableInstance.h>

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class RedshiftLifesigns : public rclcpp::Node
{
  public:
    RedshiftLifesigns(): Node("lifesigns"), lifesigns_counter(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::UInt32>("/redshift/lifesigns", 10);
      timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&RedshiftLifesigns::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::UInt32();
      message.data = lifesigns_counter++;
      //RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
    
  //private:
  //  void wait_for_network() 
  //  {
  //    RCLCPP_INFO(this->get_logger(), "Publishing to Network Table");
  //    instance = nt::NetworkTableInstance::GetDefault();
  //    instance.StartClient4("ROS Client");
      //instance.SetServerTeam(4048);
  //    instance.SetServer("192.168.1.198")
  //    while (!instance.isConnected());
  //    RCLCPP_INFO(this->get_logger(), "Connected....");
  //    auto table = instance.GetTable("ROS");
  //    entry = table->getDoubleTopic("lifesigns").Publish({});     
  //  }
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::UInt32>::SharedPtr publisher_;
    size_t lifesigns_counter;
};



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RedshiftLifesigns>());
  rclcpp::shutdown();
  return 0;
}
