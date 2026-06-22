class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        {
            return 1;
        }
        double initial = x;
        int times = ((n*n)/n);
        
        if(n>0)
        {
            for(int i =0; i<abs(n)-1; i++)
            {
                x=x*initial;
            }
            return x;
        }
        else if(n<0)
        {
            for(int i =0; i<abs(n)-1; i++)
            {
                x=x*initial;
            }
            return 1/x;
        }
    }
};
