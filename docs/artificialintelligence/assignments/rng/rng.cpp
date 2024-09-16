// add your imports here
#include <fstream>
#include <iostream>
#include <istream>
const std::string TEST_FOLDER = "\\tests\\";
unsigned int xorShift(unsigned int seed, int r1, int r2, int i);

int main() {
  std::cout << "input seed, number of numbers, min, max" << std::endl << std::endl;
  unsigned int seed, N, min, max;
  std::cin >> seed >> N >> min >> max;

  for (int i = 0; i < N; i++) {
    std::cout << xorShift(seed, min, max, i) << std::endl;
  }
}

//The purpose of this function is to take the number and xor shift it to output a pseudo-random number
unsigned int xorShift(unsigned int seed, int r1, int r2, int i) {
  unsigned int result = 0;
  result ^= seed << i + 1;
  while (result < r1 || result > r2) {
    if (result < r1) {
      result *= 10;
    }
    if (result > r2) {
      result /= 10;
    }
  }
  return result;
}
