#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int length;
    cin >> length;
    vector<int> array(length);
    for(int i = 0; i < length; i++) {
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++) {
        int a, b;
        cin >> a >> b;
        auto low_bound = distance(array.begin(), lower_bound(array.begin(), array.end(), a));
        auto up_bound = distance(array.begin(), upper_bound(array.begin(), array.end(), b));
        auto diff = up_bound - low_bound;
        cout << diff << "\n";
    }
    return 0;
}