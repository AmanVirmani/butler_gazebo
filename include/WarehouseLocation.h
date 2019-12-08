/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * @file WarehouseLocation.h
 * @driver         Aman Virmani
 * @navigator      Sandra Tinta 
 * @design keeper  Mushty Sri Sai Kaushik
 * @brief WarehouseLocatio header file
 */
#ifndef INCLUDE_WAREHOUSELOCATION_H_
#define INCLUDE_WAREHOUSELOCATION_H_

#include <iostream>

class WarehouseLocation {
 private:
   /**
   * @brief Variable that defines the x coordinate of a warehouse locaiton.
   */
  double x;
  /**
   * @brief Variable that defines the y coordinate of a warehouse locaiton.
   */
  double y;
 public:
 /**
   * @brief Getter method for checking obstacle presence
   * @param  double x an x coordinate
   * @param  double y an y coordinate
   * @return boolean giving obstacles presence
   */
  
 WarehouseLocation(double x, double y);
  /**
   * @brief Getter method for the x coordinate
   * @param  none
   * @return double
   */
  double getX();
  /**
   * @brief Getter method for y coordinate
   * @param  note
   * @return double
   */
  double getY();
};
#endif
