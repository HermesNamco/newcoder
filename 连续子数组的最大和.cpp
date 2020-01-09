class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {	//二重循环，效率低
        if(array.empty())
            return 0;
        if(array.size() == 1)
            return array[0];
        int max = INT_MIN;
        int sum = 0;
        vector<vector<int>> log(array.size(),vector<int>(array.size(),0));	//log[i][j]记录了从i到j的总和
        for(int i = 0;i < array.size();++ i){
            sum = sum + array[i];
            if(sum > max)
                max = sum;
            log[0][i] = sum;
        }
        
        for(int i = 1;i < array.size();++ i){
            for(int j = i;j < array.size();++ j){
                log[i][j] = log[0][j] - log[0][i - 1];
                if(log[i][j] > max)
                    max = log[i][j];
            }
        }
        return max;
    }
};