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

    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next !=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverse(slow->next);
        ListNode* start=head;
        ListNode* middle=newHead;

        while(middle!=NULL)
        {
            if(start->val != middle->val)
            {
                reverse(newHead);
                return false;
            }
            start=start->next;
            middle=middle->next;
        }
        reverse(newHead);
        return true;

        
    }
};