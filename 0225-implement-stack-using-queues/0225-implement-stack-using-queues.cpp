class MyStack {
private:
    std::vector<int> stack;

public:
    MyStack() { }

    void push(int x) {
        stack.push_back(x);
    }

    int pop() {
        if (!stack.empty()) {
            int topElement = stack.back();
            stack.pop_back();
            return topElement;
        }
        // Handle the case where pop is called on an empty stack
        return -1;  // or throw an exception if preferred
    }

    int top() {
        if (!stack.empty()) {
            return stack.back();
        }
        // Handle the case where top is called on an empty stack
        return -1;  // or throw an exception if preferred
    }

    bool empty() {
        return stack.empty();
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