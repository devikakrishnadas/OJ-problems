#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

void dfs(int a,vi &cap,vector< vector<pair<int,int> > >&G,int j)
{
    if(cap[a]) return;
    cap[a]=1;
    
    for(int i=0;i<G[a].size();i++)
    {
        //if(G[a][i].ss==j)
            dfs(G[a][i].ff,cap,G,j);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vi >A(n+1);
    int mal=0;
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        for(int j=0;j<l;j++)
        {
            int x;
            cin>>x;
            A[i].pb(x);
        }
        mal=max(mal,l);
    }
    vi capitalized(m+1);
    vector<vector<pair<int,int> > >G(m+1);
    vi priority(n+1,0);
    int pri=1;
    /*for(int j=0;j<mal;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(j<A[i].size() && j<A[i-1].size())
            {
            }
            else continue;
            cout<<"r1 "<<A[i-1][j]<<" "<<A[i][j]<<" "<<i<<" "<<j<<endl; 
            if(A[i-1][j]<A[i][j])
            {
                G[A[i][j]].pb(A[i-1][j]);
            }
            else if(A[i-1][j]>A[i][j])
            {
                if(priority[i-1]<priority[i])
                {
                    continue;
                }
                cout<<"enter for "<< A[i-1][j]<<" "<<A[i][j]<<" "<<priority[i]<<" "<<priority[i-1]<<" "<<i<<endl;
                dfs(A[i-1][j],capitalized,G);
                cout<<"exit for "<<capitalized[A[i-1][j]]<<" "<<capitalized[A[i][j]]<<endl;
            }
        }
    }*/
    // Making the Graph
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<min(A[i].size(),A[i-1].size());j++)
        {
            if(A[i-1][j]<A[i][j])
            {
                G[A[i][j]].pb(mp(A[i-1][j],j));
                break;
            }
            /*else if(A[i-1][j]>A[i][j])
            {
            
                //cout<<"enter for "<< A[i-1][j]<<" "<<A[i][j]<<" "<<priority[i]<<" "<<priority[i-1]<<" "<<i<<endl;
                dfs(A[i-1][j],capitalized,G);
                //cout<<"exit for "<<capitalized[A[i-1][j]]<<" "<<capitalized[A[i][j]]<<endl;
            }*/
        }
    }
//    for(int j=0;j<mal;j++)
    for(int i=1;i<n;i++)
    {
        int cnt=0;
        bool enterr=0;
  //      for(int i=1;i<n;i++)
            for(int j=0;j<A[i].size();j++)
        {
            if(j>=A[i-1].size()) continue;
      //      cout<<"hello"<<A[i-1][j]<<" "<<A[i][j]<<endl;
            if(A[i-1][j]<A[i][j])
            {
                //G[A[i][j]].pb(mp(A[i-1][j],j));
                enterr=1;
                break;
            }

            else if(A[i][j]<A[i-1][j] || ( A[i][j]>A[i-1][j] && capitalized[A[i][j]] && !capitalized[A[i-1][j]]))
            {
                if(enterr) continue;

                //cout<<"enter for "<< A[i-1][j]<<" "<<A[i][j]<<" "<<priority[i]<<" "<<priority[i-1]<<" "<<i<<endl;
                
                dfs(A[i-1][j],capitalized,G,j);
                break;
                //cout<<"exit for "<<capitalized[A[i-1][j]]<<" "<<capitalized[A[i][j]]<<endl;
            }
            else
            {
                if(enterr) continue ;
                cnt++;
                if(cnt==min(A[i].size(),A[i-1].size()) && A[i-1].size()>A[i].size())
                {
                    dfs(A[i-1][j],capitalized,G,j);break;
                }
                
            }
        }
    }
    //***********
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<min(A[i].size(),A[i-1].size());j++)
        {
            if(A[i-1][j]<A[i][j] && ((capitalized[A[i-1][j]] && capitalized[A[i][j]]) || (!capitalized[A[i][j]] && !capitalized[A[i-1][j]])))
            {
                //G[A[i][j]].pb(A[i-1][j]);
                break;
            }
            if(A[i][j]<A[i-1][j] && (capitalized[A[i-1][j]] && !capitalized[A[i][j]]))
            {
                break;
            }
  //          if(i==3)
//            {
    //            cout<<A[i-1][j]<<" "<<A[i][j]<<" "<<capitalized[A[i-1][j]]<<" "<<capitalized[A[i][j]]<<endl;
      //      }
            if(A[i-1][j]>A[i][j] && ((capitalized[A[i-1][j]] && capitalized[A[i][j]]) || (!capitalized[A[i][j]] && !capitalized[A[i-1][j]])))
            {
                cout<<A[i-1][j]<<" "<<A[i][j]<<" "<<capitalized[A[i-1][j]]<<" "<<capitalized[A[i][j]]<<endl;
                cout<<"No"<<endl;
                //if(n==100 && m==100) 
//                cout<<"1"<<endl;
                return 0;
            }
            if(A[i][j]>A[i-1][j] && (capitalized[A[i][j]] && !capitalized[A[i-1][j]]))
            {
                cout<<"No"<<endl;
                if(n==100 && m==100)
                cout<<A[i-1][j]<<" "<<A[i][j]<<" "<<capitalized[A[i-1][j]]<<" "<<capitalized[A[i][j]]<<endl;
                //if(n==100 && m==100) 
  //              cout<<"2"<<endl;
                return 0;
            }
            else break;
        }
    }
    cout<<"Yes"<<endl;
    int cntr=0;
    for(int i=1;i<=m;i++)
    {
        if(capitalized[i]) cntr++;
    }
    cout<<cntr<<endl;
    for(int i=1;i<=m;i++)
    {
        if(capitalized[i]) cout<<i<<" ";
    }
    cout<<endl;
	return 0;
}

