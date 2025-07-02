#include <algorithm>
#include <vector>

using namespace std;

class solution {
public:
  int maxMeeting(vector<int> start, vector<int> end) {

    vector<vector<int>> meeting(2, vector<int>(start.size()));
    for (int i = 0; i < start.size(); i++) {
      meeting[i][0] = start[i];
      meeting[i][1] = end[i];
    }
    sort(meeting.begin(), meeting.end());

    int count = 1;
    int last = meeting[0][1];
    for (int i = 0; i < meeting.size(); i++) {
      if (meeting[i][0] > last) {
        count++;
        last = meeting[i][1];
      }
    }
    return meeting.size();
  }
};
