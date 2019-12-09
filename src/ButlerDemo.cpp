/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * @file ButlerDemo.cpp
 * @driver         Aman Virmani
 * @navigator      Sandra Tinta 
 * @design keeper  Mushty Sri Sai Kaushik
 * Created on 24 November 2019
 * @brief This Class is the demoDriver it instatiates all object location for map
 *  for navigation and order completion 
 *    
 */
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "Navigation/Navigation.h"
#include "WarehouseLocation/WarehouseLocation.h"
#include "LocalMap/LocalMap.h"
#include "ButlerOrder/ButlerOrder.h"


/**
   * @brief  main method to run demo for the project
   * @param  int argc
   * @param  char** argc
   * @return int
   */

int main(int argc, char** argv) {
  // Initilizing Navigation Object
  auto butler_nav = Navigation();
  butler_nav.init(argc , argv);

  // initializing LocalMap which holds stattions locations
  auto wmap = LocalMap();
  wmap.initLocalMap();
  // Order object which returs a pair of locatoins
  auto myorder = ButlerOrder();
  // setting and retrieving home loaction
  auto homeLoc = wmap.getLoc('o');
  // setting initial locaiton to the homeStationi
  bool goalReached = butler_nav.isDestinationReached(homeLoc.getX(), homeLoc.getY());
  std::string inputFile = "/work/class/808x/projects/final_project/iteration03/src/butler_gazebo/data/orders.txt";
  
  auto s = myorder.getOrderFromFile(wmap,inputFile);
  // retrieving coordinates
  for (auto i = s.begin(); i< s.end(); ++i) {
  auto from = (*i).first; 
  auto to = (*i).second;
  goalReached = butler_nav.isDestinationReached(from.getX(), from.getY());
  if (goalReached) {
          ROS_INFO_STREAM("Picked up the package");
  }
  ros::spinOnce();
  // navigaring to to locatopm
  goalReached = butler_nav.isDestinationReached(to.getX(), to.getY());
  if (goalReached) {
          ROS_INFO_STREAM("Dropped off the package; Heading home now.");
  }
  ros::spinOnce();
  // navigating to home location
  goalReached = butler_nav.isDestinationReached(
                  homeLoc.getX(), homeLoc.getY());
  ros::spinOnce();
  }

  return 0;
}
