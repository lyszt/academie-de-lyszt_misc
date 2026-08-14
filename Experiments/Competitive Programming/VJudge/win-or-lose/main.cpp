#include <bits/stdc++.h>
using namespace std;



void ganha() {
    cout << "GANHA" << "\n";
}

void perde() {
    cout << "PERDE" << "\n";
}

int main()
{
    long long int n;
    cin >> n;
    if(n == 2 || n == 1) {ganha(); return 0;}
    if(n % 3 == 0) {perde(); return 0;}
    ganha();
    return 0;
    return 0;
}