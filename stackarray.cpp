#include<bits/stdc++.h>

using namespace std;

class Stack {
private:
    vector<int> stackArray;
public:
    // Push element onto the top of the stack
    void push(int x) {
        stackArray.push_back(x);
    }

    // Remove and return the top element from the stack
    int pop() {
        int top = stackArray.back();
        stackArray.pop_back();
        return top;
    }

    // Get the top element from the stack without removing it
    int top() {
        return stackArray.back();
    }

    // Check if the stack is empty
    bool empty() {
        return stackArray.empty();
    }

    // Get the size of the stack
    int size() {
        return stackArray.size();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << endl; // Output: 3

    stack.pop();

    cout << stack.top() << endl; // Output: 2

    return 0;
}
