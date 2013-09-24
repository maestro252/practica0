#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

/* 
 *El vector datos, es un vector global de tipo string en el que se almacenan los 
 * datos que ser�n organizados
 */
vector<string> datos;

/* 
 * El m�todo lecturaDeDocumento rec�be el archivo que ser� ordenado y lo pone 
 * en el vector datos que a futuro sera modificado para que quede ordenado
 */
void lecturaDeDocumento (){
FILE *archivo; //Archivo que se va a ordenar    
    string linea;
    int i=0;
    archivo = fopen("3.txt", "r"); //Se abre el archivo
    ifstream palabra("3.txt");
    if (archivo==NULL) { /*Si el archivo no existe o no se pudo abrir, se emite
                          * el mensaje Error al abrir el archivo*/
        cout << ("Error al abrir el archivo") << endl;
    }
    do { /*mientras el archivo no sea nulo, ubica cada l�nea dde �ste en una 
          * posici�n del vector datos*/
        palabra >> linea;
        datos.push_back(linea);
        i++;
    } while (palabra != NULL);    
    
    datos.erase(datos.end()); /*borra la �ltima posici�n del vector datos para 
                               * que no quede repetida*/
}
/*
 * El m�todo imprimir se encarga de imprimir cada una de las posiciones del
 *  vector
 */
 void imprimir(vector<string> datos){
    for(int i = 0; i < datos.size(); i++){
        cout << datos[i] << endl;
    }
    
} 

void ubicarCorrecto(int inicial, int longitud) // funcion encargada de hacer que el heap quede de tal forma que 
												// que todo nodo padre sea mayor que sus hijos, y todo hijo
												//izquierdo sea mayor que el derecho.
{
    int nodo = inicial;	
    while ((nodo*2)+1 <= longitud)				//limita que se comparen solo hasta la cantidad de nodos que existen
    {
        int menorIzquierdo = (nodo * 2) + 1;	//las posiciones de un heap son dadas asi, es decir el hijo izquierdo
        										// es dos veces mas la unidad que el padre
        int menorDerecho = menorIzquierdo + 1;  // analogamente, el derecho es una unidad mas que el izquierdo
        int cambiar = nodo;
        if (datos[cambiar] < datos[menorIzquierdo])	//compara si el padre y el hijo izquierdo cumplen la condicion del heap
        {
            cambiar = menorIzquierdo;				// de no cumplirla los va a cambiar
        }
        if ((menorDerecho <= longitud) && (datos[cambiar] < datos[menorDerecho])) //revisa lps hermanos y de ser neceserio los intercambiara
        {
            cambiar = menorDerecho;
        }
        if (cambiar != nodo) 						// si los indices indican que debe haber un cambio, se efectua
        {
            string tmp = datos[nodo];
            datos[nodo] = datos[cambiar];
            datos[cambiar] = tmp;
            nodo = cambiar;
        }
        else
        {
            break;						// de lo contrario se sale del ciclo
        }
    }
    return;
}
void crearHeap(int inicial, int longitud) //esta funcion se encarga de crear la estructura del heap dentro del arreglo
											// y con ayuda de la funcion ubicarCorrecto la vuelve valida
{
  int mitad = (longitud - inicial -1)/2; //al comenzar por el elemento de la mitad, esta empezando por el padre
    										// cuyo hijo izquierdo o derecho sera el ultimo elemento del arbol binario,
    										// es decir esta creando el arbol binario desde la ultima rama en forma inversa
   										//hasta la raiz
  //int mitad = longitud - 1 se puede hacer asi, e igual quedaria ordenado, no hay diferencia alguna, salvo que en el primer caso
  //ordena primero la mitad y despues ingresa uno por uno, y en este ordenada todos en un solo paso. 
    while (mitad >= 0)
    {
        ubicarCorrecto(mitad, longitud);	// se efectuan los cambios necesarios para que el orden sea apropiado
        --mitad;
    }
    return;
}
void heapSort(int size){ // funcion que se encarga de recorrer el arbol binario y rapidamente entregar en el vector los datos
						 //ordenados
   
    crearHeap(0, size-1); //crea el heap
    int longitud = size - 1; //define que el ultimo dato ya va a estar ordenado pues es el mayor, y asume que hay que continuar
    						 // on un arbol de una longitud menor en un elemento
    while (longitud > 0)
    {
        //secuencua de instrucciones donde la raiz del arbol se coloca en la ultima posicion del arreglo por ser el dato mayor
        //y se toma la ultima rama como nueva raiz y se vuelve a iterar buscando de nuevo que la raiz se convierta en el mayor dato
        string tmp = datos[longitud];
        datos[longitud] = datos[0];
        datos[0] = tmp;
        --longitud;
        ubicarCorrecto(0, longitud);
        
    }
    return;
}
int main(){
    clock_t inicio2, fin2; //se declaran las variables que tomaran el tiempo.
    lecturaDeDocumento();	//se lee el documento para ingresar los datos en el arreglo
    inicio2 = clock();		// se inicia a contar el tiempo
    heapSort(datos.size());	//se ordenan los datos
    fin2 = clock();			//se termina de contar el tiempo
    double tiempoTotal = (fin2 - inicio2) / 1000; //se convierte el tiempo de milisegundos a segundos
    imprimir(datos);		//se imprimen los datos ya ordenados y se procede a dar el resto de informacion
    cout << "El tiempo total de ordenamiento fue " << tiempoTotal 
            << " Segundos" << endl;
    	cout << "La memoria utilizada en el proceso fue ";
	cout << datos.capacity()*sizeof(string) << " Bytes" << endl;
    return 0;
    
}

