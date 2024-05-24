#include<bits/stdc++.h>
using namespace std;
struct process{
    int pid,pri,att,bt,st=0,ct,tt,wt,rm;
};
bool comparePri(process p1, process p2) {
    return p1.pri < p2.pri;
}
bool compareID(process p1 ,process p2){
    return p1.pid<p2.pid;
}
int main(){
    int n;
    struct process p[100];
    float avg_tt,avg_wt;
    int total_tt=0,total_wt=0;
    cout<<setprecision(2)<<fixed;
    cout<<"Enter the Number of Processes: ";
    cin>>n;
    cout<<"Enter priority no. , Arrival time , Brust Time : \n";
    cout<<"Pid\tAt   \tBt   Priority\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t";
        cin>>p[i].att>>p[i].bt>>p[i].pri;
        p[i].pid = i+1;
    }
    sort(p,p+n,comparePri);
    int cur=0,pass=0;
    vector<bool>vis(n,0);
    while(pass!=n){
        int id=-1;
        for(int i=0;i<n;i++){
            if(p[i].att <=cur && !vis[i]){
                    id=i;
                    break;
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
    sort(p,p+n,compareID);
    cout<<"#P\tAT\tBT\tST\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<p[i].pid<<'\t'<<p[i].att<<'\t'<<p[i].bt<<'\t'<<p[i].st<<'\t'<<p[i].ct<<'\t'<<p[i].tt<<'\t'<<p[i].wt<<endl;
    }
    cout<<"Average Turnaround Time= "<<avg_tt<<endl;
    cout<<"Average Waiting Time= "<<avg_wt<<endl;
    return 0;
}
