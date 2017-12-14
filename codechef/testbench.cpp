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
    srand(time(NULL));
    int n = 100;
    int k = (rand() % n) + n + 1;
    cout<<n<<" "<<k<<endl;
    set<pair<int,int> >a;
    while(a.size()<2*n)
    {
        a.insert(mp(rand()%100000,rand()%100000));
    }
    for(auto p:a)
    {
        cout<<p.ff<<" "<<p.ss<<endl;
    }
	return 0;
}

