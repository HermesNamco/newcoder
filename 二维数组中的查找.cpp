class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = 0;
        int col = array[0].size() - 1;
        while(!array.empty() && col >= 0 && row < array.size()){
            if(target == array[row][col])
                return true;
            if(target > array[row][col])
                ++ row;
            else
                -- col;
        }
        return false;
    }
};
//从右上角开始遍历可以减少判断情况
