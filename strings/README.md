## strings
String algorithms and snippets, common regular expressions, etc.

## Current contents

* algorithms.hpp

  * __split__ : splits a string on given separators
  
* parse-subscript.hpp

  * __parse_subscript_clike__ : parses a string like "parameterName[10]" and returns the pair [parameterName, 10]. This version is much faster than the regex one.
  * __parse_subscript_regex__ : parses a string like "parameterName[10]" and returns the pair [parameterName, 10]
  
## This is NOT a library
.hpp files in this folder are not intended to be included somewhere. They contain snippets, easy to copy-and-paste into the challenge editor.

__However__ .h files can be used as header-only.
