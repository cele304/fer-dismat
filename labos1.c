#include <stdio.h>
#include <math.h>

int main() {
	int n, i;
	float l1, l2, a0, a1, an, x1, x2, A, B;
	
	printf("Unesite prvi koeficijent lambda_1 rekurzivne relacije > ");
	scanf("%f", &l1);
	printf("Unesite drugi koeficijent lambda_2 rekurzivne relacije > ");
	scanf("%f", &l2);
	printf("Unesite vrijednost nultog clana niza a0 > ");
	scanf("%f", &a0);
	printf("Unesite vrijednost prvog clana niza a1 > ");
	scanf("%f", &a1);
	printf("Unesite redni broj n trazenog clana niza > ");
	scanf("%d", &n);
	printf("\n");
	
	x1 = (l1 + sqrt(pow(- l1, 2) - 4 * (- l2))) / 2;
	x2 = (l1 - sqrt(pow(- l1, 2) - 4 * (- l2))) / 2;
	
	if(x1 == x2) {
		A = a0;
		B = (a1 - x1 * A) / x2;
		an = A * pow(x1, n) + B * n * pow(x2, n);
	} else {
		A = (a1 - a0 * x2) / (x1 - x2);
		B = a0 - A;
		an = A * pow(x1, n) + B * pow(x2, n);
	}	
	printf("Vrijednost n-tog clana niza pomocu formule: %f\n", an);
	

	for(i = 0; i <= n - 2; i++) {
		an = l1 * a1 + l2 * a0;
		a0 = a1;
		a1 = an;
	}	
	printf("Vrijednost n-tog clana niza iz rekurzije: %f", an);
	
	return 0;
}
