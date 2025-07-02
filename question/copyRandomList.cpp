#include <cstddef>
#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node *random;

  Node(int x) {
    val = x;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head) {
      return nullptr;
    }

    Node *curr = head;

    while (curr != nullptr) {
      Node *copy = new Node(curr->val);
      copy->next = curr->next;
      curr->next = copy;
      curr = copy->next;
    }
    curr = head;
    while (curr != nullptr) {
      if (curr->random) {
        curr->next->random = curr->random->next;
      }
      curr = curr->next->next;
    }

    curr = head;
    Node *newHead = head->next;
    while (curr) {
      Node *copy = curr->next;
      curr->next = copy->next;
      if (copy->next) {
        copy->next = copy->next->next;
      }
      curr = curr->next;
    }
    return newHead;
  }
};
