#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Task {
  int gain;
  int deadline;
};

bool by_deadline(Task &a, Task &b) {
  if (a.deadline == b.deadline && a.gain > b.gain) {
    return true;
  }
  return a.deadline < b.deadline;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int tasks;
  while (cin >> tasks) {
    int hours;
    cin >> hours;
    vector<Task> tasklist;
    int sum = 0;
    for (int i = 0; i < tasks; i++) {
      Task task;
      cin >> task.gain;
      sum += task.gain;
      cin >> task.deadline;
      tasklist.push_back(task);
    }
    map<int, Task> task_picks;
    sort(tasklist.begin(), tasklist.end(), by_deadline);
    for (auto task : tasklist) {
      if (task_picks.count(task.deadline) > 0 &&
          task_picks[task.deadline].gain < task.gain &&
          task.deadline == task_picks[task.deadline].deadline) {
        task_picks[task.deadline] = task;
      } else {
        task_picks[task.deadline] = task;
      }
    }

    int current = 1;
    for (auto &[time, task] : task_picks) {
      cout << "deadline: " << time
           << "dinheiro: " << task.gain << "\n";
      sum -= task.gain;
      cout << "hour is" << current << "\n";
      if (current >= hours)
        break;
      current++;
    }
    cout << sum << "\n";
  }

  return 0;
}