//
//  main.cpp
//  Ejercicio7T8
//
//  Created by Dani on 02/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#include <iostream>
#include "Tabla.h"
#include "Lista.h"

using namespace std;

void cuentaLineas(Lista<Lista<string>> &texto);
void printTabla(Tabla<string, Lista<int>> &tabla);

int main(int argc, const char * argv[]) {
    
    Lista<string> linea1;
    linea1.ponDr("hola");
    linea1.ponDr("como");
    linea1.ponDr("estas");
    
    Lista<string> linea2;
    linea2.ponDr("como");
    linea2.ponDr("estas");
    linea2.ponDr("tu");
    
    Lista<string> linea3;
    linea3.ponDr("estas");
    linea3.ponDr("tu");
    linea3.ponDr("hoy");
    
    Lista<string> linea4;
    linea4.ponDr("tu");
    linea4.ponDr("hoy");
    linea4.ponDr("bañera");
    
    Lista<string> linea5;
    linea5.ponDr("hoy");
    linea5.ponDr("bañera");
    linea5.ponDr("caliente");
    
    Lista<Lista<string>> texto;
    texto.ponDr(linea1);
    texto.ponDr(linea2);
    texto.ponDr(linea3);
    texto.ponDr(linea4);
    texto.ponDr(linea5);
    
    cuentaLineas(texto);
    
    return 0;
}

void cuentaLineas(Lista<Lista<string>> &texto) {
    
    Tabla<string, Lista<int>> cuentas;
    
    Lista<Lista<string>>::Iterador itlineas = texto.principio();
    
    while ( itlineas != texto.final() ) {
        
        Lista<string> linea = itlineas.elem();
        
        Lista<string>::Iterador itpalabras = linea.principio();
        
        int contadorLinea = 1;
        
        while (itpalabras != linea.final()) {
            
            Lista<int> lineas;
            
            if ( cuentas.esta(itpalabras.elem()) ) {
                
                lineas = cuentas.consulta(itpalabras.elem());
            }
            
            lineas.ponDr(contadorLinea);
            
            cuentas.inserta(itpalabras.elem(), lineas);
            
            contadorLinea++;
            
            itpalabras.avanza();
        }
        
        itlineas.avanza();
    }
    
    printTabla(cuentas);
}

void printTabla(Tabla<string, Lista<int>> &tabla) {
    
    Tabla<string, Lista<int>>::Iterador it = tabla.principio();
    
    while ( it != tabla.final() ) {
        
        cout << it.clave() << " lienas: ";
        
        Lista<int> lineas = it.valor();
        
        Lista<int>::Iterador itLineas = lineas.principio();
        while ( itLineas != lineas.final()) {
            cout << itLineas.elem();
            cout << ",";
            
            itLineas.avanza();
        }
        
         cout << endl;
        
        it.avanza();
    }
}