class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {		//用开始结束两个标记进行区间搜索
        int start = 1;
        int end = 2;
        vector<vector<int>> result;
        if(sum < 3)
            return result;
        while(end <= sum/2 + 1){
            int temp = (start + end) * (end - start + 1) / 2;
            if(temp == sum){
                vector<int> arr;
                for(int i = start;i <= end; ++ i)
                    arr.push_back(i);
                result.push_back(arr);
                ++ end;
            }else if(temp < sum){
                end ++;
            }else
                start ++;
        }
        return result;
    }
};