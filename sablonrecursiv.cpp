#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("intrare.txt");
ofstream f("iesire.txt");
const int max_n=1e5+6;
int x[max_n],n;
bool ok(int k)
{
    for(int i=1; i<k; ++i)
        if(x[k]==x[i])
            return false;
    return true;
}
bool sol(int k)
{
    return k == n;
}
void print()
{
    for( int j=1; j<=n; j++)
        f<<x[j]<<" ";
    f<<endl;
}
void bt(int k)
{
    for(int i=1 ; i<=n ; ++i)
    {
        x[k]=i;
        if( ok(k) )
            if(sol(k))
                print();
            else
                bt(k+1);
    }
}
int main()
{
    cin>>n;
//    fin>>n;
    bt(1);
    fin.close();
    f.close();
}
