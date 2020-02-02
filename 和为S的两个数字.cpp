class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {		//两头一起搜索
        int start = 0;
        int end = array.size() - 1;
        vector<int> result;
        while(start < end){
            if(array[start] + array[end] == sum){               
                result.push_back(array[start]);
                result.push_back(array[end]);
                break;
            }else if(array[start] + array[end] < sum){
                ++ start;
            }else
                -- end;
        }
        return result;
    }
};