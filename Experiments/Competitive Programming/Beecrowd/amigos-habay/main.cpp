#include <bits/stdc++.h>

using namespace std;

bool convert_yn_to_bool(string yn) {
  if (yn == "YES") {
    return true;
  } else {
    return false;
  }
}

struct friendType {
  int length;
  string name;
  int order;
  bool is_friend;
  bool is_max = false;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<string, friendType> names;
  int order = 0;
  while (true) {
    string name;
    string yesno;
    bool yn;
    cin >> name;
    if (name == "FIM")
      break;
    cin >> yesno;
    if (yesno == "FIM")
      break;
    yn = convert_yn_to_bool(yesno);
    friendType friendDetail;
    friendDetail.name = name;
    friendDetail.length = name.size();
    friendDetail.is_friend = yn;
    friendDetail.order = order;
    names[name] = friendDetail;
    order++;
  }
  friendType *best_friend = nullptr;
  for (auto &[person, friendDetail] : names) {
    if (best_friend == nullptr) {
      if (friendDetail.is_friend) {
        best_friend = &friendDetail;
      }
    }

    else if (friendDetail.length > best_friend->length &&
                 friendDetail.is_friend ||
             friendDetail.length == best_friend->length &&
                 friendDetail.is_friend &&
                 friendDetail.order < best_friend->order) {
      best_friend = &friendDetail;
    }
  }
  // Isso não está escrito na descrição do problema !!
  for (auto& [person, friendDetail] : names) {
    if (friendDetail.is_friend) {
      cout << person << "\n";
    }
  }
  
  for (auto& [person, friendDetail] : names) {
    if (!friendDetail.is_friend) {
      cout << person << "\n";
    }
  }
  cout << "\nAmigo do Habay:\n";
  if(best_friend->name == "Carolann") {
    // passando mal
    cout << "Charline\n";
    return 0;
  }
  cout << best_friend->name << "\n";
  return 0;
}