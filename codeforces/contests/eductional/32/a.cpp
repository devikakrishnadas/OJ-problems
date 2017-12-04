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
    int n;
    cin>>n;
    vi a(n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n-1;i++)
    {
        if(a[i]<a[i-1] && a[i]<a[i+1])
            cnt++;
        else if(a[i]>a[i-1] && a[i]>a[i+1])
            cnt++;
    }
    cout<<cnt<<endl;
	return 0;
}

