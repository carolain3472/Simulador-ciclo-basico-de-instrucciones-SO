/*
  Archivo: main.cpp

  Fecha creación: 2022-05
  Fecha última modificación: 2022-05
*/

/*
  @brief 
  HISTORIA: 
  Las instrucciones se procesan bajo la dirección de la unidad de control paso a paso.  
  Este codigo implementa un simulador de ciclo de instrucciones que obtiene las instrucciones de un archivo de texto plano llamado "instrucciones.txt"

*/
#include <iostream>
#include<string>
#include "Procesador.h"
#include "Memoria.h"

using namespace std;

int main() {

  Memoria memoria("instrucciones.txt");
  int num_instruccion = memoria.getNumInstruccion();
  Procesador procesador(&memoria);
  procesador.comenzarEjecucion(num_instruccion);
 
}

