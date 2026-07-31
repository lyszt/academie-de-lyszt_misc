#include <iostream>
#include <stdlib.h>
#include <vector> 
#include <stack>
using namespace std; 


// 11 and 18 are adjacent lucas numbers
// find the nth lucas number

// Li = L[i-1] + L[i-2](i>=2);
// i = 5 
// L[5] = L[4] + L[3]
// i = 2
// L[0] = 2 - - 2  0 
// L[1] = 1  -  - 1 1 
// L[2] = [L1] + L[0] = 1 + 2 = 3 - 0 2 
// L[3] = L[2] + L[1] = 3 + 1 = 4  - 1 3 
// L[4] = L[3] + L[2] = 4 + 3 = 7  - 2 4 
// 11 
// 18

long long int get_lucas(long long int n) {
  vector<long long int> lucas = {2,1};
  if(n == 1) {
    return 1;
  }
  if(n == 0) {
    return 2;
  }

  for(long long int i = 2; i <= n; i++) {
    lucas.push_back(lucas[i-1] + lucas[i-2]);
  }

  return lucas.back();
}  






int main() {
  long long int n; 

  while(cin >> n) {
    cout << get_lucas(n) << endl;
  }
  return 0;
}
