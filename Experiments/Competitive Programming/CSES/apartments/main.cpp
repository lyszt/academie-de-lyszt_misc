#include <bits/stdc++.h>
#include <functional>
using namespace std;

class Applicant {
public:
  int desired_upper;
  int desired_lower;
  int size;
  Applicant(int size, int difference) {
    desired_upper = size + difference;
    desired_lower = size - difference;
    this->size = size;
  }
};

bool size_want_comparator(Applicant *a, Applicant *b) {
  if (a->size < b->size)
    return true;
  return false;
};

// distribute the apartments so that as many applicants as possible will get an
// apartment.
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int applicantsqtt, appartmentsqtt, difference;
  cin >> applicantsqtt >> appartmentsqtt >> difference;
  vector<Applicant *> applicants;
  for (int i = 0; i < applicantsqtt; i++) {
    int size;
    cin >> size;
    applicants.push_back(new Applicant(size, difference));
  }
  vector<int> appartments;
  for (int i = 0; i < appartmentsqtt; i++) {
    int app_size;
    cin >> app_size;
    appartments.push_back(app_size);
  }

  sort(appartments.begin(), appartments.end());
  sort(applicants.begin(), applicants.end(), size_want_comparator);
  int winners = 0;
  int i = 0;
  int j = 0;

  while (i < applicantsqtt && j < appartmentsqtt) {
    Applicant *applicant = applicants[i];
    int current = appartments[j];
    if (current < applicant->desired_lower)
      j++;
    else if (current > applicant->desired_upper)
      i++;
    else {
      winners++;
      i++;
      j++;
    }
  }

  cout << winners << "\n";
  return 0;
}