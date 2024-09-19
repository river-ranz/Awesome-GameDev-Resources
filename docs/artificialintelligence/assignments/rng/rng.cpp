#include <unordered_set>
#include <fstream>
#include <iostream>
#include <istream>
const std::string TEST_FOLDER = "\\tests\\";
unsigned int xorShift(unsigned int &seed, int r1, int r2);

struct State {
  unsigned int a, b;

  bool operator==(const State& other) const {
    return a == other.a && b == other.b;
  }
};

namespace std {
  template <>
  struct hash<State> {
    std::size_t operator()(const State& p) const {
      return p.a ^ p.b;
    }
  };
}

int main() {
  std::unordered_multiset<State> states;
  State state = {1, 2};

  int warmup = 0;
  int cycle = 0;

  std::cout << "input seed, number of numbers, min, max" << std::endl << std::endl;
  unsigned int seed, N, min, max;
  std::cin >> seed >> N >> min >> max;

  state.a = seed;

  for (int i = 0; i < N; i++) {
    state.b = xorShift(state.a, min, max);
    std::cout << state.b << std::endl;

    if (!states.contains(state)) {
      warmup++;
    }
    states.insert({state});

    int val = states.count(state);
    if (val == 2) {
      cycle++;
    }
  }
  warmup -= cycle;
  std::cout << "the warmup period is: " << warmup << std::endl;
  std::cout << "the cycle period is: " << cycle << std::endl;
}

//The purpose of this function is to take the number and xor shift it to output a pseudo-random number
unsigned int xorShift(unsigned int &seed, int r1, int r2) {
  unsigned int result = seed;
  result ^= result << 13;
  result ^= result >> 17;
  result ^= result << 5;

  //keeps within min-max
  result = r1 + (result % (r2 - r1 + 1));

  seed = result;
  return result;
}
