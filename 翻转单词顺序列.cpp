class Solution {
public:
    string ReverseSentence(string str) {		//用栈特性进行翻转
        string temp;
        stack<string> rev;
        string result;
        for(int i = 0; i < str.size(); ++ i){
            if(str[i] == ' '){
                rev.push(temp);
                temp.clear();
            }else{
                temp.push_back(str[i]);
            }
        }
        rev.push(temp);
        while(!rev.empty()){
            result.append(rev.top());
            result.push_back(' ');
            rev.pop();
        }
        result.erase(result.end() - 1);
        return result;
    }
};