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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        bool noAns=0;
        vector<vi>G(n+1),A(n+1);
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            G[x].pb(y);
        }
        cout<<"r1"<<endl;
        for(int i=0;i<=n;i++)
            sort(all(G[i]));
        int cnt=1;
        vi val(n+1,0);
        for(int i=0;i<G[0].size();i++)
        {
            val[G[0][i]]=cnt;
            cnt++;
        }
        
        for(int i=1;i<=n;i++)
        {
            int ptr=i+1;
            if(val[i]==0)
                continue;
            for(int j=0;j<G[i].size();j++)
            {
                if(ptr==i) ptr++;
                if(ptr==G[i][j])
                {
                    ptr++;
                }
                else
                {
                    while(ptr!=G[i][j])
                    {
                        if(val[ptr]!=val[i] && val[ptr]!=0)
                        {
                            noAns=1;
                            cout<<val[ptr]<<" "<<val[i]<<" "<<ptr<<" "<<i<<endl;
                            break;
                        }
                        cout<<ptr<<" "<<G[i][j]<<endl;
                        val[ptr]=val[i];
                        ptr++;
                    }
                }
                if(noAns) break;
            }
            if(noAns) break;
        }
        if(!noAns)
        for(int i=1;i<=n;i++)
        {
            if(val[i]==0)
            {
                noAns=1;
                break;
            }
        }
        cout<<"r2"<<endl;
        if(noAns)
        {
            cout<<-1<<endl; 
            return 0;
        }
        else 
        {
            for(int i=1;i<=n;i++)
            {
                cout<<val[i]<<" ";
            }
            cout<<endl;
        }
    }
	return 0;
}

