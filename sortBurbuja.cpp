/* 1
 * @author: Carolina Arcos Prats y Jonathan Eidelman
 * @version: Agosto de 2013
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

/* 
 * El vector datos, es un vector global de tipo string en el que se almacenan 
 * los datos que ser�n organizados
 */
vector <string> datos;

/* 
 * El m�todo lecturaDeDocumento recibe el archivo que ser� ordenado y lo pone 
 * en el vector datos
 */
void lecturaDeDocumento (){
FILE *archivo;    //Archivo que se va a ordenar
    string linea;
    int i=0;
    archivo = fopen("2.txt", "r"); //Se abre el archivo
    ifstream palabra("2.txt"); 
    if (archivo==NULL) { /*Si el archivo no existe o no se pudo abrir, se emite
                          *  el mensaje Error al abrir el archivo */
        cout << ("Error al abrir el archivo") << endl;
    }
    do { /* mientras el archivo no sea nulo, ubica cada l�nea de �ste en una
          * posici�n del vector datos */
        palabra >> linea;
        datos.push_back(linea);
        i++;
    } while (palabra != NULL);    
    
    datos.erase(datos.end()); /*borra la �ltima posici�n del vector datos para
                               *que no quede repetida*/
}

/*
 * El m�todo comparar, analiza los datos del vector datos; si la posici�n [j]
 * es mayor que la posici�n [j+1], los intercambia y contin�a iterando haciendo
 * todos los cambios necesarios. en cada iteracion deja el elemento mayor en la ultima posicion 
 * esto es, la ultima posicion que no contenga un elemento mayor que �l.
 */
vector<string> comparar(vector<string> & datos){
	for(int i = 0; i < datos.size(); i++){
		for(int j = 0; j < datos.size() - 1; j++){
			if (datos[j] > datos [j+1]){ /* si el elemento de la
                                                 *  posici�n [j] es mayor que el
                                                 *  de la posici�n [j+1], los 
                                                 * intercambia implementando el 
                                                 * temporal */
				string tempo = datos [j];
				datos[j] = datos [j+1];
				datos[j+1] = tempo;
			}
		}
	}
	return datos;
}

/*
 * El m�todo imprimir se encarga de imprimir cada una de las posiciones del
 *  vector
 */
void imprimir (vector<string> datos){
	for(int i = 0; i < datos.size(); i++){
		cout << datos[i] << endl;
	}
}

/*
 * El m�todo main es el ejecutable del programa
 */
int main(){
	clock_t inicio, fin; /*declaraci�n de las variables para medir el tiempo 
                         * de ordenamiento*/
	lecturaDeDocumento(); // se imvoca el m�todo lecturaDeDocumento
	inicio = clock(); // se inicia el tiempo de conteo del ordenamiento
	comparar(datos); /*se invoca el m�todo comparar para analizar y 
                         * organizar los datos*/
        fin = clock(); //se termina el tiempo de conteo del ordenamiento
	imprimir(datos); /*se invoca el m�todo imprimir para mostrar los datos 
                         * ordenados*/
	float tiempoTotal = (fin - inicio) / 1000;	
	cout << "El tiempo de ejecucion fue de " << tiempoTotal << " Segundos"
                << endl; /*muestra el tiempo total de ordenamiento restando el 
        tiempo final menos el inicial*/
	cout << datos.capacity()*sizeof(string) << " Bytes" << endl; /*indica la
                                                 * memoria utilizada en el 
                                                 * ordenamiento de los datos en 
                                                 * Bytes*/
	
	return 0;
}

