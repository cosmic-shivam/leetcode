/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode* , int>mpp;
        ListNode* tempa=headA;
        ListNode* tempb=headB;

        while (tempa != nullptr) 
        {
        mpp[tempa] = 1;
        tempa = tempa->next;
        }
     // Traverse through list B and check if any node is already in the map
    while (tempb != nullptr) {
        if (mpp.find(tempb) != mpp.end()) {
            return tempb;
        }
        tempb = tempb->next;
    }

    return nullptr;


        
    }
};