#include<bits/stdc++.h>
using namespace std;
int N=200004;
int maxn=20;
int dp[200004][21];
int k[200004],level[200004];
int result (int x,int y)
{
    if(y<=0)
        return x;
    for(int i=0;i<=maxn;i++)
    {
        if((1<<i)&y)
        {
            x=dp[x][i];
        }
    }
    return x;
}
void dfs(int i)
{
    k[i]=1;
    if(k[dp[i][0]]==0)
    {
        dfs(dp[i][0]);
    }
 
    level[i]=level[dp[i][0]]+1;
    //cout<<i<<" "<<level[i]<<endl;
    //cout<<i<<" "<<dp[i][0]<<endl;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>dp[i][0];
    }
    for(int i=1;i<=maxn;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
 
    for(int i=1;i<=n;i++)
    {
        if(k[i]==0)
        {
            dfs(i);
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        //cout<<a<<"f "<<b<<endl;
        //cout<<level[a]<<" y"<<level[b]<<endl;
        //cout<<result(a,level[a]-level[b])<<endl;
        //cout<<dp[a][1]<<endl;
        if(result(a,level[a]-level[b])==b)
        {
            cout<<level[a]-level[b]<<endl;
        }
        else if(result(result(a,level[a]),level[result(a,level[a])]-level[b])==b)
        {
            cout<<level[a]+level[result(a,level[a])]-level[b]<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}
