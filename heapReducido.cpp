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
 * datos que serán organizados
 */
vector<string> datos;

/*
 * El método lecturaDeDocumento recíbe el archivo que será ordenado y lo pone
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
  do { /*mientras el archivo no sea nulo, ubica cada línea dde éste en una
	* posición del vector datos*/
    palabra >> linea;
    datos.push_back(linea);
    i++;
  } while (palabra != NULL);

  datos.erase(datos.end()); /*borra la última posición del vector datos para
			     * que no quede repetida*/
}
void ordenar (){
  make_heap(datos.begin(), datos.end());
  sort_heap(datos.begin(), datos.end());

}

int main(){
  lecturaDeDocumento();
  //for (int i = 0; i < datos.size(); i++){
  //cout << datos[i] << endl;
  //}
  clock_t inicio, fin;
  inicio = clock();
  ordenar();
  fin = clock();
  for (int i = 0; i < datos.size(); i++){
    cout << datos[i] << endl;
  }
  double tiempototal = (fin - inicio) / 1000;
  cout << "El tiempo total de ordenamiento fue " << tiempototal << endl;
  return 0;
}
