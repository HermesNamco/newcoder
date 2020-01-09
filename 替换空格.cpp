class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i = 0;i < length;++ i){		//先统计空格个数，预留空间
            if(*(str + i) == ' ')
                ++ count;
        }
        if(count == 0)
            return;
        char *ptrForward = str + length;	//指向原字符串末尾
        length = length + 2 * count;
        char *ptrBack = str + length;		//指向预留空间后的末尾
        while(ptrForward != ptrBack){
            if(*ptrForward == ' '){
                *ptrBack = '0';
                -- ptrBack;
                *ptrBack = '2';
                -- ptrBack;
                *ptrBack = '%';
            }else
                *ptrBack = *ptrForward;
            -- ptrForward;
            -- ptrBack;
        }
        return;
	}
};