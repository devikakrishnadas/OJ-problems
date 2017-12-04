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
    vll b(100,0);

    for(ll i=1;i<=14;i++)
    {
        b[i]=(1<<(i-1))*((1<<i)-1);
    }
    int n;
    cin>>n;
    for(int i=14;i>=1;i--)
    {
        if(n%b[i]==0)
        {
            cout<<b[i]<<endl;
            break;
        }
    }
	return 0;
}

