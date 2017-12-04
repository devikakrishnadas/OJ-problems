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
    int sum=0;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int maindiff=INT_MAX;
    int cursum=0;
    for(int i=0;i<n;i++)
    {
        cursum=0;
        for(int j=0;j<n;j++)
        {
            cursum+=a[(i+j)%n];
            maindiff=min(maindiff,abs(sum-cursum-cursum));
        }
    }
    cout<<maindiff<<endl;
	return 0;
}

