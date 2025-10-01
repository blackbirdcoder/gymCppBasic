#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

enum { SIZE_BIT, MAX_NUM };
const char *notification = " bit unsigned integer maximum is ";
const unsigned short uCharValue[] = {sizeof(char) * CHAR_BIT, UCHAR_MAX};
const unsigned int uShortValue[] = {sizeof(short) * CHAR_BIT, USHRT_MAX};
const unsigned int uIntValue[] = {sizeof(int) * CHAR_BIT, UINT_MAX};
const unsigned long long uLLValue[] = {sizeof(long long) * CHAR_BIT,
                                       ULLONG_MAX};

int main(void) {
  cout << uCharValue[SIZE_BIT] << notification << uCharValue[MAX_NUM] << "\n";
  cout << uShortValue[SIZE_BIT] << notification << uShortValue[MAX_NUM] << "\n";
  cout << uIntValue[SIZE_BIT] << notification << uIntValue[MAX_NUM] << "\n";
  cout << uLLValue[SIZE_BIT] << notification << uLLValue[MAX_NUM] << "\n";

  return 0;
}
