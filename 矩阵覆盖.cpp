class Solution {
public:
    int rectCover(int number) {		
        if(number == 0)
            return 0;
        int before1 = 1;
        int before2 = 0;
        int result = 0;
        for(int i = 1;i <= number;++ i){		//本质上还是斐波那契数列求解
            result = before1 + before2;
            before2 = before1;
            before1 = result;
        }
        return result;
    }
};

/*
n = 1 的时候
只能横着覆盖，一种
n = 2 的时候
可以横着和竖着覆盖，两种
n = 3 的时候
第三级横着覆盖，用了一级，剩下 n = 2，有两种覆盖方法
第三季竖着覆盖，用了两级，剩下 n = 1，有一种覆盖方法
总共有 3 种
n = 4 的时候
第 4 级横着覆盖，用了一级，剩下 n = 3，有三种覆盖方法
第 4 级竖着覆盖，用了两级，剩下 n = 2，有两种覆盖方法
总共有 5 种方法
n = n 的时候
第 n 级横着覆盖，用了一级，剩下 n = n - 1，所以关注第 n - 1 种有几种覆盖方法
第 n 级竖着覆盖，用了两级，剩下 n = n - 2，所以关注第 n - 2 种有几种覆盖方法
总和为两种情况的总和
*/