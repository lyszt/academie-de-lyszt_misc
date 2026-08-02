#include <iostream>
#include <vector>
#include <climits>
#include <stdlib.h>
#include <unordered_map>

// We call a 44-digit integer with three
//  or more consecutive same digits, such as 11181118, good.
// You are given a 44-digit integer NN. Answer the question: Is NN good?

using namespace std;

unordered_map<int, pair<int, int>> get_digits_occurences(int n)
{
    int digit;
    unordered_map<int, pair<int, int>> occurrences;

    int last;
    while (n != 0)
    {
        digit = n % 10;
        auto pos = occurrences.find(digit);
        if (pos == occurrences.end())
        {
            occurrences.emplace(make_pair(digit, make_pair(digit, 1)));
        }
        else if (digit == last)
        {
            occurrences.at(digit).first = digit;
            occurrences.at(digit).second = occurrences.at(digit).second + 1;
        }
        else
        {
            occurrences.at(last).second = 0;
        }
        last = digit;
        n /= 10;
    }

    return occurrences;
}

bool is_good(int n)
{
    if (n <= 110)
    {
        return false;
    }

    unordered_map<int, pair<int, int>> digit_map = get_digits_occurences(n);
    for (auto it = digit_map.begin(); it != digit_map.end(); it++)
    {
        if (it->second.second >= 3)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (is_good(n))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}