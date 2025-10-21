#include <cstdint>
#include <iostream>

enum { MIN = 2, MAX = 80 };

uint64_t *fibArray(uint8_t);
void show(uint64_t *, uint8_t);
bool isNull(uint64_t *);

int main(void) {
  const uint8_t N = 11;
  uint64_t *fib = fibArray(N);

  if (isNull(fib)) {
    std::cout << "Goodbye!" << std::endl;
    return 0;
  }

  show(fib, N);
  delete[] fib;

  return 0;
}

uint64_t *fibArray(uint8_t n) {
  if (n < MIN || n > MAX) {
    return nullptr;
  }

  uint64_t *boxPtr = new uint64_t[n];
  boxPtr[0] = 0ull;
  boxPtr[1] = 1ull;

  if (n == 2) {
    return boxPtr;
  }

  for (uint8_t i = 1; i < n - 1; ++i) {
    boxPtr[i + 1] = boxPtr[i] + boxPtr[i - 1];
  }

  return boxPtr;
}

void show(uint64_t *ptr, uint8_t n) {
  for (uint8_t i = 0; i < n; ++i) {
    std::cout << ptr[i] << " ";
  }
  std::cout << std::endl;
}

bool isNull(uint64_t *target) { return target == nullptr ? true : false; }
