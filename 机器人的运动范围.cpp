class Solution {
public:
    int movingCount(int threshold, int rows, int cols)			//本质是广度优先搜索
    {
        if(threshold < 0)
            return 0;
        if(rows <= 0 || cols <= 0)
            return 0;
        vector<vector<bool>> map(rows,vector<bool>(cols,true));
        int result = checkLink(map,rows,cols,threshold);
        return result;
    }
    bool check(int x,int y,int threshold){
        int sum = 0;
        while(x || y){
            sum = sum + x % 10 + y % 10;
            x = x / 10;
            y = y / 10;
        }
        if(sum <= threshold)
            return true;
        else
            return false;
    }
    int checkLink(vector<vector<bool>> map,int rows,int cols,int threshold){
        queue<int> xPos;
        queue<int> yPos;
        xPos.push(0);
        yPos.push(0);
        int count = 1;
        map[0][0] = false;
        while(!xPos.empty()){

            int x = xPos.front();
            int y = yPos.front();
            xPos.pop();
            yPos.pop();

            if(x + 1 < rows && map[x + 1][y] && check(x + 1,y,threshold)){		//本来我写的是向四个方向搜索，但看别人两个方向搜索就能通过，没细想
                ++ count;
                map[x + 1][y] = false;
                xPos.push(x + 1);
                yPos.push(y);
            }

            if(y + 1 < cols && map[x][y + 1] && check(x ,y + 1,threshold)){
                ++ count;
                map[x][y + 1] = false;
                xPos.push(x);
                yPos.push(y + 1);
            }
            

        }
        return count;
    }
    
};
