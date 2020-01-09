/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {		//遍历两遍，效率较低，第一遍复制next，第二遍找random
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*,RandomListNode*> randomlist;

        if(pHead == NULL)
            return NULL;
        RandomListNode* resultHead = new RandomListNode(pHead -> label);
        RandomListNode* nowNode = resultHead;
        RandomListNode* p = pHead ->next;

        while(p != NULL){
            RandomListNode* temp = new RandomListNode(p ->label);
            nowNode -> next = temp;
            randomlist.insert(make_pair(p,temp));
            nowNode = nowNode -> next;
            p = p -> next;
        }

        p = pHead;
        nowNode = resultHead;

        while(p != NULL){
            map<RandomListNode*,RandomListNode*>::iterator pos = randomlist.find(p -> random);
            if(pos != randomlist.end()){
                nowNode -> random = pos->second;
            }else
                nowNode -> random = NULL;
            nowNode = nowNode->next;
            p = p->next;

        }

        return resultHead;
    }
};