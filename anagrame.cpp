#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std; 
ifstream fin("anagrame1.in"); 
ofstream fout("anagrame1.out"); 
int st[10],top,f[10],n; 
char cuv[10],a[10]; 
void Citire() { 
	int i; fin>>cuv; 
	sort(cuv,cuv+strlen(cuv)); 
	n++; 
	f[n]++; 
	a[n]=cuv[0]; 
	for(i=1; i<strlen(cuv);) {
		 if(a[n]==cuv[i]) { 
			 f[n]++; i++; }
			  else { 
				  n++; 
				  f[n]++; 
				  a[n]=cuv[i]; 
				  i++; }
				   }
				    }
				     
void Afisare() { 
	int i; 
	for(i=1; i<=n; i++) 
	fout<<a[st[i]]; fout<<"\n"; } 
void Back(int top) { 
		int i; 
		if(top==(n+1)) Afisare(); 
		else for(i=1; i<=n; i++)
		 if(f[i]) { 
			 f[i]--; 
			 st[top]=i; 
			 Back(top+1); 
			 f[i]++; 
			 } 
			 } 
int main() { 
	Citire(); 
	Back(1);
	 fin.close(); 
	 fout.close();
	  return 0; } 

