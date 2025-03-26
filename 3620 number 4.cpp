/*First check whether the tress are empty or not. If both is empty, return true */
#include <bits/stdc++.h>
using namespace std;

struct tree{
    int value;
    tree *l, *r:

    tree(int value){
        this -> value = value;
        this -> = this ->r = nullptr;

    }
};

int isSimilar(tree* a, tree* b){ //recoursive finction to check if the two binary trees are similar
  if(a==nullptr && b ==nullptr)
  return 1;

  return(a && b) && (a->value == b->value) && isSimilar(a->l, b->l)& isSimilar(a->r, b->r);
}

int main(){
    tree *a = nullptr;

    a = new tree(15);
   a->l = new tree(10);
   a->r = new tree(20);
   a->l->l = new tree(8);
   a->l->r = new tree(12);
   a->r->l = new tree(16);
   a->r->r = new tree(25);


   tree *b= nullptr;

   b = new tree(15);
   b->l = new tree(10);
   b->r = new tree(20);
   b->l->l = new tree(8);
   b->l->r = new tree(12);
   b->r->l = new tree(16);
   b->r-> = new tree(25);

   if (isSimilar(a,b))
   cout<<"The binary trees are similar";
   else
   cout<<"The binary trees are different.";
   return 0;

}