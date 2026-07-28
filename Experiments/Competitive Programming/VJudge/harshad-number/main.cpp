#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
// an integer x is a harshad number if 
// x is divisible by f(x) where f(x) is the sum of the digits in x 
// when written in base 10

int get_sum_digits(int n, int sum) {
  if(n == 0) {
    return sum;
  }
  return get_sum_digits(n/10, sum + (n % 10));
}

int main() {
  int n;
  while(cin >> n){
    if (n % (get_sum_digits(n, 0)) == 0) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  return 0;
}
