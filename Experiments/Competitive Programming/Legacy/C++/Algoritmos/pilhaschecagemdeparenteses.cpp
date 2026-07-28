// g++ -std=c++11 -O2 -Wall test.cpp -o test

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>



int n_main() {
    using namespace std;
    string expression;

    // left ( right )

    char left = '(';
    char right = ')';
    while (cin >> expression){
        int left_counter = 0;
        int right_counter = 0;
        int pairs = 0;
        stack<char> parentheses;
        int not_paired;
        for (auto it = expression.begin(); it < expression.end(); it++) {
            if (*it == '(') {
                parentheses.push(*it);
            } else if (*it == ')') {
                if (!parentheses.empty() && parentheses.top() == '(') {
                    parentheses.pop();
                }
                else {
                    parentheses.push(*it);
                }
            }
        }
        if(!parentheses.empty()){
            printf("incorrect\n");
        }
        else {
            printf("correct\n");
        }
    }

    return 0;


}









