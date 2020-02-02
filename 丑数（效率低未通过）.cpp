class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int count = 1;
        long long number = 1;
        if(index == 1)
            return 1;
        while(count < index){
            ++ number;
            bool flag = checkUglyNumber(number);
            if(flag)
                ++ count;
        }
        return number;
    }

    bool checkUglyNumber(int num){

        if(num == 1)
            return true;

        if(num % 2 == 0)
            return checkUglyNumber(num / 2);
        if(num % 3 == 0)
            return checkUglyNumber(num / 3);
        if(num % 5 == 0)
            return checkUglyNumber(num / 5);
        return false;
    }
};