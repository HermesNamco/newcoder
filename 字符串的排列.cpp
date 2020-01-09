class Solution {
public:
    vector<string> Permutation(string str) {	//效率不高
        vector<string> result;
        if(str.empty())
            return result;
        map<string,int> temp;		//使用map避免重复字符串
        per(str,0,temp);
        for(map<string,int>::iterator pos = temp.begin(); pos != temp.end(); ++ pos){
            result.push_back(pos->first);
        }
        return result;
    }
    void per(string str,int start,map<string,int>& temp){	//剑指offer书上的算法
        if(str[start] == '\0'){
            if(temp.find(str) == temp.end())
                temp.insert(make_pair(str,1));
            return;
        }
        for(int i = start;i < str.size();++ i){

            char tempChar = str[start];
            str[start] = str[i];
            str[i] = tempChar;

            per(str,start + 1, temp);

            tempChar = str[start];
            str[start] = str[i];
            str[i] = tempChar;
        }
    }
};