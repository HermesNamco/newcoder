class Solution {
public:
    bool isNumeric(char* string)
    {
        bool split = false;				//表示是否已经存在E或e
        bool splitPoint = false;		//表示是否已经存在‘.’
        
        if(*string == '+' || *string == '-')
            ++ string;

        while(*string != '\0'){
            if(*string >= '0' && *string <= '9')
                ++ string;
            else if(*string == 'E' || *string == 'e' && split != true){
                ++ string;
                split = true;
                if(*string == '+' || *string == '-')
                    ++ string;
                if(*string == '\0')
                    return false;
            }else if(*string == '.' && split != true && splitPoint != true){
                ++ string;
                splitPoint = true;
                if(*string == '\0')
                    return false;
            }
            else
                return false;
        }
        return true;
    }

};