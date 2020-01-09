class Solution {
public:
    double Power(double base, int exponent) {		//直观解法，效率不高
        if(exponent == 0)
            return 1.0;
        double result = 1.0;
        if(exponent < 0){
            exponent = -1 * exponent;
            base = 1/base;
        }
        for(int i = 0;i < exponent;++ i){
            result = result * base;
        }
        
        return result;
    }
};