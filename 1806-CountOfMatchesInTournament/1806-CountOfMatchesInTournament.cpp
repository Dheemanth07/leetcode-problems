// Last updated: 6/22/2026, 6:29:45 PM
class Solution {
public:
    int numberOfMatches(int n) {
        int count=0;
        if(n==0) return 0;
        while(n!=1){
            if(n%2==0){
                count+=n/2;
                n/=2;
            }
            if(n%2!=0){
                count+=(n-1)/2;
                n=(n+1)/2;
            }
        }  
        return count;
    }
};