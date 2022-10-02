#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+2, MOD=1e9+7;
//ax+by=gcd(a,b)
// We require x,y and gcd if we have a and b
// gcd(d,0)=d so, ax+0=a ->x=1 and y=0
struct triplet{
    int x,y,gcd;
};
triplet extendedEuclid(int a, int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallAns=extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd= smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}
signed main(){
    int a,b;
    cin>>a>>b;
    triplet ans= extendedEuclid(a,b);
    cout<<ans.gcd;
    return 0;
}