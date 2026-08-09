#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if((a + b + c) % 2 != 0)  {
        cout << "No" << endl;
        return 0;
    }
    if(a == b + c || b == a + c || c == b + a) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}