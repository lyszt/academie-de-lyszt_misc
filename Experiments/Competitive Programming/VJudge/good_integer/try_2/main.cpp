#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> digits(4);
    int n;
    cin >> n;
    for(int i = 0; i < 4; i++){
        digits[i] = n % 10;
        n /= 10;
    }
    sort(digits.begin(),digits.end(), greater<>());
    int current_num = digits[0];
    int count = 0;
    for(int i = 0; i < 4; i++){
        if(digits[i] == current_num) {
            count++;
        } else {
            count = 1;
        }
        if(count >= 3){cout << "Yes"; return 0;}
        current_num = digits[i];
    }
    cout << "No" << "\n";
    return 0;
}