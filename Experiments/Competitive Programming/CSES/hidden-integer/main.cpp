#include <bits/stdc++.h>


using namespace std;
int main()
{
    int count = 0;
    char c;
    int low = 1;
    int high = pow(10,9);
    long long int guess = (low + high) / 2;
    string answer;
    while(low <= high) {
        guess = (low + high) / 2;
        c = '?';
        if(count == 30) break;
        switch(c) {
            case '?':
            count++;
            cout << "? " << guess << "\n";
            // y < x?
            cin >> answer; 
            if(answer == "YES") {
                low = guess + 1;
                guess = (low + high) / 2;
            }   
            else {
                high = guess;
            }
            
            break;
            case '!':
                high = guess;
                cout << "! " << guess;
            default:
                break;
        }
        if (c == '!') break;
    }
    cout << "! " << low << "\n";
    return 0;
}