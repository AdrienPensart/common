#pragma once

#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include <sstream>

// hack to quote string at compile time
#define Q(x) #x
#define QUOTE(x) Q(x)
/*
// hack to comment log lines when in release mode
#define COMMENT SLASH(/)
#define SLASH(s) /##s
*/

namespace Common {
	template<typename T>
	std::string toString( const T & Value ) {
		std::ostringstream oss;
		oss << Value;
		return oss.str();
	}

	inline std::string toString( const std::wstring & Value ) {
		return std::string( Value.begin(), Value.end() );
	}

	template<typename T>
	bool fromString( const std::string & Str, T & Dest ) {
		std::istringstream iss( Str );
		return iss >> Dest != 0;
	}

	inline std::string currentTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d %H-%M-%S", &tstruct);
		return buf;
	}

	inline std::string currentDate() {
		time_t now;
		time(&now);
		std::string mytime = ctime(&now);
		mytime.erase(std::remove(mytime.begin(), mytime.end(), '\n'), mytime.end());
		return mytime;
	}

	inline void split(const std::string& input, const std::string& delimiter, std::vector<std::string>& output) {
		size_t start = 0;
		size_t end = 0;
		while (start != std::string::npos && end != std::string::npos) {
			start = input.find_first_not_of(delimiter, end);
			if (start != std::string::npos) {
				end = input.find_first_of(delimiter, start);
				if (end != std::string::npos)
					output.push_back(input.substr(start, end - start));
				else
					output.push_back(input.substr(start));
			}
		}
	}
} // Common
