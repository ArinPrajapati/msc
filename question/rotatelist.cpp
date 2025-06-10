#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *tail = head;
    int l = 1;
    while (tail->next != nullptr) {
      tail = tail->next;
      l+=1;

    }
    k = k % l;
    if(k ==  0 ) return head;
    tail->next= head;

    k = l - k;

    // find new head 
    ListNode* newtail =  head;
    while(k > 0){
      newtail = newtail->next;
      k--;
    }
    ListNode* newHead = newtail->next;
    newtail->next = nullptr;


    return newHead;
  }
};

int main() {

  ListNode *head = new ListNode(0);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  Solution sol;
  ListNode *rotatedHead = sol.rotateRight(head, 3);
  ListNode *current = rotatedHead;
  while (current) {
    cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
  return 0;
}
