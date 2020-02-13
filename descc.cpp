#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("iesire.txt");
const int max_n = 1e6 + 5;
int st[max_n],i,n;

void print(int k)
{
    bool ok=false;
    for(i=1;i<=k;i++){
            if(st[i]>st[i-1])
                {ok=true;
		}
        else {
			ok=false;
            break;
			 }
        }
        if(ok==true){
          for(i=1;i<=k;i++)
			fout<<st[i]<<" ";
          fout<<endl;
        }
}
void bt(int k, int l)
{
    //int i;
    st[k]=l;
    print(k);
    for(i=1;i<st[k];i++)
    {
        st[k]=st[k]-i;
        bt(k+1,i);
        st[k]=st[k]+i;
    }
}
int main()
{
    cin>>n;
    bt(1,n);
    fout.close();
}
