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
        //if one of the lists is empty, return the other list
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        //sort 
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* merged;
        if(temp1->val > temp2->val) {
            merged = list2;
            if(temp2-> next == nullptr) {
                temp2 = nullptr;
            }
            else {
                temp2 = temp2->next;
            }
        }
        else {
            merged = list1;
            if(temp1->next == nullptr) {
                temp1 = nullptr;
            }
            else {
                temp1 = temp1->next;
            }
        }
        ListNode* currentMerged = merged;
        
        while (temp1 != nullptr || temp2 != nullptr) {
            if (temp1 == nullptr) {
                currentMerged->next = temp2;
                break;
            }
            if (temp2 == nullptr) {
                currentMerged->next = temp1;
                break;
            }
            if (temp1->val > temp2->val) {
                currentMerged->next = temp2;
                temp2 = temp2->next;
            } else {
                currentMerged->next = temp1;
                temp1 = temp1->next;
            }
            currentMerged = currentMerged->next;
        }
        return merged;
    }
};
