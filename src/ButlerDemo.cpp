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
 *      for navigatoin and for the orderd 
 *    
 */
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "Navigation.h"
#include "WarehouseLocation.h"
#include "LocalMap.h"
#include "ButlerOrder.h"

/** function declarations **/
char choose();
bool goalReached = false;

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
  // setting initial locaiton to the homeStation
  goalReached = butler_nav.isDestinationReached(homeLoc.getX(), homeLoc.getY());
  char choice = 'q';

  do {
     choice = choose();
     if (choice == 'o') {
       // prints menu for user to entry from and to station
       auto s = myorder.getOrder(wmap);
       // retrieving coordintes
       auto from = s.first;
       auto to = s.second;
       // navigation to from location
       goalReached = butler_nav.isDestinationReached(from.getX(), from.getY());
       ros::spinOnce();
       // navigaring to to locatopm
       goalReached = butler_nav.isDestinationReached(to.getX(), to.getY());
       ros::spinOnce();
       // navigating to home location
       goalReached = butler_nav.isDestinationReached(
                           homeLoc.getX(), homeLoc.getY());
       ros::spinOnce();

       if (choice !='q') {
         if (goalReached) {
            ROS_INFO("Congratulations!");
            ros::spinOnce();

         } else {
            ROS_INFO("Hard Luck!");
         }
      }
     }   }while(choice !='q');
  return 0;
}

char choose() {
  char choice = 'q';
  std::cout << "|'o': Enter Order " << std::endl;
  std::cout << "|'q': Quit "<< std::endl;
  std::cout << "|-------------------------------|" << std::endl;
  std::cout << "|WHAT TO DO?";
  std::cin >> choice;
  return choice;
}
