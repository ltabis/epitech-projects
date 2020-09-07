/**
 *  @file     src/Color.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

namespace zia {

	#ifdef _WINDOWS
		auto constexpr const GREEN = "";
		auto constexpr const RED = "";
		auto constexpr const MAGENTA = "";
		auto constexpr const CYAN = "";
		auto constexpr const BLUE = "";
		auto constexpr const YELLOW = "";
		auto constexpr const RESET = "";
	#else
		auto constexpr const GREEN = "\033[1;32m";
		auto constexpr const RED = "\033[1;31m";
		auto constexpr const MAGENTA = "\033[1;35m";
		auto constexpr const CYAN = "\033[1;36m";
		auto constexpr const BLUE = "\033[1;34m";
		auto constexpr const YELLOW = "\033[1;33m";
		auto constexpr const RESET = "\033[0m";
	#endif

}