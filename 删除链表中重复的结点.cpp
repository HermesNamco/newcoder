class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)		//对开头就重复的情况进行特殊处理，移动pHead
    {													//之后用一个certain指明明确与前后都不重复的节点，再依次检查各个节点
        int reNum = INT_MIN;
        while(pHead != NULL){
            if(pHead -> next != NULL && pHead -> val == pHead -> next -> val){
                reNum = pHead -> val;
                pHead = pHead -> next -> next;
            }else if(pHead -> val == reNum)
                pHead = pHead -> next;
            else
                break;
        }
        if(pHead == NULL)
            return NULL;
        reNum = pHead -> val;
        ListNode* certain = pHead;
        ListNode* p = pHead -> next;
        while(p != NULL){
            if(p -> next != NULL && p -> val == p -> next -> val){
                reNum = p -> val;
                p = p -> next -> next;
                certain -> next = p;
            }else if(p -> val == reNum){
                p = p -> next;
                certain -> next = p;
            }else{
                certain = p;
                p = p -> next;
            }
        }
        return pHead;
    }
};
