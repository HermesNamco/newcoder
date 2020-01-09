/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* temp = NULL;
        ListNode* last = NULL;
        while(pHead){
            temp = pHead -> next;
            pHead -> next = last;
            last = pHead;
            pHead = temp;
        }
        return last;
    }
};