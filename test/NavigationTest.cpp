/*
 The BSD-3-Clause License
 Copyright 2019 Aman Virmani, Sri Sai Kaushik, Sandra Tinta
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * @file NavigationTest.cpp
 * @driver         Mushty Sri Sai Kaushik
 * @navigator      Aman Virmani 
 * @design keeper  Sandra Tinta
 * Created on 8 December 2019
 * @brief 	   Test cases for Navigation class
 *        
 */


#include <gtest/gtest.h>
#include <ros/ros.h>
#include <ros/service_client.h>
#include <Navigation.h>



TEST(butlerDemo, checkIsDestinationReachedType) {
	Navigation t;
	x = 0.0;
	y = 0.0;
	int val = t.isDestinationReached(x, y);
	EXPECT_TRUE(typeid(val), typeid(bool));
       }



