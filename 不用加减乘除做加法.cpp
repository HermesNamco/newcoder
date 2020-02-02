class Solution {
public:
    int Add(int num1, int num2)
    {
        int ret = 0;
        int carry = 0;
        do{
            ret = num1 ^ num2;				//先不考虑进位，用异或实现相加

            carry = (num1 & num2) << 1;		//计算进位值

            num1 = ret;
            num2 = carry;					//再次将ret和进位相加	
        }while(num2 != 0);
        return ret;
    }
};
