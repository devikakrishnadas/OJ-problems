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

void dfs(int a,vector<vi> &G,vi &cap)
{
    cap[a]=1;
    for(int i=0;i<G[a].size();i++)
    {
        dfs(G[a][i],G,cap);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    vi capitalize(m+1,0);
    vector< vi >A(n+1),G(m+1);
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
    }
    //Make graph for all k corresponding to the occurance of the first difference in A[i] & A[i-1]
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(j>=A[i-1].size()) break;
            if(A[i][j]!=A[i-1][j])
            {
                if(A[i][j]>A[i-1][j])
                {
                    G[ A[i][j] ].pb( A[i-1][j] );
                }
                break;
            }
        }
    }
    //Capitalize A[i-1] and all nodes connected to it if A[i-1]>A[i]
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(j>=A[i-1].size()) break;
            if(A[i][j]!=A[i-1][j])
            {
                if(A[i][j]<A[i-1][j])
                {
                    dfs(A[i-1][j],G,capitalize);
                }
                break;
            }
        }
    }
    //Check if the resulting formation is correct
    for(int i=1;i<n;i++)
    {
        int cntr=0;
        for(int j=0;j<A[i].size();j++)
        {
            if(j>=A[i-1].size()) break;
            if(A[i][j]!=A[i-1][j])
            {
                if(A[i-1][j]<A[i][j] && capitalize[A[i][j]] && !capitalize[A[i-1][j]])
                {
//                    cout<<A[i][j]<<" "<<A[i-1][j]<<" "<<capitalize[A[i][j]]<<" "<<capitalize[A[i-1][j]]<<endl;
                    cout<<"No"<<endl;
                    return 0;
                }
                else if(A[i-1][j]>A[i][j] && capitalize[A[i-1][j]]==capitalize[A[i][j]])
                {
//                    cout<<A[i][j]<<" "<<A[i-1][j]<<" "<<capitalize[A[i][j]]<<" "<<capitalize[A[i-1][j]]<<endl;
                    cout<<"No"<<endl;
                    return 0;
                }
                break;
            }
            else cntr++;
        }
        if(cntr==min(A[i].size(),A[i-1].size()))
        {
            if(A[i-1].size()>A[i].size())
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    //count and print the number of letters to be capitalized
    int cnt=0;
    for(int i=0;i<=m;i++)
    {
        if(capitalize[i]) cnt++;
    }
    cout<<"Yes"<<endl<<cnt<<endl;
    for(int i=0;i<=m;i++)
    {
        if(capitalize[i]) cout<<i<<" ";
    }
    cout<<endl;
	return 0;
}
