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
    int n=10000;
    srand(time(NULL));
    cout<<n<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<i<<" "<<i-1<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<rand()%100000<<" ";
    }
    cout<<endl;
	return 0;
}

