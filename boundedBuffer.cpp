#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
queue<int>q;
int  s=1,e=10,f=0,data=1;
void producer()
{
    e--;
    s++;
    cout<<"Producced :"<<data<<endl;
    q.push(data);
    Sleep(3000);
    data++;
    s--;
    f++;
}
void consume()
{
    f--;
    s++;
    int tm= q.front();
    q.pop();
    cout<<"Consumed:"<<tm;
    Sleep(3000);
    s--;
    e++;
}
int main(){
    int n;
    while(1){
        cout<<"1.Producer\n2.consumer\n3.exit\n";
        cin>>n;
        if(n==1){
            if(e==0)cout<<"The buffer is full\n";
            else producer();
        }
        else if(n==2){
            if(f==0)cout<<"Ther buffer is empty\n";
            else consume();
        }
        else break;
    }
    return 0;
}


