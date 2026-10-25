#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define MAX numeric_limits<int>::max()
using namespace std;

void minMonedas(const vector<int>& V, int d, vector<int>& salida){
	int tamV=V.size();
	int tamS=salida.size();
	vector<vector<int>> M(tamV, vector<int>(d+1,numeric_limits<int>::max()));
	
	for(int i=0; i<tamV; i++){
	   M[i][0]=0;
	}
	for(int j=1; j<d+1; j++){
	   if(j>=V[0] && M[0][j-V[0]]!= MAX){
	      M[0][j]=1+M[0][j-V[0]];
	   }
	}
	for(int i=1; i<tamV; i++){
	   for(int j=1; j<d+1; j++){
	      if(j<V[i] || M[i][j-V[i]] == MAX){//Si con la moneda actual no puedo porque es demasiado grande o porque después no hay combinación posible
	         M[i][j]=M[i-1][j]; //Me quedo con el resultado de mirar con una más pequeña
	      }
	      else if(M[i-1][j]!=MAX){ //Si que puedo con la actual, pero si puedo con la anterior, cuál es mejor?
	         M[i][j] = min(M[i-1][j], 1+M[i][j-V[i]]); //devolver mínimo
	      }
	      else{
	         M[i][j] = 1+M[i][j-V[i]]; //devolver única opción
	      }
	   }
	}
	
	//Tabla de mínimo hecha.
	//Ahora rellenar el vector salida
	int i=tamV-1, j=d;
	while(i!=0 || j!=0){
	   if(M[i][j]!=M[i-1][j] || i==0){ //Mientras hayamos llegado hasta la moneda más pequeña o la menor tome más monedas 
	      salida[i]++; //Sumamos una moneda del tipo que sirve para llegar al mínimo devuelto
	      j=j-V[i]; //nos desplazamos en horizontal
	   }
	   else{
	      i=i-1;//Probamos con la moneda menor
	   }
	}

}
