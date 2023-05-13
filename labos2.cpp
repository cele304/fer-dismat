#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int iscrpni(int **tezineBridova, int n) {
    int najkraciPut = INT_MAX;
    int niz[n + 1];
    
    for (int i = 1; i <= n; i++)
        niz[i - 1] = i;
    niz[n] = 1;

    while (true) {
        int trenutniPut = 0;
        for (int i = 0; i < n; i++) 
            trenutniPut += tezineBridova[niz[i] - 1][niz[i + 1] - 1];
        if (trenutniPut < najkraciPut) 
			najkraciPut = trenutniPut;
        if (!next_permutation(niz + 1, niz + n)) 
			break;
    }

    return najkraciPut;
    
}


int pohlepni(int **tezineBridova, int n){
    int vrhL = n;
    int posjeceno[n]; 
	int vrijednost = INT_MAX;
    int x, y, i, j;      

    for(i = 0; i < n; ++i)
        posjeceno[i] = 1;

    for(i = 0; i < n; ++i){                         
        for(j = 0; j < n; ++j) {
            if(tezineBridova[i][j] < vrijednost && tezineBridova[i][j] != 0){
                x = i;
                y = j;
                vrijednost = tezineBridova[i][j];
            }
        }
    }
    int ukupno = tezineBridova[x][y];             
    posjeceno[x] = 0;
    posjeceno[y] = 0;
    vrhL-= 2;

    while(vrhL > 0){
        int nextX, nextY, minX = INT_MAX, minY = INT_MAX;
            for(i = 0; i < n; ++i){         
                if(tezineBridova[x][i] < minX && tezineBridova[x][i] > 0 && posjeceno[i] != 0){
                    minX = tezineBridova[x][i];
                    nextX = i;
                }
            }
        
            for(i = 0; i < n; ++i){       
                if(tezineBridova[y][i] < minY && tezineBridova[y][i] > 0 && posjeceno[i] != 0){
                    minY = tezineBridova[y][i];
                    nextY = i;
                }
            }
           if(minX <= minY){                
                ukupno += tezineBridova[x][nextX];
                posjeceno[nextX] = 0;
                x = nextX;
           } else {
               ukupno += tezineBridova[y][nextY];
               posjeceno[nextY] = 0;
               y = nextY;
           }
        vrhL--;
        if(vrhL == 0) 
			ukupno += tezineBridova[x][y];
    }
    return ukupno;
}




int main() {
	int n, a, b, k, l, i, j, rez;
	cout << "Unesite redom, odvojene razmakom, parametre n, a i b > ";
	cin >> n >> a >> b;
	
	int **tezineBridova = new int*[n];

	for (k=1; k<=n; k++) {
		tezineBridova[k-1] = new int[n];
		for (l=1; l<=n; l++) {
			if (k < l) {
				rez = pow(a*k + b*l, 2) + 1;
				tezineBridova[k-1][l-1] = rez;
			}		
			else if (k > l) {
				rez = pow(a*l + b*k, 2) + 1;
				tezineBridova[k-1][l-1] = rez;			
			}
			else {
				rez = 0;							
				tezineBridova[k-1][l-1] = rez;
			}
			
		}
	}
	
	cout << endl;
	int rezI = iscrpni(tezineBridova, n);
	int rezP = pohlepni(tezineBridova, n);
	
	cout << "Iscrpni algoritam nalazi ciklus duljine > " << rezI << endl;
	cout << "Pohlepni algoritam nalazi ciklus duljine > " << rezP << endl << endl;
	
	if (rezI == rezP)
		cout << "Pohlepni algoritam na ovom grafu daje optimalno rjesenje!";
	else
		cout << "Pohlepni algoritam na ovom grafu ne daje optimalno rjesenje!"; 
	return 0;
}
