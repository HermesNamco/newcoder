class Solution {
public:
    void Insert(int num)					// 偷懒求法，面试被锤
    {
        data.push_back(num);
        sort(data.begin(),data.end());				
    }

    double GetMedian()
    {
        if(data.size() & 1)
            med = data[data.size() >> 1];
        else
            med = (double)(data[data.size() >> 1] + data[(data.size() >> 1) - 1]) / 2;
        return med;
    }
private:
    vector<int> data;
    double med;
};
