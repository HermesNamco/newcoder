class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        n && (ret += Sum_Solution(n-1)); 		//此行没有赋值，用&&检查n是否为零，若为零则&&右边不执行直接return ret
        return ret;								//达成递归终止条件，被称为熔断或短路求值
    }
};