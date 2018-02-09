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
    int x,h,m;
    cin>>x>>h>>m;
    int curtime = h*60 + m;
    int mi=INT_MAX;
    for(int i=0;i<=24*60;i++)
    {
        if(i>curtime)
        {
            curtime+=(24*60);
        }
        int ch = i/60;
        int cm = i%60;
        if((curtime-i)%x == 0 and (ch%10 == 7 or ch/10 == 7 or cm%10 == 7 or cm/10 == 7))
        {
            mi = min(mi,(curtime - i)/x);
        }
    }
    cout<<mi<<endl;
	return 0;
}

