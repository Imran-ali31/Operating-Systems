#include <bits/stdc++.h>
using namespace std;
struct process{
    int pid,att,bt,st,tt,ct,wt;
};
bool compare(process p1,process p2){
    return p1.att<p2.att;
}
bool compareID(process p1,process p2){
    return p1.pid<p2.pid;
}
int main(){
    int n,tq;
    process p[100];
    float avg_tt,avg_wt;
    int total_tt=0,total_wt=0;
    int remain[100];
    cout<<setprecision(2)<<fixed;
    cout<<"Enter the number of Process : ";
    cin>>n;
    cout<<"Enter arrival time and Burst time \nPid\tAt Bt\n";
    for(int i = 0; i < n; i++) {
        cout<<i+1<<"\t";
        cin>>p[i].att>>p[i].bt;
        remain[i]=p[i].bt;
        p[i].pid = i+1;
    }
    cout<<"Enter time quantum: ";
    cin>>tq;
    sort(p,p+n,compare);
    queue<int>qq;
    int cur=0;
    qq.push(0);
    int pass=0;
    vector<bool>vis(n,0);
    while(pass!=n){
        int idx=qq.front();
        qq.pop();
        if(remain[idx]==p[idx].bt){
            p[idx].st= max(cur,p[idx].att);
            cur=p[idx].st;
        }
        if(remain[idx]-tq>0){
            remain[idx]-=tq;
            cur+=tq;
        }
        else{
            cur+=remain[idx];
            remain[idx]=0;
            pass++;
            p[idx].ct=cur;
            p[idx].tt=p[idx].ct-p[idx].att;
            p[idx].wt=p[idx].tt-p[idx].bt;
            total_tt+=p[idx].tt;
            total_wt+=p[idx].wt;
        }
        for(int i=1;i<n;i++){
            if(remain[i]>0 && p[i].att <=cur && !vis[i]){
                qq.push(i);
                vis[i]=1;
            }
        }
        if(remain[idx]>0)qq.push(idx);

        if(qq.empty()){
            for(int i=1;i<n;i++){
                if(remain[i]>0){
                    qq.push(i);
                    vis[i]=1;
                    break;
                }
            }
        }
    }
    avg_tt= (float)total_tt/n;
    avg_wt= (float)total_wt/n;
    sort(p,p+n,compareID);
    cout<<"#P\tAT\tBT\tST\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<p[i].pid<<'\t'<<p[i].att<<'\t'<<p[i].bt<<'\t'<<p[i].st<<'\t'<<p[i].ct<<'\t'<<p[i].tt<<'\t'<<p[i].wt<<endl;
    }
    cout<<"Average Turnaround Time= "<<avg_tt<<endl;
    cout<<"Average Waiting Time= "<<avg_wt<<endl;
    return 0;
}
