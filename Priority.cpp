#include<bits/stdc++.h>
using namespace std;
struct process{
    int pid,at,bt,ct,tat,wt,pri;
};
void print(process *p,int n)
{
    //system("cls");
    float tct=0,ttat=0,twt=0;
    cout<<"Pid\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
        tct+=p[i].ct;
        ttat+=p[i].tat;
        twt+=p[i].wt;
    }
    cout<<endl;
    cout<<"Average CT :"<<tct/n<<endl;
    cout<<"Average TAT :"<<ttat/n<<endl;
    cout<<"Average WT :"<<twt/n<<endl;
}
void sort_process(process *p,int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++){
            if(p[j].pri>p[j+1].pri){
                process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"How Many Processes? :";
    cin>>n;
    process p[n];
    queue<process>ready_q,process_q,c;
    //inputing Data(AT and BT)
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        cout<<"Input Arrival Time , Burst Time and Priority of P"<<i+1<<" :";
        cin>>p[i].at>>p[i].bt>>p[i].pri;
        process_q.push(p[i]);
    }
    //put first process in ready queue to be execute first
    ready_q.push(process_q.front());
    process_q.pop();

    int tp=0;//time pointer.
    while(!ready_q.empty()){
        //sorting process
        int qs=ready_q.size();
        process cp[qs]={0};
        for(int i=0;i<qs;i++){
            cp[i]=ready_q.front();
            ready_q.pop();
        }
        sort_process(cp,qs);
        for(int i=0;i<qs;i++){
            ready_q.push(cp[i]);
        }


        //finding CT
        if(tp<ready_q.front().at){
            tp=ready_q.front().at+ready_q.front().bt;
            ready_q.front().ct=tp;
        }
        else
        {
            tp+=ready_q.front().bt;
            ready_q.front().ct=tp;
        }
        //process has come in time tp at ready queue
        int s=process_q.size();
        while(s!=0){
            if(tp>=process_q.front().at){
                ready_q.push(process_q.front());
                process_q.pop();
            }
            else{
                process_q.push(process_q.front());
                process_q.pop();
            }
            s--;
        }

        //finding TAT & WT
        ready_q.front().tat=ready_q.front().ct-ready_q.front().at;
        ready_q.front().wt=ready_q.front().tat-ready_q.front().bt;
        c.push(ready_q.front());
        ready_q.pop();
    }

    //print result
    int i=0;
    while(c.size()>0)
    {
        p[i]=c.front();
        c.pop();
        i++;
    }
    print(p,n);
}
//input
/*
4
0 5 40
1 4 30
2 2 20
4 1 10
*/
/*
4
0 5 40
2 4 30
3 2 20
5 1 10
*/


