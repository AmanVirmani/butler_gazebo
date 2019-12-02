/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * @file ButlerDemo.hpp
 * @driver         Aman Virmani
 * @navigator      Sandra Tinta 
 * @design keeper  Mushty Sri Sai Kaushik
 * Created on 24 November 2019
 * @brief Butler header file
 */

#include<iostream>
#include <ros/ros.h>

class Butler {
  public:
    /**
   * @brief Variable that defines current location of the robot
   */
    int currentLocation[3];
    /**
     @brief Variable that defines current velocity of the robot
    */
    int currentVelocity[6];
    /**
     @brief Variable that defines pickup station location
    */
    int pickUpLocation[3];
    /**
     @brief Variable that defines dropoff station location
    */
    int dropOffLocation[3];
    /**
     @brief Variable that defines home location where rebot needs to return after order completion
    */
    int homeLocation[3];
    /**
     @brief Variable that defines which load object to transport
    */
    string loadObject;
    /**
     * @brief runs the butler agent
     * @param  none
     * @return none
     */
    void run();
    /**
     * @brief starts the buter demo
     * @param  none
     * @return current order for the robot to complete
     */
    int* getOrder();
    /**
     * @brief starts the buter demo
     * @param  none
     * @return current location of the robot
     */
    int* getCurrentLocation();
    /**
     * @brief starts the buter demo
     * @param  none
     * @return current velocity of the robot
     */
    int* getCurrentVelocity();
};
