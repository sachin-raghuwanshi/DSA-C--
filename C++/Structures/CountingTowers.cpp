#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
int n;
ll dp[1000005][2];
ll mod=1000000007;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[0][1]=1;
    dp[0][0]=1;
    for(int i=1;i<1e6;i++)
    {
        dp[i][1]=(dp[i-1][0]+2ll*dp[i-1][1])%mod;
        dp[i][0]=(4ll*dp[i-1][0]+dp[i-1][1])%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
    
        cin>>n;
        //cout<<n<<endl;
        //cout<<dp[n-1][0]<<" "<<dp[n-1][1]<<endl;
        cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
        
    }
 
 
    
}
