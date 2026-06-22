// Last updated: 6/22/2026, 6:30:09 PM
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,product=1;
        while(n!=0){
            sum+=n%10;
            product*=n%10;
            n/=10;
        }
        return product-sum;

    }
};