#include <array>
#include <cmath>
#include <iostream>
#include <random>
#include <string>

/// Returns a random int number in the range from min to max.
int getRandomInt(int min, int max) {
  auto generator = std::mt19937{std::random_device{}()};
  auto distribution = std::uniform_int_distribution<int>{min, max};
  return distribution(generator);
}

/// Returns a random double number in the range from min to max.
double getRandomDouble(double min, double max) {
  auto generator = std::mt19937{std::random_device{}()};
  auto distribution = std::uniform_real_distribution<double>{min, max};
  return distribution(generator);
}

/// Returns some number on the specified index.
double getSomeNumber(int index) {
  switch (index) {
  case 0:
    return static_cast<double>(getRandomInt(-4, 0));
  case 1:
    return static_cast<double>(getRandomInt(100, 299));
  case 2:
    while (true) {
      if (const auto element = getRandomInt(-35, 1); element % 2 == 0) {
        return static_cast<double>(element);
      }
    }
  case 3:
    return static_cast<double>(getRandomInt(-128, 127));
  case 4:
    while (true) {
      if (const auto element = getRandomInt(-7, 12); element % 2 != 0) {
        return static_cast<double>(element);
      }
    }
  case 5:
    return getRandomDouble(-7.85, 28.0 * std::sqrt(3.0));
  case 6:
    return static_cast<double>(getRandomInt(-100, 100));
  case 7:
    return static_cast<double>(getRandomInt(23, 71));
  case 8:
    return static_cast<double>(getRandomInt(0, 1));
  case 9:
    return getRandomDouble(sqrt(17.0), sqrt(182.0));
  default:
    std::cerr << "error: Unknown " << index
              << " array index. The element will be set to 0.\n";
    return 0.0;
  }
}

/// Prints array.
template <typename Type, size_t Size>
void printArray(const std::array<Type, Size> &array,
                const std::string &name = "Array",
                const std::string &terminator = "\n") {
  std::cout << name << ":\n";

  for (const auto &element : array) {
    std::cout << "  " << element << '\n';
  }
  std::cout << terminator;
}

int main() {
  auto numbers = std::array<double, 10>{};

  // Fill in the numbers.
  for (auto i = 0; i < numbers.size(); ++i) {
    numbers[i] = getSomeNumber(i);
  }

  printArray(numbers, "Numbers", "");
  return 0;
}