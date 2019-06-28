#include "TST.h"

#define MAX_LEN 1024


TSTNode* Insert(TSTNode* root, char* str)
{
 if(root == NULL)
 {
  root = (TSTNode*)malloc(sizeof(TSTNode));
  if(root == NULL)
  {
   return NULL;
  }
  root->data = *str;
  root->bEOS = false;
  root->left = root->eq = root->right = NULL;
 }
 
 if(*str  < root->data)
  root->left = Insert(root->left, str);
 else if (*str == root->data)
 {
  if(*(str + 1))
   root->eq = Insert(root->eq, str + 1);
  else
   root->bEOS = true;
 }
 else
  root->right = Insert(root->right, str);
 
 return root; 
}

static void PrintHelper(TSTNode* root, char* buffer, int depth)
{
  if (root)
  {
    PrintHelper(root->left, buffer, depth);

    buffer[depth] = root->data;
    if (root->bEOS)
    {
     buffer[depth + 1] = '\0';
     std::cout<< buffer << std::endl;
    }

    PrintHelper(root->eq, buffer, depth + 1);

    PrintHelper(root->right, buffer, depth);
  }
}

void PrintAllStringsInTST(TSTNode* root)
{
 char buffer[MAX_LEN];
 PrintHelper(root, buffer, 0);
}

bool SearchTST(TSTNode *root, char* pattern)
{
  while (root != NULL){
    if (*pattern < root->data)
      root = root->left;
    else if (*pattern == root->data){
      if (root->bEOS && *(pattern + 1) == '\0')
        return true;
      pattern++;
      root = root->eq;
    }
    else
      root = root->right;
  }
 return false;
}


void Searchprefi(TSTNode *root, char* pattern){
  cout<<pattern;
  while (root != NULL){
    //cout<<pattern;
    if (*pattern < root->data)
      root = root->left;
    else if (*pattern == root->data){
      if (root->bEOS && *(pattern + 1) == '\0'){
        
        PrintAllStringsInTST(root);
      }
        //return true;
      pattern++;
      root = root->eq;
    }
    else
      root = root->right;
  }

  //cout<< root->data;
 //return false;
}


/*
void Prefij(TSTNode *root, char* pattern){
  if(root){

  }
}
/*
void printARBOL(int num){
    string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.exe.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    es<<"digraph mentions {"<<endl;
    printARBOL1(es, root);
    es<<"}"<<endl;
    es.close();
    system(buffer);
}

void printARBOL1(ofstream & es,TSTNode *n){
    if(n!=NULL){
        if(n->left != NULL){
          es<< n->data;
          es<< " -> ";
          es<< n->left->data<< endl;
          printARBOL1(es,n->left);
        }
        if(n->eq != NULL){
          es<<n->key;
          es<< " -> ";
          es<<n->eq->data<<endl;
          printARBOL1(es,n->eq);
        }
        if(n->right != NULL){
          es<< n->data;
          es<< " -> ";
          es<< n->right->data<<endl;
          printARBOL1(es, n->right); 
        }
    }
}
*/