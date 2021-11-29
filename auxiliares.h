#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

// Auxiliares Generales

bool esSuHogar(hogar h, individuo i);

// Auxiliares Problema 1

bool esVacia(vector<vector<int>> t);

bool esMatriz(vector<vector<int>> t);

bool cantidadCorrectaDeColumnasI(eph_i ti);

bool cantidadCorrectaDeColumnasH(eph_h th);

bool hayIndividuosSinHogares(eph_i ti, eph_h th);

bool hayHogaresSinIndividuos(eph_i ti, eph_h th);

bool hayRepetidosI(eph_i ti);

bool hayRepetidosH(eph_h th);

bool mismoAnioYTrimestre(eph_i ti, eph_h th);

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti);

bool cantidadValidaDormitorios(eph_h th);

bool valoresEnRangoI(eph_i ti);

bool valoresEnRangoH(eph_h th);

// Auxiliares Problema 2

bool esCasa(hogar h);

// Auxiliares Problema 3

float proporcionCasasConHC(eph_h th, eph_i ti, int region);

// Auxiliares Problema 4

float proporcionTeleworking(eph_h th, eph_i ti);

// Auxiliares Problema 5

int cantidadHabitantes (int codusu, eph_i ti);

// Auxiliares Problema 6

// Auxiliares Problema 7

void ordenarPorRegion(eph_h &th);

void ordenarPorCODUSU(eph_h &th);

void ordenarIndividuosPorCODUSUDeHogar(eph_h &th, eph_i &ti);

void ordenarIndividuosPorComponente(eph_i &ti);

// Auxiliares Problema 8
int ingresos(hogar h, eph_i ti);

// Auxiliares Problema 9

// Auxiliares Problema 10

int cantidadHogaresEnAnillo(int distDesde, int distHasta, pair <int ,int> centro, eph_h th);

// Auxiliares Problema 11

bool cumpleCondicion(vector < pair < int, dato > >  busqueda, individuo);

#endif //SOLUCION_AUXILIARES_H
