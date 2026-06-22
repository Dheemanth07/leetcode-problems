// Last updated: 6/22/2026, 6:29:09 PM
class Solution {
public:
    int sumOfMultiples(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%3==0 || i%5==0 || i%7==0)
                sum+=i;
        }
        return sum;
    }
};