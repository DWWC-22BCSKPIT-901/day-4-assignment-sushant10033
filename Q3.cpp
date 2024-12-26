#include <stack>
#include <iostream>

class MyQueue {
private:
    std::stack<int> inputStack;  // Stack for push operations
    std::stack<int> outputStack; // Stack for pop and peek operations

    
    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    void push(int x) {
        inputStack.push(x);
    }

    
    int pop() {
        transferIfNeeded();
        if (outputStack.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }

    
    int peek() {
        transferIfNeeded();
        if (outputStack.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return outputStack.top();
    }

    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    std::cout << "Peek: " << q.peek() << std::endl; // Output: 1
    std::cout << "Pop: " << q.pop() << std::endl;   // Output: 1
    std::cout << "Empty: " << std::boolalpha << q.empty() << std::endl; // Output: false

    return 0;
}
