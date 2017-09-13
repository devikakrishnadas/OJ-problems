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
	ifstream fin;
	ofstream fout;
	fin.open("C-large.txt");
	fout.open("op.txt");
	int t;
	int k=0;
	fin>>t;
	while(t--)
	{
		k++;
		int d,n;
		fin>>d>>n;
		//d=5;
		char A[50][50];
		memset(A, '/', sizeof(A[0][0]) *2500);
		int cnt=0;
		bool no=0;
		for(int i=0;;i++)
		{
			for(int j=0;j<48;j+=3)
			{
			//	cnt++;
				if(cnt==n-1 && i>=2)
				{
					A[i][j]=A[i][j+1]=A[i][j+2]='I';
					cnt++;
				}
				if(cnt==n-2 && i>=(2))
				{
					A[i][j]=A[i][j+1]='I';
					A[i][j+2]='O';
					cnt+=2;
					
				}
				if(cnt==n)
				{
					no=1;
					break;
				}
				A[i][j]='I';
				A[i][j+1]='/';
				A[i][j+2]='O';
				cnt++;
				if(i>=2) cnt+=2;
			}
			if(no)
				break;
		}
		cnt=0;
		fout<<"Case #"<<k<<": "<<endl;
		for(int i=0;i<50;i++)
		{
			for(int j=0;j<50;j++)
			{
				fout<<A[i][j];
			}
			fout<<endl;
		}
	}
	return 0;
}

