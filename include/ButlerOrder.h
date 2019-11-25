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

#include<iostream>
#include <ros/ros.h>

class Order {
 public:
  /**
   * @brief Variable that defines the current location of the bot.
   */
  int currentOrder:butlerOrderMsg;
  /**
   * @brief Variables that defines the next destination.
   */
  bool orderFlag;
  /**
   * @brief Getter method for checking obstacle presence
   * @param  none
   * @return boolean giving obstacles presence
   */
  bool getOrderFlag();
  /**
   * @brief Getter method for checking obstacle presence
   * @param  none
   * @return boolean giving obstacles presence
   */
  void processOrder(butlerOrderMsg);
  /**
   * @brief Getter method for order
   * @param  Order message from butler
   * @return void
   */
  void getOrder(butlerOrderMsg);
};
