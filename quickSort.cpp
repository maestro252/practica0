
/*
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
 *El vector datos, es un vector global de tipo string en el que se almacenan los 
 * datos que serán organizados
 */
vector<string> datos;

/* 
 * El método lecturaDeDocumento recíbe el archivo que será ordenado y lo pone 
 * en el vector datos
 */
void lecturaDeDocumento (){
FILE *archivo; //Archivo que se va a ordenar    
    string linea;
    int i=0;
    archivo = fopen("4.txt", "r"); //Se abre el archivo
    ifstream palabra("4.txt");
    if (archivo==NULL) { /*Si el archivo no existe o no se pudo abrir, se emite
                          * el mensaje Error al abrir el archivo*/
        cout << ("Error al abrir el archivo") << endl;
    }
    do { /*mientras el archivo no sea nulo, ubica cada línea dde éste en una 
          * posición del vector datos*/
        palabra >> linea;
        datos.push_back(linea);
        i++;
    } while (palabra != NULL);    
    
    datos.erase(datos.end()); /*borra la última posición del vector datos para 
                               * que no quede repetida*/
}

/*
 * El método quickSort se encarga de analizar los datos y organizarlos;
 * selecciona el contenido de la posición exacta en la mitad del arreglo como pivote y lo
 * mueve de tal manera que a su izquiera queden los valores menores a el, y a su
 * derecha los valores mayores a el; luego de manera recursiva, realiza el mismo
 * procedimiento para los subvectores formados a saber: el de la izquierda del elemento ya colocado
 * y el de la izquierda del mismo.
 */
void quickSort(vector<string> & datos, int izq, int der){
	int i, d;
	i = izq;
	d = der;
	int mitad = (i + d) / 2;
	string pivote = datos[mitad];
	string tempo;	
	while(i < d){
		while (datos[i] < pivote && i < der) i++; /*aumenta i mientras
                                                         * el valor de la posi-
                                                         * cion i sea menor a la
                                                         * del pivote y sea menor
                                                         * que der */
		while (pivote < datos[d] && d > izq) d--; /*disminuye d mientras
                                                         * el valor de la posi-
                                                         * ción d sea mayor a la
                                                         * del pivote y sea mayor
                                                         * que izq */
		if (i <= d) { /*si i es menor o igual que d, cambia los valores
                         * del vector en el índica i con el del índice d */
			tempo = datos[i];
			datos[i] = datos[d];
			datos[d] = tempo;
			i++;
			d--;
		} 			
	} 	
	if(izq < d){ // recursividad para el subvector de la izquierda	
		quickSort (datos, izq, d);
	}
	if(der > i){ // recursividad para el subvector de la derecha
		quickSort (datos, i, der);		
	}	
}

/*
 * El método imprimir se encarga de imprimir cada una de las posiciones del
 *  vector
 */
void imprimir (vector<string> datos){
	for (int i = 0; i < datos.size(); i++){
		cout << datos[i] << endl;
	}
	cout << endl;
}

/*
 * El método main es el ejecutable del programa
 */
int main (){
        clock_t inicio, fin; /*declaración de las variables para medir el tiempo
                              *  de ordenamiento*/
	lecturaDeDocumento();// se invoca el método lecturaDeDocumento	
	inicio = clock(); // se inicia el tiempo de conteo del ordenamiento
	quickSort(datos,0, datos.size() - 1); /*se invoca el método quickSort para 
                                         * ordenar los datos del vector datos, 
                                         * desde la posición cero hasta la 
                                         * longitud del vector*/
	fin = clock(); //se termina el tiempo de conteo del ordenamiento
	float tiempoTotal = fin - inicio; // tiempo total de ordenamiento
	imprimir(datos); /*se invoca el método imprimir para mostrar los datos 
                         * ordenados*/
	cout << "El tiempo real de ejecucion fue " << tiempoTotal 
                << " Milisegundos" << endl;
	cout << "El tiempo en segundos es " << (tiempoTotal / 1000) << endl;
	cout << datos.capacity()*sizeof(string) << " Bytes" << endl; /*indica la
                                         *  memoria utilizada en el ordenamiento
                                         *  de los datos en Bytes*/
	return 0;
}
