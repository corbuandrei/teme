#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
ofstream fout("iesire.txt");
typedef char  culoare[10];
culoare C[7];
int V[200];
int k;
void scan ()
{
	strcpy (C[1], "galben");
	strcpy (C[2], "rosu");
	strcpy (C[3], "verde");
	strcpy (C[4], "albastru");
	strcpy (C[5], "alb");
	strcpy (C[6], "negru");
}
int Solutie ()
{
	return (k==3);
}
void Tipar ()
{
	for (int j=1; j<=k; j++)
		fout << setw(10)<<C[V[j]]<< " ";
	fout << endl;
}
int Valid ()
{
	if (k==2)
		if ( (V[k]!=3)&&(V[k]!=1))
			return 0;
	for (int i=1; i<=k-1; i++)
		if (V[k]==V[i])
			return 0;
	return 1;

}
void Drapel_Back ()
{
	for (k=1; k<=6; k++)
		V[k]=0;
	k=1;
	while (k>0)
	{
		while (V[k]<6)
		{
			V[k] ++;
			if (Valid()){
				if (Solutie())
					Tipar ();
				else
					k++;}
		}
		V[k--]=0;
	}
}
int main ()
{
	scan();
	Drapel_Back ();
}
