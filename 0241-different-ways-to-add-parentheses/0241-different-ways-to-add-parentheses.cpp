class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

    // Traverse the expression
    for (int i = 0; i < expression.size(); i++) {
        // If the character is an operator
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            // Split the expression into two parts
            string leftPart = expression.substr(0, i);
            string rightPart = expression.substr(i + 1);

            // Recursively solve for both parts
            vector<int> leftResults = diffWaysToCompute(leftPart);
            vector<int> rightResults = diffWaysToCompute(rightPart);

            // Combine the results based on the operator
            for (int left : leftResults) {
                for (int right : rightResults) {
                    if (expression[i] == '+') {
                        result.push_back(left + right);
                    } else if (expression[i] == '-') {
                        result.push_back(left - right);
                    } else if (expression[i] == '*') {
                        result.push_back(left * right);
                    }
                }
            }
        }
    }

    // Base case: if no operators are present, convert the expression to a number
    if (result.empty()) {
        result.push_back(stoi(expression));
    }

    return result;
    }
};