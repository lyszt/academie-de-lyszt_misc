#include <bits/stdc++.h>

using namespace std;

// O número de novos inscritos no seu canal em um dia, é sempre igual ao teto da média de inscritos nos últimos 30 dias anteriores.

struct Channel
{
    queue<int> subscribers;
    // Usar queue dá TLE, não use queue
    int currentF;
    int neededF;
    int needed_days = 0;
    int sum = 0;
    int current_idx;

    double get_avg()
    {
        queue<int> copy_subscribers = subscribers;
        int avg = ceil(sum / 30.0);
        currentF += avg;
        return avg;
    }
};

int recursive_growth(Channel *channel)
{
    if (channel->currentF >= channel->neededF)
    {
        return channel->needed_days;
    }
    cout << channel->currentF << "\n";

    channel->subscribers.emplace(channel->get_avg());
    channel->sum -= channel->subscribers.front();
    channel->subscribers.pop();
    channel->needed_days++;

    if (channel->currentF >= channel->neededF)
    {
        return channel->needed_days;
    }
    return recursive_growth(channel);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int currentF, neededF;
    Channel channel;
    cin >> channel.currentF;
    cin >> channel.neededF;
    for (int i = 0; i < 30; i++)
    {
        int n;
        cin >> n;
        channel.sum += n;
        channel.subscribers.emplace(n);
    }
    recursive_growth(&channel);

    cout << channel.needed_days << "\n";

    return 0;
}