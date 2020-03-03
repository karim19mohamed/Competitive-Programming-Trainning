// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <sstream>

using namespace std;

int main ()
{
  double x=22.3458;
  stringstream ss;
  ss << x << endl;
  string n=ss.str();
  cout << "asdada   " << n << endl;
  return 0;
}
