/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * @file LocalMap.h
 * @driver         Aman Virmani
 * @navigator      Sandra Tinta 
 * @design keeper  Mushty Sri Sai Kaushik
 * Created on 24 November 2019
 * @brief LocalMap header file
 */
#ifndef INCLUDE_LOCALMAP_H_
#define INCLUDE_LOCALMAP_H_

#include <ros/ros.h>
#include <iostream>
#include <unordered_map>
#include "WarehouseLocation.h"

class LocalMap {
 public:
  /**
   * @brief Variable that contains the known rack locations of the warehouse
   */
  std::unordered_map<char, WarehouseLocation> warehouse_layout;
  /**
   * @brief  prints all known tags locations
   * @param  none
   * @return none
   */
  void printLocTags();

/**
   * @brief  prints all known warehouse locations with coordinates
   * @param  none
   * @return none
   */
  void printMapLayout();

  /**
   * @brief  initiaizes the local warehhouse map
   * @param  none
   * @return none
   */
  void initLocalMap();
 /**
   * @brief  Returns a Warehouse Location based on the tag
   * @param  char tad for the location station
   * @return WarehouseLocation if location not found return home location
   */

  WarehouseLocation getLoc(char);
};
#endif  //  INCLUDE_LOCALMAP_H_

