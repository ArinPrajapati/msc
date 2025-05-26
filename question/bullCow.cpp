#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string getHint(string secret, string guess) {
    if (secret.size() != guess.size())
      return "";

    unordered_map<char, int> map;
    int cow = 0;
    int bull = 0;
    for (size_t i = 0; i < secret.size(); i++) {
      if (map.find(secret[i]) == map.end()) {
        map[secret[i]] = 0;
      }
      map[secret[i]]++;
    }

    for (size_t i = 0; i < guess.size(); i++) {
      if (guess[i] != secret[i]) {
        if (map.find(guess[i]) != map.end()) {
          if (map[guess[i]] != 0) {
            map[guess[i]]--;
            cow++;
          }
        }
      } else {
        if (map[guess[i]] == 0) {
          cow--;
          bull++;
        } else {
          map[guess[i]]--;
          bull++;
        }
      }
    }

    return to_string(bull) + "A" + to_string(cow) + "B";
  }
};

int main() {
  Solution s;
  cout << s.getHint("1807", "7810");
  return 0;
}
