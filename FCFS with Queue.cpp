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
        cout<<tq.front().pid<<" ";
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
    queue<process>q,k,c;
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        cout<<"Input Arrival Time & Burst Time of P"<<i+1<<" :";
        cin>>p[i].at>>p[i].bt;
        k.push(p[i]);
    }

    q.push(k.front());
    k.pop();
    //object sort
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++){
            if(p[j].bt>p[j+1].bt){
                process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }*/
    int tp=0;//time pointer.
    while(!q.empty()){
        if(tp<q.front().at){
            tp=q.front().at+q.front().bt;
            q.front().ct=tp;
        }
        else
        {
            tp+=q.front().bt;
            q.front().ct=tp;
        }
        //queue<process>copy_k=k;
        int s=k.size();
        while(s!=0){
            if(tp>k.front().at){
                q.push(k.front());
                k.pop();
            }
            else{
                k.push(k.front());
                k.pop();
            }
            s--;
        }
        q.front().tat=q.front().ct-q.front().at;
        q.front().wt=q.front().tat-q.front().bt;
        c.push(q.front());
        q.pop();
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
5
1 7
3 3
6 2
7 10
9 1
*/
/*
3
0 9
1 3
1 2
*/

