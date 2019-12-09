/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * @file ButlerOrder.hpp
 * @driver         Aman Virmani
 * @navigator      Sandra Tinta 
 * @design keeper  Mushty Sri Sai Kaushik
 * Created on 24 November 2019
 * @brief Order header file
 */
#ifndef INCLUDE_BUTLERORDER_H_
#define INCLUDE_BUTLERORDER_H_

#include <ros/ros.h>
#include <iostream>
#include <utility>
#include "WarehouseLocation/WarehouseLocation.h"
#include "LocalMap/LocalMap.h"
//#include <fstream>

//using namespace std;
class ButlerOrder {
 public:
   /**
   * @brief Variable that defines the FROM  location of the order.
   */
  static WarehouseLocation fromLoc;
  
  /**
   * @brief Variable that defines the TO location of the order.
   */
  static WarehouseLocation toLoc;
  
  /**
   *@brief Constructor for the order; default location is set to zero.
   */
  ButlerOrder();
  
  /**
   * @brief Getter method for order
   * @param  LocalMap which carries all known bin values; used to retrieve 
   *         requests based on tags
   * @param  string which represents the path of the order file to input orders from
   * @return std::vector<std::make_pair<Warehouse,Warehouse>>
   */
  std::vector<std::pair<WarehouseLocation, WarehouseLocation>> getOrderFromFile(LocalMap mymap, std::string inputFile);
};
#endif  // INCLUDE_BUTLERORDER_H_
