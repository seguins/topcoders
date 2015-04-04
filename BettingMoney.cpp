#include <iostream>
#include <vector>

class BettingMoney {
public:
  int moneyMade(std::vector<int> amounts, std::vector<int> centsPerDollar, int finalResult) {
    int result = 0;
    for (int i = 0 ; i < amounts.size() ; i++) {
      if (i == finalResult) {
        result -= amounts[i] * centsPerDollar[i];
      } else {
        result += amounts[i] * 100;
      }
    }
    return result;
  }
};


bool test(std::vector<int> amounts, std::vector<int> centsPerDollar, int finalResult, int result) {
  BettingMoney a;

  return a.moneyMade(amounts, centsPerDollar, finalResult) == result;
}

int main() {
  std::cout << "Test0 : " << test(std::vector<int>({10,20,30}), std::vector<int>({20,30,40}), 1, 3400) << std::endl;
  std::cout << "Test1 : " << test(std::vector<int>({200, 300, 100}), std::vector<int>({10, 10, 10}), 2, 49000) << std::endl;
  std::cout << "Test2 : " << test(std::vector<int>({100, 100, 100, 100}), std::vector<int>({5, 5, 5, 5}), 0, 29500) << std::endl;
  std::cout << "Test3 : " << test(std::vector<int>({5000, 5000}), std::vector<int>({100, 2}), 0, 0) << std::endl;
  std::cout << "Test4 : " << test(std::vector<int>({10}), std::vector<int>({100}), 0, -1000) << std::endl;

  return 0;
}
