#include <iostream>
#include "monedas.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
	vector<int> salida = {0,0,0,0,0}, V = {2,3,5,7,11};
	int d;
	//char num[3];
	cout << "Dime un cambio a devolver" << endl;
	//cin >> num;
	//d=atoi(num);
	cin >> d;
	minMonedas(V,d, salida);

	for(int i=0; i<5; i++){
   	   cout << V[i] << "-->" << salida[i] << "  ";
	}
	cout << endl;
	return 0;
}
