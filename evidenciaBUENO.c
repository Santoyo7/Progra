/*
Evidencia 1 
TC1031: Programación de estructuras de datos y algoritmos fundamentales
Fernando Santoyo Moncada A01028389
NOMBRE
NOMBRE
*/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<winsock.h>
#include<locale.h>

struct lista
{
	int info;
	struct lista *sig,*ant;
}*CAB=NULL,*AUX=NULL,*P=NULL,*FD=NULL,*QD=NULL,*Fd=NULL,*Qd=NULL;
int main()
{
	
	void insertar(void);
	void visualizar(void);
//	void insertarVarios(void);
	void eliminar();
//	void eliminarVarios();
//	void eliminarTodo();	
//	void buscar(void);
	void listaVacia();
//	void numeroNodos
	
	
	char opc;
	do{
		
		
		printf("\n| SELECCIONE UNA OPCION             |\n");
		printf("| 1) INSERTAR                       |\n");
		printf("| 2) AÑADIR VARIOS                  |\n");
		printf("| 3) VISUALIZAR                     |\n");
		printf("| 4) ELIMINAR                       |\n");
		printf("| 5) ELIMINAR VARIOS                |\n");
		printf("| 6) ELIMINAR TODO                  |\n");
		printf("| 7) BUSCAR                         |\n");
		printf("| 8) NUMERO DE NODOS                |\n");
		printf("| 9) ESTADO DE LA LISTA             |\n");
		
		
		
		opc=getch();
		switch(opc)
		{
		case '1':
			insertar();
			break;
		case '2':
	//		insertarVarios();
			break;
		case '3':
			visualizar();
			break;
		case '4':
			eliminar();
			break;
		case'5':
	//		eliminarTodo();
			break;
		case '6':
	//		eliminarVarios();
			break;
		case '7':
	//		buscar();
			break;
		case '8':
	//		numeroNodos();
			break;
		case '9':
			listaVacia();
			break;
	
	
		}
		
	}while(opc!='10');
	getch();
	return 0;
}

void listaVacia(void)
{
	if(CAB==NULL){
		printf("\nLISTA VACIA\n");
		
	}else{
		printf("\nLA LISTA NO ESTA VACIA\n");
		
	};
}


void visualizar(void)
{
	if(CAB==NULL){
		printf("\nLISTA VACIA\n");
		getchar();
	}
	AUX=CAB;
	printf("LISTA:\n\n");
	while(AUX->sig!=CAB){
		printf("->%d\n",AUX->info);
		AUX=AUX->sig;
	}
	if(AUX->sig==CAB){
		printf("->%d\n",AUX->info);
	}
	getch();
}


void insertar(void)
{
	
	AUX=(struct lista *)malloc(sizeof(struct lista));
	printf("\nINGRESE UN NUMERO ENTERO: ");
	scanf("%d",&AUX->info);
	AUX->sig=CAB; 
	AUX->ant=CAB; 
	if(CAB==NULL){ 
		CAB=AUX;
		P=AUX;
	}else{ 
		while(P->sig!=CAB){
			P=P->sig;
		}
	}
	P->sig=AUX; 
	AUX->ant=P;
	CAB->ant=AUX;
}




void eliminar(){
	int x;
	printf("INGRESE UN NUMERO PARA ELIMINAR EL SIGUIENTE: ");
	scanf("%d",&x);
	x=x+1;
	FD=CAB;
	QD=CAB;
	while(FD->info!=x&&FD->sig!=CAB){ 
		FD=FD->sig; 
	}
	QD=FD->sig;
	if(FD->sig==CAB&&FD->info==x){
		printf("\nEL NUMERO INGRESADO NO SE ENCUENTRA EN LA LISTA O ES LA CABECERA");
	}else
	   if(FD->sig==CAB&&FD->info!=x){
		printf("\nEL NUMERO INGRESADO NO SE ENCUENTRA EN LA LISTA O ES LA CABECERA");
	}else{
		   FD->sig=QD->sig;
		   (QD->sig)->ant=FD;
		   printf("\nELIMINADO %d",QD->info);
		   free(QD); 
	   }
	   getch();
}




