#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> notes = {100,20,10,5,1};
    int current_note = 0;
    int bills = 0;
    int sum = 0;
    while(sum < n) {
        int note = notes[current_note];
        if(sum + note > n) {
            current_note++;
            continue;
        }
        sum += note;
        bills++;
    }    
    cout << bills << "\n";
    return 0;
}