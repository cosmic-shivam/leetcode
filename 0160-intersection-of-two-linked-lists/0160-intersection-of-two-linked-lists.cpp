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
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        if(headA==NULL || headB==NULL)return NULL;

        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2)return temp1;
            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;



    //     map<ListNode* , int>mpp;
    //     ListNode* tempa=headA;
    //     ListNode* tempb=headB;

    //     while (tempa != nullptr) 
    //     {
    //     mpp[tempa] = 1;
    //     tempa = tempa->next;
    //     }
    //  // Traverse through list B and check if any node is already in the map
    //     while (tempb != nullptr) {
    //     if (mpp.find(tempb) != mpp.end()) {
    //         return tempb;
    //     }
    //     tempb = tempb->next;
    // }

    // return nullptr;


        
    }
};