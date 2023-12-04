#include <bits/stdc++.h> 
using namespace std; 

bool grid[36][36]; 
char ans[36]; 
bool again=0; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	for (int i=0; i<36; ++i) ans[i]='*';

	int p1, m1, p2, m2, t;
	cin>>p1>>m1>>p2>>m2>>t; 
	--p1, --p2; 
	int turn=0; 
	for (int i=1; i<=t; ++i) {
		//cout<<'\n';
		//cout<<i<<' '<<turn<<'\n';
		if (turn==0) {
			bool played=0; 
			int cnt=0; 
			while (!played) {
				if (!cnt) {p1+=m1; p1%=36;} 
				else {p1=(p1+1)%36;} 
				++cnt;
				for (int x : {-6, 1, 6, -1}) {
					if (x==-6) {
						if (p1-6<0) continue; 	
					}
					if (x==1) {
						if (p1%6==5) continue; 
					}
					if (x==6) {
						if (p1+6>35) continue; 	
					}
					if (x==-1) {
						if (p1%6==0) continue; 
					}
					int n=p1+x; 	
					if (n>=0&&n<36&&!grid[p1][n]&&!grid[n][p1]) {
						//cout<<p1<<' '<<n<<'\n';
						grid[p1][n]=1; 
						grid[n][p1]=1; 
						// now check if that completed a square 
						for (int a=0; a<36; ++a) {
							if (ans[a]!='*') continue; 
							if (a%6==5) continue; 
							if (a+6>35) continue; 
							if ((a+6)%6==5) continue; 
							if (a+7>35) continue; 
							if (grid[a][a+1]&&grid[a][a+6]&&grid[a+6][a+7]&&grid[a+1][a+7]) {
								// completed a square!
								ans[a]='X';
								again=1; 
							}
						}
						played=1; 
						break; 
					}
				}
			}
		} else {
			bool played=0; 
			int cnt=0;  
			while (!played) {
				if (!cnt) {p2+=m2; p2%=36;} 
				else p2=(p2+1)%36; 
				++cnt; 
				for (int x : {-6, -1, 6, 1}) {
					if (x==-6) {
						if (p2-6<0) continue; 	
					}
					if (x==1) {
						if (p2%6==5) continue; 
					}
					if (x==6) {
						if (p2+6>35) continue; 	
					}
					if (x==-1) {
						if (p2%6==0) continue; 
					}
					int n=p2+x; 	
					if (n>=0&&n<36&&!grid[p2][n]&&!grid[n][p2]) {
						//cout<<p2<<' '<<n<<'\n';
						grid[p2][n]=1; 
						grid[n][p2]=1; 
						// now check if that completed a square 
						for (int a=0; a<36; ++a) {
							if (ans[a]!='*') continue; 
							if (a%6==5) continue; 
							if (a+6>35) continue; 
							if ((a+6)%6==5) continue; 
							if (a+7>35) continue; 
							if (grid[a][a+1]&&grid[a][a+6]&&grid[a+6][a+7]&&grid[a+1][a+7]) {
								// completed a square!
								ans[a]='O';
								again=1; 
							}
						}
						played=1; 
						break; 
					}
				}
			}

		}
		if (!again) {
			turn=!turn; 
		} else {
			again=0; 
		}
	}
	int pt0=0, pt1=0; 
	for (int i=0; i<36; ++i) {
		if (i==30) break; 
		if (i%6==5) {
			cout<<'\n';
			continue; 
		}
		cout<<ans[i]<<' ';
		if (ans[i]=='X') ++pt0; 
		if (ans[i]=='O') ++pt1; 
	}
	cout<<pt0<<' '<<pt1<<'\n';

	return 0; 
}
