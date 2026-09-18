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
             bool isPalindrome(ListNode* head) {
                     if (!head || !head->next) return true;

                             // Step 1: Find the middle of the linked list
                                     ListNode* slow = head;
                                             ListNode* fast = head;
                                                     while (fast && fast->next) {
                                                                 slow = slow->next;
                                                                             fast = fast->next->next;
                                                                                     }

                                                                                             // Step 2: Reverse the second half
                                                                                                     ListNode* prev = nullptr;
                                                                                                             while (slow) {
                                                                                                                         ListNode* nextTemp = slow->next;
                                                                                                                                     slow->next = prev;
                                                                                                                                                 prev = slow;
                                                                                                                                                             slow = nextTemp;
                                                                                                                                                                     }

                                                                                                                                                                             // Step 3: Compare the first half and the reversed second half
                                                                                                                                                                                     ListNode* left = head;
                                                                                                                                                                                             ListNode* right = prev;
                                                                                                                                                                                                     while (right) {
                                                                                                                                                                                                                 if (left->val != right->val) return false;
                                                                                                                                                                                                                             left = left->next;
                                                                                                                                                                                                                                         right = right->next;
                                                                                                                                                                                                                                                 }

                                                                                                                                                                                                                                                         return true;
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                             };
                                                                                                                                                                                                                                                             