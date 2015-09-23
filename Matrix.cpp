#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

void Matrix::Dijkstra(){
  int i;
  int Q = 0;

  do{
    S[Q] = true;
    for(i = Q+1; i < N && i < (Q+7); ++i){
      if(dist[i] > (dist[Q] + 2)){
	dist[i] = (dist[Q] + 2);
	pred[i] = Q;
      }
    }
    for(int k = 0; k < SandL; ++k){
      if(SL[k][0] == Q){
	i = SL[k][1];
	if(dist[i] > (dist[Q] + 1)){
	  dist[i] = (dist[Q] + 1);
	  pred[i] = Q;
	}
      }
    }
    
    dist[0] = 10*N;
    for(int i = (N-1); i > 0; --i){
      if(S[i] == false){
	if(dist[0] > dist[i]){
	  dist[0] = dist[i];
	  Q = i;
	}
      }
    }
    dist[0] = 0;
    if(Q == (N-1)){
      pred[0] = dist[N-1];
      return;
    }
  }while(1);
}
