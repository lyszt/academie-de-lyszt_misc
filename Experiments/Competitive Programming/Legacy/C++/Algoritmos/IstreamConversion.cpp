#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<float> A(100);
    A.reserve(100);
    for(int i = 0; i <= 100; i++){
        cin >> A[i];
    }
    for(auto it = A.begin(); it <= A.end()-1; it++){
        if(*it <= 10)
        {
            cout << fixed << setprecision(1) << "A[" << distance(A.begin(), it) << "] = " << *it << endl;
        }
    }
}

