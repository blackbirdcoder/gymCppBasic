#include <iostream>
#include <string>

void notification(std::string, long long, long long &);
void notification(std::string, long long, long long *);
void notification(std::string, int, int *);
void setToOne(int);
void setToOneRef(int &);
void setToOne(int *);
long long product(int, int, long long *);
void productNude(int, int, long long *);
void productNudeRef(int, int, long long &);

int main(void) {
  std::cout << "---- 1\n";
  int target = 0;
  notification("after", target, &target);
  setToOne(target);
  notification("before", target, &target);

  std::cout << "---- 2\n";
  notification("after", target, &target);
  setToOneRef(target);
  notification("before", target, &target);

  std::cout << "---- 3\n";
  notification("after", target, &target);
  setToOne(&target);
  notification("before", target, &target);

  std::cout << "---- 4\n";
  long long resultOne = 0;
  notification("after", resultOne, &resultOne);
  resultOne = product(1, 0, &resultOne);
  notification("before", resultOne, &resultOne);

  std::cout << "---- 5\n";
  long long resultTwo = 0;
  int a, b;
  a = 1;
  b = 0;
  notification("after", a, &a);
  notification("after", b, &b);
  notification("after", resultTwo, &resultTwo);
  productNude(a, b, &resultTwo);
  notification("before", a, &a);
  notification("before", b, &b);
  notification("before", resultTwo, &resultTwo);

  std::cout << "---- 6\n";
  long long resultThree = 0;
  int c, d;
  c = 1;
  d = 0;
  notification("after", c, &c);
  notification("after", d, &d);
  notification("after", resultThree, &resultThree);
  productNudeRef(c, d, resultThree);
  notification("before", c, &c);
  notification("before", d, &d);
  notification("before", resultThree, &resultThree);

  return 0;
}

void notification(std::string str, int num, int *nump) {
  std::cout << str << " value: " << num << " address: " << nump << std::endl;
}

void notification(std::string str, long long num, long long *nump) {
  std::cout << str << " value: " << num << " address: " << nump << std::endl;
}

void notification(std::string str, long long num, long long &numr) {
  std::cout << str << " value: " << num << " address: " << numr << std::endl;
}

void setToOne(int num) {
  num = 1;
  notification("inner", num, &num);
}

void setToOneRef(int &num) {
  num = 1;
  notification("ref", num, &num);
}

void setToOne(int *num) {
  *num = 1;
  notification("inner", *num, num);
}

long long product(int a, int b, long long *p) {
  return a + b;
  notification("inner", *p, p);
}

void productNude(int a, int b, long long *p) {
  notification("inner", *p, p);
  *p = a * b;
}

void productNudeRef(int a, int b, long long &r) {
  notification("inner Ref", r, r);
  r = a * b;
}
