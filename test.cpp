#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

struct A
{
    int x, y;
};
struct cmp
{
    bool operator()(const A& a,const A& b)
    {
        return a.x<b.x;
    }

};
typedef struct A A;
int main()
{
    A arr[3];

    arr[0].x=5;
    arr[1].x=4;
    arr[2].x=3;

     priority_queue<A,vector<A>,cmp> p(arr,arr+3);

     for(int i=0;i<3;i++)

     {
        cout<< p<<endl;
        p.pop();
     }
    //...
   // std::sort(arr, arr+3, [](A a, A b)->bool{ return a.x < b.x; });
    //std::sort(array, array+1000, [](A a, A b){ return a.y < b.y; });
}
