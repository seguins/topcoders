#include <iostream>
#include <string>

class AB {
  public:
    std::string createString(int N, int K) {
        std::string result(N, 'B');
        int currentValue = 0;
        int n = 0;
        
        for (int i = 0; i < N ; i++) {
            int tmp = (currentValue - n) + (N - i - 1);
            if (tmp < K) {
                currentValue = tmp;
                n++;
                result[i] = 'A';
                i = N - (K - currentValue) - 3;
                if (i >= N || i < 0) {
                    return "";    
                }
            } else if (tmp == K) {
                result[i] = 'A';
                return result;
            }
        }
        
        return "";
    }
};


bool test(int N, int K, std::string const &result) {
  AB a;

  return a.createString(N,K) == result;
}

int main() {

  std::cout << "Test0 : " << test(3, 2, "ABB") << std::endl;
  std::cout << "Test1 : " << test(2, 0, "BA") << std::endl;
  std::cout << "Test2 : " << test(5, 8, "") << std::endl;
  std::cout << "Test3 : " << test(10, 12, "ABBBBABBBB") << std::endl;

  return 0;
}
