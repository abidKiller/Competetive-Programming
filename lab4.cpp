#include<bits/stdc++.h>
using namespace std;

struct job
{

    int no;
    int burst;
    int priority;
    int arrival;
    int start;
    int finish;
    int waiting;
    int reponse;

};
typedef struct job job;
void display(job jobs[],string type)
{

}

void NPSJF(job jobs[])
{
    int avgWait;
    int avgResponse;

    priority_queue<job>

    sort(jobs,jobs+5,[](const job& a,const job& a)->bool{return a.arrival<b.arrival};)







}

int main()
{
    job jobs[5];
    fstream inFile;
    inFile.open("process.txt");

    for(int i=0;i<5;i++)
    {
        inFile>>jobs[i].burst>>jobs[i].priority>>jobs[i].arrival;
        jobs[i].no=i+1;
    }




  //  [](A a, A b){ return a.x < b.x; }
  /*  deque<job> jobsd(jobs,jobs+5);
    sort(jobs,jobs+5,[](job x,job y)-> bool { return x.arrival >y.arrival; });
    sort(jobsd.begin(),jobsd.end(),[](job x,job y)-> bool { return x.arrival >y.arrival; });

    for(int i=0;i<5;i++)
    {
          cout<<jobsd[i].no<<" "<< jobsd[i].arrival<<endl;



    }

   */
  /*  OSAlgo work;
    work.PSJf(jobs);
    work.NPSjf(jobs);
    work.PP(jobs);
    work.NPP(jobs);
    work.RR(jobs);
  */
}
