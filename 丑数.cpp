class Solution {
public:

    int GetUglyNumber_Solution(int index) {	//仿评论区大佬的写法
        vector<int> result(1,1);
        int mul_2 = 0,mul_3 = 0,mul_5 = 0;      //需乘3，5，2的坐标
        if(index <= 1)
            return index;
        while(result.size() < index){

            int x = result[mul_2] * 2;
            int y = result[mul_3] * 3;
            int z = result[mul_5] * 5;

            int temp = min(z,min(x,y));

            if(temp == x)
                ++ mul_2;
            if(temp == y)
                ++ mul_3;
            if(temp == z)
                ++ mul_5;

            result.push_back(temp);


        }
        return result[index - 1];
    }

};