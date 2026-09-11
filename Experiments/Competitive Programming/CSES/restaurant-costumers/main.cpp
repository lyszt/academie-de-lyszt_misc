#include <bits/stdc++.h>


using namespace std;
int main()
{
    vector<pair<int, int>> events;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){ 
        int arriving, leaving;
        cin >> arriving >> leaving;
        events.push_back(make_pair(arriving, 1));
        events.push_back(make_pair(leaving, -1));
    }
    sort(events.begin(), events.end());
    // pessoas vao entrando e conforme vão entrnado uma lista de pessoas vai sendo mantida na hora, 
    // por isso a ordenação
    int max = 0;
    int sum = 0;
    for(auto it = events.begin(); it != events.end(); it++){
        sum += (*it).second;
        if(sum > max) {
            max = sum;
        }
    }

    cout << max << "\n";
    


    return 0;
}