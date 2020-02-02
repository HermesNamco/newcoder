class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0)
            return -1;

        vector<int> record;			//用数组模拟环，计算下标移除指定位置
        for(int i = 0; i < n;++ i){
            record.push_back(i);
        }
        int step = 0;
        while(record.size() != 1){
            step = (step + m - 1) % n;
            record.erase(record.begin() + step);
            n --;
        }
        return record[0];
    }
};