    // g++ -std=c++11 -O2 -Wall test.cpp -o test

    #include <iostream>

    bool VerifyPrime(int b){
        if(b <= 1){
            return false;
        }
        for(int j = 2; j*j <= b; j++) {
            if (b % j == 0) return false;

        }
        return true;

    }
    int main() {
        using namespace std;
        int a, b;
        cin >> a;
        for(int i = 0; i < a; i++) {
            cin >> b;
            VerifyPrime(b) ? cout << "Prime\n" : cout << "Not Prime\n";
        }
        return 0;
        }









