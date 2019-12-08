#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "Navigation.h"
#include "WarehouseLocation.h"
#include "LocalMap.h"
#include "ButlerOrder.h"

/** function declarations **/
//bool moveToGoal(double xGoal, double yGoal);
char choose();

bool goalReached = false;

/* TODO THIS IS ONLY A TEMPORARY HELPER MAIN BASED ON TUTORIALS*/
int main(int argc, char** argv){
   auto butler_nav = Navigation();
   butler_nav.init(argc,argv);

//----- TEST-
  auto wmap = LocalMap();
  wmap.initLocalMap();
  auto myorder = ButlerOrder();
  auto homeLoc = wmap.getLoc('o');
//-----
 
 goalReached = butler_nav.isDestinationReached(homeLoc.getX(), homeLoc.getY());
  char choice = 'q';

do{   


     choice =choose();
     if (choice == 'o') {


     auto s= myorder.getOrder(wmap);
     auto from = s.first;
     auto to = s.second;

      goalReached = butler_nav.isDestinationReached(from.getX(), from.getY());
      ros::spinOnce();
      goalReached = butler_nav.isDestinationReached(to.getX(), to.getY());
      ros::spinOnce();
      goalReached = butler_nav.isDestinationReached(homeLoc.getX(), homeLoc.getY());
      ros::spinOnce();
      /*if (choice == '0'){
         goalReached = butler_nav.isDestinationReached(xCafe, yCafe);
      }else if (choice == '1'){
         goalReached = butler_nav.isDestinationReached(xOffice1, yOffice1);
      }else if (choice == '2'){
         goalReached = butler_nav.isDestinationReached(xOffice2, yOffice2);
      }else if (choice == '3'){
         goalReached = butler_nav.isDestinationReached(xOffice3, yOffice3);
      }*/
      if (choice !='q'){
         if (goalReached){
            ROS_INFO("Congratulations!");
            ros::spinOnce();

         }else{
            ROS_INFO("Hard Luck!");
         }
      }
}   }while(choice !='q');
   return 0;
}

char choose(){
	char choice='q';
	std::cout<<"|'o': Enter Order "<<std::endl;
	std::cout<<"|'q': Quit "<<std::endl;
	std::cout<<"|-------------------------------|"<<std::endl;
	std::cout<<"|WHAT TO DO?";
	std::cin>>choice;

	return choice;


}
