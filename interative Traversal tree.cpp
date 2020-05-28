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
/// any kind of processing uses POSTORDER traversal
class Processing
{
  public:

int countALL(node* p)
{
  int l=0;
  int r=0;
  if(p!=NULL)
  {
    l=countALL(p->left);
    r=countALL(p->right);
     
    return l+r+1;
  }
  return 0;
}

int countNonLeaf(node* p)
{
  int l=0;
  int r=0;
  if(p!=NULL)
  {
    l=countNonLeaf(p->left);
    r=countNonLeaf(p->right);
    if(p->left&&p->right)
       return l+r+1; //incremnts the return if node if nonleaf
    else 
    return l+r;
  }
  return 0;
}

int addAllNodeElements(node* p)
{
  int l=0;
  int r=0;
  if(p!=NULL)
  {
    l+=addAllNodeElements(p->left);
    r+=addAllNodeElements(p->right);
     
    return l+r+p->data; // adds nodes data 
  }
  return 0;
}

int maxHeight(node* p)
{
  int l=0;
  int r=0;

  if(p!=NULL)
  {
    l=maxHeight(p->left);
    r=maxHeight(p->right);

    if(l>r)
      return l+1;
    else 
      return r+1;
  }
  return 0;
}
};
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
// hardest one
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




};
void levelOrder(node* p){

  queue<node*> q;

  q.push(p);

  while(!q.empty()){
    node *t=q.front();
    q.pop();
    printf("%c",t->data);
    if(t->left){
        q.push(t->left);
    }
    if(t->right)
    {
        q.push(t->right);
    }
      
  
  }

}
int main()
{
  char a[]="abcdefg"; // array representation of tree

  init(a);
  fflush(stdout);
  inorder(root);
  printf("\n");
//  postOrder(root);
  printf("\n");
  levelOrder(root);
 


}
