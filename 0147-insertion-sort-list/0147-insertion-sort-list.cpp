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
    ListNode* insertionSortList(ListNode* head) {
        // Dummy node for the sorted list
        ListNode dummy(0);
        dummy.next = nullptr;

        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;

            // Find correct position in sorted list
            ListNode* prev = &dummy;
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr node
            curr->next = prev->next;
            prev->next = curr;

            // Move forward
            curr = nextNode;
        }

        return dummy.next;
    }
};
