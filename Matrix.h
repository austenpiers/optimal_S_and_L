#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Matrix{
 public:
  int N, **SL, SandL;
  int *dist;
  bool *S;
  int *pred;

 Matrix(int sz, int nmb):N(sz), SandL(nmb){
   dist = new int[N];
   S = new bool[N];
   pred = new int[N];
   SL = new int*[SandL];
   for(int i=0; i<SandL;++i)
     SL[i] = new int[2];
  for(int j=0; j<N; ++j){
    dist[j] = N*10;
    S[j] = false;
    pred[j] = j-1;
  }
   pred[0] = dist[0] = 0;
 };


  ~Matrix(){	
    for(int i = 0; i<SandL; ++i){
      delete[] SL[i];
    }
    delete[] SL;
    delete[] dist;
    delete[] pred;
    delete[] S;
  };

  void Dijkstra();
  string int_string(int number);

};

#endif
