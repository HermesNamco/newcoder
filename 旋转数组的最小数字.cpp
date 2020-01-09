class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int beforeNum = INT_MIN;
        if(rotateArray.empty())			//针对数组size为0的情况
            return 0;
        for(int i = 0;i < rotateArray.size();++ i){
            if(rotateArray[i] < beforeNum)
                return rotateArray[i];
            beforeNum = rotateArray[i];
        }
        return beforeNum;				//针对数组size1为1的情况
    }
};