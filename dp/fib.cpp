#include<bits/stdc++.h>
#include <unordered_map>


using namespace std;

class Solution {
private: 
    int fibo(int n , unordered_map<int,int> &memo){
        if(memo[n]){
            return memo[n];
        }
        if(n <= 2) return 1;
        memo[n]  =  fibo(n - 1,memo) + fibo(n - 2,memo);
        return memo[n];
    }
public:
    int fib(int n) {
        unordered_map<int,int> memo;
        return fibo(n,memo);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << sol.fib(n) << endl;
    return 0;
}
