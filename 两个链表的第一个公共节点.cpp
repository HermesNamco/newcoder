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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {	//单链表具有公共节点就一定具有公共尾部
        vector<ListNode *> p1;
        vector<ListNode *> p2;
        if(pHead1 == NULL)
            return NULL;
        if(pHead2 == NULL)
            return NULL;
        while(pHead1 != NULL){
            p1.push_back(pHead1);
            pHead1 = pHead1->next;
        }
        while(pHead2 != NULL){
            p2.push_back(pHead2);
            pHead2 = pHead2->next;
        }
        for(int i = p1.size() - 1, j = p2.size() - 1;i >= 0,j >= 0;--i, --j){
            if(p1[i] != p2[j]){
                if(i == p1.size() - 1)
                    return NULL;
                else
                    return p1[i + 1];
            }
        }
        return p1.size() < p2.size() ? p1[0] : p2[0];
    }
};