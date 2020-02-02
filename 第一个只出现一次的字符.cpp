class Solution {
public:
    int FirstNotRepeatingChar(string str) {		//O(n)复杂度，效率高于leetcode.初级算法.字符串中的版本
        
        if(str.empty())
            return -1;
        
        vector<int> charactor(58,0);		//区分大小写，用ASCII码 - 65作为下标
        int count = 0;
        
        string::iterator index = str.begin();
        
        while(index != str.end()){
            ++ charactor[*index - 65];
            ++ index;
        }
        for(int i = 0;i < str.size();++ i){
            if(charactor[str[i] - 65] == 1)
                return i;
        }
        return -1;

    }
};