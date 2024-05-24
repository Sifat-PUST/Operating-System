#include<bits/stdc++.h>
using namespace std;
void print(int *a,int n)
{
    cout<<"PID\tBlock No."<<endl<<"-----------------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"<<*(a+i)<<endl<<endl;
    }
}
int main()
{
    int pros_no,space_no;
    cout<<"Enter Process Number :";
    cin>>pros_no;
    cout<<"Enter Partition Number :";
    cin>>space_no;
    int p[pros_no],space[space_no],result[pros_no]={0};
    cout<<"Enter Process Sizes :"<<endl;
    for(int i=0;i<pros_no;i++)
    {
        cout<<"Size of P"<<i+1<<" :";
        cin>>p[i];
    }
    cout<<"Enter Partition Sizes :"<<endl;
    for(int i=0;i<space_no;i++)
    {
        cout<<"Size of Space "<<i+1<<" :";
        cin>>space[i];
    }
    for(int i=0;i<pros_no;i++)
    {
        int j=0;
        while(j<space_no)
        {
            if(p[i]<=space[j]){
                space[j]-=p[i];
                result[i]=j+1;
                //flag= true;
                break;
            }
            else{
                //result[j][i]=0;
                j++;
            }

        }
    }
    cout<<endl<<endl;
    print(result,pros_no);

}
/*
4 2
50 75 100 25
100 150
*/
/*
4 5
212 417 122 426
100 500 200 300 600
*/
