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
    freopen("injurious.in","r",stdin);
    freopen("injurious.out","w",stdout);
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    vi b( 2*1313131 + 100,-1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[2*a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(b[(a[i]+a[j])] < j && i<b[(a[i]+a[j])])
            {
                cout<<"Yes"<<endl;
                cout<<i+1<<" "<<b[(a[i]+a[j])]+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
	cin.tie(0);
	cout.tie(0);
	return 0;
}

