#include <cstdint>
#include <iostream>

uint16_t const ROWS = 3u;
uint16_t const COLS = 4u;

uint16_t **createMatrix();
void clearMatrix(uint16_t **);
void showMatrix(uint16_t **);
uint16_t sumMatrix(uint16_t **);

int main(void) {
  uint16_t **mtxPtr = createMatrix();
  showMatrix(mtxPtr);
  uint16_t sum = sumMatrix(mtxPtr);
  std::cout << "Sum: " << sum << std::endl;

  clearMatrix(mtxPtr);
  return 0;
}

uint16_t **createMatrix() {
  uint16_t filler = 1u;
  uint16_t **ptr = new uint16_t *[ROWS];

  for (uint16_t i = 0u; i < ROWS; ++i) {
    ptr[i] = new uint16_t[COLS];
    for (uint16_t j = 0u; j < COLS; ++j) {
      ptr[i][j] = filler++;
    }
  }

  return ptr;
}

void clearMatrix(uint16_t **ptr) {
  for (uint16_t i = 0u; i < ROWS; ++i) {
    delete[] ptr[i];
  }
  delete[] ptr;
}

void showMatrix(uint16_t **ptr) {
  for (uint16_t i = 0u; i < ROWS; ++i) {
    for (uint16_t j = 0u; j < COLS; ++j) {
      std::cout << ptr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

uint16_t sumMatrix(uint16_t **ptr) {
  uint16_t sum = 0u;

  for (uint16_t i = 0u; i < ROWS; ++i) {
    for (uint16_t j = 0; j < COLS; ++j) {
      sum += ptr[i][j];
    }
  }

  return sum;
}