#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, r;
    cin >> n >> r;
    int displayed_rating;
    if(n > 10) {
        displayed_rating = r;
        cout << displayed_rating;
        return 0;
    }
    int inner_rating = r + 1000 - 100 * n;
    cout << inner_rating;
}

// inner = display - 100(10-K)