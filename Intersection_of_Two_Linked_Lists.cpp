/*
  Intersection of Two Linked Lists
  
  Write a program to find the node at which the intersection of two singly
  linked lists begins.

  For example, the following two linked lists:
  A:           a1 ¡ú a2
                    ¨K
                      c1 ¡ú c2 ¡ú c3
                    ¨J            
  B:     b1 ¡ú b2 ¡ú b3
  begin to intersect at node c1.

  Notes:

  If the two linked lists have no intersection at all, return null.
  The linked lists must retain their original structure after the function
  returns.
  You may assume there are no cycles anywhere in the entire linked structure.
  Your code should preferably run in O(n) time and use only O(1) memory.
*/

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
        if (headA == NULL || headB == NULL) return NULL;
        
        // To calculate the number of each list.
        ListNode *nodeA = headA, *nodeB = headB;
        int numA = 1, numB = 1;
        while (nodeA->next) {
            nodeA = nodeA->next;
            numA++;
        }
        while (nodeB->next) {
            nodeB = nodeB->next;
            numB++;
        }
        
        // There is no intersection of these two lists.
        if (nodeA != nodeB) return NULL;
        
        // The longer list will be shorten to the same length as the shorter one.
        for (int i = numA; i < numB; i++) {
            headB = headB->next;
        }
        for (int i = numB; i < numA; i++) {
            headA = headA->next;
        }
        
        // To find the beginning element of the intersection.
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};
