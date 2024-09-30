class CustomStack {
    private:
    vector<int> stack;   // Vector to hold the stack elements
    int maxSize;         // Maximum size of the stack
    public:
    CustomStack(int maxSize) {
      this->maxSize = maxSize;   
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {  // Only push if stack has not reached maxSize
            stack.push_back(x);
        }
        
    }
    
    int pop() {
        if (stack.empty()) {
        return -1;  // Return -1 if stack is empty
        }
        int topElement = stack.back();  // Get the top element
        stack.pop_back();  // Remove the top element
        return topElement;
        
    }
    
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());  // Increment the first 'k' elements or all if k > stack size
        for (int i = 0; i < limit; ++i) {
            stack[i] += val;  // Increment each element
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */