class Solution {
public:
    int InversePairs(vector<int> data) {

        long long count = 0;

        vector<int> temp(data.size(),0);
        divide(0,data.size() - 1,data,temp,count);		//归并排序，先分割，再合并，合并途中，统计逆序对
        return count % 1000000007;
    }

    void divide(long long left,long long right,vector<int>& data,vector<int> &temp,long long& count){
        if(left >= right)
            return;
        long long mid = (left + right) / 2;
        divide(left,mid,data,temp,count);
        divide(mid + 1,right,data,temp,count);
        merge(data,left,mid,right,temp,count);
    }

    void merge(vector<int>& data,long long left,long long mid,long long right ,vector<int> &temp,long long& count){

        long long t = left;
        long long i = left;
        long long j = mid + 1;

        while(i <= mid && j <= right){
            if(data[i] < data[j]){
                temp[t] = data[i];
                ++ i;
                ++ t;
            }
            else {
                temp[t] = data[j];
                ++ j;
                ++ t;
                count += mid - i + 1;
            }
        }

        while(i <= mid){
            temp[t] = data[i];
            ++ t;
            ++ i;
        }
        while(j <= right){
            temp[t] = data[j];
            ++ t;
            ++ j;
        }
        for(long long i = left;i <= right;++ i)
            data[i] = temp[i];
        return;
    }
};
