#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        stack<long long int> odd;
        stack<long long int> even;
        long long int a;
        for (long long int i = 0; i < n; i++)
        {
            cin >> a;
            if (a % 2 == 0)
            {
                even.emplace(a);
                if (even.size() == 2)
                {
                    even.pop();
                    even.pop();
                }
            }
            else
            {
                odd.emplace(a);
                if (odd.size() == 2)
                {
                    odd.pop();
                    odd.pop();
                }
            }
        }
        if (odd.size() > 0)
        {
            cout << odd.top() << "\n";
        }

        if (even.size() > 0)
        {
            cout << even.top() << "\n";
        }
    }

    return 0;
}