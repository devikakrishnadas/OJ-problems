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
    vi a(12);
    for(int i=0;i<12;i++)
    {
        cin>>a[i];
    }
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(all(a));
    reverse(all(a));
    int cnt = 0;
    for(int i=0;i<12;i++)
    {
        cnt++;
        n = n - min(n,a[i]);
        if(n==0)
        {
            cout<<cnt<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
	return 0;
}

