/*
  Archivo: Slot.h

  Fecha creación: 2022-05
  Fecha última modificación: 2022-05
*/

/**
  @class Slot
  @brief
  Atributos:
    - direccion
    - valor 

*/

#ifndef HH_SLOT
#define HH_SLOT


#include<string>
#include<vector>

using namespace std;

class Slot
{
  protected:
    string posicion;
    int valor;

  public:
    /**
      Constructor. Da valores iniciales a los atributos internos
    */
    Slot(string posicion, int valor);
    /**
      Destructor. No hace nada
    */
    virtual ~Slot();
    /**
      Pregunta y retorna el valor de esa direccion 
    */
    virtual int obtenerValor();
    /**
      Pregunta y retorna el id de la direccion
    */
    virtual string obtenerPosicion();
    /**
      cambia el valor de esta dirrecion
    */
    virtual void cambiarValor(int nuevoValor);
    
    
};

#else
class Slot; // Declaración adelantada
#endif
