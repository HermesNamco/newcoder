class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int flag1 = 0;			//用两个flag表示四种方向
        int flag2 = 1;

        int posX = 0;
        int posY = 0;
        vector<int> result;

        if(matrix.empty())
            return result;
        if(matrix[0].empty())
            return result;

        vector<vector<int>> isPrint(matrix.size(),vector<int>(matrix[0].size(),0));

        while(isPrint[posX][posY] == 0){
            result.push_back(matrix[posX][posY]);
            isPrint[posX][posY] = 1;
            int count = 0;
            if(posY + 1*flag2 == matrix[0].size()){
                flag1 = 1;
                flag2 = 0;
                count ++;
            }
            if(posX + 1*flag1 == matrix.size()){
                flag1 = 0;
                flag2 = -1;
                count ++;
            }
            if(posY + 1*flag2 == -1){
                flag1 = -1;
                flag2 = 0;
                count ++;
            }
            if(count >= 2)		//以免出现只有1个元素时，数组越界
                break;
            if(isPrint[posX + 1*flag1][posY + 1*flag2] == 1 ){
                if(flag1 == 0 && flag2 == 1){
                    flag1 = 1;
                    flag2 = 0;
                }
                else if(flag1 == 1 && flag2 == 0){
                    flag1 = 0;
                    flag2 = -1;
                }
                else if(flag1 == 0 && flag2 == -1){
                    flag1 = -1;
                    flag2 = 0;
                }
                else if(flag1 == -1 && flag2 == 0){
                    flag1 = 0;
                    flag2 = 1;
                }
            }
            posX = posX + 1*flag1;
            posY = posY + 1*flag2;
        }
        return result;
    }
};