#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int compareVersion(string version1, string version2) {

    int v1start = 0;
    int v2start = 0;
    int v1n = version1.size();
    int v2n = version2.size();

   while (v1start < v1n || v2start < v2n) {
            string v1 = "0", v2 = "0";

            if (v1start < v1n) {
                size_t pos1 = version1.find('.', v1start);
                v1 = (pos1 == string::npos) ? version1.substr(v1start)
                    : (pos1 == v1start) ? "0"
                    : version1.substr(v1start, pos1 - v1start);
                v1start = (pos1 == string::npos) ? v1n : pos1 + 1;
            }

            if (v2start < v2n) {
                size_t pos2 = version2.find('.', v2start);
                v2 = (pos2 == string::npos) ? version2.substr(v2start)
                    : (pos2 == v2start) ? "0"
                    : version2.substr(v2start, pos2 - v2start);
                v2start = (pos2 == string::npos) ? v2n : pos2 + 1;
            }

            cout << "Comparing: " << v1 << " vs " << v2 << endl;

            int num1 = stoi(v1);
            int num2 = stoi(v2);

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }

    return 0;
  }
};

int main() {

  Solution s;
  cout << s.compareVersion("4",
                           "4.969.3.863.960.99661.8.085.769.0.735662509.75003");
  return 0;
}
