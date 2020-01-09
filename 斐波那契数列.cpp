class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int result = (int) ((1.0/sqrt(5))*pow(0.5,n)*(pow(1+sqrt(5),n)-pow(1-sqrt(5),n)));//斐波那契数列第N项通项公式
        return result;
    }
};