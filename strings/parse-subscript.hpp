/* Parsing of strings like "parameter[index]"
   parameter is a string, index is a number
*/

#include <string>
#include <utility>
#include <regex>

// much faster than the regex version
// returns the pair [parameter, index]
std::pair<std::string, int> parse_subscript_clike(const string& param)
{
   const char* begSb = strchr(param.c_str(), '[');
   const char* endSb = strchr(param.c_str(), ']');
   if (begSb && endSb && begSb < endSb)
   {
      return{ param.substr(0, std::distance(param.c_str(), begSb)), stoi(string(begSb + 1, endSb)) };
   }
   return {};
}

// returns the pair [parameter, index]
std::pair<std::string, int> parse_subscript_regex(const string& param)
{
   static const std::regex subscriptRegex(R"(([^\[]+)\[(\d+)\])");
   std::smatch match;
   if (std::regex_search(param, match, subscriptRegex))
   {
      return{ match[1], stoi(match[2]) };
   }
   return {};
}
