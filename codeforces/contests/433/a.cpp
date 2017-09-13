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
    int num=n/2;
    int den=n-num;
    if(num==den)
    {
        num--;
        den++;
    }
    for(int i=num,j=den;i>=1;i--,j++)
    {
        if(__gcd(i,j)==1)
        {
            cout<<i<<" "<<j<<endl;
            return 0;
        }
    }
	return 0;
}

