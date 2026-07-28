#include <iostream>
#include <vector>

int main(){
    using namespace std;

    vector <string>word;
    unsigned int length;
    unsigned int i;
    unsigned int limit;
    string input;

    limit;
    for(i = 0; i < 4; i++){
        input;
        word.push_back(input);
    }
    for(i = 0; i < 4; i++){
     length = word[i].size();
        if(length > limit){
            cout << word[i].at(0) << (length - 2) << word[i].at(word[i].size()-1) << endl;
        } else {
            cout << word[i]<< endl;
        }
    }
}   