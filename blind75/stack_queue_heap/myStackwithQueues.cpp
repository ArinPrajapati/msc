#include<queue>

using namespace std;

class MyStack {
private:
    void reverseQueue(queue<int> &q){
        if(q.empty())return;
        int front = q.front();
        q.pop();
        reverseQueue(q);
        q.push(front);
    }
public:
    queue<int> q;
    MyStack() {
       q={}; 
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        reverseQueue(q);
        int front = q.front();
        q.pop();
        reverseQueue(q);
        return front;
    } 
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
