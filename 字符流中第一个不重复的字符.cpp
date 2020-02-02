class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        res[ch] ++;
        if(res[ch] == 1)
            str.push(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!str.empty()){		//检查一下队列首部是否只出现一次
            if(res[str.front()] == 1)
                return str.front();
            else
                str.pop();
        }
        return '#';
    }
private:
    queue<char> str;		//用一个队列表示各个字符首次出现的顺序
    int res[128];			//用一个128位的数字标识ASCII码能表示的字符出现的个数
};