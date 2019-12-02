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
 * @brief Navigation header file
 */
#ifndef INCLUDE_NAVIGATION_H_
#define INCLUDE_NAVIGATION_H_

#include <ros/ros.h>
#include<iostream>

class Navigation {
 private:
  /**
   * @brief Variable that notifies if there's an obstacle present
   */
  bool obstaclePresent;
 
 public:
  /**
   * @brief  Getter method for checking if destination is reached   
   * @param  current location and the destination of the robot      
   * @return boolean giving whether destination is reached          
   */                                                               
  bool isDestinationReached(double x_destination, double y_destination);  
   /**                                                               
   * @brief  Initializes handler for Navigation                
   * @param  none                                                   
   * @return none                                                   
   */                                                               
  void init(int argc, char** argv);                                                      
  /**                                                               
   * @brief  moves robot when no obstacle is present                
   * @param  none                                                   
   * @return none                                                   
   */                                                               
  void move();                                                      
  /**                                                               
   * @brief  gives a call back                                      
   * @param  none                                                   
   * @return none                                                   
   */                                                               
  void laserCallBack();                                             
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
  bool isObstaclePresent();
  /**
   * @brief  gives the path planning algorithm
   * @param  current location and the destination of the robot
   * @return none
   */
  void getOptimalPath(int currentLocation, int destination);
  /**
   * @brief  Turns the robot when obstacle is present
   * @param  none
   * @return none
   */
  void changeDirection();
};
#endif
