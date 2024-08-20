/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* dummy = new ListNode(-1); // Dummy node to start the result list
    ListNode* temp = dummy; // Pointer to construct the result list
    int carry = 0; // Carry value

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry; // Start with the carry from the last iteration
        
        if (l1 != NULL) {
            sum += l1->val; // Add value from the first list
            l1 = l1->next; // Move to the next node in l1
        }
        if (l2 != NULL) {
            sum += l2->val; // Add value from the second list
            l2 = l2->next; // Move to the next node in l2
        }
        
        carry = sum / 10; // Calculate new carry
        sum = sum % 10; // Keep the single digit as the current node's value
        
        temp->next = new ListNode(sum); // Create a new node with the sum value
        temp = temp->next; // Move to the next position in the result list
    }
    
    return dummy->next; 
    }
};