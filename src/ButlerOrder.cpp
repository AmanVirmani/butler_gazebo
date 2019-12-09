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
#include <fstream>
#include "ButlerOrder/ButlerOrder.h"

using namespace std;
ButlerOrder::ButlerOrder() {
        WarehouseLocation toLoc(0, 0);
        WarehouseLocation fromLoc(0, 0);
}

std::vector<std::pair<WarehouseLocation, WarehouseLocation>> ButlerOrder::getOrderFromFile(LocalMap mymap, std::string inputFile) {
        ifstream orderFile;
        orderFile.open(inputFile);
        string orderString;
        std::vector <pair <WarehouseLocation, WarehouseLocation>> orders;
        while (!orderFile.eof()) {
                getline(orderFile,orderString);
                char from = orderString[0];
                char to = orderString[1];
                auto f = mymap.getLoc(from);
                auto t = mymap.getLoc(to);
                orders.push_back(std::make_pair(f, t));
        }
        return orders;
}
