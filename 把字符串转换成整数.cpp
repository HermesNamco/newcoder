class Solution {
public:
    int StrToInt(string str) {
        int i;
        int flag;
        long long result = 0;
        if(str[0] == '+'){
            flag = 1;
            i = 1;
        }else if(str[0] == '-'){
            flag = -1;
            i = 1;
        }else if(str[0] >= '0' && str[0] <= '9'){
            flag = 1;
            i = 0;
        }else
            return 0;

        for(;i < str.size(); ++ i){
            if(str[i] >= '0' && str[i] <= '9')
                result = (result << 1) + (result << 3) + str[i] - '0';
            else
                return 0;

        }
        if((flag * result) > INT_MAX || (flag * result) < INT_MIN)		//防止出现超出INT范围的情况
            return 0;
        return flag * result;
    }
};
