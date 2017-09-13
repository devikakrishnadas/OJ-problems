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

bool check(vector<vi> &G,vi &val,int n,int cnt)
{
    //cout<<"r2"<<endl;
    vector<vi>A(n+1);
    for(int i=1;i<=n;i++)
    {
        A[val[i]].pb(i);
    }
    vi ptr(n+1,0);
    vector<vi>G_(n+1);
    //cout<<"r3"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
      //      cout<<"r3.1"<<endl;
            while(A[j][ptr[j]]<=i && ptr[j]<A[j].size())
                ptr[j]++;
        //    cout<<"r3.2"<<endl;
            if(ptr[j]==A[j].size())
                continue;
          //  cout<<"r3.3"<<endl;
            G_[i].pb(A[j][ptr[j]]);
            //cout<<"r3.4"<<endl;
        }
        sort(all(G_[i]));
        sort(all(G[i]));
    }
    //cout<<"r4"<<endl;
    /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            cout<<G[i][j]<<" "<<G_[i][j]<<endl;
        }
    }*/
    if(G_==G)
        return 0;
    //cout<<"r5"<<endl;
    return 1;
}
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
        bool noExist=0;
        vector<vi>Gout(n+1),Gin(n+1);
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            Gout[x].pb(y);
            Gin[y].pb(x);
            if(x>=y)
            {
                noExist=1;
            }
        }
        vi val(n+1,0);
        int values=1;
        if(noExist)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(Gin[i].size()==0)
            {
                noExist=1;
                break;
            }
            sort(all(Gin[i]));
            if(Gin[i][0]==0)
            {
                val[i]=values;
                values++;
            }
            else
            {
                val[i]=val[Gin[i][0]];
            }
        }
//        cout<<"r1"<<endl;
        if(noExist)
        {
            cout<<-1<<endl;
            continue;
        }
        sort(all(Gout[0]));
        
        for(int i=1;i<Gout[0].size();i++)
        {
            int cnt=0;
            for(int j=0;j<Gin[Gout[0][i]].size();j++)
            {
                if(Gin[Gin[Gout[0][i]][j]].size()==0) continue;
                if(Gin[Gin[Gout[0][i]][j]][0]==0)
                {
                    cnt++;
                }
                
            }
            if(cnt<i)
            {
                noExist=1;
                break;
            }
        }
        if(noExist)
        {
            cout<<-1<<endl;
            continue;
        }
       // cout<<"r1"<<endl;
        noExist=check(Gout,val,n,values-1);
       // cout<<"r6"<<endl;
        if(noExist)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }    
	return 0;
}

