#include <bits/stdc++.h>
using namespace std;

int main()
{
    int volunteers;
    // O cemitério é o set complementar de 1 a N - R
    while (cin >> volunteers)
    {
        int returnees;
        cin >> returnees;
        vector<int> graveyard(volunteers);

        if (returnees == volunteers)
        {
            for (int i = 0; i < returnees; i++)
            {
                int returnee;
                cin >> returnee;
            }
            cout << "*\n";
        }
        else
        {
            iota(graveyard.begin(), graveyard.end(), 1);
            for (int i = 0; i < returnees; i++)
            {
                int returnee;
                cin >> returnee;
                auto returnee_index = find(graveyard.begin(), graveyard.end(), returnee);

                if (returnee_index != graveyard.end())
                {
                    graveyard.erase(returnee_index);
                }
            }
            for (auto dead : graveyard)
            {
                cout << dead << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}