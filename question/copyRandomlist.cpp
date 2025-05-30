#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};




class Solution {
public:
    Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> copyof;

    Node* p = head;

    while(p) {
      copyof[p] = new Node(p->val);
      p = p->next;
    }

    p = head;

    while(p){
      Node* c = copyof[p];
      c->next = p->next ? copyof[p->next]:nullptr;
      c->random = p->random ? copyof[p->random]:nullptr;
      p = p->next;
    }

    return copyof[head];

    }
};



int main(){
  Solution n;
  //n.copyRandomList(Node *head)
  return 0;
}
