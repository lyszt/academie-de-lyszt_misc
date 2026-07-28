    // g++ -std=c++11 -O2 -Wall test.cpp -o test

    #include <iostream>
    #include <vector>

    int main() {
        using namespace std;
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> sort_simples = {a,b,c};
        vector<int> sort_original = sort_simples;
        for(auto it = sort_simples.begin(); it != sort_simples.end()-1; it++){
            int current = *it;
            int next_value = *next(it);
            if(*next(it)<*it)
            {
                *next(it) =  current;
                *it = next_value;

            }

        }
        // Reverse pointer
        for(auto it = sort_simples.end()-1; it != sort_simples.begin(); it--){
            int current = *it;
            int previous_value = *prev(it);
            if(*prev(it)>*it)
            {
                *prev(it) =  current;
                *it = previous_value;

            }
        }
        printf("%i\n%i\n%i\n\n", sort_simples[0],sort_simples[1],sort_simples[2]);
        printf("%i\n%i\n%i\n", sort_original[0],sort_original[1],sort_original[2]);
    }









