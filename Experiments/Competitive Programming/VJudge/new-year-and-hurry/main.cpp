#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <vector>

int main () {
    int n, k;
    std::cin >> n >> k;
    
    // Number of problems n and minutes k
    // maximum number of problems can solve
    int start = 20;
    std::vector<int> difficulty;
    difficulty.resize(n);
    for(auto it = difficulty.begin(); it < difficulty.end(); it++) {
        *it = 5 * (std::distance(difficulty.begin(), it) + 1);
    }
    int problem_minutes = std::accumulate(difficulty.begin(), difficulty.end(), 0);
    //by default we expect he can solve all problems
    int budget = 240 - k;
    while(problem_minutes > budget) {
        problem_minutes -= (5 * n);
        n-=1;
    }
    std::cout << n << std::endl; 
    return 0;
}