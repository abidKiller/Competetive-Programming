#include<bits/stdc++.h>
using namespace std;

class employee{
    protected:
        int x;
    public:
        
        employee(int x){
            this->x = x;
        }
        virtual void print(){
            cout<<"employee"<<x<<endl;
        }
};
class swe:public employee{
    public:
    swe(int x):employee(x){
        
    }
    void print() override{
        cout<<"swe"<<x<<endl;
    }
    
};
class hde:public employee{
    public:
    hde(int x):employee(x){
        this->x = x;
    }
    void print() override{
        cout<<"hde"<<x<<endl;
    }
    
};




int main(){
   hde* a=new hde(223);
   swe* b=new swe(24);
   employee* c=new employee(213);
   vector<employee*> pt;

   pt.push_back(a);
   pt.push_back(b);
   pt.push_back(c);

    for(int i=0;i<pt.size();i++){
        pt[i]->print();
    }
    cout<<pt[0]<<" "<<a<<endl;
}