/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * @file Navigation.h
 * @driver         Aman Virmani
 * @navigator      Sandra Tinta 
 * @design keeper  Mushty Sri Sai Kaushik
 * Created on 24 November 2019
 * @brief This Class implements the main Navigation Functions to 
 *        supports both localization and  mobility of the butler robot
 */

#include <ros/ros.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "Navigation.h" 

  /**
   * @brief Variable that notifies if there's an obstacle present
   */
  bool obstaclePresent;
 
   /**                                                               
   * @brief  moves robot when no obstacle is present                
   * @param  none                                                   
   * @return none                                                   
   */
  void Navigation::init(int argc, char** argv){
    ros::init(argc, argv, "butler_navigation_node");
    auto n = ros::NodeHandle();
    ros::spinOnce();
  }
                                                               
  /**
   * @brief  Getter method for checking if destination is reached   
   * @param  current location and the destination of the robot      
   * @return boolean giving whether destination is reached          
   */                                                               
  bool Navigation::isDestinationReached(double x_destination,  double y_destination){
   //define a client for to send goal requests to the move_base server through a SimpleActionClient
   actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

   //wait for the action server to come up
   while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
   }

   move_base_msgs::MoveBaseGoal goal;

   //set up the frame parameters
   goal.target_pose.header.frame_id = "map";
   goal.target_pose.header.stamp = ros::Time::now();

   /* moving towards the goal*/

   goal.target_pose.pose.position.x =  x_destination;
   goal.target_pose.pose.position.y =  y_destination;
   goal.target_pose.pose.position.z =  0.0;
   goal.target_pose.pose.orientation.x = 0.0;
   goal.target_pose.pose.orientation.y = 0.0;
   goal.target_pose.pose.orientation.z = 0.0;
   goal.target_pose.pose.orientation.w = 1.0;

   ROS_INFO("Sending goal location ...");
   ac.sendGoal(goal);

   ac.waitForResult();

   if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
      ROS_INFO("You have reached the destination");
      return true;
   }
   else{
      ROS_INFO("The robot failed to reach the destination");
      return false;
   }


  }  
  /**                                                               
   * @brief  moves robot when no obstacle is present                
   * @param  none                                                   
   * @return none                                                   
   */                                                               
  void move(){};                                                      
  /**                                                               
   * @brief  gives a call back                                      
   * @param  none                                                   
   * @return none                                                   
   */                                                               
  void laserCallBack(){};                                             
  /**
   * @brief Variable that defines the current location of the bot.
   */
  int currentLocation;
  /**
   * @brief Variables that defines the next destination.
   */
  int destination;
  /**
   * @brief Getter method for checking obstacle presence
   * @param  none
   * @return boolean giving obstacles presence
   */
  bool isObstaclePresent(){};
  /**
   * @brief  gives the path planning algorithm
   * @param  current location and the destination of the robot
   * @return none
   */
  void getOptimalPath(int currentLocation, int destination){};
  /**
   * @brief  Turns the robot when obstacle is present
   * @param  none
   * @return none
   */
  void changeDirection(){};
