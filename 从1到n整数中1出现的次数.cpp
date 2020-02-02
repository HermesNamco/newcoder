class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)	//双重循环暴力求解，不可取
    {
        int count = 0;
        for(int i = 1; i <= n;++ i){		
            string temp = to_string(i);
            int pos = 0;
            while(pos < temp.size()){
                if(temp.at(pos) == '1')
                    ++ count;
                ++ pos;
            }
        }
        return count;
    }
};
