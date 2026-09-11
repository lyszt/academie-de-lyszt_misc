#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> distinct;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        distinct.emplace(a);
    }
    cout << distinct.size() << "\n";
    return 0;
}