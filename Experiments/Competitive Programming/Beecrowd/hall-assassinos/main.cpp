#include <bits/stdc++.h>

// HALL OF MURDERERS
// Aaascqciio 2
// Aabbobsgvl 3

using namespace std;
int main()
{
    string name, assassinado;
    map<string, int> murder_map;
    while (cin >> name)
    {
        cin >> assassinado;

        if (murder_map.find(name) == murder_map.end() && murder_map[name] != -1)
        {
            murder_map[name] = 1;
        }
        else if (murder_map[name] != -1)
        {
            murder_map[name]++;
        }
        murder_map[assassinado] = -1;
    }
    cout << "HALL OF MURDERERS\n";
    for (auto &[murderer, count] : murder_map)
    {
        if (count <= 0)
        {
            continue;
        }
        cout << murderer << " " << count;
        cout << "\n";
    }

    return 0;
}