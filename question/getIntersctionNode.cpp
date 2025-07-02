#include <cstddef>

struct Node {
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {};
};

class Solution {
public:
  Node *getIntersectionNode(Node *headA, Node *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    
  Node* pa = headA; 
  Node* pb = headB;

    
    while(pa != pb){
      pa = pa == nullptr ? headB : pa->next;
      pb = pb == nullptr ? headA : pb->next;
    }

    return pa;
  }
};
