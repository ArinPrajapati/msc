#include <bits/stdc++.h>

using namespace std;

struct Node{
  int value;
  Node* next;
};



class functions {

public:

  void insertNode(Node*& node ,int at,Node* newNode){
    Node* temp = node;
    if(at == 0){
      node = newNode;
      node->next = temp;
      return;
    }
    while(at > 1 && temp->next != NULL){
      temp = temp->next;
      at--;
    }
    Node* temp2= temp->next;
    temp->next = newNode;
    newNode->next = temp2;

  };
  void deleteNode(Node* head,int pos){
    if(head == NULL) return;

    if(pos = 0){
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node* temp = head;
    for(int i = 0; i < pos - 1 && temp->next != NULL;i++){
      temp = temp->next;
    }

    if(temp->next == NULL) return;


    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;



  }
  void printerLL(Node* node){
    Node* temp = node;
    while(temp->next != NULL){
      cout << temp->value << "->";
      temp = temp->next;
    }
      cout << temp->value << "::"<< endl;
  }
};

int main(){
  functions fs;

  Node* head;
  head = new Node;
  head->value= 5;
  head->next= NULL;

  Node* second;
  second = new Node;
  second->value = 10;
  second->next = NULL;

  Node* third;
  third = new Node;
  third->value = 15;
  third->next = NULL;


  head->next = second;
  second->next = third;

  fs.printerLL(head);


  Node* newNode;
  newNode = new Node;
  newNode->value = 43;
  newNode->next = NULL;

  fs.insertNode(head, 0, newNode);
  fs.printerLL(head);


  return 0;
}
