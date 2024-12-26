5  You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
●	The valid operators are '+', '-', '*', and '/'.
●	Each operand may be an integer or another expression.
●	The division between two integers always truncates toward zero.
●	There will not be any division by zero.
●	The input represents a valid arithmetic expression in a reverse polish notation.
●	The answer and all the intermediate calculations can be represented in a 32-bit integer.


  #include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

class Solution {
public:
    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const std::string& token : tokens) {
            if (isOperator(token)) {
                // Pop the top two numbers for the operation
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();

                // Perform the operation and push the result back onto the stack
                stack.push(applyOperation(a, b, token));
            } else {
                // Push the number onto the stack
                stack.push(std::stoi(token));
            }
        }

        // The final result will be at the top of the stack
        return stack.top();
    }

private:
    // Check if a string is an operator
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    // Apply an operator to two operands
    int applyOperation(int a, int b, const std::string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        throw std::invalid_argument("Invalid operator");
    }
};

int main() {
    Solution solution;

    // Example input
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    std::cout << "Result: " << solution.evalRPN(tokens) << std::endl;

    // Another example
    tokens = {"4", "13", "5", "/", "+"};
    std::cout << "Result: " << solution.evalRPN(tokens) << std::endl;

    return 0;
}
