class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> temp;
        if(input.empty())
            return temp;
        else if(k == 0)
            return temp;
        else if(k > input.size())
            return temp;
        sort(input.begin(),input.end());		//偷懒了，用的STL中sort函数快排
        vector<int> result(input.begin(),input.begin() + k);
        return result;
    }
};