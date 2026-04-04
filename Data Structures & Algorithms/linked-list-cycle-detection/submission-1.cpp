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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) {
            return false;
        }
        set<ListNode*> myset;
        ListNode* current = head;
        while(current->next != nullptr) {
            if(myset.contains(current)) {
                return true;
            }
            else {
                myset.insert(current);
            }
            current = current->next;
        }
        return false;
    }
};
