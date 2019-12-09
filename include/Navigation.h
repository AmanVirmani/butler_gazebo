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
 public:
  /**
   * @brief Method for checking if destination is reached   
   * @param  destination x and y coordinate      
   * @return boolean giving whether destination is reached          
   */                                                               
  bool isDestinationReached(double x_destination, double y_destination);
   /**                                                               
   * @brief  Initializes handler for Navigation                
   * @param  none                                                   
   * @return none                                                   
   */                                                               
  void init(int argc, char** argv);
};
#endif  // INCLUDE_NAVIGATION_H_
