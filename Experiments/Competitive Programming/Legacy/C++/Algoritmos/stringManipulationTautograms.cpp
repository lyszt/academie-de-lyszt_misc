    // g++ -std=c++11 -O2 -Wall test.cpp -o test

    #include <iostream>
    #include <vector>
#include <algorithm>
#include <sstream>
#include <string>

    int main() {
        using namespace std;
        string sentence;

        while(getline(cin,sentence) && sentence[0] != '*')
        {
            vector<string> phrase;
            string word;
            istringstream iss(sentence);
            while(getline(iss, word, ' ')){
                phrase.push_back(word);
            }

            {
                phrase.push_back(word);
            }
            bool tautogram = true;
            const char f_letter = tolower(phrase[0][0],locale());
            for(auto & i : phrase)
            {
                if(f_letter != tolower(i[0],locale()))
                    {
                    tautogram = false;
                    break;
                }
            }
            if(tautogram == true){cout << "Y" << endl;}
            else { cout << "N" << endl;}
        }


        }










