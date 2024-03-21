#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p_no,re_no;
    cout<<"How many process: ";
    cin>>p_no;
    cout<<"how many resource: ";
    cin>>re_no;
    cout<<p_no<<" "<<re_no<<endl;

    int a=0,k=re_no;
    int re[re_no];
    int av[re_no];
    int al[p_no][re_no];
    int mn[p_no][re_no];
    int rn[p_no][re_no];
    //taking total resource number
    while(k--)
    {
        cout<<"Total Resource of resource-"<<a+1<<" :";
        cin>>re[a];
        a++;
    }
    //taking allocation of resource
    for(int i=0;i<p_no;i++)
    {
        cout<<"Allocation of process-"<<i+1<<" :"<<endl;
        for(int j=0;j<re_no;j++)
        {
            cin>>al[i][j];
        }
    }
    //getting available of resource
    for(int i=0;i<re_no;i++)
    {
        int sum=0;
        for(int j=0;j<p_no;j++)
        {
            sum+=al[j][i];
        }
        av[i]=re[i]-sum;
    }
    //taking maximum need
    for(int i=0;i<p_no;i++)
    {
        cout<<"Maximum Need of process-"<<i+1<<" :"<<endl;
        for(int j=0;j<re_no;j++)
        {
            cin>>mn[i][j];
        }
    }
    //calculate remaining need
    for(int i=0;i<p_no;i++)
    {
        cout<<"Maximum Need of process-"<<i+1<<" :"<<endl;
        for(int j=0;j<re_no;j++)
        {
            rn[i][j]=mn[i][j]-al[i][j];
        }
    }
    //checking deadlock and find safe sequence..
    vector<int> safe_sequence;
    queue<int> deadlock;
    for(int i=0;i<p_no;i++){
        deadlock.push(i);
    }

    while(!deadlock.empty()){
        int i=deadlock.front();
        deadlock.pop();
        bool temp=false;
        for(int j=0;j<re_no;j++)
        {
            if(rn[i][j]<=av[j])
            {
                temp=true;
            }
            else{
                temp=false;
                break;
            }
        }
        if(temp){
            safe_sequence.push_back(i+1);
            //new available
            for(int k=0;k<re_no;k++)
            {
                av[k]=av[k]+al[i][k];
            }
        }
        else{
            deadlock.push(i);
        }
    }
    //print safe sequence
    system("cls");
    for(auto i:safe_sequence){
        cout<<i<<" ";
    }
}
/*
    5 3
    10 5 7

    0 1 0
    2 0 0
    3 0 2
    2 1 1
    0 0 2

    7 5 3
    3 2 2
    9 0 2
    4 2 2
    5 3 3
*/

