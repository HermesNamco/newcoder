/*解法不直观，本地测试通过，牛客上发生段错误
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;

        if(pHead1 -> val >= pHead2 -> val){
            p1 = pHead1;
            p2 = pHead2;
        }else{
            p2 = pHead1;
            p1 = pHead2;
        }

        if(pHead2 == NULL)
            return pHead1;
        if(pHead1 == NULL)
            return pHead2;

        
        while(p1 && p2 -> next){

            if(p1 -> val < p2 -> next -> val){
                temp2 = p2 -> next;
                p2 -> next = p1;
                temp1 = p1 -> next;
                p1 -> next = temp2;
                p1 = temp1;
            }
            p2 = p2 -> next;
        }
        if(p2 -> next == NULL ){
            p2 -> next = p1;
        }
        if(pHead1 -> val >= pHead2 -> val)
            return pHead2;
        else
            return pHead1;
    }
};
*/
/*更清晰的思路，同样本地测试样例通过，牛客同一样例未通过
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* p = new ListNode(INT_MIN);
        p -> next = NULL;
        ListNode* root = p;
        
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1 <= pHead2){
                p -> next = pHead1;
                pHead1 = pHead1 -> next;
                p = p -> next;
            }else{
                p -> next = pHead2;
                pHead2 = pHead2 -> next;
                p = p -> next;
            }
        }
        if(pHead1 != NULL){
            p -> next = pHead1;
        }
        if(pHead2 != NULL){
            p -> next = pHead2;
        }
        return root -> next;
    }
};
*/
//通过的代码
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* result = NULL;
        ListNode* current = NULL;
         
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;

        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val <= pHead2->val){
                if(result == NULL){
                    current = result = pHead1;
                } else {
                    current->next = pHead1;
                    current = current->next;
                }
                pHead1 = pHead1->next;
            } else {
                if(result == NULL){
                    current = result = pHead2;
                } else {
                    current->next = pHead2;
                    current = current->next;
                }
                pHead2 = pHead2->next;
            }
        }
         
        if(pHead1 == NULL){
            current->next = pHead2;
        }
        if(pHead2 == NULL){
            current->next = pHead1;
        }
         
        return result;
    }
};