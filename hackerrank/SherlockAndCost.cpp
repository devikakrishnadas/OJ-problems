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
        ll prev;
        for(int i=n;i>=1;i--)
        {
            int val1=abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]);
            int val2=abs(1-a[i-1]) + abs(a[i+1]-1);
            int val3=abs(a[i]-1) + abs(1-a[i]);
            if(val1 >= val2 && val1 >= val3)
            {
                if(prev +
            }
            else if(val2 >= val1 && val2 >= val3 )
            {
                b[i]=1;
                b[i+1]=a[i+1];
                b[i-1]=a[i-1];
            }
            else
            {
                b[i]=a[i];
                b[i+1]=1;
                b[i-1]=1;
            }
            prev=abs(b[i+1]-b[i])+abs(b[i]-b[i-1]);
        }
    }
	return 0;
}

