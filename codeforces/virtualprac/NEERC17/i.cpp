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

vector<pair<int,int> >ranges;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    int j=1;
    ranges.pb(mp(1,n));
    while(1)
    {
        char c;
        for(int i=1;i<=n;i++)
        {
            cout<<"? "<<i<<" "<<j<<endl;
            cin>>c;
            if(c == '<')
                less++;
            else great++;

            fflush(stdout);
        }

    }
	return 0;
}

