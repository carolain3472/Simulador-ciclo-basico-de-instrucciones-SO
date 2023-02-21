
/*
  Archivo: Procesador.cpp

  Fecha creación: 2022-05
  Fecha última modificación: 2022-06-16
*/

#include "Procesador.h"  



Procesador::Procesador(Memoria* memoria)
{
  this->memoriaPrincipal=memoria;
    
  this->contadorPrograma_PC=0;
  this->controlMemoria_ICR="";
  this->accesoMemoria_MAR="";
  this->datosMemoria_MDR="";
  //this->unidadDeControl_UC="";

  this->acumulador=0;
  this->ALU=0;
  
  
 
}

Procesador::~Procesador()
{
  //No hace nada
}

void Procesador::comenzarEjecucion(int instruccionInicial)
{
  //Obtener PC
  this->contadorPrograma_PC = instruccionInicial;
  while(true)
  {
    //decirle al procesador que direccion de memoria buscar
    //se carga el MAR con lo que hay en el PC
    this->accesoMemoria_MAR = to_string(this->contadorPrograma_PC);
    //obtiene la informacion de la memoria
    instruccion = memoriaPrincipal->obtenerInstruccion(stoi(accesoMemoria_MAR));
    //devuelve la informacion que habia en esa parte de la memoria
    //se carga en el MDR lo que se obtuvo de la memoria
    this->datosMemoria_MDR = instruccion.at(0);
    //se carga el ICR con la instruccion a ejecutar  
    this->controlMemoria_ICR=datosMemoria_MDR;
    //aumenta el contador de programa
    contadorPrograma_PC++;
    //se envia la instruccion a la unidad de control para ser ejecutada
      this->unidadDeControl_UC = instruccion;
    
    if(datosMemoria_MDR=="END")
    {
      //si la instruccion es un END el proceso termina su ejecucion
      cout<<"Termino el proceso";
      break;      
    }
    else
    {
      unidadDeControl();
    }   
    
  }
}



//funcion de la unidad de control

void Procesador::unidadDeControl()
{  
  if(controlMemoria_ICR=="SET")
  {
    set();    
  }
  if(controlMemoria_ICR=="LDR")
  {
    ldr();
  }
  
  if(controlMemoria_ICR=="SHW")
  {
    shw();
  }

  if(controlMemoria_ICR=="ADD")
  {
    add();
  }

  if(controlMemoria_ICR=="STR")
  {
    str();
  }

  if(controlMemoria_ICR=="SUB")
  {
    sub();
  }

  if(controlMemoria_ICR=="MUL")
  {
    mul();
  }

  if(controlMemoria_ICR=="DIV")
  {
    div();
  }

  if(controlMemoria_ICR=="INC")
  {
    inc();
  }
  
  if(controlMemoria_ICR=="DEC")
  {
    dec();
  }

  if(controlMemoria_ICR=="MOV")
  {
    mov();
  }

  if(controlMemoria_ICR=="BEQ")
  {
    beq();
  }

}


//funciones de las instrucciones

void Procesador::set()
{
  memoriaPrincipal -> almacenarPosicion(instruccion);
}

void Procesador::ldr()
{
  this->accesoMemoria_MAR = unidadDeControl_UC.at(1);
  this->datosMemoria_MDR= to_string(memoriaPrincipal->obtenerValor(accesoMemoria_MAR));
  this->acumulador= stoi(datosMemoria_MDR);
}

void Procesador::shw()
{
  if(unidadDeControl_UC.at(1)=="ACC")
  {
    cout<<"Valor acumulador:"+to_string(getAcumulador())<<endl;
  }
  else if(unidadDeControl_UC.at(1)=="ICR")
  {
    cout<<"Registro ICR:"+getICR()<<endl;
  }
  else if(unidadDeControl_UC.at(1)=="MAR")
  {
    cout<<"Registro MAR:"+getMAR()<<endl;
  }
  else if(unidadDeControl_UC.at(1)=="MDR")
  {
    cout<<"Registro MDR:"+getMDR()<<endl;
  }
  else if(unidadDeControl_UC.at(1)=="UC")
  {
    cout<<"Registro UC:"+getUC()<<endl;
  }
  else
  {
    this->accesoMemoria_MAR = unidadDeControl_UC.at(1);
    this->datosMemoria_MDR= to_string(memoriaPrincipal->obtenerValor(accesoMemoria_MAR));
    cout<<datosMemoria_MDR<<endl;    
  }

}

