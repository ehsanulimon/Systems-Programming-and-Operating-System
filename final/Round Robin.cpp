 #include <iostream>

using namespace std;

int main()
{
    cout << "************ Round Robin Scheduling Algorithm in C++ **********" << endl;
    cout << "************ Ehsanul Imon 64 **********" << endl;
    int i,j,qt,n, count0=0, temp,  ex=0, p[100], At[100],bt[100],rem_bt[100], tat[100], wt[100];
    float avg_tat=0, avg_wt=0;
    // ************* input *********

    cout<<"enter  process number : ";
    cin>>n;
    cout<<"\n enter process sequence : ";
    for(i=0;i<n;i++){
        cin>>p[i];
    }
       cout<<"enter Arrival Time : ";
    for(i=0;i<n;i++){
        cin>>At[i];
    }
           cout<<"enter Burst Time : ";
    for(i=0;i<n;i++){
        cin>>bt[i];
        rem_bt[i]=bt[i]; //   P[i].remaining_time = P[i].burst_time;
    }
    cout<<"Enter Quantum time : ";
    cin>>qt;



    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){


            if(At[i]>At[j])// 1st index At > 2nd index At
            {
           temp = bt[i];
            bt[i]=bt[j];
            bt[j]=temp;

             temp = rem_bt[i];
             rem_bt[i]=rem_bt[j];
             rem_bt[j]=temp;

                temp = p[i];
                p[i]=p[j];
                p[j]=temp;

                 temp = At[i];
                At[i]=At[j];
                At[j]=temp;
            }

        }
    }

while(true){              //for(;;){}

    for(i=0 , count0=0;i<n;i++){
        temp = qt;
        if( rem_bt[i]==0){
            count0++;
            continue;
        }
         if(rem_bt[i]>qt){
        rem_bt[i]=rem_bt[i] - qt;

        }
        else if(rem_bt[i]>= 0){
            temp =rem_bt[i];
            rem_bt[i]=0;
        }
        ex+=temp;
        tat[i]=ex-At[i];
    }



if(n == count0)
    break;
}


cout<<"process    Arrival time    burst time \t turnaround time \t  waiting time"<<endl;
for(i=0;i<n;i++){
    avg_tat+=tat[i];
    wt[i]=tat[i]-bt[i];
    avg_wt+=wt[i];
    cout<<" p["<<p[i]<<"]\t\t"<<"at["<<At[i]<<"]\t\t"<<" bt["<<bt[i]<<"]\t\t"<<" tat["<<tat[i]<<"]\t\t"<<" wt["<<wt[i]<<"]\t\t"<<endl;

}

avg_tat=avg_tat/n;
avg_wt =avg_wt/n;
cout<<"avg. tt = "<<avg_tat<<" avg. wt = "<<avg_wt;


    return 0;
}
