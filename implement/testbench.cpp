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
    char comm[]={'C','I','K','D'};
    srand(time(NULL));
    int q=200000;
    cout<<q<<endl;
    for(int i=0;i<q;i++)
    {
        cout<<comm[rand()%4]<<" "<<rand()%1000000000<<endl;
    }
	return 0;
}

