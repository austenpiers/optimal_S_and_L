#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

string int_string(int);

int main(int argc, char *argv[])
{
  char buffer[256];
  (cin.getline(buffer,256));
  string inpt(buffer);
  int games = atoi(&(inpt[0]));
  inpt.erase();
  
  //looping through games
  for(int game = 1; game <= games; ++game)
    {
      //first line
      cin.getline(buffer,256);
      string ipt(buffer);
      int *gameSpecs = new int[3];
      //setting the game information
      int n = 0;
      for(int j = 0; j < 3; ++j, ++n){
	gameSpecs[j] = 0;
	for(n; (n+1) < ipt.length() && ipt[n] != 32; ++n)
	  gameSpecs[j] = (gameSpecs[j]*10) + (ipt[n] - 48);
      }
      ipt.erase();
      
      //making the board
      n = (gameSpecs[0]*gameSpecs[0]);
      int SnLa = gameSpecs[1]+gameSpecs[2];
      Matrix *mtx = new Matrix(n,SnLa);
      
      int track = 0;
      int lines = 2;
      //placing ladders and snakes
      while(lines){
	cin.getline(buffer,256);
	string inptu(buffer);
	int it = 0, end = (inptu.length() - 1);
			
	for(int i = gameSpecs[1]; i!=0; --i){
	  //begining position
	  int p = 0;
	  for(it; inptu[it] != 32; ++it)
	    p = (p*10) + inptu[it] - 48;
	  ++it;
				
	  //ending position
	  int v = 0;
	  for(it; it<end && inptu[it]!=32; ++it)
	    v = (v*10) + inptu[it] - 48;
	  ++it;
				
	  //updating board
	  mtx->SL[track][0] = p-1;
	  mtx->SL[track][1] = v-1;
	  ++track;
	}
	//switching from latters to snakes
	gameSpecs[1] = gameSpecs[2]; gameSpecs[2] = 0;
	--lines;
      }
      delete[] gameSpecs;
		
      //Finding Shortest Path\\
      int plea = 0;
      (mtx->Dijkstra());
      
      int pathLength = mtx->pred[0];
      mtx->pred[0] = 0;
      string Moves = int_string(n);
      
      for(int iter=(n-1), pvL=mtx->pred[iter]; iter!=0; iter=mtx->pred[iter],pvL=mtx->pred[iter],Moves=int_string(iter+1)+Moves){
	if(pvL > iter){
	  Moves = "-" + Moves;
	  --pathLength;
	  continue;
	}
	int pass = 0;
	for(int k = 0; k < SnLa; ++k){
	  if(mtx->SL[k][0] == pvL && mtx->SL[k][1] == iter){
	    Moves = "+" + Moves;
	    --pathLength;
	    pass = 1;
	  }
	}
	if(!(pass))
	  Moves = " " + Moves;
      }
      cout << "Board Game #" << game << ":\n" << (pathLength/2) << endl << Moves << endl;
      //return 1;

      delete mtx;
    }
}

string int_string(int number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}
