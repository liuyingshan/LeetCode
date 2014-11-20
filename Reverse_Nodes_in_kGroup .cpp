/*
  Given a linked list, reverse the nodes of a linked list k at a time and
  return its modified list.
  If the number of nodes is not a multiple of k then left-out nodes in the
  end should remain as it is.
  You may not alter the values in the nodes, only nodes itself may be
  changed.

  Only constant memory is allowed.

  For example,
  Given this linked list: 1->2->3->4->5
  For k = 2, you should return: 2->1->4->3->5
  For k = 3, you should return: 3->2->1->4->5
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
    // Reverse sub-linked list which starts from head node.
    // preHead's next node is the head node of the reversed sub-linked list.
	// The function returns the tail node of the reversed sub-linked list.
    ListNode *subReverse(ListNode *preHead, ListNode *head, int cnt) {
        if (cnt == 0) {
            preHead->next = head;
        } else {
            subReverse(preHead, head->next, cnt - 1)->next = head;
        }
        return head;
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k <= 1) return head;
        
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *st = newHead, *en, *tail;
        while (st != NULL) {
        	// Check whether last nodes is enough to be reversed. 
            int cnt = 0;
            en = st->next;
            while (cnt < k && en != NULL) {
                ++cnt;
                en = en->next;
            }
            
            if (cnt < k) break;
            tail = subReverse(st, st->next, k-1);
            tail->next = en;
            st = tail;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};
