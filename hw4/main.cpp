#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

enum { SIZE_BIT, MAX_NUM };
const char *notification = " bit unsigned integer maximum is ";
const short charValue[] = {sizeof(char) * CHAR_BIT,
                           (short)(pow(2, CHAR_BIT) - 1)};
const int shortValue[] = {sizeof(short) * CHAR_BIT,
                          (int)(pow(2, CHAR_BIT * 2) - 1)};
const int intValue[] = {sizeof(int) * CHAR_BIT, (int)pow(2, CHAR_BIT * 4) - 1};
const long long llValue[] = {sizeof(long long) * CHAR_BIT,
                             (long long)pow(2, CHAR_BIT * 8) - 1};

int main(void) {
  cout << charValue[SIZE_BIT] << notification << charValue[MAX_NUM] << "\n";
  cout << shortValue[SIZE_BIT] << notification << shortValue[MAX_NUM] << "\n";
  cout << intValue[SIZE_BIT] << notification << intValue[MAX_NUM] << "\n";
  cout << llValue[SIZE_BIT] << notification << llValue[MAX_NUM] << "\n";
  return 0;
}
