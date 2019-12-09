# Butler Robot Gazebo  Simulation  

[![Build Status](https://travis-ci.org/stinta/butler_gazebo.svg?branch=master)](https://travis-ci.org/stinta/butler_gazebo)
[![Coverage Status](https://coveralls.io/repos/github/stinta/butler_gazebo/badge.svg?branch=master)](https://coveralls.io/github/stinta/butler_gazebo?branch=master)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)


# Overview
This project implements a material handling robot simulation inspired by an autonomous robot called “Butler” originally developed by GreyOrange which optimizes goods-to-Person transport.  
Our approach is to develop a Butler robot simulation in which the robot picks-up and delivers objects from and to known stations upon an unknown user or system generated order being issued.  Assuming a environment map known at priori, our Butler robot uses the TurtleBot robot as its base platform and uses its distance measurement sensor to dynamically avoid obstacles as it follows its trajectory for delivering object from the collection station to a destination station.  The robot starts and ends its delivery cycle at a home or charging station location.  
The robotic system pre-plans a potential optimal trajectory for navigation. To show the successful pick-up and delivery of the objects by the robot, at the pickup location the Butler will publish a message indicating the pickup action and the object will disappear from the collection station; similarly, at the destination location the Butler will publish a message indicating the delivery action and the object will appear at the destination location.  

The presentation for this project can be found [here](.).

# Team
- **Aman Virmani** 
- **Mushty Sri Sai Kaushik** 
- **Sandra Tinta**

# Project Presentation Demo
Presentation of the project can be found [here](https://docs.google.com/presentation/d/1mTpTO3ToKmhLyNpknvycvceg3DJquGKYsKFBesBz2Ys/edit?usp=sharing)
Video Demo of the project [link](https://drive.google.com/file/d/14qTYDipqx67uZgGsAohmteuUzysgYbOv/view?usp=sharing)

# Project Design

The team followed the AIP process and pair programming.  The AIP iteration actions are documented [here](https://docs.google.com/spreadsheets/d/1O8GisJ7VpNulYqH-gaPCvG_NAVHMwOyPO4F18fhpBL4/edit?ts=5ddb0c09#gid=0).  
The overall project design followed Object-Oriented programming paradigm.  The design is documented in the following [Activity](https://github.com/stinta/butler_gazebo/blob/master/UML/revised/ActivityDiagram.pdf) and [Class Hierarchy](https://github.com/stinta/butler_gazebo/blob/master/UML/revised/ClassDiagram_v2.pdf) UML Diagrams.  
Planning and review notes during each development iteration can be found [here](https://docs.google.com/document/u/0/d/1aiRbswW5R_R5Iiowr5hDhnN0nU_4OwQu9OM1Oh6o9Pk/mobilebasic)


# Dependencies
- ROS Kinetic 
To install follow this [link](http://wiki.ros.org/kinetic/Installation)
- Ubuntu 16.04
- Turtlebot packages 
To install turtlebot, type the following:
```
sudo apt-get install ros-kinetic-turtlebot-gazebo 
ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-rviz-launchers
```

# Standard Install
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone https://github.com/AmanVirmani/WalkerBot
cd ..
catkin_make
```

# Running the Simulation Demo
Type each of the given commands in a new terminal 
```
roslaunch butler_gazebo butler_world.launch 
roslaunch butler_gazebo amcl_demo.launch
roslaunch butler_gazebo view_navigation.launch

./devel/lib/butler_gazebo/butler_gazebo
```

#  Test Suite
The instruction on how to build and run the test suite are as follows :

## Building Test suite
  ```
  cd ~/catkin_ws/
  source ./devel/setup.bash
  catkin_make test
  ```
## Running Test suite
  ```
  catkin_make run_tests
  ```


## Documentation Generation
To install doxygen run the following command:
```
sudo apt-get install doxygen
```
Now from the cloned directory run:
```
doxygen doxygen
```
Generated doxygen files are in html format and you can find them in ./docs folder. With the following command
```
firefox docs/html/index.html
```

# Known Issues/Limitations
The turtlebot is used here to focus on the implementation, but for actual operation we need to model a robot that has the capability to actually pickup objects.

# Code Checks
cppcheck
```
cppcheck --std=c++11 $(find . -name \*.cpp -or -name \*.srv -or -name \*.h  | grep -vE -e "^./build/" -e "^./results/")
```
cpplint
```
cpplint $(find . -name \*.cpp -or -name \*.h | grep -vE -e "^./build/" -e "^./results")
```
# License
[BSD-3](https://opensource.org/licenses/BSD-3-Clause)

