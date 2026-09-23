#include <bits/stdc++.h>
#include <utility>
using namespace std;
// problema dos infernos
pair<deque<int>, bool> recursive_stacking(deque<int> *target_stack,
                                          deque<int> *og_stack,
                                          deque<int> *final_stack) {

  if (target_stack->empty()) {
    return make_pair(*final_stack, true);
  }
  if (!final_stack->empty() && final_stack->front() == target_stack->back()) {
    final_stack->pop_front();
    target_stack->pop_back();
    return recursive_stacking(target_stack, og_stack, final_stack);
  }
  if (!og_stack->empty() && og_stack->back() == target_stack->back()) {
    og_stack->pop_back();
    target_stack->pop_back();
    return recursive_stacking(target_stack, og_stack, final_stack);
  }
  if (!og_stack->empty()) {
    final_stack->emplace_front(og_stack->back());
    og_stack->pop_back();
    return recursive_stacking(target_stack, og_stack, final_stack);
  }
  return make_pair(*final_stack, false);
}

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    deque<int> coaches;
    for (int i = 1; i <= n; i++) {
      coaches.emplace_front(i);
    }
    
    while (true) {
      deque<int> numbers;
      int element;
      cin >> element;
      if (element == 0) {
        break;
      }
      numbers.emplace_front(element);

      for (int i = 1; i < n; i++) {
        cin >> element;
        numbers.emplace_front(element);
      }

      deque<int> target_copy = numbers;
      deque<int> og_copy = coaches;
      deque<int> station;

      if (recursive_stacking(&target_copy, &og_copy, &station).second) {
        cout << "Yes" << "\n";
      } else {
        cout << "No" << "\n";
      }
    }
    cout << "\n";
  }
  return 0;
}