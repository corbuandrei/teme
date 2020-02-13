#include <iostream>
#include <string>
using namespace std;
string Rot13(string s)
{
    int i = 0;
    string s_buffer = "";
    unsigned char c = '\0';
    while(i <=s.length())
    {
        c = s[i];
        if (islower(c))
        {
            c += 13;
            if (c > 'z')
            {
                c-= 26;
            }
        }
        if (isupper(c))
        {
            c += 13;
            if (c > 'Z')
            {
                c-=26;
            }
        }
        s_buffer += c;
        i++;
    }
    return s_buffer;
}
int main()
{
    string s_test;
    getline(cin,s_test);
    string s0 = "";
    s0 = Rot13(s_test);
    cout << "Original : " << s_test.c_str() << endl;
    cout << "Decriptat : " << s0.c_str() << endl;
    s0 = Rot13(s0);
    s0.clear();
    s_test.clear();
    return 0;
}
