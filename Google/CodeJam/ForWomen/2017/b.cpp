#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

int main()
{
	int t;
	ifstream fin;
	ofstream fout;	
	fin.open("B-large.txt");
	fout.open("op.txt");
	fin>>t;
	int k=0;
	while(t--)
	{
		k++;
		int n;
		fin>>n;
		vector<double>A(2*n+100);
		for(int i=0;i<2*n;i++)
		{
			fin>>A[i];
		}
		sort(A.begin(),A.begin()+2*n);
		//vector<double>ans;
		double fans=1.0;
		for(int i=0,j=2*n-1;i<n;i++,j--)
		{
			//ans.pb(1-(A[i]*A[j]));
			fans*=(1-(A[i]*A[j]));
		}
		fout<<"Case #"<<k<<": "<<fixed<<setprecision(6)<<fans<<endl;
		
	}
	return 0;
}

