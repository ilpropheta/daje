/*
  std::string algorithms and snippets.
*/

#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, const char* delims)
{
  vector<string> tokens;
  string::size_type start = 0;
  auto pos = str.find_first_of(delims, start);
  while(pos != string::npos) 
  {
    if(pos != start)
    { 
      tokens.emplace_back(str, start, pos - start);  
    }
    start = pos + 1;
    pos = str.find_first_of(delims, start);
  }
  if(start < str.length())
    tokens.emplace_back(str, start, str.length() - start);
  return tokens;
}

/* Q: Is it possible to limit the number of tokens by using the same algorithm as the one above?
   A: Yes, by applying kind of "template method pattern":
*/

template<typename Limiter>                                                    
std::vector<std::string> split_impl(const std::string& str, const char* delims, Limiter limiter)
{//                                                                             ^___ deals with stopping when enough token are read
  vector<string> tokens;
  string::size_type start = 0;
  auto pos = str.find_first_of(delims, start);
  while(pos != string::npos && limiter.on_loop()) 
  {
    if(pos != start)
    { 
      tokens.emplace_back(str, start, pos - start);
      limiter.on_insertion();
    }
    start = pos + 1;
    pos = str.find_first_of(delims, start);
  }
  if(start < str.length())
    tokens.emplace_back(str, start, str.length() - start);
  return tokens;
}

// classical version (no limit)
std::vector<std::string> split(const std::string& str, const char* delims)
{
  struct no_limit
  {
    inline bool on_loop() { return true; }
    inline void on_insertion() {}
  };
  return split_internal(str, delims, no_limit());
}

// limited version
std::vector<std::string> split(const std::string& str, const char* delims, size_t maxTokens)
{
  struct limit_at_n
  {
    inline bool on_loop() { return _limit!=0; }
    inline void on_insertion() { --_limit; }
    size_t _limit;
  };
  return maxTokens>0 ? split_internal(str, delims, limit_at_n{maxTokens}) : vector<string>();
}
