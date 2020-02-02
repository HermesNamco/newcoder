class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if(size <= 0){														//空窗的情况
            vector<int> result;
            return result;
        }
        vector<int> result(num.size() - size + 1,INT_MIN);					
        for(int i = 0; i < num.size(); ++ i){
            fill(result, num[i],i,size);									//fill可以自行处理窗口大于num.size()的情况
        }
        return result;
    }
    void fill(vector<int>& res, int data, int pos,int size){				//滑动窗口，尝试将窗口内染成自己的颜色，遇到更大的数就染成更重的颜色
        for(int i = pos - size + 1; i <= pos ; ++ i){
            if(i < 0 || i >= res.size())
                continue;
            if(res[i] < data)
                res[i] = data;
        }
    }
};