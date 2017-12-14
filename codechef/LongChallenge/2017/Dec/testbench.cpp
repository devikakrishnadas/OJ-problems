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
    cout<<1<<endl;
    srand(time(NULL));
	int t=1;
    int n=rand()%5+1;
    int m=rand()%5 + 1;
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n+m;i++)
    {
        cout<<rand()%(M)<<" "<<rand()%(M)<<endl;
    }
    return 0;
}

