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
    ifstream fin;
    ofstream fout;
    int t;
    cin>>t;
    while(t--)
    {
        int n,ts,tf;
        cin>>n>>ts>>tf;
        vector<pair<pair<int,int>,int> >A;
        for(int i=1;i<n;i++)
        {
            int s,f,d;
            cin>>s>>f>>d;
            A.pb(mp(mp(s,f),d));
        }
        int t=0;
        vi arrivalTime(n+1,0);
        vi isTour(n+1,0);
        
        for(int i=0;i<A.size();i++)
        {
            arrivalTime[i]=t;
            if(i==0)
            {
                t=A[i].ff.ff+A[i].ff.ss;
            }
            else
            {
                int x=(t-A[i].ff.ff)/A[i].ff.ss;
                if((t-A[i].ff.ff)%A[i].ff.ss!=0)
                    x++;
                t=A[i].ff.ss*x + A[i].ff.ff;
            }
        }
        vi endTime(n+1,0);
        arrivalTime[A.size()]=t;
        int mint=0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A.size();j++)
            {
                int tt=arrivalTime[j];
                tt=tt+ts;
                int x=(tt-A[j].ff.ff)/A[j].ff.ss;
                if((tt-A[j].ff.ff)%A[j].ff.ss)
                    x++;
                tt=x*A[j].ff.ss+A[j].ff.ff;
                for(int k=i+1;k<A.size();k++)
                {
                    int xx=(tt-A[k].ff.ff)/(A[k].ff.ss);
                    if((tt-A[k].ff.ff)%A[k].ff.ss)
                        x++;
                    tt=xx*A[k].ff.ss+A[j].ff.ff;
                }
                endTime[j]=tt;
                tt=tt+A[i].ss;
                if(endTime[j]<endTime[mint])
                {
                    mint=j;
                }
            }
            if(endTime[mint]>tf)
            {
                continue;
            }
            int tt=arrivalTime[mint];
            isTour[mint]=1;
            for(int j=mint;j<A.size();j++)
            {
                arrivalTime[j]=tt;
                int x=(tt-A[j].ff.ff)/A[j].ff.ss;
                if((tt-A[j].ff.ff)%A[j].ff.ss)
                    x++;
                tt=x*A[j].ff.ss+A[j].ff.ff;
            }
        }
        int cnt=0;
        for(int i=0;i<A.size();i++)
        {
            if(isTour[i])
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
	return 0;
}

