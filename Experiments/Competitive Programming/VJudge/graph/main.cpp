#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> adj_list(n + 1);

    for (int i = 0; i < n; i++)
    {
        int u, k;

        cin >> u >> k;

        for (int i = 0; i < k; i++) {
            int a;

            cin >> a;

            adj_list[u].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool found = false;

            for (int neighbour : adj_list[i]) {
                if (neighbour == j) {
                    found = true;
                    break;
                }
            }

            cout << (found ? "1" : "0") << (j == n ? "" : " ");
        }

        cout << "\n";
    }

    return 0;
}