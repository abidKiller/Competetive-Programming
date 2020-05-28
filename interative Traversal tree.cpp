#include <bits/stdc++.h>

using namespace std;


typedef struct node{
 
  char data;
  node* left;
  node* right;

} node;

void inorder(node* p)
{

  if(p!=NULL){
    inorder(p->left);
    printf("%c",p->data);
    inorder(p->right);
  }

}

node* root=NULL;
void init(char a[])
{
  node *t,*p;

  queue<node*> q;
   
  root = (node*)malloc(sizeof(node));
  root->data=a[0];
  root->right=NULL;
  root->left=NULL;
  q.push(root);
  int i=1;
  while(!q.empty()){
       p=q.front();
       q.pop();
       
       if(a[i]!='\0')
       {
         t=(node* )malloc(sizeof(node));

         t->data=a[i++];
         t->right=NULL;
         t->left=NULL;
         p->left=t;
         q.push(t);

       }

       if(a[i]!='\0')
       {
         t=(node* )malloc(sizeof(node));

         t->data=a[i++];
         t->right=NULL;
         t->left=NULL;

         p->right=t;

         q.push(t);

       }
  }
}

void postOrder(node* p)
{
  stack<node*> s;
  long int temp;
  while(p!=NULL || !s.empty()){
     
     if(p){
       s.push(p);
       p=p->left;
     }
     
     
     else{
        
        temp=(long int) s.top();
        s.pop();
        
        if(temp>0){
          s.push((node*)(-temp));
          p=((node*) temp)->right; 
        }

        else {
          
          printf("%c",((node*) -temp)->data);
         
          p=NULL;
        }

     }
  }




}
int main()
{
  char a[]="abcdefg";

  init(a);
  fflush(stdout);
  inorder(root);
  printf("\n");
  postOrder(root);
 


}
