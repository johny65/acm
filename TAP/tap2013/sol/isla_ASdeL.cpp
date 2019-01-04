//============================================================================
// Name        : isla_ASdeL.cpp
// Author      : Alejandro Strejilevich de Loma
// Version     : 2013-09-21
// Description : ACM ICPC 2013 TAP
//============================================================================

//-----elegir si se chequea o no el input (1/0)
#define CHECK_INPUT 0

//-----no cambiar desde aqui...

#if !CHECK_INPUT
    #define NDEBUG
#endif

#include <cassert>
//#include <fstream>
#include <iostream>
using namespace std;

void Entrada(void);
void Salida(void);

int main(void) {
    Entrada();
    Salida();
    return 0;
}

//-----...hasta aqui

//-----la solucion propiamente dicha desde aqui hasta el final

const long MaxF=500; // cantidad maxima de filas F
const long MaxC=500; // cantidad maxima de columnas C
const long MaxH=1000000; // altura maxima H

//#include <climits>

const long DeltaF[4]={0,1,0,-1};
const long DeltaC[4]={1,0,-1,0};
const long NoVisitado=-1;
const long SuperVisitado=-2; // LONG_MAX;

// input
long F, C, H[MaxF+2][MaxC+2];
// algoritmo
long ColaInicio, ColaFin, ColaF[MaxF*MaxC], ColaC[MaxF*MaxC], Tiempo[MaxF+2][MaxC+2];

bool PuedoLlegar(long Espera) { // globales DeltaF, DeltaC, NoVisitado, F, C, H, ColaInicio, ColaFin, ColaF, ColaC, Tiempo
	bool FueraDelBarco;
	long i, ActualF, ActualC, Tiempo1, NuevaF, NuevaC;
	ColaInicio=0;Tiempo[ColaF[0]=1][ColaC[0]=1]=Espera;ColaFin=1; // crea cola con [1][1] y visita; H[1][1]>=1 ==> nunca se intenta con una Espera con la que no pueda pisar esa celda
    do {
    	Tiempo1=Tiempo[ActualF=ColaF[ColaInicio]][ActualC=ColaC[ColaInicio]]+1;ColaInicio++; // desencola e incrementa tiempo
    	for (i=0; i<4; i++) {
    		NuevaF=ActualF+DeltaF[i];
    		NuevaC=ActualC+DeltaC[i];
    		if (Tiempo[NuevaF][NuevaC]==NoVisitado)
				if (H[NuevaF][NuevaC]>Tiempo1) {
					Tiempo[ColaF[ColaFin]=NuevaF][ColaC[ColaFin]=NuevaC]=Tiempo1;ColaFin++; // encola y visita
				}
    	}
    	FueraDelBarco=(Tiempo[F][C]==NoVisitado);
    } while (ColaInicio<ColaFin // cola no esta vacia
    	  && FueraDelBarco);
    for (i=0; i<ColaFin; i++)
    	Tiempo[ColaF[i]][ColaC[i]]=NoVisitado; // desvisita
	return !FueraDelBarco;
}

// entrada e inicializacion
void Entrada(void) { // globales F, C, H, Tiempo
	long i, j, F1, C1;
    cin >> F >> C;
    assert(1<=F && F<=MaxF);
    assert(1<=C && C<=MaxC);
    F1=F+1;
    C1=C+1;
    for (i=1; i<=F; i++) {
    	for (j=1; j<=C; j++) {
    	    cin >> H[i][j];
    	    assert(1<=H[i][j] && H[i][j]<=MaxH);
    	    Tiempo[i][j]=NoVisitado;
    	}
    	Tiempo[0][i]=Tiempo[F1][i]=Tiempo[i][0]=Tiempo[i][C1]=SuperVisitado;
    }
}

// solucion y salida
void Salida(void) { // globales F, C, H
	long SiPuedo, NoPuedo, TalvezPuedo;
	if (PuedoLlegar(SiPuedo=0)) {
		NoPuedo=min(H[1][1],H[F][C]-(F+C-2));
		while (NoPuedo-SiPuedo>1)
			if (PuedoLlegar(TalvezPuedo=(SiPuedo+NoPuedo)>>1))
				SiPuedo=TalvezPuedo;
			else
				NoPuedo=TalvezPuedo;
		cout << SiPuedo << endl;
	} else
		cout << -1 << endl;
}
