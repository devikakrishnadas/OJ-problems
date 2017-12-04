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

const double PI = 3.14159265358979323846;

int main()
{
    double a, b, c, d;
    cin>>a>>b>>c>>d;
    double rad=sqrt((a-c)*(a-c)+(b-d)*(b-d));
    rad=rad/4;
    double ans=PI*rad*rad*14/3;
    printf("%.15f\n", ans);
	return 0;
}

