class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(),numbers.end());
        int count = 0;
        int lastNum = 0;
        if(numbers.size() == 0)
            return false;
        for(int i = 0; i < numbers.size(); ++ i){
            if(numbers[i] == 0){
                ++ count;
                lastNum = 0;
            }
            else{
                if(lastNum == 0)
                    lastNum = numbers[i];
                else{
                    if(lastNum + 1 > numbers[i])
                        return false;
                    else if(lastNum + 1 < numbers[i] && count > 0){
                        lastNum = lastNum + 1;
                        -- count;
                        -- i;
                    }else if(lastNum + 1 < numbers[i] && count == 0){
                        return false;
                    }else
                        lastNum = numbers[i];
                }
            }
        }
        return true;
    }
};