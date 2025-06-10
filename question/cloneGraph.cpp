#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
private:
  Node *cloner(Node *node, unordered_map<Node *, Node *> &map) {
    if (map.count(node) > 0) {
      return map[node];
    }

    Node *copy = new Node(node->val);
    map[node] = copy;

    for (Node *neighbor : node->neighbors) {
      copy->neighbors.push_back(cloner(neighbor, map));
    }

    return copy;
  }

public:
  Node *cloneGraph(Node *node) {
    if(!node){
      return nullptr;
    }
    unordered_map<Node *, Node *> map;
    return cloner(node, map);
  }
};
