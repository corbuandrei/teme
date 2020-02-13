#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
const int max_n = 1e6;
int n,v[max_n],sol;
ofstream fout("iesire.txt");
void afisare(){
	int i,j; 
	sol++; 
	fout<<"\n Solutia: "<<sol<<'\n'; 
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) 
			if (v[i]==j) 
				fout<<"D "; 
			else fout<<"* "; 
	fout<<'\n'; 
	} 
} 
int valid(int k) {
	int i; 
	for (i=1;i<=k-1;i++) 
		if ((v[i]==v[k])||(abs(v[k]-v[i])==(k-i))) 
			return 0; 
	return 1;
}
int solutie(int k) {
	return (k == n);
} 
void BK(int k) {
	int i; 
	for (i=1;i<=n;i++){ 
		v[k]=i; 
		if (valid(k)==1){ 
			if (solutie(k)==1) 
				afisare();
			else 
				BK(k+1); 
		} 
	} 
} 
int main() {
	cout<<"n= ";cin>>n;
	BK(1);
	fout.close();
}
