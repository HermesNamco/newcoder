class Solution {
public:
     int  NumberOf1(int n) {
         int result = 0;
         for(int i = 0;i < 32;++ i){	//避免了死循环发生，但仅适用于32位int的系统
             if(n & 1 == 1)				//一种优化方案是将1换成flag，对flag左移，左移不会出现死循环，右移对负数来讲左边补1，会发生死循环
                 result ++;
             n = n >> 1;
         }
         return result;
     }
};
/*
最佳答案，详细解析看剑指offer书

public class Solution {
    public int NumberOf1(int n) {
        int count = 0;
        while(n!= 0){
            count++;
            n = n & (n - 1);
         }
        return count;
    }
}
*/
