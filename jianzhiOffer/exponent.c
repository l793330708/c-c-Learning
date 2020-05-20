 #include <stdio.h>

 double Power(double base, int exponent) {
        double rs = 1;
        if(exponent >0)
        {
            while(exponent>0)
            {
                if(exponent&1) rs = rs * base;
                exponent>>=1;
                base = base * base;
                
            }
            return rs;
        }else{
            exponent*=-1;
            while(exponent>0)
            {
                if(exponent&1) rs = rs * base;
                exponent>>=1;
                base = base * base;
            }
            return 1.0/rs;
        }
       
        
    }
int main()
{
    printf("%f",Power(2,0));
    return 0;
}