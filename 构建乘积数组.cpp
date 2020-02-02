class Solution {
public:
    vector<int> multiply(const vector<int>& A) {		//循环两次，将题目乘法拆分成两部分，即该数左边的乘积和右边的乘积分别计算
        vector<int> result(A.size(),1);
        int mul = 1;
        for(int i = 0; i < A.size() - 1; ++ i){
            mul *= A[i];
            result[i + 1] = mul;
        }
        mul = 1;
        for(int i = A.size() - 1; i > 0; -- i){
            mul *= A[i];
            result[i - 1] *= mul;
        }
        return result;
    }
};