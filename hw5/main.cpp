#include <cmath>
#include <iostream>

const int LIMIT = 20;
const int BASE = 2;
const int BIAS = 13;
const int DIV = 2;

int main(void) {
  for (int i = 1; i <= LIMIT; ++i) {
    std::cout << "Number is " << i << std::endl;
    std::cout << "2^number is " << int(pow(BASE, i)) << std::endl;
    std::cout << "Number is " << i << " " << (i % DIV == 0 ? "even" : "odd")
              << std::endl;
    std::cout << i << " "
              << (i <= BIAS ? "a lucky number" : "a not lucky number")
              << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
