class Solution {
public:
    long gcd(long a, long b){
        if((a%b)==0){
            return b;
        }else{
            return gcd(b, a%b);
        }
    }

    int minimizeSet(long long div1, long long div2, long long c1, long long c2) {
        long long l=1, h=INT_MAX, mid, ans, a, b, c;

        long long g=gcd(max(div1, div2), min(div1, div2));
        long long lcm=(long(div1)*long(div2))/g;
        while(l<h) {
            long long mid= l + (h-l)/2;
            a=mid-(mid/div1);
            b=mid-(mid/div2);
            c=mid-(mid/div1)-(mid/div2)+(mid/lcm);
            
            if(a>=c1 && b>=c2 && a+b-c>=c1+c2){
                ans=mid;
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
