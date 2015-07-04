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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *cur = head;
        ListNode *pre;
        ListNode *tmp = head;
        ListNode *preTmp;
        int len = 0;
        if(NULL == head)
        {
            return NULL;
        }
        while(tmp != NULL)
        {
            tmp = tmp -> next;
            len++;
        }
        tmp = head;
        k = k%len;
        if(0 == k)
        {
            return head;
        }
        while(k > 0)
        {
            preTmp = tmp;
            tmp = tmp->next;
            k--;
        }
        if(NULL == tmp)
        {
            return head;
        }
        while(NULL != tmp)
        {
            pre = cur;
            cur = cur->next;
            preTmp = tmp;
            tmp = tmp->next;
        }
        pre->next = NULL;
        preTmp->next = head;
        return cur;
        
        
        
    }
};