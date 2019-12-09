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

#include <ros/ros.h>
#include <iostream>
#include "ButlerOrder.h"
  /**
   * @brief Constructor for the order; default location is set to zero.
   */
  ButlerOrder::ButlerOrder() {
    WarehouseLocation toLoc(0, 0);
    WarehouseLocation fromLoc(0, 0);
  }
  /**
   * @brief Getter method for order
   * @param  LocalMap which carries all known bin values; used to retrieve 
   *         requests based on tags
   * @return std::make_pair
   */
  std::pair<WarehouseLocation, WarehouseLocation>
                ButlerOrder::getOrder(LocalMap mymap) {
    char from;
    char to;
    std::cout << "|-------------------------------|" << std::endl;
    std::cout <<
         "|ENTER FROM and TO locations from following options:"
         << std::endl;
    mymap.printLocTags();
    std::cout << "|FROM: ";
    std::cin >> from;
    auto f = mymap.getLoc(from);
    std::cout << f.getX() << " " << f.getY() << std::endl;
    std::cout << "|TO: ";
    std::cin >> to;
    auto t = mymap.getLoc(to);
    std::cout << t.getX() << " " << t.getY() << std::endl;
    std::cout << std::endl;
    return std::make_pair(f, t);
  }
