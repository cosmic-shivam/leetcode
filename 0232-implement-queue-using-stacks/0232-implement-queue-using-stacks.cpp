class MyQueue {
private:
    std::stack<int> inStack;
    std::stack<int> outStack;

    // Helper function to transfer elements from inStack to outStack
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() { }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            transfer();
        }
        int topElement = outStack.top();
        outStack.pop();
        return topElement;
    }

    int peek() {
        if (outStack.empty()) {
            transfer();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};