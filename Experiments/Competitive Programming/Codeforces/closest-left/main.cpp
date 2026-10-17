#include <bits/stdc++.h>

using namespace std;

int main(){
    int length, queries;
    cin >> length >> queries;
    vector<int> array(length);
    for(int i = 0; i < length; i++) {
        cin >> array[i];
        // non-decreasing order
    }
    for(int i = 0; i < queries; i++) {
        int query;
        cin >> query;
        auto idx_it = upper_bound(array.begin(), array.end(), query);
        int idx = distance(array.begin(), idx_it);
        cout << idx << "\n";
    }

    return 0;
}