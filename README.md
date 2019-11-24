# Butler Robot Gazebo  Simulation  

[![Build Status](https://travis-ci.org/stinta/butler_gazebo.svg?branch=master)](https://travis-ci.org/stinta/butler_gazebo)
[![Coverage Status](https://coveralls.io/repos/github/stinta/butler_gazebo/badge.svg?branch=master)](https://coveralls.io/github/stinta/butler_gazebo?branch=master)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)


## Overview
This project implements a material handling robot simulation inspired by an autonomous robot called “Butler” originally developed by GreyOrange which optimizes goods-to-Person transport.  
Our approach is to develop a Butler robot simulation in which the robot picks-up and delivers objects from and to known stations upon an unknown user or system generated order being issued.  Assuming a environment map known at priori, our Butler robot uses the TurtleBot robot as its base platform and uses its distance measurement sensor to dynamically avoid obstacles as it follows its trajectory for delivering object from the collection station to a destination station.  The robot starts and ends its delivery cycle at a home or charging station location.  
The robotic system pre-plans a potential optimal trajectory for navigation. To show the successful pick-up and delivery of the objects by the robot, at the pickup location the Butler will publish a message indicating the pickup action and the object will disappear from the collection station; similarly, at the destination location the Butler will publish a message indicating the delivery action and the object will appear at the destination location.  

The presentation for this project can be found [here](./add/link.here).

## Team
- **Aman Virmani**:
- **Mushty Sri Sai Kaushik** :
- **Sandra Tinta** :

## Project Design

The team followed the AIP process and pair programming.  The AIP iteration actions are documented [here](https:://addlink.here).  
The overall project design followed Object-Oriented programming paradigm.  The design is documented in the following [Activity](http:??) and [Class Hierarchy](http://xxx.yyy) UML Diagrams.  
Planning and review notes during each development iteration can be found [here](./link/here)


## Dependencies


## Standard Install


## Running the Simulation Demo

## Running the Simulation Demo with Rosbag enabled

## Running the Test Suite

## Documentation Generation

## Known Issues/Limitations

## Code Checks
cppcheck
```
cppcheck --std=c++11 $(find . -name \*.cpp -or -name \*.srv | grep -vE -e "^./
build/" -e "^./results/")
```
cpplint
```
 cpplint $(find . -name \*.cpp | grep -vE -e "^./build/" -e "^./results")
```
## License
[BSD-3](https://opensource.org/licenses/BSD-3-Clause)

