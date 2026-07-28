// g++ -std=c++11 -O2 -Wall test.cpp -o test

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int FindGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    int loops = std::max(a,b);
    std::stack<int> divisors;
    if (b <= 1 || a <= 1) {
        return 1;
    }
    for (int j = loops; j > 0; j--) {
        divisors.push(j);
    while(!divisors.empty()){
        int divisor = divisors.top();
        if((a % divisor == 0 && b % divisor == 0)){
            return divisor;

        }
        else {
            divisors.pop();
        }
        }
    }
    return 1;
}

int main() {
    using namespace std;
    int tests;
    int n1, d1, n2, d2;
    int numerator;
    int denominator;
    char expr;
    char expression_sign;
    vector<int> expression1val;
    string expression;
    char generic;
    cin >> tests;
    // n1/ b + c / d

    for(int i = 0; i < tests; i++)
    {
        cin >> n1 >> generic >> d1 >> expr >> n2 >> generic >> d2;
        if(expr == '+')
        {
            numerator = (n1*d2+n2*d1);
            denominator = (d1*d2);
        }
        if(expr == '-')
        {
            numerator = (n1*d2-n2*d1);
            denominator = (d1*d2);
        }
        if(expr == '*')
        {
            numerator = n1 * n2;
            denominator = d1 * d2;
        }
        if(expr == '/')
        {
            numerator = n1 * d2;
            denominator = n2*d1;
        }
        int simplified_denominator;
        int simplified_numerator;
        int divisor = FindGCD(numerator, denominator);
        simplified_denominator = denominator/divisor;
        simplified_numerator = numerator/divisor;
        if(divisor != 1)
        {
         printf("%i/%i = %i/%i\n",numerator,denominator, simplified_numerator, simplified_denominator);
        } else {
            printf("%i/%i = %i/%i\n",numerator,denominator, numerator, denominator);
        }
    }


    return 0;



}









