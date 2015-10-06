/* Some useful IO manipulators/proxies
*/

/* Manipulator for reading a line to a string, in stream-like fashion. E.g.:
  istringstream ss("some line with spaces\nfield1 field2");
  string line1, line2;
  ss >> as_line >> line1 >> as_line >> line2;
  // line1 cointains "some line with spaces"
  // line2 cointains "field1 field2"
*/

struct lines_manip
{
  istream& operator()(string& s)
    {
        getline(is, s);
        return is;
    }
    
    istream& is;
};

struct line_t {} as_line;

lines_manip operator>>(istream& is, line_t)
{
    return {is};
}

istream& operator>>(lines_manip setter, string& s)
{
    return setter(s);
}
