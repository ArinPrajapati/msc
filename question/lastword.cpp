#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
  int lengthOfLastWord(string s) {
    int n = s.size();
    if (n == 1 && s[n - 1] != ' '){
      return 1;
    }
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
      cout << "Current character: " << s[i] << endl;

      if (s[i] == ' ' && count > 0) {
        return count;
      }

      if (s[i] != ' ') {
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  string s = "a ";
  int result = sol.lengthOfLastWord(s);
  cout << "Length of last word: " << result << endl; // Output: 5
  return 0;
}
