#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
  int boots;
  while (cin >> boots) {
    unordered_map<char, unordered_map<int, stack<int>>> shoes;
    int pairs = 0;
    int size;
    char side;
    for (int i = 0; i < boots; i++) {
      cin >> size >> side;
      shoes[side][size].emplace(size);
      switch (side) {
      case 'E':
        if (!shoes['D'][size].empty()) {
          shoes[side][size].pop();
          shoes['D'][size].pop();
          pairs++;
        }
        break;
      case 'D':
        if (!shoes['E'][size].empty()) {
          shoes[side][size].pop();
          shoes['E'][size].pop();
          pairs++;
        }
        break;
      default:
        break;
      }
    }
    cout << pairs << "\n";
  }

  return 0;
}