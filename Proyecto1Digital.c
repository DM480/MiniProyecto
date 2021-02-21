/*
 * File:   Proyecto1Digital.c
 * Author: diegomazariegos
 *
 * Created on February 20, 2021, 2:55 PM
 */


#include <xc.h>
#include <stdio.h>
#include "config.h"
#define  _XTAL_FREQ 8000000;

//******************************************************************************
//                              VARIABLES
//******************************************************************************

int pote;

//******************************************************************************
//                     PROTOTIPOS DE FUNCIONES
//******************************************************************************

void setup(void);

void __interrupt () interrupcion(void);


//******************************************************************************
//                           CONFIGURACION
//******************************************************************************

void setup(void){
    
    ANSEL  = 0B00000001;
    ANSELH = 0;
    
    TRISA = 0B000000001;
    PORTA = 0;
    
}

//******************************************************************************
//                           FUNCION DE INTERRUPCION
//******************************************************************************

void __interrupt () interrupcion(){
    
    if(PIR1bits.ADIF == 1){
        pote  = ADRESH;
        PIR1bits.ADIF = 0;
}
}


void main(void) {
    
    OSCCONbits.IRCF  = 0B111;     
    OSCCONbits.SCS   = 1;
    
    //__delay_ms(100);
    ADCON0bits.ADON  = 1;
    ADCON0bits.CHS   = 0B0000;
    ADCON0bits.ADCS  = 0B11;
    ADCON1bits.ADFM  = 0;   //Justificacion a la izquierda de los bits mas significativos
    ADCON1bits.VCFG0 = 0;       //Voltaje de referencia negativa pos = VDD
    ADCON1bits.VCFG1 = 0;       //Voltaje de referencia negativa neg = VSS
    INTCONbits.GIE  = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE   = 1;
    PIR1bits.ADIF   = 0;

    
    while(1){
        
    }
    
    return;
}
