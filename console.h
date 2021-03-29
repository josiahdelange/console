/***
MIT License

Copyright (c) 2021 Josiah DeLange

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
***/


#ifndef console

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

static std::vector<std::string> ssplit(const std::string &s, char delim)
{
	std::string item;
	std::stringstream ss(s);
	std::vector<std::string> tokens;
	while(getline(ss, item, delim))
	{
		tokens.push_back(item);
	}
	return tokens;
}

static void console(std::string fcnCaller, std::string componentName, std::string strBuff)
{
#if defined(TIMESTAMP_DATE)
	char timeStamp[20];
	std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::strftime(timeStamp, sizeof(timeStamp), "%F %T", std::localtime(&t));
#elif defined(TIMESTAMP_EPOCH)
	auto t = std::chrono::system_clock::now();
	auto duration = t.time_since_epoch();
	auto timeStamp = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
#else
#error "Must define TIMESTAMP_DATE or TIME_STAMP_EPOCH."
#endif
	std::cout << "[" << timeStamp << "] ";
	std::vector<std::string> fcnCaller_ = ssplit(fcnCaller, '(');
	std::vector<std::string> fcnCaller__ = ssplit(fcnCaller_[0], ' ');
	std::cout << componentName << "[" << fcnCaller__.back() << "] ";
	std::cout << strBuff << std::endl;
}

static void _console(std::string fcnCaller, std::string componentName, std::string strBuff)
{
	console(fcnCaller, componentName, strBuff);
}

#define console(componentName, strBuff) _console(__PRETTY_FUNCTION__ , componentName, strBuff)

#endif
