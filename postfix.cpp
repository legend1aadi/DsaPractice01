#include <iostream>

using namespace std;

class Stack {
private:
    double* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size = 100) {
        capacity = size;
        arr = new double[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(double value) {
        if (topIndex >= capacity - 1) {
            return; // Simple implementation for demo
        }
        arr[++topIndex] = value;
    }

    double pop() {
        if (isEmpty()) {
            throw "Stack is empty";
        }
        return arr[topIndex--];
    }

    double top() {
        if (isEmpty()) {
            throw "Stack is empty";
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }

    void printStack() {
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i];
            if (i < topIndex) cout << " ";
        }
    }
};

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

double evaluate_postfix(const char* expression) {
    Stack stack;
    
    cout << "Expression: " << expression << endl;
    cout << "Tokens to process: " << expression << endl;
    cout << "------------------------------" << endl;
    
    // Simple manual parsing - works for single digit numbers
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ') continue;
        
        if (isDigit(expression[i])) {
            double value = expression[i] - '0';
            stack.push(value);
            cout << "Pushed operand: " << value << " | Stack: ";
            stack.printStack();
            cout << endl;
        }
        else if (isOperator(expression[i])) {
            if (stack.size() < 2) {
                throw "Invalid expression: Insufficient operands";
            }
            
            double operand2 = stack.pop();
            double operand1 = stack.pop();
            double result;
            char op = expression[i];
            
            if (op == '+') {
                result = operand1 + operand2;
            } else if (op == '-') {
                result = operand1 - operand2;
            } else if (op == '*') {
                result = operand1 * operand2;
            } else if (op == '/') {
                if (operand2 == 0) {
                    throw "Cannot divide by zero";
                }
                result = operand1 / operand2;
            } else if (op == '^') {
                result = 1.0;
                for (int j = 0; j < operand2; j++) {
                    result *= operand1;
                }
            }
            
            stack.push(result);
            cout << "Calculated: " << operand1 << " " << op << " " << operand2 << " = " << result << " | Stack: ";
            stack.printStack();
            cout << endl;
        }
        else {
            throw "Invalid token encountered";
        }
    }
    
    cout << "------------------------------" << endl;
    
    if (stack.size() == 1) {
        double final_result = stack.top();
        if (final_result == static_cast<int>(final_result)) {
            return static_cast<int>(final_result);
        }
        return final_result;
    } else {
        throw "Invalid expression: Too many operands or insufficient operators";
    }
}

int main() {
    // Using single-digit numbers for simplicity
    const char* expressions[] = {
        "1 5 +",        // 1 + 5 = 6
        "2 3 1 * + 9 -", // 2 + (3 * 1) - 9 = -4
        "5 1 2 +"       // Should error - too many operands
    };
    
    for (int i = 0; i < 3; i++) {
        try {
            double result = evaluate_postfix(expressions[i]);
            cout << "Result: " << result << "\n" << endl;
        } catch (const char* msg) {
            cout << "Error: " << msg << "\n" << endl;
        }
    }
    
    return 0;
}