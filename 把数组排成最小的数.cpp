class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),com);	//按首位数逐次比较排序
        string result;
        for(int s : numbers){
            result.append(to_string(s));
        }
        return result;
    }
    bool static com(const int &a,const int &b){		//sort 升序排序函数

        string tempA = to_string(a);
        string tempB = to_string(b);

        int indexA = 0;
        int indexB = 0;

        while(true){
            if(tempA.at(indexA) < tempB.at(indexB))
                return true;
            else if(tempA.at(indexA) > tempB.at(indexB))
                return false;
            else{
                ++ indexA;
                ++ indexB;
                if(indexA == tempA.size() && indexB == tempB.size())
                    return true;
                else if(indexA == tempA.size() && indexB < tempB.size())
                    -- indexA;
                else if(indexA < tempA.size() && indexB == tempB.size())
                    -- indexB;
                else
                    continue;
            }
        }
    }
};