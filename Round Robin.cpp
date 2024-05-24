#include<bits/stdc++.h>
using namespace std;
struct process{
    int pid,at,bt,ct,tat,wt;
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
void sq(queue<process>q){
    queue<process>tq=q;
    while(!tq.empty()){
        cout<<tq.front().wt<<" ";
        //cout<<tq[0].pid.front()<<" ";
        tq.pop();
    }
    cout<<endl;
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
        cout<<"Input Arrival Time & Burst Time of P"<<i+1<<" :";
        cin>>p[i].at>>p[i].bt;
        process_q.push(p[i]);
    }
    int TQ=2;
    //put first process in ready queue to be execute first
    ready_q.push(process_q.front());
    process_q.pop();

    int tp=0;//time pointer.
    while(!ready_q.empty()){
        //finding CT
        if(tp<ready_q.front().at){
            tp=ready_q.front().at+TQ;
            ready_q.front().bt-=TQ;
        }
        else
        {
            tp+=TQ;
            ready_q.front().bt-=TQ;
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
        if(ready_q.front().bt<=0){

            if(ready_q.front().bt<0){
            tp=tp+ready_q.front().bt;
            }
            ready_q.front().ct=tp;

            //finding TAT & WT
            ready_q.front().tat=ready_q.front().ct-ready_q.front().at;
            ready_q.front().bt=p[ready_q.front().pid-1].bt;
            ready_q.front().wt=ready_q.front().tat-p[ready_q.front().pid-1].bt;
            c.push(ready_q.front());
            ready_q.pop();
        }
        else{
            ready_q.push(ready_q.front());
            ready_q.pop();
        }
    }
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
0 5
1 4
2 2
4 1
*/
/*
3
0 9
1 3
1 2
*/

