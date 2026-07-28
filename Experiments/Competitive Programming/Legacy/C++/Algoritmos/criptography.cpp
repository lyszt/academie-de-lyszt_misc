// g++ -std=c++11 -O2 -Wall test.cpp -o test

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


int main() {
    using namespace std;
    string input;
    int tests;
    cin >> tests;
    for(int i = tests; i > 0; i--){
            getline(cin >> ws, input);
            for (auto it = input.begin(); it <= input.end(); it++)
            {
                if((*it >= 65 && *it <= 90) || (*it >=97 && *it <= 122)){
                    *it += + 3;
                }
            }
            reverse(input.begin(),input.end());
        for (auto it = input.begin()+(input.size()/2); it <= input.end(); it++)
        {
            *it -= 1;
        }
        cout << input << endl;


    }





}









