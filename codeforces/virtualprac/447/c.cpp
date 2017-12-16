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

vi ans(1000023,0),a(1000023,0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi b;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        b.pb(x);
    }
    int gcd = b[0];
    for(int i=1;i<n;i++)
    {
        gcd = __gcd(gcd,b[i]);
    }
    if(gcd!=b[0])
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<2*n-1<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<b[i]<<" ";
            if(i!=n-1)
            {
                cout<<b[0]<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}

