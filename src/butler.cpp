/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * @file butlercpp.h
 * @driver         Aman Virmani
 * @navigator      Sandra Tinta 
 * @design keeper  Mushty Sri Sai Kaushik
 * Created on 29 November 2019
 * @brief This class implements the main functions of the robot to complete the orders and return back to home location
 */
#include <string.h>
#include "Butler.h"

void Butler::Butler() {
        /* can make a ros msg for location data */ 
      memset(homeLocation, 0, sizeof(homeLocation);
      memset(homeLocation, 0, sizeof(currentLocation);
      memset(homeLocation, 0, sizeof(pickUpLocation);
      memset(homeLocation, 0, sizeof(dropOffLocation);

  /* proximity Threshold before bot starts turning */
  proximityThresh = 0.8;

  /* obstacle present is false by default */
  obstaclePresent = false;

  /* Publish the velocity*/
  publishVelocity = nh.advertise <geometry_msgs::Twist>
  ("/mobile_base/commands/velocity", 1000);
  /* subscribeLaser to subscribe to laser scan data */
  subscribeLaser = nh.subscribe<sensor_msgs::LaserScan> ("/scan", 1000,
      &Butler::laserCallback, this);
  /* inititializing with zero velocity */
  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
  /* publisher the initial velocity data */
  publishVelocity.publish(msg);

  /* Current Order Info */
  ButlerOrderMsg currentOrder;        
}

ButlerOrderMsg Butler::getOrder {
        /* load order from order file : Call the get order function from order class */
        Order newOrder;
        currentOrder = newOrder.getOrder();
        return currentOrder;
}

int* getCurrentLocation() {
        /* Use tf to get current Location */
        int* currentLocation = new int[3]();
        return currentLocation;
}

int* getCurrentVelocity() {
        /* subscribe to "/mobile_base/commands/velocity" */ 
        int* currentVelocity = new int[3]();
        return currentVelocity;
}

bool hasReachedDst() {
        currentLocation = this->getCurrentLocation();
        for (int i = 0; i < 3; ++i) {
                if (currentLocation[i] != dropOffLocation[i] ) 
                        return false;
        }                
        return true;
}
void Butler::run {
  /* Update as per activity diagram once other classes are done */
  ros::Rate loop_rate(10);

  /* tf transform broadcaster object */
  static tf::TransformBroadcaster br;
  tf::Transform transform;

  while(ros::ok) {
    /* broadcast the transform */
    br.sendTransform(
    tf::StampedTransform(transform, ros::Time::now(), "world", "world"));

    ros::spinOnce()
    loop_rate.sleep();
  }

} 
