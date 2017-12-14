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
    for(int a=0;a<1000;a++)
    {
        for(int b=0;b<1000;b++)
        {
            int v = 60304 - a*420 - b*659;
            int c = v/994;
            //cout<<a*420 + b*659 + c*994<<endl;
            if(a*420 + b*659 + c*994 == 60304 && c>=0)
            {
                cout<<a<<" "<<b<<" "<<c<<endl;
                break;
            }
            //if(a*420 + b*659 + c*994 > 60304) break;
        }
    }
	return 0;
}

