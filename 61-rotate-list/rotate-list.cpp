 class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or single node
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

         
        int length = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

         
        k = k % length;

         
        if (k == 0)
            return head;

         
        tail->next = head;

         
        int steps = length - k;

        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // New head is after new tail
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};