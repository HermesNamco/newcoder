class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int,int> count;
        map<int,int>::iterator temp;
        int size = numbers.size();
        for(int i = 0;i < size;++ i){
            temp = count.find(numbers[i]);
            if(temp == count.end()){
                count.insert(make_pair(numbers[i],1));
                temp = count.find(numbers[i]);
            }
            else {
                temp->second ++;
            }
            if(temp -> second > size/2)
                return temp -> first;
        }
        return 0;
    }
};