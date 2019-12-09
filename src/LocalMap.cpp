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

#include "LocalMap/LocalMap.h"

std::unordered_map<char, WarehouseLocation> warehouse_layout;
   
void LocalMap::initLocalMap() {
  warehouse_layout.insert(std::make_pair('a', WarehouseLocation(-9.1, -4.1)));
  warehouse_layout.insert(std::make_pair('b', WarehouseLocation(-5.39, -4.89)));
  warehouse_layout.insert(std::make_pair('c', WarehouseLocation(-1.55, -5.55)));
  warehouse_layout.insert(std::make_pair('d', WarehouseLocation(2.55, -5.55)));
  warehouse_layout.insert(std::make_pair('e', WarehouseLocation(6.56, -5.86)));
  warehouse_layout.insert(std::make_pair('f', WarehouseLocation(-7.7, -0.5)));
  warehouse_layout.insert(std::make_pair('g', WarehouseLocation(-4.18, -1.26)));
  warehouse_layout.insert(std::make_pair('h', WarehouseLocation(-0.46, -1.28)));
  warehouse_layout.insert(std::make_pair('i', WarehouseLocation(3.52, -1.5)));
  warehouse_layout.insert(std::make_pair('j', WarehouseLocation(7.0, -1.9)));
  warehouse_layout.insert(std::make_pair('o', WarehouseLocation(0.78, 0.15)));
}
   
void LocalMap::printMapLayout() {
  std::unordered_map<char, WarehouseLocation>::iterator itr;
  for (itr = warehouse_layout.begin(); itr != warehouse_layout.end(); itr++) {
    std::cout << itr->first <<
         " " << (itr->second).getX() <<
         " " << (itr->second).getY() << std::endl;
    }
}
   
void LocalMap::printLocTags() {
  std::vector<char> ktag;
  ktag.reserve(warehouse_layout.size());
  for (auto& it : warehouse_layout) {
    ktag.push_back(it.first);
  }
  std::sort(ktag.begin(), ktag.end());
  for (auto& k : ktag) {
    std::cout << k << " ";
  }
  std::cout << std::endl;
}

WarehouseLocation LocalMap::getLoc(char tag) {
  auto search = warehouse_layout.find(tag);
  if ( search != warehouse_layout.end())
    return search->second;
  return WarehouseLocation(0.78, 0.15);
}
