
#include<iostream>
#include<vector>
#define MAX_SIZE 1000
using namespace std;
class Turing_Machine
{
public:
    vector<char> v;
    int pointer ;
    Turing_Machine()
    {
        v.resize(1000);
        this->pointer=1;
        for(int i=0; i<this->v.size(); i++)
        {
            this->v[i]='-';
        }
    }
    void transition(bool direction,char output)
    {
        if(direction==0)///left
        {
            v[pointer]=output;
            this->pointer=this->pointer-1;
        }
        if(direction==1)///left
        {
            v[pointer]=output;
            this->pointer=this->pointer+1;
        }
    }
    void print(int left,int right)
    {
        cout<<"Pointer is => "<<this->pointer<<endl;
        for(int i=left; i<=right; i++)
        {
            cout<<this->v[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    ///input
    Turing_Machine m1;
    ///a^n,b^n,c^n
    string input;
    cin>>input;

    m1.v[0]='$';
    for(int i=1; i<input.size()+1; i++)
    {
        m1.v[i]=input[i-1];
    }
    m1.print(0,input.size());
    int state=0;
    int x=1000;
    int reject=0;
    while(1&&x>0)
    {
        x--;
        if(state==0)
        {
            cout<<"Inside state= "<<state<<endl;
            if(m1.v[m1.pointer]!='-')
            {
                m1.transition(1,m1.v[m1.pointer]);
                state=0;
                cout<<"Going to state= "<<state<<endl;
            }
            else if(m1.v[m1.pointer]=='-')
            {
                m1.transition(0,'-');
                state=1;
                cout<<"Going to state= "<<state<<endl;
            }
            else
            {
                reject=1;
                break;
            }
        }
        else if(state==1)
        {
            cout<<"Inside state= "<<state<<endl;
            if(m1.v[m1.pointer]=='0')
            {
                m1.transition(1,'1');
                state=2;
                cout<<"Going to state= "<<state<<endl;
                break;
            }
            if(m1.v[m1.pointer]=='1'||m1.v[m1.pointer]=='$')
            {

                if(m1.v[m1.pointer]=='$')
                {
                    m1.transition(0,'0');
                    state=1;
                    cout<<"Going to state= "<<state<<endl;
                    break;
                }
                m1.transition(0,'0');
                state=1;
                cout<<"Going to state= "<<state<<endl;

            }
            else
            {
                reject=1;
                break;
            }
        }
        m1.print(0,input.size());
    }
    if(reject==0)
    {
        m1.print(0,input.size());
        cout<<"YES"<<endl;
    }
    else if(reject==1)
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
