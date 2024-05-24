#include<bits/stdc++.h>
using namespace std;
void print(int *at,int *bt,int *ct,int *tat,int *wt,int n)
{
    float tct=0,ttat=0,twt=0;
    cout<<"Pid\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"<<*(at+i)<<"\t"<<*(bt+i)<<"\t"<<*(ct+i)<<"\t"<<*(tat+i)<<"\t"<<*(wt+i)<<endl;
        tct+=ct[i];
        ttat+=*(tat+i);
        twt+=*(wt+i);
    }
    cout<<endl;
    cout<<"Average CT :"<<tct/n<<endl;
    cout<<"Average TAT :"<<ttat/n<<endl;
    cout<<"Average WT :"<<twt/n<<endl;
}
int main()
{
    int n;
    cout<<"How Many Processes? :";
    cin>>n;
    int at[n],bt[n],ct[n]={0},tat[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Input Arrival Time & Burst Time of P"<<i+1<<" :";
        cin>>at[i]>>bt[i];
    }
    int tp=0;//time pointer.
    for(int i=0;i<n;i++)
    {
        if(tp<at[i]){
            tp=at[i]+bt[i];
            ct[i]=tp;
        }
        else{
            tp+=bt[i];
            ct[i]=tp;
        }
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    print(at,bt,ct,tat,wt,n);
}
//input
/*
4
1 3
2 1
6 2
7 3
*/
