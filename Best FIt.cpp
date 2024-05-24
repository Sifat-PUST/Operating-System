#include<bits/stdc++.h>
using namespace std;
struct space{
    int sid;
    int size;
};
void print(int *a,int n)
{
    cout<<"PID\tBlock No."<<endl<<"-----------------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"<<*(a+i)<<endl<<endl;
    }
}
void sort_obj(space *p,int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++){
            if(p[j].size>p[j+1].size){
                space temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int main()
{
    int pros_no,space_no;
    cout<<"Enter Process Number :";
    cin>>pros_no;
    cout<<"Enter Partition Number :";
    cin>>space_no;
    int p[pros_no],result[pros_no]={0};
    space s[space_no];
    cout<<"Enter Process Sizes :"<<endl;
    for(int i=0;i<pros_no;i++)
    {
        cout<<"Size of P"<<i+1<<" :";
        cin>>p[i];
    }
    cout<<"Enter Partition Sizes :"<<endl;
    for(int i=0;i<space_no;i++)
    {
        s[i].sid=i+1;
        cout<<"Size of Space "<<i+1<<" :";
        cin>>s[i].size;
    }

    //Main Algo
    for(int i=0;i<pros_no;i++)
    {
        sort_obj(s,space_no);
        for(int j=0;j<space_no;j++)
        {
            if(p[i]<=s[j].size){
                result[i]=s[j].sid;
                s[j].size-=p[i];
                break;
            }
        }
    }

    //printing
    cout<<endl<<endl;
    print(result,pros_no);

}
/*
4 2
50 75 100 25
100 150
*/
/*
3 3
10 20 30
5 10 20
*/


