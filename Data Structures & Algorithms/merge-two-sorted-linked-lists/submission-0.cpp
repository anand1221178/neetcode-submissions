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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cm = &dummy;

        ListNode* c1 = list1;
        ListNode* c2 = list2;

        while(c1!= nullptr && c2!=nullptr)
        {
            if(c1->val <= c2->val)
            {
                cm->next = c1;
                c1 = c1->next;
            }
            else
            {
                cm->next = c2;
                c2 = c2->next;
            }

            cm = cm->next;
        }

        if (c1 != nullptr) {
            cm->next = c1;
        } else {
            cm->next = c2;
        }

        return dummy.next;
    }
};
