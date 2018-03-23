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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main()
{
    int x;
    //cin>>x;
//    sieve();
    sf("%d",&x);
    int i=0;
    int ma=0;
    int tx=x;
    for(int i=2;i<=sqrt(x);i++)
    {
        while(x%i==0)
        {
            ma=max(ma,i);
            x=x/i;
        }
    }

    if(x!=1 and x!=tx)
        ma=max(ma,x);
    x=tx;
    int mi = 10000001;
    int ma2=0;
    for(int i=x-ma+1;i<=x;i++)
    {
        int ti=i;
        ma2=0;
        for(int j=sqrt(i);j>=2;j--)
        {
            while(ti%j==0)
            {
                ma2=max(ma2,j);
                ti=ti/j;
                
            }
        }
        if(ti!=1 and ti!=i) ma2 = max(ma2,ti);
        mi=min(mi,i-ma2+1);
    }
    //cout<<mi<<endl;
    pf("%d\n",mi);
	return 0;
}

