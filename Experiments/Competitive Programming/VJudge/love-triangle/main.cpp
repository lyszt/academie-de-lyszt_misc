#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> adj_list(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        adj_list[i] = a;
    }

    for (int i = 1; i <= n; i++)
    {
        if (adj_list[adj_list[adj_list[i]]] == i)
        {

            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;

    return 0;
}