class Solution {
public:
    int cutRope(int number) {							//利用定理，和一样的数差别越小乘积越大，该实现实质为贪心算法
        int slice = 2;									//从将number分成两片来试探
        int mul = 0;
        while(1){
            int res = number % slice;
            vector<int> pices(slice,number / slice);	//先记录个大概值
			int temp = 1;
            for(int i = 0; i < slice; ++ i){			//再用余数加到分片上去
                if(res != 0){
                    pices[i] ++;
                    res --;
                }
                temp = temp * pices[i];
            }
            if(mul < temp)								//易知，乘积曲线为二次函数，当出现乘积下滑时，说明到达峰值
                mul = temp;
            else
                break;
        }
        return mul;
    }
};
//牛客测试运行时间为4ms

class Solution {										//动态规划实现，运行时间也是4ms，内存占用较大
public:
    int cutRope(int number) {
       // n<=3的情况，m>1必须要分段，例如：3必须分成1、2；1、1、1 ，n=3最大分段乘积是2,
        if(number==2)
            return 1;
        if(number==3)
            return 2;
        vector<int> dp (number,0);
        /*
        下面3行是n>=4的情况，跟n<=3不同，4可以分很多段，比如分成1、3，
        这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
         */
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        int res=0;//记录最大的
        for (int i = 4; i <= number; i++) {
            for (int j = 1; j <=i/2 ; j++) {							//只用计算得到i/2，如4，可分为1*3和3*1等效
               res = res > (dp[j]*dp[i-j]) ? res : (dp[j]*dp[i-j]);		//计算之前问题的最优情况，循环计算哪两个分解问题乘积更优
            }
            dp[i]=res;
        }
        return dp[number];
    }
};