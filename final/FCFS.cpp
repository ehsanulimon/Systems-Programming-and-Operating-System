#include <iostream>

using namespace std;

int main()
{	cout<<"---First come first serve scheduling algorithm---"<<endl;
	int p[100] ={0};
	int At[100]={0},bt[100]={0},ct[100]={0},tt[100]={0},wt[100]={0};
	int n,i,j,temp,sum=0;
	float avg_tt=0,avg_wt=0;

	cout<<"Enter array size: ";
	cin>>n;
	cout<<"\nEnter process sequence:"<<endl;
	for(i=0;i<n;i++){
    cin>>p[i];
	}
    cout<<"\nEnter Arrival Time: (AT)"<<endl;
	for(i=0;i<n;i++){
    cin>>At[i];
	}
	cout<<"\nEnter Burst Time: (BT)"<<endl;
	for(i=0;i<n;i++){
    cin>>bt[i];
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(At[i]>At[j]){

				temp = At[i];
				At[i]=At[j];
				At[j]=temp;

					temp = bt[i];
				bt[i]=bt[j];
				bt[j]=temp;

					temp = p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	//calculate completion time of the process
	for(i=0;i<n;i++){
		sum=sum+bt[i];
		ct[i]+=sum;
	}
	//calculate turnaround time and waiting time
	for(i=0;i<n;i++){
		tt[i]=ct[i]-At[i];
		avg_tt+=tt[i];

		wt[i]=tt[i]-bt[i];
		avg_wt+=wt[i];
	}
	cout<<"Solution  "<<endl;
	cout<<"Process\tAT\tBT\tCT\tTT\tWT" <<endl;
	for(i=0;i<n;i++){
	cout<<"p"<<p[i]<<"\t"<<At[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tt[i]<<"\t"<<wt[i]<<endl;
	}
	cout<<"Total turnaround time ="<<avg_tt<<endl;
	cout<<"Total waiting time ="<<avg_wt<<endl;
    cout<<"Average turnaround time ="<<avg_tt/n<<endl;
	cout<<"Average waiting time ="<<avg_wt/n<<endl;
	
cout<<"-------Gannt Chart -------------\n";
for(i=0;i<n;i++){
	cout<<"[P"<<p[i]<<" ]";
}
cout<<"\n--------------------------------";


    return 0;
}

