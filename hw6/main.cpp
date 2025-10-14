#include <iostream>
#include <string>

void notification(std::string, long long *);
void notification(std::string, int *);

void setToOne(int);
void setToOneRef(int &);
void setToOne(int *);

long long product(int, int);
void productPtr(int, int, long long *);
void productRef(int, int, long long &);

int main(void) {
  std::cout << "---- 1 ---- (Value)\n";
  int targetOne = 0;
  notification("before", &targetOne);
  setToOne(targetOne);
  notification("after", &targetOne);

  std::cout << "---- 2 ---- (Link)\n";
  int targetTwo = 0;
  notification("before", &targetTwo);
  setToOneRef(targetTwo);
  notification("after", &targetTwo);

  std::cout << "---- 3 ---- (Pointer)\n";
  int targetThree = 0;
  notification("before", &targetThree);
  setToOne(&targetThree);
  notification("after", &targetThree);

  std::cout << "---- 4 ---- (Return)\n";
  long long resultOne = 0;
  notification("before", &resultOne);
  resultOne = product(10, 2);
  notification("after", &resultOne);

  std::cout << "---- 5 ---- (Pointer)\n";
  long long resultTwo = 0;
  int a = 10;
  int b = 30;
  notification("before 'a'", &a);
  notification("before 'b'", &b);
  notification("before 'resultTwo'", &resultTwo);
  productPtr(a, b, &resultTwo);
  notification("after 'a'", &a);
  notification("after 'b'", &b);
  notification("after 'resultTwo'", &resultTwo);

  std::cout << "---- 6 ---- (Link)\n";
  long long resultThree = 0;
  int c = 20;
  int d = 40;
  notification("before 'c'", &c);
  notification("before 'd'", &d);
  notification("before 'resultThree'", &resultThree);
  productRef(c, d, resultThree);
  notification("after 'c'", &c);
  notification("after 'd'", &d);
  notification("after 'resultThree'", &resultThree);

  return 0;
}

void notification(std::string str, int *num) {
  std::cout << str << " value: " << *num << " address: " << num << std::endl;
}

void notification(std::string str, long long *num) {
  std::cout << str << " value: " << *num << " address: " << num << std::endl;
}

void setToOne(int num) {
  num = 1;
  notification("inner", &num);
}

void setToOneRef(int &num) {
  num = 1;
  notification("inner", &num);
}

void setToOne(int *num) {
  *num = 1;
  notification("inner", num);
}

long long product(int a, int b) {
  long long c = a + b;
  return c;
}

void productPtr(int a, int b, long long *p) {
  notification("inner", p);
  *p = a * b;
}

void productRef(int a, int b, long long &r) {
  notification("inner", &r);
  r = a * b;
}
