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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return nullptr;
        }
        //find count 
        int count = 0;
        ListNode* Nnode = head;
        while(Nnode != nullptr) {
            Nnode = Nnode->next;
            count++;
        }
        Nnode = head;
        count = count-n;
        if(count == 0) {
            head = head->next;
            return head;
        }
        for(int i = 0; i < count; i++) {
            Nnode = Nnode->next;
        }
        ListNode* nextNode = Nnode->next;
        Nnode = nullptr;
        ListNode* prevNode = head;
        for(int i = 0; i < count-1; i++) {
            prevNode = prevNode->next;
        }
        prevNode->next = nextNode;
        return head;
    }
};
