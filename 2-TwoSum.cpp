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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        ListNode *pFirst = NULL;
        ListNode *pTmp = NULL;
        ListNode *pPre = NULL;
        int iFirstIn = 0;
        int iFlag  = 0;
        int iSum;
        int iDigit;
        while((NULL != l1) || (NULL != l2))
        {
            pPre = pTmp;
            pTmp = (ListNode *)malloc(sizeof(ListNode));
            if(0 == iFirstIn)
            {
                pFirst = pTmp;
                iFirstIn = 1;
            }
            else
            {
                pPre->next = pTmp;
            }
            if((NULL != l1) && (NULL != l2))
            {
                iSum = l1->val + l2->val + iFlag;
                l1 = l1->next;
                l2 = l2->next;
                
            }
            else if((NULL != l1) && (NULL == l2))
            {
                iSum = l1->val + iFlag;
                l1 = l1->next;
            }
            else
            {
                iSum = l2->val + iFlag;
                l2 = l2->next;
            }
            iDigit = iSum % 10;
            iFlag = iSum/10;
            pTmp->val = iDigit;
            pTmp->next = NULL;
        }
        if(iFlag == 1)
        {
            pPre = pTmp;
            pTmp = (ListNode *)malloc(sizeof(ListNode));
            pTmp -> val = 1;
            pTmp -> next = NULL;
            pPre -> next = pTmp;
        }
        return pFirst;
        
    }
    
};