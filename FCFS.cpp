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
    sort(p,p+n,compare);

    for(int i = 0; i < n; i++) {
        p[i].st = (i == 0)?p[i].att:max(p[i-1].ct,p[i].att);
        p[i].ct = p[i].st + p[i].bt;
        p[i].tt = p[i].ct - p[i].att;
        p[i].wt = p[i].tt - p[i].bt;
        total_tt += p[i].tt;
        total_wt += p[i].wt;
    }

    avg_tt = (float) total_tt / n;
    avg_wt = (float) total_wt / n;
    sort(p,p+n,compareID);

    cout<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].att<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tt<<"\t"<<p[i].wt<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_tt<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;
}
