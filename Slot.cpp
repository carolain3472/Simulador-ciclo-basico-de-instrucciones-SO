/*
  Archivo: Slot.cpp

  Fecha creación: 2022-05
  Fecha última modificación: 2022-05
*/

#include "Slot.h" 

Slot::Slot(string posicion, int valor)
{
  this->posicion=posicion;
  this->valor=valor;
 
}

Slot::~Slot()
{
  //No hace nada
}

int Slot::obtenerValor()
{
  return valor;
}
  
string Slot::obtenerPosicion()
{
  return posicion;
}

void Slot::cambiarValor(int nuevoValor)
{
  this->valor = nuevoValor;
}
