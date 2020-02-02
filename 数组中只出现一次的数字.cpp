class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        unordered_map<int ,int> list;
        for(int k = 0;k < data.size();++ k){
            unordered_map<int ,int>::iterator temp = list.find(data[k]);
            if(temp == list.end()){
                list.insert(make_pair(data[k],1));
            }else{
                list.erase(temp);
            }
        }
        int result1 = list.begin()->first;
        int result2 = (++list.begin())->first;
        *num1 = result1;
        *num2 = result2;
    }
};