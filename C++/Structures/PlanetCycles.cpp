#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
vector<int>par;
vector<int>vis;
queue<int>q;
vector<int>ans;
bool sac=false;
void dfs(int i)
{
    vis[i]=1;
    q.push(par[i]);
    if(vis[par[i]]==0)
    {
        dfs(par[i]);
    }
    else
    {
        if(ans[par[i]]!=-1)
        {
            sac=true;
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    par.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        cin>>par[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            sac=false;
            q.push(i);
            dfs(i);
            if(sac)
            {
                while(q.size())
                {
                    ans[q.front()]=ans[q.back()]+q.size()-1;
                    q.pop();
                }
            }
            else
        {
            while(q.front()!=q.back())
            {
                 ans[q.front()]=q.size()-1;
                 q.pop();
            }
            int x=q.size()-1;
            while(q.size())
            {
                ans[q.front()]=x;
                q.pop();
            }
        }
        }
        
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    
}
