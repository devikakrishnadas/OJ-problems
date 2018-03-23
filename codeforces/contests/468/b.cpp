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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int tn=0;
    a=a-1;
    b=b-1;
    while(n)
    {
        n=n/2;
        tn++;
    }
    n=tn-1;
    vi aa(n,0),bb(n,0);
    for(int i=0,ta=1;i<n;i++,ta=ta*2)
    {
        aa[i]=(a&ta ? 1 : 0);
        bb[i]=(b&ta ? 1 : 0);
    }
    reverse(all(aa));
    reverse(all(bb));
    if(aa[0] != bb[0])
    {
        cout<<"Final!"<<endl;
    }
    else
    {
        REP(i,n)
        {
            if(aa[i]!=bb[i])
            {
                cout<<n-i<<endl;
                return 0;
            }
        }
    }
	return 0;
}

