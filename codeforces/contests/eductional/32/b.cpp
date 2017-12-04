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
    int l=0,d=0,u=0,r=0;
    string s;
    int n;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
    }
    cout<<2*(min(l,r) + min(u,d))<<endl;
	return 0;
}

