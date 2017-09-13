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

/*FINDS THE LONGEST PALINDROMIC SUBSTRING*/

int Max(vi arr,int &s,int &e,int n)/* Finds the length of max palindromic sub-array and its start and end position*/
{
	int ma=0;
        for(int i=0;i<n;i++)
        {
                if(arr[i]>ma)
                {
                        ma=arr[i];
                        s=i-(ma/2);
                        e=i+(ma/2);
                }
        }
	return ma;
}

void printMax(vc A,int s,int e)/* Prints the vector A from index s to index e*/
{
        for(int i=s;i<=e;i++)
        {
                if(A[i]!='$')
                        cout<<A[i];
        }
        cout<<endl;
}

void Manachers(vc A,int n) /* Function to compute the Longest Palindromic Substring */
{
	vi arr(n,0);
	int s=0,e=0;
	int ma=0;
	for(int i=0;i<n;)
	{
		while(s>0 && e<n-1 && A[s-1]==A[e+1])
		{
			s--;
			e++;
		}
		arr[i] = e-s+1;
		if(e==n-1) break;
		bool enter=0;
		int nC=e ;
		if(i%2==0)
			nC++;
		for(int j=i+1;j<=e;j++)
		{
			int rev=i-(j-i);
			arr[j]=min(arr[rev],2*(e-j)+1);
			if(j+arr[rev]/2 == e)
			{
				enter=1;
				i=j;
				s=j-arr[rev]/2;
				e=j+arr[rev]/2;
				break;
			}
		}
		if(!enter)
		{
			i=e+1;
			e=i;
			s=i;
		}	
	}
	ma=Max(arr,s,e,n);
	printMax(A,s,e);
}
int main()
{
	vc C;
	char x;
	int n;
	cin>>n;
	/*'$' is added between every character and at the end to consider the case of EVEN palindromes*/
	C.pb('$');
	for(int i=0;i<n;i++)
	{
		cin>>x;
		C.pb(x);
		C.pb('$');
	}
	Manachers(C,2*n+1);/* Length of array changes to 2n+1 because we add $ at n+1 positions*/

	return 0;
}

