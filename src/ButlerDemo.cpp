#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "Navigation.h"


/** function declarations **/
//bool moveToGoal(double xGoal, double yGoal);
char choose();

/** declare the coordinates of interest **/
double xCafe = -0.16;
double yCafe = -1.52;
double xOffice1 = -1.1 ;
double yOffice1 = 2.0;
double xOffice2 = 0.1 ;
double yOffice2 = 0;
double xOffice3 = 3.0 ;
double yOffice3 = 0;

bool goalReached = false;

/* TODO THIS IS ONLY A TEMPORARY HELPER MAIN BASED ON TUTORIALS*/
int main(int argc, char** argv){
   auto butler_nav = Navigation();
   butler_nav.init(argc,argv);

   char choice = 'q';
   do{
      choice =choose();
      if (choice == '0'){
         goalReached = butler_nav.isDestinationReached(xCafe, yCafe);
      }else if (choice == '1'){
         goalReached = butler_nav.isDestinationReached(xOffice1, yOffice1);
      }else if (choice == '2'){
         goalReached = butler_nav.isDestinationReached(xOffice2, yOffice2);
      }else if (choice == '3'){
         goalReached = butler_nav.isDestinationReached(xOffice3, yOffice3);
      }
      if (choice!='q'){
         if (goalReached){
            ROS_INFO("Congratulations!");
            ros::spinOnce();

         }else{
            ROS_INFO("Hard Luck!");
         }
      }
   }while(choice !='q');
   return 0;
}

char choose(){
	char choice='q';
	std::cout<<"|-------------------------------|"<<std::endl;
	std::cout<<"|PRESSE A KEY:"<<std::endl;
	std::cout<<"|'0': Cafe "<<std::endl;
	std::cout<<"|'1': Office 1 "<<std::endl;
	std::cout<<"|'2': Office 2 "<<std::endl;
	std::cout<<"|'3': Office 3 "<<std::endl;
	std::cout<<"|'q': Quit "<<std::endl;
	std::cout<<"|-------------------------------|"<<std::endl;
	std::cout<<"|WHERE TO GO?";
	std::cin>>choice;

	return choice;


}
