#ifndef TST_H
#define TST_H

#include <iostream>
#include <cstdlib>
#include <utility>
using namespace std;

typedef struct TSTNode{
 char data;
 bool bEOS; 
 struct TSTNode* left;   
 struct TSTNode* eq;  
 struct TSTNode* right; 
}TSTNode;

TSTNode* Insert(TSTNode* root, char* str); 
void PrintAllStringsInTST(TSTNode* root);
bool SearchTST(TSTNode *root, char* pattern);
void Searchprefi(TSTNode *root, char* pattern);
//void Prefij(TSTNode *root, char* pattern);
//void printArbol();
#endif