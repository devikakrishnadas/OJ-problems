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

bool fact(int a,int b)
{
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0 and i<=b)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int p,y;
    cin>>p>>y;
    for(int i=y;i>p;i--)
    {
        if(!fact(i,p))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
	return 0;
}

