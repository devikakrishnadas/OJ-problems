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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n+2,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        vi b(n+3,0);
        vi c(n+3,0);
        for(int i=n;i>=1;i--)
        {
            if(i==n)
            {
                b[i]=1;
                c[i]=a[i];
            }
            else
            {
                b[i]=max(b[i+1],c[i+1]+abs(1-a[i+1]));
                c[i]=max(c[i+1]+abs(a[i+1]-a[i]),b[i+1]+abs(1-a[i]));
            }
        }
        cout<<max(b[1],c[1])<<endl;
    }
	return 0;
}

