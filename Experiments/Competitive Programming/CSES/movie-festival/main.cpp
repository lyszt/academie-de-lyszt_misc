#include <bits/stdc++.h>

struct MovieData {
    int time;
    int movie_id;
    int starting;
    int ending;
};

bool comparator(MovieData &a, MovieData &b) {
    if(a.ending < b.ending){
        return true;
    }
    return false;
}

using namespace std;
int main() {
  vector<MovieData> events;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int starting, ending;
    cin >> starting >> ending;
    MovieData ending_data;
    ending_data.movie_id = i;
    ending_data.time = ending;
    ending_data.starting = starting;
    ending_data.ending = ending;

    events.push_back(ending_data);
  }
  sort(events.begin(), events.end(), comparator);


  int movies_watched = 0;
  int current_end = 0;
  for (auto event : events) {
    if(event.starting >= current_end) {
        movies_watched++;
        current_end = event.ending;
    }
  }
  cout << movies_watched << "\n";

  return 0;
}