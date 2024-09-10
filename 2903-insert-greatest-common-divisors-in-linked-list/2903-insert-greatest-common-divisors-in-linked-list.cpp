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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* curr=head;
        ListNode* nextnode=head->next;

        while(nextnode!=NULL)
        {
            int data=gcd(curr->val,nextnode->val);
            ListNode* temp=new ListNode(data);
            curr->next=temp;
            temp->next=nextnode;
            curr=nextnode;
            nextnode=nextnode->next;
        }
        return head;
        
    }
};