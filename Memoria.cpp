/*
  Archivo: Memoria.cpp

  Fecha creación: 2022-05
  Fecha última modificación: 2022-06-16
*/

#include <fstream>
#include <sstream>
#include "Memoria.h"  
#include "Slot.h"


Memoria::Memoria(string nombreArchivo)
{
  //almacenar instrucciones
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  while (getline(archivo, linea))
  {
    almacenarInstrucciones(linea); 
  }

  //almacena los datos o variables de las instrucciones
  this->num_instruccion=0;
  
  while(instrucciones.at(num_instruccion).at(0)=="SET")
  {
    almacenarPosicion(instrucciones.at(num_instruccion));    
    this->num_instruccion++;
  } 
}

Memoria::~Memoria()
{
  //No hace nada
}

void Memoria::almacenarInstrucciones(string linea)
{
  vector<string> words;
  string word;
  stringstream sstream(linea);
  
  while(getline(sstream, word,' '))
  {
    words.push_back(word);
  }

  instrucciones.push_back(words);
}

void Memoria::almacenarPosicion(vector<string> instruccion)
{
  string posicion = instruccion.at(1);
  int valor = stoi(instruccion.at(2));
  Slot slot(posicion, valor);
  posiciones.push_back(slot);

}

int Memoria::obtenerValor(string posicionEnMemoria)
{
  for(int num_posiciones=0; num_posiciones<posiciones.size(); num_posiciones++)
  {
    if(posiciones.at(num_posiciones).obtenerPosicion()==posicionEnMemoria) 
    {
      return posiciones.at(num_posiciones).obtenerValor(); 
    }
  }
  return 0;
}
    
vector<string> Memoria::obtenerInstruccion(int posicionDeInstruccion)
{
  return instrucciones.at(posicionDeInstruccion);
}
  
void Memoria::cambiarValor(string posicionEnMemoria, int nuevoValor)
{
  bool isInMemoria = false;
  for(int num_posiciones=0;num_posiciones<posiciones.size(); num_posiciones++)
  {
    if(posiciones.at(num_posiciones).obtenerPosicion()==posicionEnMemoria) 
    {
      isInMemoria = true;
      posiciones.at(num_posiciones).cambiarValor(nuevoValor); 
    }    
  }

  if(!isInMemoria)
  {
    vector<string> nuevaInstruccion = {"SET",posicionEnMemoria,to_string(nuevoValor)};    
    almacenarPosicion(nuevaInstruccion);
  }
}

int Memoria::getNumInstruccion()
{
  return num_instruccion;
}

void Memoria::eliminarDireccion(string posicionEnMemoria)
{
  for(int num_posiciones=0;num_posiciones<posiciones.size(); num_posiciones++)
  {
    if(posiciones.at(num_posiciones).obtenerPosicion()==posicionEnMemoria) 
    {
      posiciones.erase(posiciones.begin()+num_posiciones);
    }    
  }
  
}
