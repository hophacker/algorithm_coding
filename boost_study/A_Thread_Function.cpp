/*
 * =====================================================================================
 *
 *       Filename:  A_Thread_Function.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/06/2014 04:47:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jiefeng.hopkins@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */



#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>

void workerFunc(){
    boost::posix_time::seconds workTime(3);
    std::cout << "Worker: running" << std::endl;
}
