#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
ll st[800008],arr[200005],brr[200005],bst[800008],pp[200005];
const ll p=29,mod= 1e9+7;
int n,q;
void build_tree(int ss,int se,int si)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        bst[si]=brr[ss];
        return ;
    }
    int mid=(ss+se)/2;
    build_tree(ss,mid,2*si);
    build_tree(mid+1,se,2*si+1);
    st[si]=(st[2*si]+st[2*si+1])%mod;
    bst[si]=(bst[2*si]+bst[2*si+1])%mod;
 
}
ll query_st(int ss,int se,int qs,int qe,int si)
{
     if(qe<ss||se<qs)return 0;
     if(qs<=ss&&se<=qe)return st[si];
     int mid=(ss+se)/2;
     ll l=query_st(ss,mid,qs,qe,2*si);
     ll r=query_st(mid+1,se,qs,qe,2*si+1);
     return (l+r)%mod;
 
}
ll query_bst(int ss,int se,int qs,int qe,int si)
{
     if(qe<ss||se<qs)return 0;
     if(qs<=ss&&se<=qe)return bst[si];
     int mid=(ss+se)/2;
     ll l=query_bst(ss,mid,qs,qe,2*si);
     ll r=query_bst(mid+1,se,qs,qe,2*si+1);
     return (l+r)%mod;
 
}
void update(int ss,int se,int si,int x)
{
     if(ss==se)
     {
         st[si]=arr[ss];
         bst[si]=brr[ss];
         return ;
     }
     int mid=(ss+se)/2;
     if(x<=mid)
    {
         update(ss,mid,2*si,x);
    }
    else
    {
        update(mid+1,se,2*si+1,x);
    }
    st[si]=(st[2*si]+st[2*si+1])%mod;
    bst[si]=(bst[2*si]+bst[2*si+1])%mod;
     
}
bool solve(int a,int b)
{
    int ls,le,rs,re;
    ls=a;
    le=(a+b)/2;
    rs=(a+b+1)/2;
    re=b;
    ll lhs=(((query_st(1,n,rs,re,1))*(pp[n-le]))%mod);
    ll rhs=(((query_bst(1,n,ls,le,1))*(pp[rs-1]))%mod);
    
    return lhs==rhs;
 
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>q;
    string s;
    cin>>s;
    arr[0]=brr[0]=0;
   
    pp[0]=1;
    for(int i=1;i<=n;i++)
    {
        pp[i]=(pp[i-1]*p)%mod;
        arr[i]=(((s[i-1]-'a'+1)*pp[i-1])%mod)%mod;
        
    }
    for(int i=1;i<=n;i++)
    {
        brr[i]=(((s[i-1]-'a'+1)*pp[n-i])%mod)%mod;
 
    }
    build_tree(1,n,1);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;
            char y;
            cin>>x>>y;
            arr[x]=(((y-'a'+1)*pp[x-1])%mod)%mod;
            brr[x]=(((y-'a'+1)*pp[n-x])%mod)%mod;
            update(1,n,1,x);
        }
        else
        {
            int a,b;
            cin>>a>>b;
            (solve(a,b))?cout<<"YES\n":cout<<"NO\n";
        }
    }
    
 
    
}
