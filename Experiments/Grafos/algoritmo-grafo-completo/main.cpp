#include <iostream>
#include <math.h>
#include <vector>
#define NUM_VERTICES 25
using namespace std;

vector<vector<int>> MATRIZ_ADJ = {
     {0,1,1,1,1},
     {1,0,1,1,1},
     {1,1,0,1,1},
     {1,1,1,0,1},
     {1,1,1,1,0}
};

bool verify_completeness(vector<vector<int>> matrix){
    int size = matrix.size();
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++) {
            if(matrix[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

int main() {
    if(verify_completeness(MATRIZ_ADJ) == true){
        cout << "It is complete" << endl;;
        return 0;
    } 
    cout << "It is not complete." << endl;
    return 0; 
}