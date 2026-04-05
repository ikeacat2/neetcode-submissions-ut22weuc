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
    void reorderList(ListNode* head) {
        //0 or 1 elements stay the same
        if((head == nullptr) || (head->next == nullptr)) {
            return;
        }
        ListNode* tail = head;
        //find the tail;
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        //2 elements also stays the same
        if(head->next == tail) {
            return;
        }
        //find the middle 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the second half, list starts at middle
        ListNode* prev = nullptr; 
        ListNode* current = slow->next;
        slow->next = nullptr; //split up the list here (slow = mid point)
        while(current) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        // merge the 2 lists 
        ListNode* ptr1 = head;
        ListNode* ptr2 = prev;
        //every other one goes through each list
        while(ptr2) {
            ListNode* temp1 = ptr1->next;
            ListNode* temp2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = temp1;
            ptr1 = temp1;
            ptr2 = temp2;

        }

    }
};
