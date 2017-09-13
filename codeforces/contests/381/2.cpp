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


#define INF 1e9

struct Node {
 int offt;
 int cmax;
} ;


Node tree[1000]; //a segment tree is nearly twice as large as the array.
int arr[1000];
void update(int n, int b, int e, int i, int j, int val)
{
 	

 	if (b>=i && e<=j)
 	{
  		tree[n].offt += val;
 	 	tree[n].cmax += val;
  		return;
 	}

  	update(n*2 , b , (b+e)/2 , i , j , val);
 	update(n*2+1 , (b+e)/2 + 1 , e , i , j , val);

  	tree[n].cmax = max ( tree[n*2].cmax , tree[n*2+1].cmax ) + tree[n].offt;
}



void build(int n, int b, int e)
{
 	if (b>e) return;
 	else if (b==e)
 	{
  		tree[n].offt = arr[b];
  		return;
 	}

 	build ( n*2 , b , (b+e)/2 ); //go to children...child nodes of node n are 2n and 2n+1.

	build (n*2+1, (b+e)/2 + 1 , e );

 	//now both child nodes 2n and 2n+1 are built (ie they have done their responsibility of storing the correct information)
 	tree[n].offt = max( tree[n*2].offt , tree[n*2 + 1].offt );

}

int query(int n, int b, int e, int i, int j, int offt)
{
 //	if (b>e || i>j || b>j || e

 	if (b>=i && e<=j)
 		 return tree[n].cmax + offt; //the increment of current node is already added to cmax here (see update function)

 	 offt += tree[n].offt;
	 return max ( query(n*2 , b , (b+e)/2 , i , j, offt) , 
  	 query(n*2+1 , (b+e)/2 + 1 , e , i , j, offt) );
}

int main()
{
	int tc,x,a,b,v;
	int n,m;
	cin>>n>>m;
	// cin >> tc;
	for(int i=0;i<n;i++)
		cin>>arr[i];uild(1,0,n-1);
	while(m--)
 	{
  		cin>> a >> b;
   		update(1,0,n-1,a,b,1);
 	}
	cout << query(1,0,n-1,0,n-1,0) << endl;
	return 0;
}

