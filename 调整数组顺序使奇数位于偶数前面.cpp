class Solution {
public:
    void reOrderArray(vector<int> &array) {
        bool flag = true;
        int before;
        while(flag){			//冒泡思想
            flag = false;
            before = array[0];
            for(int i = 1;i < array.size();++ i){
                if(before%2 == 0 && array[i]%2 == 1){
                    array[i - 1] = array[i];
                    array[i] = before;
                    flag = true;
                }
                before = array[i];
            }
        }
        return;
    }
};