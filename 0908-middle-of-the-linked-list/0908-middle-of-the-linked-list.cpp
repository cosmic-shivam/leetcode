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
    ListNode* middleNode(ListNode* head) {
        
         // Initialize two pointers, slow and fast
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Move slow pointer by one and fast pointer by two nodes at a time
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // When fast reaches the end, slow will be at the middle
    return slow;
    }
};