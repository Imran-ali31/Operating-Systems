#include<bits/stdc++.h>
#define MIN 999999;
using namespace std;
struct process{
    int pid,pri,att,bt,st=0,ct,tt,wt,temp,rt;
};
bool compareAt(process p1, process p2) {
    return p1.att < p2.att;
}
bool compareID(process p1 ,process p2){
    return p1.pid<p2.pid;
}
int main(){
    int n,remaining,val,index;
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
        p[i].temp= p[i].pri;
        p[i].rt=p[i].bt;
    }
    remaining=n;
	sort(p,p+n,compareAt);
    val=p[0].temp,index=0;
	for(int j=0;j<n&&p[j].att<=p[0].att;j++)
		if(p[j].temp<val)
			val=p[j].temp,index=j;
	int i=index;
	int c=p[i].ct=p[i].att+1;
	p[i].rt--;
	if(p[i].rt==0)
	{
		p[i].temp=MIN;
		remaining--;
	}
	while(remaining>0)
	{
		val=p[0].temp,index=0;
    	for(int j=0;j<n&&p[j].att<=c;j++)
    		if(p[j].temp<val)
    			val=p[j].temp,index=j;
    	i=index;
		p[i].ct=c=c+1;
		p[i].rt--;
		if(p[i].rt==0)
		{
		    p[i].temp=MIN;
		    remaining--;
		}
	}
    for(int i=0;i<n;i++){
        p[i].tt=p[i].ct-p[i].att;
        total_tt+=p[i].tt;
        p[i].wt=p[i].tt-p[i].bt;
        total_wt+=p[i].wt;
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
