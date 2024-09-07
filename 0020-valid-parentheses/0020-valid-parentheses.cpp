class Solution {
public:
    bool isValid(string s) {
         stack<char> temp;

       for(char c : s) {
        // Push opening brackets onto the stack
        if(c == '(' || c == '[' || c == '{') {
            temp.push(c);
        }
        // Check for matching closing brackets
        else {
            if(temp.empty()) return false; // If no opening bracket, return false
            char top = temp.top();
            if((c == ')' && top == '(') ||
               (c == ']' && top == '[') ||
               (c == '}' && top == '{')) {
                temp.pop(); // Pop if there's a matching pair
            } else {
                return false; // If there's a mismatch, return false
            }
        }
    }
    // Stack should be empty if all brackets are matched
    return temp.empty();
    }
};