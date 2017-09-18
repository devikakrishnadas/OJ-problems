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
        if(n%2)
        {
            int temp=n/2;
            for(int i=n/2 +1 ;i<= n+n/2;i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int i=n/2;i< n+n/2; i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
	return 0;
}

