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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi l(n),g(n);
        REP(i,n)
        {
            cin>>l[i];
        }
        REP(i,n)
        {
            cin>>g[i];
        }
        bool front=1,back=1;
        REP(i,n)
        {
            front &= (l[i]<=g[i]);
        }
        reverse(all(l));
        REP(i,n)
        {
            back &= (l[i]<=g[i]);
        }
        bool both = front & back;
        if(both)
        {
            cout<<"both"<<endl;
        }
        else if(front)
        {
            cout<<"front"<<endl;
        }
        else if(back)
        {
            cout<<"back"<<endl;
        }
        else
        {
            cout<<"none"<<endl;
        }
    }
	return 0;
}

