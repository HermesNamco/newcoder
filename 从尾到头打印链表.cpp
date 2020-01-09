class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> temp;				//利用栈先进后出的特性实现逆序访问
        ListNode* ptr = head;
        while(ptr){
            temp.push(ptr -> val);
            ptr = ptr -> next;
        }
        //reverse(result.begin(),result.end());
        while(!temp.empty()){
            result.push_back(temp.top());
            temp.pop();
        }
        return result;
    }
};