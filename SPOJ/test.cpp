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
    int t=1000000; //rand()%1000;
    ofstream fout;
    fout.open("testfile.txt");
    fout<<t<<endl;
    for(int i=0;i<t;i++)
    {
        int a=rand()%100001;
        int b=rand()%100001;
        int c=rand()%100001;
        fout<<a<<" "<<b<<" "<<c<<endl;
    }
	return 0;
}

