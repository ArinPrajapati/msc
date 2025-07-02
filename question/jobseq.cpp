#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct Job {
  char id;
  int deadline;
  int profit;
};

using namespace std;

bool compare(Job a, Job b) { return a.profit > b.profit; }
// [{a,3,100}]
pair<vector<char>, int> jobSequecing(Job jobs[], int n) {
  sort(jobs, jobs + n, compare);

  int maxDeadline = 0;

  for (int i = 0; i < n; i++) {
    maxDeadline = max(maxDeadline, jobs[n].deadline);
  }

  vector<bool> slot(maxDeadline + 1, false);

  vector<char> jobOrder;

  int totalProfit = 0;

  for (int i = 0; i < n; i++) {
    for (int t = jobs[i].deadline; t > 0; t--) {
      if (!slot[t]) {
        slot[t] = true;
        jobOrder.push_back(jobs[i].id);
        totalProfit += jobs[i].profit;
        break;
      }
    }
  }
  return make_pair(jobOrder, totalProfit);
}

int main() {
  Job jobs[] = {
      {'a', 3, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
  int n = sizeof(jobs) / sizeof(jobs[0]);
  pair<vector<char>, int> result = jobSequecing(jobs, n);
  cout << "Job Order: ";
  for (char job : result.first) {
    cout << job << " ";
  }
  cout << "\nTotal Profit: " << result.second << endl;
  return 0;
}
