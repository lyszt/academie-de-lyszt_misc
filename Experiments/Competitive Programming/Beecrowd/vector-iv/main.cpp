#include <bits/stdc++.h>
using namespace std;

pair<int, int> recursive_filling(pair<int, int> filled, int number_c, int index_o, int index_e, vector<int> *odd, vector<int> *even)
{
    if (number_c >= 15)
    {
        return filled;
    }
    bool end_o = false;
    bool end_e = false;
    if (index_o == 4)
    {
        end_o = true;
    }
     if (index_e == 4)
    {
        end_e = true;
    }

    index_o = index_o % 5;
    index_e = index_e % 5;

    filled = make_pair(filled.first % 5, filled.second % 5);

    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        filled.first++;
        (*even)[index_e] = n;
        if (end_e)
        {
            for (int i = 0; i < 5; i++)
            {
                printf("par[%d] = %d\n", i, (*even)[i]);
            }
        }
        index_e++;
        
    }
    else
    {
        filled.second++;
        (*odd)[index_o] = n;
        if (end_o)
        {
            for (int i = 0; i < 5; i++)
            {
                printf("impar[%d] = %d\n", i, (*odd)[i]);
            }
        }
        index_o++;
    }

    return recursive_filling(filled, number_c + 1, index_o, index_e, odd, even);
}

int main()
{
    vector<int> odd(5);
    vector<int> even(5);

    pair<int, int> remaining = recursive_filling(make_pair(0, 0), 0, 0, 0, &odd, &even);
    for (int i = 0; i < remaining.second; i++)
    {

        printf("impar[%d] = %d\n", i, odd[i]);
    }
    for (int i = 0; i < remaining.first; i++)
    {
        printf("par[%d] = %d\n", i, even[i]);
    }
    return 0;
}