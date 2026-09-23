#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int children;
  cin >> children;
  int maximum_weight;
  cin >> maximum_weight;
  vector<int> gondola;

  int sum_crianca = 0;
  for (int i = 0; i < children; i++) {
    int weight;
    cin >> weight;
    sum_crianca += weight;
    // supoe-se que nao e possivel dividir uma child em duas
    if (weight <= maximum_weight) {
      gondola.push_back(weight);
    }
  }
  if (sum_crianca == children) {
    // caso especial calculado rapido
    cout << sum_crianca / 2 << "\n";
    return 0;
  }

  // i hate you two pointer algorithm i hate you (and i wanted to do this some other way)
  sort(gondola.begin(), gondola.end());
  vector<pair<int,int>> gondolas_of_hell;
  auto left = gondola.begin();
  auto right = gondola.end() - 1;
  while(left <= right) {
    if(left == right) {
        gondolas_of_hell.push_back(make_pair(*left, *right));
        break;
    }
    if(*left + *right <= maximum_weight) {
        gondolas_of_hell.push_back(make_pair(*left,*right));
        left++;
        right--;    
    }
    else if(*right <= maximum_weight){
        gondolas_of_hell.push_back(make_pair(*right,*right));
        right--;
    }
  }

  cout << gondolas_of_hell.size() << "\n";
  return 0;
}