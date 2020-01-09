/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {		//书上使用两个指针实现
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        vector<ListNode*> listVal;			//记录所有节点信息
        if(pListHead == NULL)				//考虑空指针情况
            return NULL;
        while(pListHead){
            listVal.push_back(pListHead);
            pListHead = pListHead -> next;
        }
        if(listVal.size() < k)				//考虑总长小于k的情况
            return NULL;
        ListNode* result = listVal[listVal.size() - k];
        return result;
    } 
};		//仍未考虑k = 0的情况