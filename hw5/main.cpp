#include <cmath>
#include <iostream>

namespace constant {
const int LIMIT = 20;
const int BASE = 2;
const int BIAS = 13;
const int DIV = 2;
}; // namespace constant

using namespace std;
using namespace constant;

int main(void) {
  for (int i = 1; i <= LIMIT; ++i) {
    cout << "Number is " << i << endl;
    cout << "2^number is " << pow(BASE, i) << endl;
    cout << "Number is " << i << " " << (i % DIV == 0 ? "even" : "odd") << endl;
    cout << i << " " << (i < BIAS ? "a lucky number" : "a not lucky number")
         << endl;
  }
  return 0;
}
