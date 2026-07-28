// g++ -std=c++11 -O2 -Wall test.cpp -o test

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


int main() {
    using namespace std;
    vector<string> names;
    vector<double> points;
    int n;
    string name;
    cin >> n;
    names.reserve(n); // Reserve space from n
    points.reserve(n); // Reserve space from n
    for(int i = 0; i < n; i++)
    {
        vector<double> jumps(7);
        double difficulty;
        cin >> name;
        cin >> difficulty;
        for(int j = 0; j < 7; j++)
        {
            cin >> jumps[j];
        }
        auto min_max = minmax_element(jumps.begin(),jumps.end());
        double result = 0;
        for(auto &jump : jumps)
        {
            if(&jump != &*min_max.first && &jump != &*min_max.second)
            {
                result += jump;
            }
        }
        result *= difficulty;

        names.push_back(name);
        points.push_back(result);

    }
    for(int i = 0; i < names.size(); i++){
        printf("%s %.2lf\n",names[i].c_str(),points[i]);
    }
    return 0;
}








