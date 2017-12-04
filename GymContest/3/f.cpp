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
    int n,k;
    cin>>n>>k;
    vi a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        
        a[i]+=a[i-1];
    }
    if((2*k)>=n)
    {
        cout<<a[n]<<endl;
        return 0;
    }
    int ma2=0;

    vi maxarr(n+1,0);
    int mat=0;
    for(int i=0,j=k;j<=n;i++,j++)
    {
        mat=max(mat,a[j]-a[i]);
        maxarr[j]=mat;
    }
    for(int i=n-k,j=n;i>=0;i--,j--)
    {
        ma2=max(a[j]-a[i]+maxarr[i],ma2);
    }
    cout<<ma2<<endl;
	return 0;
}

