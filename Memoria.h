/*
  Archivo: Memoria.h

  Fecha creación: 2022-05
  Fecha última modificación: 2022-06-16
*/

/**
  @class Memoria
  @brief
  Atributos:
    - direcciones de memoria
    - instrucciones
    - id de la instruccion que se está ejecutando

  Relaciones:
    - contiene los slots de memoria o las direcciones en el vector de las direcciones de memoria (posiciones)
*/

#ifndef HH_MEMORIA
#define HH_MEMORIA


#include<string>
#include<vector>
#include "Slot.h"


using namespace std;

class Memoria
{
  protected:
    vector<Slot> posiciones;//carga valores
    vector<vector<string>>instrucciones;//carga instrucciones
    int num_instruccion;

  public:
    /**
      Constructor. Da valores iniciales a los atributos internos
    */
    Memoria(string nombreArchivo);
    /**
      Destructor. No hace nada
    */
    virtual ~Memoria();

    /**
      Almacenar todas las intrucciones menos las de tipo SET en un vector 
    */
    virtual void almacenarInstrucciones(string linea);
    
    /**
      Almacenar todas las intrucciones de tipo SET en un vector diferente al anterior
    */
    virtual void almacenarPosicion(vector<string> instruccion);

    /**
      Devuelve el valor que hay en una posicion en memoria
    */
    virtual int obtenerValor(string posicion);

    /**
      Devuelve el vector de una instrucion. Las posiciones del vector contienen las palabras de la instruccion
    */
    virtual vector<string> obtenerInstruccion(int posicion);
    /**
      cambia el valor de una direccion o slot por otro, si la direcion a la que se está queriendo acceder no existe, la crea. 
    */
    virtual void cambiarValor(string posicion, int nuevoValor);
    /**
      Devuelve el indicador de la posicion de ultima instruccion que se ejecutó
    */
    virtual int getNumInstruccion();
    /**
      elimina una direccion de la memoria
    */
    virtual void eliminarDireccion(string posicion);

    
};

#else
class Memoria; // Declaración adelantada
#endif
