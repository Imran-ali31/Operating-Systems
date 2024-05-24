#include<bits/stdc++.h>
using namespace std;
void Print(vector<int>alloc,int n, vector<int> proSize){
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << proSize[i] << "\t\t";
		if (alloc[i] != -1)
			cout << alloc[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}
void worstFit(vector<int>blkSize,int m , vector<int>proSize, int n)
{
	vector<int>alloc(n,-1);
	for (int i=0; i<n; i++)
	{
		int idx = -1;
		for (int j=0; j<m; j++)
		{
			if (blkSize[j] >= proSize[i])
			{
				if (idx == -1) idx = j;
				else if (blkSize[idx] < blkSize[j])idx = j;
			}
		}
		if (idx != -1)
		{
			alloc[i] = idx;
			blkSize[idx] -= proSize[i];
		}
	}
	Print(alloc,n,proSize);

}
void bestFit(vector<int>blkSize,int m , vector<int>proSize, int n)
{
	vector<int>alloc(n,-1);
	for (int i=0; i<n; i++)
	{
		int idx = -1;
		for (int j=0; j<m; j++)
		{
			if (blkSize[j] >= proSize[i])
			{
				if (idx == -1) idx = j;
				else if (blkSize[idx] > blkSize[j])idx = j;
			}
		}
		if (idx != -1)
		{
			alloc[i] = idx;
			blkSize[idx] -= proSize[i];
		}
	}
	Print(alloc,n,proSize);

}
void firstFit(vector<int>blkSize, int m, vector<int>proSize, int n)
{
	vector<int>alloc(n,-1);
	for (int i=0; i<n; i++)
	{
		int idx = -1;
		for (int j=0; j<m; j++)
		{
			if (blkSize[j] >= proSize[i]){
                idx=j;
                break;
			}
		}
		if (idx != -1)
		{
			alloc[i] = idx;
			blkSize[idx] -= proSize[i];
		}
	}
	Print(alloc,n,proSize);

}
int main(){
    int n,m;
    cout<<"Enter the number of memory block:";
    cin>>n;
     vector<int>blkSize(n);
     cout<<"Enter the Each block size of memory :";
     for(auto &x:blkSize)cin>>x;
    cout<<"Enter the number of process: ";
    cin>>m;
    vector<int>proSize(m);
    cout<<"Enter the Size of each process:";
    for(auto &x:proSize)cin>>x;
    while(1){
        cout<<"Enter choice:\n\t1.Press 1 First Fit\n\t2.Press 2 Best Fit\n\t3.Press 3 Worst Fit\n\t4.Any key for exit.\Your Choice: ";
        int ch;
        cin>>ch;
        switch(ch){
        case 1:
            firstFit(blkSize,n,proSize,m);
            break;
        case 2:
            bestFit(blkSize,n,proSize,m);
            break;
        case 3:
            worstFit(blkSize,n,proSize,m);
            break;
        default:
            ch=-1;
            break;
        }
        if(ch==-1)break;
    }
    return 0;
}
