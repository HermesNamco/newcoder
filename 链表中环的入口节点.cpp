/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)		//毫无技术的做法，用map记录并每次进行查找
    {
        unordered_map<ListNode*,bool> res;			
        while(pHead != NULL){
            if(res.find(pHead) != res.end()){
                return pHead;
            }else
                res.insert(make_pair(pHead,true));
            pHead = pHead -> next;
        }
        return NULL;
    }
};



//先说个定理：两个指针一个fast、一个slow同时从一个链表的头部出发
//fast一次走2步，slow一次走一步，如果该链表有环，两个指针必然在环内相遇
//此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
//这次两个指针一次走一步，相遇的地方就是入口节点。
//这个定理可以自己去网上看看证明。
public class Solution {
    public ListNode EntryNodeOfLoop(ListNode pHead){		//真正优秀的做法，快慢指针搜索
        ListNode fast = pHead;
        ListNode slow = pHead;
        while(fast != null && fast.next !=null){			//让两个指针都走进环中
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow)
                break;
        }
        if(fast == null || fast.next == null)
            return null;
        fast = pHead;										//将两个指针步长都改成一步，可以证明两者必在入口相遇
        while(fast != slow){
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }
}
