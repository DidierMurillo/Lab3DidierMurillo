#include <iostream>
using namespace std;

int Impresion(int**,int);
int main(){
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
                                cin>>Fila[i];
                        }
                        for (int j = 0; j < NMatriz; ++j)
                        {
                                Matriz[i][j]=Fila[i];
                        }
                }        
        }else{
                cout<<"El tamaño es muy pequeño";
        } 

        if(Impresion(Matriz,NMatriz)==1){
                cout<<"Matriz invalida ";
        }else{
                cout<<"Matriz Valida se procedera a iniciar el juego";
        }
}


int Impresion(int** Matriz,int NMatriz){
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
