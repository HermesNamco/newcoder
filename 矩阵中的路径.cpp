class Solution {					
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)		//经典回溯算法，务必记住
    {
       
        bool* flag=new bool[rows*cols];
        memset(flag,false,rows*cols);
        
        for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
               if(search(matrix,rows,cols,i, j,str,0,flag)){
                   return true;
               }
           }
       }
        delete[] flag;
        return false;
    }
    bool search(char* matrix, int rows,int cols,int r,int c,char* str,int count,bool* flag){

        //因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
       int index = r * cols + c;
        //flag[index]==true,说明被访问过了，那么也返回true;
       if(r < 0 || r >= rows || c < 0 || c >= cols || matrix[index] != str[count] || flag[index]==true)
            return false;
        //字符串已经查找结束，说明找到该路径了
       if(str[count + 1]=='\0') 
           return true;
        //向四个方向进行递归查找,向左，向右，向上，向下查找
       flag[index] = true;//标记访问过
       if(  search(matrix, rows, cols, r - 1,      c,     str, count + 1, flag)
          ||search(matrix, rows, cols, r + 1,      c,     str, count + 1, flag)
          ||search(matrix, rows, cols, r    ,  c - 1, str, count + 1, flag)
          ||search(matrix, rows, cols, r    ,  c + 1, str, count + 1, flag))
        {
            return true;
        }
        flag[index] = false;
        return false;
    }
};
