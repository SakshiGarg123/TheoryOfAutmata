#include<bits/stdc++.h>
#include<vector>
#define MAX_SIZE 1000
using namespace std;
int state = 0;

class Turing_Machine
{
public:
    list<char> l;
    list<char>::iterator head;
    bool direction;
    Turing_Machine(string s){
        l.push_back('$');
        for(int i=0;i<MAX_SIZE;++i){
            if(i<s.length()){
                l.push_back(s[i]);
            }
            else
            l.push_back('-');
        }
        head = l.begin();
        head++;
    }

    void transition(char ch, bool dir){
        string s = (!dir)?"left":"right";
        cout<<"pointer at"<<" "<<*head<<"->"<<ch<<","<<s<<endl;
        print();
        *head = ch;
        if(!dir){
            head--;
            cout<<"left  ";
        }
        else head++;
    }
    void print(){
        list<char>::iterator it;
        cout<<"pointer at "<<*head<<endl;
        for(it=l.begin();it!=l.end();++it){
            cout<<*it;
        }
        cout<<endl;
    }
};
int main()
{

    string input;
    cin>>input;
    Turing_Machine m(input);

    int ind = 0;
    bool flag = 1;
//    input = "$" + input;
//    list<char>::iterator it;
//    for(int i=0,it=m.l.begin();i<input.length() && it!=m.l.end();++i,++it){
//        cout<<*it<<" ";
//    }
    while(flag){
            list<char>::iterator it = m.head;
            char ch = *it;

        ind++;
        switch(state){

        case 0:
            cout<<"in state "<<state<<endl;
            if(ch=='a' || ch=='b'){
                m.transition(ch,1);
            }
            else if(ch=='-'){
                m.transition(ch,0);
                state = 1;
            }
            else{
                cout<<"error in state 0, input "<<ch;
                flag = 0;
            }
             it = m.head;
             ch = *it;
            cout<<"going to state "<<state<<endl;
            break;
        case 1:
            cout<<"in state "<<state<<endl;
            if(ch=='x'){
                m.transition('x',0);
            }
            else if(ch=='a'){
                m.transition('x',1);
                state = 2;
            }
            else if(ch=='b'){
                m.transition('x',1);
                state = 3;
            }
            else if(ch=='-'){
                m.transition(ch,1);
                state = 5;
            }
            else{
                cout<<"error in state 1, input "<<ch;
                flag = 0;
            }
             it = m.head;
             ch = *it;
            cout<<"going to state "<<state<<endl;
            break;
        case 2:
            cout<<"in state "<<state<<endl;
            if(ch=='a' || ch=='b' || ch=='x'){
                m.transition(ch,1);
            }
            else if(ch=='-'){
                m.transition('a',0);
                state = 4;
            }
            else{
                cout<<"error in state 2,input "<<ch;
                flag = 0;
            }
             it = m.head;
             ch = *it;
            cout<<"going to state "<<state<<endl;
            break;
        case 3:
            cout<<"in state "<<state<<endl;
            m.print();
            if(ch=='a' || ch=='b' || ch=='x'){
                m.transition(ch,1);
            }
            else if(ch=='-'){
                m.transition('b',0);
                state = 4;
            }
            else{
                cout<<"error in state 3, input "<<ch;
                flag = 0;
            }
            it = m.head;
            ch = *it;
            cout<<"going to state "<<state<<"with input "<<ch<<endl;
            break;
        case 4:
            cout<<"in state "<<state<<endl;
            if(ch=='a' || ch=='b'){
                m.transition(ch,0);
            }
            else if(ch=='x'){
                m.transition(ch,0);
                state = 1;
            }
            else{
                cout<<"error in state 4, input "<<ch;
                flag = 0;
            }
            it = m.head;
            ch = *it;
            cout<<"going to state "<<state<<endl;
            break;
        case 5:
            if(ch=='x'){
                m.transition('-',1);
            }
            else if(ch=='a' || ch=='b'){
                cout<<"Accepted string "<<input<<endl;
                flag = 0;
            }
            else{
                cout<<"error in state 5, input "<<ch;
                flag = 0;
            }
        }
    }
//    list<char>::iterator it = m.l.begin();
//
//    for(int i=0;i<=2*input.size();++i){
//        cout<<*it;
//    }

    m.print();

    return 0;
}
