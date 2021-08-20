#include<bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define INF_ll 1000000000000000007
#define ll long long
#define endl "\n"
#define uint unsigned long long 
#define unmp unordered_map
#define unst unordered_set
#define int long long 
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define line cout << " " << endl


// if needed make stoi function don't rely on that in built function

vector<vector<int>> mul(vector<vector<int>> v1,vector<vector<int>> v2){
	vector<vector<int>> ans(2,vector<int>(2));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			int sum=0;
			for(int k=0;k<2;k++){
				sum=(sum%INF+((v1[i][k]%INF)*(v2[k][j])%INF)%INF)%INF;
			}
			ans[i][j]=sum;
		}
	}
	return ans;
}

vector<vector<int>> fastmultiplication(vector<vector<int>> Matrix,int pow){
	vector<vector<int>> res(2,vector<int>(2));
	for(int i=0;i<2;i++){
		res[i][i]=1;
	}
	vector<vector<int>> matrix={{1},{1}};
	// for(auto x:matrix){
	// 	for(auto y:x){
	// 		cout << y << endl;
	// 	}
	// }
	pow--;
	while(pow>0){
		if(pow%2!=0){
			res=mul(res,Matrix);
			pow--;
		}
		else{
			Matrix=mul(Matrix,Matrix);
			pow=pow/2;
		}
	}
	// for(auto x:res){
	// 	for(auto y:x){
	// 		cout << y << " ";
	// 	}
	// 	cout << " " << endl;
	// }
	res = mul(res,matrix);
	return res;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
    
    int t;
    //t=1;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	vector<vector<int>> Matrix(2,vector<int>(2));
    	Matrix[0][0]=1;
    	Matrix[0][1]=1;
    	Matrix[1][0]=1;
    	Matrix[1][1]=0;

    	vector<vector<int>> matrix = fastmultiplication(Matrix,n);

    	cout << matrix[0][0] << endl;

        

    }
    return 0;
    
}