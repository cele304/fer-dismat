#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cmath>
#include <cstdlib>
using namespace std;

int kromatski(int tocka, int* boje, int br, int A[20][20], int n) {
    int moguceBoje[br + 1];
    for (int i=0; i<br+1; i++) 
        moguceBoje[i] = i+1;

    for (int i=1; i<tocka; i++)
        if (A[tocka-1][i-1] == 1)
            moguceBoje[boje[i-1]-1] = 0;

    int min=0;
    for (int i=0; i<br+1; i++) {
        if (moguceBoje[i] != 0) {
            int poziv;
            boje[tocka-1] = moguceBoje[i];
            if (i == br) {
                if(tocka != n)
                    poziv = kromatski(tocka+1, boje, br+1, A, n);
                else poziv = br+1;
            } else {
                if (tocka != n) 
                    poziv = kromatski(tocka+1, boje, br, A, n);
                else poziv = br;
            } if (poziv != 0 && (poziv < min || min == 0)) 
                min = poziv;
        }
    } 
    return min;
}

int main() {
	char ime[50];
	cout << "Unesite ime datoteke > ";
	cin >> ime;
	FILE *f = fopen(ime, "r");

	int n, S, i, j, k;
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &S);
    int skup[20], M[20][20], boje[20], max=0;
    bool found = false;
    
    for (i=0; i<S; i++)
        fscanf(f, "%d", &skup[i]);
        
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            for (k=0; k<S; k++) {
                if (abs(i-j) == skup[k]) {
                    found = true;
                    break;
                }
            } if (found)
                M[i][j] = 1;
            else M[i][j] = 0;
            found = false;
        }
    }
    
    for (i=0; i<n; i++) {
        int tmp = 0;
        for (j=0; j<n; j++)
            if (M[i][j] == 1)
                tmp++;
        if (tmp > max)
            max = tmp;
    } max++;

    for (i=0; i<n; i++)
        boje[i] = 0;

    int kr = kromatski(1, boje, 0, M, n);
    printf("Kromatski broj zadanog grafa je %d", kr);   
    return 0;
}
