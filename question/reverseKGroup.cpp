#include <iostream>


struct Node {
    int val;
    Node* next;

    Node(int val, Node* next) : val(val), next(next) {}
};


class solution{
  public:
  Node* reverseKGroup(Node *head,int k){
    int count = 0;
    Node *node = head;

    
    while(node != nullptr && count < k){
      node= node->next;
      count++;
    }

    if(count == k){
      Node *prev = nullptr;
      Node *curr = head;
      Node *next = nullptr;
      int i = 0;
      while (i<k) {
        next = curr->next;
        curr->next = prev;
        prev  = curr;
        curr = next;
         i++;
      };

      head->next = reverseKGroup(next,k);
      return prev;
    }
    return head;
  }

};

int main(){

  return 0;
}
