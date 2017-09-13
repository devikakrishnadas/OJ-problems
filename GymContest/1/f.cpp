#include<bits/stdc++.h>
#define ll unsigned long long
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
    int cnt=0;
    while(t--)
    {
        cnt++;
        ll n,m;
        cin>>n>>m;
        ll r1=(-1+sqrt(1+8*m))/2;
        ll r2=m-((ll)((r1*(r1+1))/2));
        if(r2)
        {
            r2--;
        }
        else
        {
            r2=r1-1;
            r1=r1-1;
        }
        cout<<"Case "<<cnt<<": "<<r1<<" "<<r2<<endl;
    }
	return 0;
}

