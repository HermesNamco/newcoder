class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {		//用unordered_map实现快速查找，效率还是比较低
        unordered_map<int,bool> res;
        for(int i = 0; i < length; ++ i){
            if(res.find(numbers[i]) == res.end()){
                res.insert(make_pair(numbers[i],true));
            }else{
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<bool> res(length,false);						//利用题目数字范围在length内的条件，用数组的每位表示对应数字是否出现过
        for(int i = 0; i < length; ++ i){					//效率较上面做法更高
            if(res[numbers[i]] == false)
                res[numbers[i]] = true;
            else{
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};
