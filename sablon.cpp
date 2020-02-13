#include <iostream>
#include <fstream>
using namespace std;
//ifstream fin("intrare.txt");
ofstream f("iesire.txt");
const int max_n = 1e6 + 5;
int st[max_n],n,k,i;
void init()
{
    st[k]=0;
}
int succesor()
{
    if(st[k]<n)
    {
        st[k]++;
        return 1;
    }
    else return 0;
}
int valid()
{
    for(i=1; i<k; i++)
        if(st[k]==st[i])
            return 0;
    return 1;
}
int sol()
{
    return (k==n);
}
void print()
{
    for(i=1; i<=n; i++)
        f<<st[i]<<" ";
    f<<endl;
}
void bt()
{
    int AS;
    k=1;
    init();
    while(k>0)
    {
        do {}
        while((AS=succesor())&&!valid());
        if(AS)
            if(sol())
                print();
            else
            {
                k++;
                init();
            }
        else k--;
    }
}
int main()
{
    cin>>n;
    bt();
//    fin.close();
    f.close();
    return 0;
}
