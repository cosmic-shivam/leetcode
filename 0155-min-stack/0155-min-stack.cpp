class MinStack {
public:
stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            // If the stack is empty, push the value along with itself as the minimum
            st.push({val, val});
        } else {
            // Push the value along with the minimum between the current value and the top minimum
            st.push({val, min(val, st.top().second)});
        }
        
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
        
    }
    
    int top() {
         if (!st.empty()) {
            return st.top().first;  // Return the top value
        }
        return -1;  // Return -1 if the stack is empty
    }
    
    int getMin() {
        if (!st.empty()) {
            return st.top().second;  // Return the top minimum
        }
        return -1;  // Return -1 if the stack is empty
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */