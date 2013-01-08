#include <iostream>
#include <vector>

using namespace std;

vector< vector<short> > campo(102);

void calcular(vector< vector<short> > &campo, int m, int n, int field)
{
	for (int f=1; f<=m; f++){
		for (int c=1; c<=n; c++){
			if (campo[f][c] == -1){ //hay una mina, sumar 1 a los adyacentes si no son minas
				if (campo[f-1][c-1] != -1) campo[f-1][c-1]++;
				if (campo[f-1][c] != -1) campo[f-1][c]++;
				if (campo[f-1][c+1] != -1) campo[f-1][c+1]++;
				if (campo[f][c-1] != -1) campo[f][c-1]++;
				if (campo[f][c+1] != -1) campo[f][c+1]++;
				if (campo[f+1][c-1] != -1) campo[f+1][c-1]++;
				if (campo[f+1][c] != -1) campo[f+1][c]++;
				if (campo[f+1][c+1] != -1) campo[f+1][c+1]++;
			}
		}
	}
	
	//mostrar el nuevo campo
	if (field != 1) printf("\n");
	printf("Field #%i:\n", field);
	for (int f=1; f<=m; f++){
		for (int c=1; c<=n; c++){
			if (campo[f][c] == -1)
				printf("*");
			else
				printf("%i", campo[f][c]);
		}
		printf("\n");
	}
}

int main()
{
	//inicializar campo vacío de 100x100
	vector<short> ini(102, 0);
	for (int i=0; i<102; i++){
		campo[i]=ini;
	}
	
	int field=0;
	
	int m, n;
	scanf("%i %i", &m, &n);
	char t[100];
	while (m != 0 && n != 0){
		field++;
		for (int i=1; i<=m; i++){
			vector<short> fila(n+2);
			scanf("%s", t);
			for (int j=0; j<n; j++){
				if (t[j]=='*') fila[j+1]=-1;
				else fila[j+1]=0;
			}
			campo[i] = fila;
		}
		calcular(campo, m, n, field);
		scanf("%i %i", &m, &n);
	}

	return 0;
}