void Procesador::add()
{
  if(unidadDeControl_UC.at(2) != "NULL")
  {
    ldr();
    unidadDeControl_UC.erase(unidadDeControl_UC.begin()+1); 
  }
  
  this->ALU= this->acumulador; 
  ldr();
  this->ALU += this->acumulador; 
  this-> acumulador = this-> ALU;

  if(unidadDeControl_UC.at(2) != "NULL")
  {
    unidadDeControl_UC.erase(unidadDeControl_UC.begin()+1);
    str();
    
  }
}

void Procesador::str()
{
  this->accesoMemoria_MAR = unidadDeControl_UC.at(1);
  this->datosMemoria_MDR= to_string(this->acumulador);
  memoriaPrincipal->cambiarValor(accesoMemoria_MAR, stoi(datosMemoria_MDR));
}

void Procesador::sub()
{
  if(unidadDeControl_UC.at(2) != "NULL")
  {
    ldr();
    unidadDeControl_UC.erase(unidadDeControl_UC.begin()+1); 
  }
  
  this->ALU= this->acumulador; 
  ldr();
  this->ALU -= this->acumulador; 
  this-> acumulador = this-> ALU;

  if(unidadDeControl_UC.at(2) != "NULL")
  {
    unidadDeControl_UC.erase(unidadDeControl_UC.begin()+1);
    str();
    
  }

}

void Procesador::mul()
{
  //PREGUNTAR
  if(unidadDeControl_UC.at(2) != "NULL")
  {
    ldr();
    unidadDeControl_UC.erase(unidadDeControl_UC.begin()+1); 
  }
  
  this->ALU= this->acumulador; 
  ldr();
  this->ALU *= this->acumulador; 
  this-> acumulador = this-> ALU;

  if(unidadDeControl_UC.at(2) != "NULL")
  {
    unidadDeControl_UC.erase(unidadDeControl_UC.begin()+1);
    str();
    
  }
}

void Procesador::div()
{
  //Preguntar
  this->ALU= this->acumulador; 
  ldr();
  this->ALU /= this->acumulador; 
  this-> acumulador = this-> ALU;
}

void Procesador::inc()
{
  ldr();
  this->ALU= this->acumulador; 
  this->ALU += 1;
  this-> acumulador = this-> ALU;
  str();
}

void Procesador::dec()
{
  ldr();
  this->ALU= this->acumulador; 
  this->ALU -= 1;
  this-> acumulador = this-> ALU;
  str();
}

void Procesador::mov()
{
  ldr();
  memoriaPrincipal->eliminarDireccion(accesoMemoria_MAR);
  this->accesoMemoria_MAR = unidadDeControl_UC.at(2);
  this->datosMemoria_MDR= to_string(this->acumulador);
  memoriaPrincipal->cambiarValor(accesoMemoria_MAR, stoi(datosMemoria_MDR));  
}

void Procesador::beq()
{
  sub();
  if(acumulador == 0)
  {
    str();    
  }
}

//obtener valores de los registros 

int Procesador::getPC()
{
  return this->contadorPrograma_PC;
}
  
string Procesador::getICR()
{
  return this->controlMemoria_ICR;
}
  
string Procesador::getMAR()
{
  return this->accesoMemoria_MAR;
}
  
string Procesador::getMDR()
{
  return this->datosMemoria_MDR;
}

string Procesador::getUC()
{
  string instruccionTexto;
  for(int posicionInstruccion=0; posicionInstruccion<unidadDeControl_UC.size(); posicionInstruccion++)
  {
    instruccionTexto += unidadDeControl_UC.at(posicionInstruccion);
  }

  return instruccionTexto;
}

int Procesador::getAcumulador()
{
  return this->acumulador;
}
