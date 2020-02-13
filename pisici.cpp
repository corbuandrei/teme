//problema 5

#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("iesire.txt");
int x[100],pus[100],n,m;
void print()
{ for(int i=1;i<=n+m;i++) if(x[i]==1) fout<<"P ";
                          else fout<<"C ";
  fout<<endl;
}

int sol(int k)
{
    int c=0,p=0,i;
    for(i=1;i<=k;i++) 
      if(x[i]==0) c++;
      else p++;
    if(p>n || c>m) return 0;  
    if(k>=3) if(x[k-2]==0 && x[k-1]==1 && x[k]==0) return 0;
    return 1;
}

void bt(int k)
{ for(int i=1;i>=0;i--)
   {
          x[k]=i;
          if(sol(k))
            if(k==n+m) print();
            else bt(k+1);
   }      
}
int main()
{ 
  cin>>n>>m;
  bt(1);
  return 0;
}  
