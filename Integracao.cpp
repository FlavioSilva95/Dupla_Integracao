#include <stdio.h>
#include <math.h>

float a, b, cons, expx, expy, lmta1, lmtb1, lmta2, lmtb2, passo1, passo2;
int n;

void telaInicio(){

	printf("%c\t\t\t\t\t\t\t\t\t%c\n", 218, 191);
	printf("%cO programa fara o calculo baseando-se uma funcao: (ax^d + by^e + c)\t%c\n"
		"%cSendo:\t'a' e 'b' coeficientes de suas respectivas icognitas (x, y)\t%c\n"
		"%c\t'd' e 'e' expoentes de suas respectivas icognitas (x, y)\t%c\n"
		"%C\t'c' constante\t\t\t\t\t\t\t%c\n"
		"%cObs: Torna possivel uma funcao com radicais, desde que seja inserido\t%c\n"
		"%ca razao (r/n) como expoente.\t\t\t\t\t\t%c\n"
		"%cSendo 'r' o valor do grau de exponenciacao do radicando e 'n' o indice\t%c\n", 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179);
	printf("%c\t\t\t\t\t\t\t\t\t%c\n", 192, 217);
}

bool inicializacao(){

	printf("\nDigite o valor de 'a' (coeficiente x): ");
	scanf("%f", &a);
	printf("\nDigite o valor de 'd' (expoente x): ");
	scanf("%f", &expx);
	printf("\nDigite o valor de 'b' (coeficiente y): ");
	scanf("%f", &b);
	printf("\nDigite o valor de 'e' (expoente y): ");
	scanf("%f", &expy);
	printf("\nDigite o valor de 'c' (constante): ");
	scanf("%f", &cons);
	printf("\nFuncao: (%.2fx^%.2f) + (%.2fy^%.2f) + %f\n", a, expx, b, expy, cons);

	while(true){	
		fflush(stdin);
		printf("Deseja continuar (s/n)? ");
		char op = fgetc(stdin);
		if (op == 's' || op == 'S') break;
		if (op == 'n' || op == 'N') return false;
	}

	printf("\nLimites\n");
	printf("Limite inferior (1a integral): ");
	scanf("%f", &lmta1);
	printf("Limite superior (1a integral): ");
	scanf("%f", &lmtb1);
	printf("Limite inferior (2a integral): ");
	scanf("%f", &lmta2);
	printf("Limite superior (2a integral): ");
	scanf("%f", &lmtb2);
	
	do{
		printf("Digite no numero de elementos 'n' (divisivel por 3): ");
		scanf("%d",&n);
		n = labs(n);
	}while(n%3 != 0);

	printf(	"Integral dupla:\n"
		"%c%.3f%c%.3f (%.2fx^%.3f) + (%.2fy^%.3f) + %f\n"
		"%c%.3f%c%.3f\n", 179, lmtb1, 179, lmtb2, a, expx, b, expy, cons, 179, lmta1, 179, lmta2);
	
	passo1 = (lmtb1 - lmta1) / n;
	passo2 = (lmtb2 - lmta2) / n;

	return true;
}

float integracao2(float arg){

	float integ = 0;
	int c = 1;
    
	for(int i = 0; i <= n; i++){
	    
		if (i == 0 || i == n) c = 1;
		else if (i%3 == 0) c = 2;
		else c = 3;
        
        float y = passo2*i + lmta2;
        float z = arg + b*pow(y, expy);
        printf("i = %d y = %f z = %f c = %d c*z = %f\n", i, y, z, c, c*z);

		integ += z * c;
		
		printf("Somatoria z: %f\n", integ);
	}
    
	printf("3*%f*(%f)/8 = %f\n", passo2, integ, 3*passo2*integ/8); 

	return 3*passo2*integ/8;
}

void integracao1(){

	float integ = 0;
	int c;

	for(int i = 0; i <= n; i++){
		
		if (i == 0 || i == n) c = 1;
		else if (i%3 == 0) c = 2;
		else c = 3;

		float x = a*pow(passo1*i + lmta1, expx);
		float y = integracao2(x + cons);
		printf("\nParcial (1a Integral):\n");
		printf("i = %d x = %f y = %f c = %d c*y = %f\n\n", i, x, y, c, c*y);
		integ += y*c;
	}

	printf("\nRESULTADO FINAL: 3*%f*(%f)/8 = %f\n------------------\n\n", passo1, integ, 3*passo1*integ/8);
}

int main(){

	telaInicio();
	printf("\n");

	while(true){

		printf("(0) - Sair\n(1) - Inserir uma nova funcao: ");
		fflush(stdin);

		switch(fgetc(stdin)){
		case 48: return 0;
		case 49: (inicializacao()) ? integracao1() : printf("\n...\n"); break;
		default: printf("Comando invalido!\n");
		}	
	}

	return 0;
}