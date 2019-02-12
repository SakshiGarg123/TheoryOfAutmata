#include<iostream>
using namespace std;

char* fun(){
    char *s = new char[5];
    s[0] = 'h';
    s[1] = 'g';
    s[2] = '\0';
    return s;
}
int main()
{
    cout<<fun();


return 0 ;
}
