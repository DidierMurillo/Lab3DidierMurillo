#include <iostream>
using namespace std;
void Inicio(int**,int,int,int);
void Impresion(int**,int);
int Validar(int**,int);
void Problema();
void Binario(int);
void Imprimir(int*);
void Decimal(int);

int main(){
        int Respuesta=0;
        cout<<"Ingrese su opcion:";
        cin>>Respuesta;
        if(Respuesta==2){
                cout<<"Ingrese su opcion: Decimal-Binario 1 \n Binario-Decimal 2 \n Suma 3 \n";
                cin>>Respuesta;
                if(Respuesta==1){
                        cout<<"Ingrese el numero a convertir:";
                        int N=0;
                        cin>>N;
                        Binario(N);
                }if(Respuesta==2){
                  cout<<"Ingrese el numero a convertirir:";
                        int N=0;
                        cin>>N;
                        Decimal(N);
                }
        }else{
                int NMatriz;
                cout<<"Ingrese el tamaño del laberinto";
                cin>>NMatriz;
                int** Matriz=new int*[NMatriz];
                if(NMatriz>=3)
                {
                        for(int i=0;i<NMatriz;i++){
                                Matriz[i]=new int[NMatriz];
                                cout<<"Ingrese los numeros de fila del laberinto por digito;"<<"\n";
                                int Fila[NMatriz];
                                for (int x = 0; x < NMatriz; ++x)
                                {
                                        cin>>Fila[x];
                                }
                                for (int j = 0; j < NMatriz; ++j)
                                {
                                   Matriz[i][j]=Fila[j];
                                }
                        }
           }else{
                        cout<<"El tamaño es muy pequeño";
                }

                if(Validar(Matriz,NMatriz)==1){
                        cout<<"Matriz invalida ";

           }else{
                        cout<<"Matriz Valida se procedera a iniciar el juego"<<"\n";
                        Impresion(Matriz,NMatriz);
                        for(int i=0;i<NMatriz;i++){
                                for(int j=0;j<NMatriz;j++){
                                        if(Matriz[i][j]==2){
                                                Inicio(Matriz,i,j,NMatriz);
                                        }
                                }
                        }
                }
        }

}

int Validar(int** Matriz,int NMatriz){
        int Cont3=0;
        int Cont2=0;
        for (int i = 0; i < NMatriz; ++i)
        {
                for (int j = 0; j < NMatriz; ++j)
                {
                        if(Matriz[i][j]<=3){
                                if(Matriz[i][j]==2){
                                        Cont2++;
                                }
                                if(Matriz[i][j]==3){
                                  Cont3++;
                                }
                        }else{
                                return 1;
                        }

                }

        }
        if(Cont2==1&&Cont3==1){
                return 0;
        }
}

void Inicio(int** Matriz,int Y,int X,int Z){
        char Letra=' ';
        int Puntuacion=0;
        cout<<Y<<"\n"<<X;
        do{
                cout<<"Ingrese su movimiento Mayuscula";
                cin>>Letra;
                if(Letra=='W'&&Matriz[Y-1][X]==1){
                        Matriz[Y][X]=9;
                        Y--;
                        Matriz[Y][X]=2;
                        Impresion(Matriz,Z);
                        Puntuacion++;
                }else if(Letra=='W'&&Matriz[Y-1][X]==3){
                        Matriz[Y][X]=3;
                }
                if(Letra=='S'&&Matriz[Y+1][X]==1){
                        Matriz[Y][X]=9;
                        Y++;
                        Matriz[Y][X]=2;
                        Impresion(Matriz,Z);
                        Puntuacion++;
                        cout<<"Abajo";
                }else if(Letra=='S'&&Matriz[Y+1][X]==3){
                        Matriz[Y][X]=3;
                }
                if(Letra=='D'&&Matriz[Y][X+1]==1){
                        Matriz[Y][X]=9;
                        X++;
                        Matriz[Y][X]=2;
                        Impresion(Matriz,Z);
                        Puntuacion++;
                        cout<<"DErecha";
                }else if(Letra=='D'&&Matriz[Y][X+1]==3){
                        Matriz[Y][X]=3;
                }

                if(Letra=='A'&&Matriz[Y][X-1]==1){
                        Matriz[Y][X]=9;
                        X--;
                        Matriz[Y][X]=2;
                        Impresion(Matriz,Z);
                        Puntuacion++;
                        cout<<"Entro";
                }else if(Letra=='A'&&Matriz[Y][X-1]==3){
                        Matriz[Y][X]=3;
                }

        }while(Matriz[Y][X]!=3);
        cout<<"Completaste el Laberinto Felicidades Puntuacion:"<<Puntuacion<<"\n";
}

void Impresion(int** Matriz,int X){
        for (int i = 0; i < X; ++i)
        {
                for (int j = 0; j < X; ++j)
                {
                        cout<<"|"<<Matriz[i][j]<<"|";
                }
                        cout<<"\n";
        }
        cout<<"Siguiente Turno"<<"\n";
}

void  Binario(int Numero){
  int Bina[10];
  int Cont=0;
        while(Numero>0){
                Bina[Cont]=Numero%2;
                Numero=Numero/2;
                Cont++;
        }
        cout<<"Binario:"<<"--";
        for (int i=Cont-1;i>=0;--i)
        {
            cout<<Bina[i];
        }

}

void Decimal(int Deci){
  int Conversion[10];
  int Cont=0;
  int Cont2=0;
  int Total=0;
  while(Deci>=0){
      Conversion[Cont]=Deci%10;
      Deci=Deci/10;
      Cont++;
  }
  for (int i = 0; i < Cont; ++i)
  {
      if(Conversion[i]==1){
	int Sumatoria=Conversion[i]*2;
	for(int j=0;j<Cont2;j++){
		Sumatoria=Sumatoria*2;
	}
	Total+=Sumatoria;
	Cont2++;
      }else{
	Cont2++;
      }		
	
  }
  cout<<Total;
}
