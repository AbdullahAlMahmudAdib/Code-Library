#include <iostream>
#include <vector>

using namespace std;

class fibonacci_dp {
private:
   vector<int> fib;
   int mod;
   
   int add_mod(int x, int y) {      // returns (x + y) % mod
      return (1LL * x + y) % mod;
   }
   
   void pre_process() {             // bottom-up dynamic programming fib(n) = (fib(n-1) + fib(n-2)) % mod
      int n = (int)fib.size();
      if (n > 0) fib[0] = 0;        // Correct initialization for fib(0)
      if (n > 1) fib[1] = 1;        // Correct initialization for fib(1)
      for (int i = 2; i < n; ++i) {
         fib[i] = add_mod(fib[i - 1], fib[i - 2]);
      }
   }
   
public:
   fibonacci_dp(int maximum_N, int M) {  // initialized
      mod = M;
      fib.resize(maximum_N + 1);
      pre_process();
   }
   
   int fibonacci(int n) {           // returns nth fibonacci number
      return fib[n];
   }
};

int main() {
   int maximum_N = 10;
   int M = 1000000007;  // Example modulus value
   fibonacci_dp fib_dp(maximum_N, M);
   
   for (int i = 0; i <= maximum_N; ++i) {
      cout << "fib(" << i << ") = " << fib_dp.fibonacci(i) << endl;
   }
   
   return 0;
}

/*
 * Expected output:
 * fib(0) = 0
 * fib(1) = 1
 * fib(2) = 1
 * fib(3) = 2
 * fib(4) = 3
 * fib(5) = 5
 * fib(6) = 8
 * fib(7) = 13
 * fib(8) = 21
 * fib(9) = 34
 * fib(10) = 55
 */
