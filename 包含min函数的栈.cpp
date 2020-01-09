class Solution {
public:
    void push(int value) {
        data.push(value);
        sortData.push_back(value);
        sort(sortData.begin(),sortData.end());
    }
    void pop() {
        int temp = data.top();
        data.pop();
        vector<int>::iterator pos = sortData.begin();
        while(pos != sortData.end()){
            if(*pos == temp){
                sortData.erase(pos);
                break;
            }
            ++ pos;
        }
    }
    int top() {
        return data.top();
    }
    int min() {
        return sortData[0];		//直接获取排序后数组头即为栈中最小值
    }
private:
    stack<int> data;
    vector<int> sortData;		//采用一个排序数组实现
};