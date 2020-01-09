class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> result;
        result.push_back(1);
        result.push_back(1);
        if(number == 1)
            return 1;
        for(int i = 1;i < number;++ i){		//正确的算法，每一项都是前n-1项的和
            int pushNum = 0;
            for(int j = 0;j <= i;++ j)
                pushNum = pushNum + result[j];
            result.push_back(pushNum);
        }
        /*for(int i = 0;i < number;++ i){
            if(i == 0)
                result = result + 1;
            else if(i == 1)
                result = result + 1;
            else
                result = result + (int) ((1.0/sqrt(5))*pow(0.5,i + 1)*(pow(1+sqrt(5),i + 1)-pow(1-sqrt(5),i + 1)));	//错误的解法
        }*/
        return result[number];
    }
};