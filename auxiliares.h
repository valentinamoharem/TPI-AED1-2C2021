#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

// Auxiliares Generales

bool esSuHogar(hogar h, individuo i);

// Auxiliares Problema 1

bool esValida(eph_h th, eph_i ti);

// Auxiliares Problema 2

int maximaCantidadHabitaciones (eph_h th, int region);

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones);

// Auxiliares Problema 3

float proporcionCasasConHC(eph_h th, eph_i ti, int region);

// Auxiliares Problema 4

float proporcionTeleworking(eph_h th, eph_i ti);

// Auxiliares Problema 5

int cantidadDeHabitantes (int codusu,eph_i ti);

// Auxiliares Problema 6

bool sinRepetidos(vector < par_hi > pair);

// Auxiliares Problema 9

// Auxiliares Problema 10

int cantidadHogaresEnAnillo(int distDesde, int distHasta, pair <int ,int> centro, eph_h th);

// Auxiliares Problema 11

bool cumpleCondicion(vector < pair < int, dato > >  busqueda, individuo);

#endif //SOLUCION_AUXILIARES_H
