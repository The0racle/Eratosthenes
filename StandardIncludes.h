/*
 * StandardIncludes.h
 *
 *  Created on: Jul 1, 2010
 *     
 */

#ifndef STANDARDINCLUDES_H_
#define STANDARDINCLUDES_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <boost/thread/thread.hpp>
#include <boost/timer.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/bind.hpp>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istringstream;
using std::ostringstream;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::iostream;
using std::map;
using std::set;
using boost::timer;
boost::condition condition;
using boost::thread_group;
using boost::mutex;
using boost::bind;

#endif /* STANDARDINCLUDES_H_ */
