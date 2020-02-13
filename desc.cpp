#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("iesire.txt");
const int max_n = 1e6 + 5;
int st[max_n],n,i,s;
void bt(int k){
	if(s == n){
		for(i=1;i<=k-1;++i)
			fout<<st[i]<<" ";
		fout<<endl;}
	else {
		st[k]=0;
		while(st[k]+s<n){
			st[k]++;
			s+=st[k];
			bt(k+1);
			s-=st[k];
		}
	}
}
int main()
{
    cin>>n;
    bt(1);
    fout.close();
}
