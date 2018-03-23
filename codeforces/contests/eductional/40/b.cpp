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

int n;
int ans=INT_MAX;
int A[101][101]={0};
int func(int i, string &s,int cnt,bool done)
{
    int j=0;
    if(i==n)
    {
        return cnt;
    }
    while(s[i+j]==s[j] and j<i and i+j<n)
    {
        j++;
    }
    int a=INT_MAX,b=INT_MAX;
    if(j==i and !done)
    {
        a=func(i+j,s,cnt+1,1);
    }
    if(1){

        b=func(i+1,s,cnt+1,done);
    }
    return min(a,b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    string s;
    cin>>s;
    cout<<func(1,s,1,0)<<endl;
	return 0;
}

