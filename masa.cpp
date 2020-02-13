#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("intrare.txt");
ofstream fout("iesire.txt");
int a[500][500],x[500],p[500],n;
void scan()
{
    int i,j;
    fin>>n;
    while(fin>>i>>j)
        a[i][j]=a[j][i]=1;

}
void print()
{
   int i;
   for(i=1;i<=n;i++)
        fout<<x[i]<<" ";
   fout<<endl;
}
int sol(int k)
{
   if(k>1)
        if(a[x[k]][x[k-1]]==1)
            return 0;
   if(k==n)
        if(a[x[1]][x[n]]==1)
            return 0;
   return 1;
}
void back(int k)
{
    for(int i=1;i<=n;i++)
      if(!p[i])
      {
          x[k]=i;
          p[i]=1;
          if(sol(k))
                if(k==n)
                {
                    print();
                }
                else back(k+1);
          p[i]=0;
      }

}
int main()
{
    scan();
    back(1);
    fin.close();
    fout.close();
    return 0;
}
