class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {	//分别二分查找上下界，找的后两者相减求出
        int first = getFirstK(data ,k);
        int last = getLastK(data ,k);
        return last - first + 1;				
    }
    int getFirstK(vector<int> data ,int k){	//只适用于升序排序数字，降序需更改判别条件
        int start = 0;
        int end = data.size() - 1;
        int mid = (start + end) / 2;
        while(start <= end){
            if(data[mid] >= k){
                end = mid - 1;
                mid = (start + end) / 2;
            }else{
                start = mid + 1;
                mid = (start + end) / 2;
            }
        }
        return start;
    }
    int getLastK(vector<int> data ,int k){
        int start = 0;
        int end = data.size() - 1;
        int mid = (start + end) / 2;
        while(start <= end){
            if(data[mid] > k){
                end = mid - 1;
                mid = (start + end) / 2;
            }else{
                start = mid + 1;
                mid = (start + end) / 2;
            }
        }
        return end;
    }
};
