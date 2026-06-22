// Last updated: 6/22/2026, 6:29:04 PM
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=0,num2=0,sum=0,bsum=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0)
                sum+=i;
            else
                bsum+=i;
        }
        return sum-bsum;
    }
};