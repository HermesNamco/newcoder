class Solution {
public:
    string LeftRotateString(string str, int n) {
        for(int i = 0; i < n; ++ i){
            char temp = str[i];
            str.push_back(temp);
        }
        return str.substr(n);
    }
};
