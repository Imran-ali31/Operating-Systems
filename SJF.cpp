#include <bits/stdc++.h>
using namespace std;

struct process {
    int pid,att,bt,st,ct,tt,wt;
};

bool compare(process p1, process p2) {
    return p1.att < p2.bt;
}
bool compareID(process p1 ,process p2){
    return p1.pid<p2.pid;
}
int main() {
    int n;
    struct process p[100];
    float avg_tt,avg_wt,avg_rt;
    int total_tt = 0,total_wt=0,total_rt=0,idle=0;
    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter arrival time and Burst time \nPid\tAt Bt\n";
    for(int i = 0; i < n; i++) {
        cout<<i+1<<"\t";
        cin>>p[i].att>>p[i].bt;
        p[i].pid = i+1;
        cout<<endl;
    }
    int cur=0,pass=0;
    vector<bool>vis(n,0);
    while(pass!=n){
        int id=-1;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            if(p[i].att <=cur && !vis[i]){
                if(p[i].bt<mn){
                    mn=p[i].bt;
                    id=i;
                }
                if(p[i].bt ==mn){
                    if(p[i].att<p[id].att){
                        mn=p[i].bt;
                        id=i;
                    }
                }
            }
        }
        if(id!=-1){
            p[id].st=cur;
            p[id].ct=p[id].st+p[id].bt;
            p[id].tt= p[id].ct-p[id].att;
            p[id].wt=p[id].tt-p[id].bt;
            total_tt += p[id].tt;
            total_wt += p[id].wt;
            vis[id]=1;
            cur= p[id].ct;
            pass++;
        }
        else cur++;

    }
    avg_tt= (float)total_tt/n;
    avg_wt= (float)total_wt/n;
    cout<<"#P\tAT\tBT\tST\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<p[i].pid<<'\t'<<p[i].att<<'\t'<<p[i].bt<<'\t'<<p[i].st<<'\t'<<p[i].ct<<'\t'<<p[i].tt<<'\t'<<p[i].wt<<endl;
    }
    cout<<"Average Turnaround Time= "<<avg_tt<<endl;
    cout<<"Average Waiting Time= "<<avg_wt<<endl;
    return 0;
}
