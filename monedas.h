#include <iostream>
#include <vector>
#include <limits>
#define MAX numeric_limits<int>::max()
using namespace std;

void minMonedas(const vector<int>& V, int d, vector<int>& salida){
	int tamV=V.size();
	int tamS=salida.size();
	vector<vector<int>> M(tamV, vector<int>(d,numeric_limits<int>::max()));
	
	for(int i=0; i<tamV; i++){
	   M[i][0]=0;
	}
	for(int j=1; j<d; j++){
	   if(j>=V[0] && M[0][j-V[0]]!= MAX){
	      M[0][j]=1+M[0][j-V[0]];
	   }
	}
	for(int i=1; i<tamV; i++){
	   for(int j=1; j<d; j++){
	      if(j<V[i] || M[i][j-V[i]] == MAX){
	         M[i][j]=M[i-1][j];
	      }
	      else if(M[i-1][j]!=MAX){
	      ()//devolver mínimo
	      }
	      else{
	      //devolver única opción
	      }
	   }
	}


}
