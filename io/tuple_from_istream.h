/*
  Fed up with verbose semantics of declaring + reading variables from streams?
  Actually I wrote these utilities after some Python...
*/

#include <tuple>
#include <iostream>

// Base case. See the next function for an example.
template<typename T>
std::tuple<T> tuple_from(std::istream& is)
{
    T elem; is >> elem;
    return std::make_tuple(std::move(elem));
}

/* Example:
   auto problemVars = tuple_from<int, int, double>(cin);
   get<0>(problemVars) // int
   get<1>(problemVars) // int
   get<2>(problemVars) // double
*/
template<typename H, typename S, typename... T>
std::tuple<H, S, T...> tuple_from(std::istream& is)
{
    H head; is >> head;
    return std::tuple_cat(std::make_tuple(std::move(head)), tuple_from<S, T...>(is));
}

/* Same as before except that this version uses cin.
   auto problemVars = tuple_from<int, int, double>(); // from cin
*/
template<typename H, typename S, typename... T>
std::tuple<H, S, T...> tuple_from()
{
    H head; is >> head;
    return std::tuple_cat(std::make_tuple(std::move(head)), tuple_from<S, T...>(std::cin));
}
