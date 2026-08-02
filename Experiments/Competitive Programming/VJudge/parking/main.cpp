#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

// fee = a * t
// else fee = b
// t = n

int main() {
    int n, a, b;
    while(cin >> n >> a >> b) {
        cout << min((a*n), b) << endl;
    }
    return 0;
}