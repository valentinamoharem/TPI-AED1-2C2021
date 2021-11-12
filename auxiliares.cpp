#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares Generales

bool trabaja(individuo i) {
    return i[7] == 1;
}

bool esSuHogar(individuo i, hogar h) {
    return h[0] == i[0];
}

bool esDeCiudadGrande(individuo i, eph_h th) {
    bool resp = false;
    for (int k = 0; k < th.size(); k++) {
        if(esSuHogar(i,th[k]) && th[k][7] == 1) {
            resp = true;
        } else {
            resp = false;
        }
    }
    return resp;
}

int cantidadHabitantes(hogar h, eph_i ti) {
    int cantidad = 0;
    for(int i = 0; i < ti.size(); i++) {
        if(h[0] == ti[i][0]) {
            cantidad++;
        }
    }
    return cantidad;
}

// Auxiliares Problema 3

bool esHogarValido(hogar h, int region) {
    return h[8] == 1 && h[6] == region && h[7] == 0;
}

bool esHogarConHC(hogar h, eph_i ti) {
    return cantidadHabitantes(h,ti) > 3*h[9];
}

int cantidadHogaresValidosConHC(eph_h th, eph_i ti, int region) {
    int cantidad = 0;
    for(int i = 0; i < th.size(); i++) {
        if(esHogarValido(th[i], region) && esHogarConHC(th[i], ti)){
            cantidad++;
        }
    }
    return cantidad;
}

int cantidadHogaresValidos(eph_h th, eph_i ti, int region) {
    int cantidad = 0;
    for(int i = 0; i < th.size(); i++) {
        if(esHogarValido(th[i], region)){
            cantidad++;
        }
    }
    return cantidad;
}

float proporcionCasasConHC(eph_h th, eph_i ti, int region) {
    float resp = 0;
    if(cantidadHogaresValidos(th, ti, region) > 0) {
        resp = cantidadHogaresValidosConHC(th, ti, region)/cantidadHogaresValidos(th, ti, region);
    }
    return resp;
}

// Auxiliares Problema 4

bool suHogarEsCasaODepto(individuo i, eph_h th) {
    bool resp = false;
    for (int k = 0; k < th.size(); k++) {
        if(esSuHogar(i,th[k]) && (th[k][8] == 1 || th[k][8] == 2)) {
            resp = true;
        } else {
            resp = false;
        }
    }
    return resp;
}

bool viveEnHogarValido(individuo i, eph_h th) {
    return esDeCiudadGrande(i, th) && suHogarEsCasaODepto(i, th);
}

bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo i, eph_h th) {
    bool resp = false;
    for (int k = 0; k < th.size(); k++) {
        if(esSuHogar(i,th[k]) && th[k][11] == 1) {
            resp = true;
        } else {
            resp = false;
        }
    }
    return resp;
}

bool realizaSusTareasEnEsteHogar(individuo i) {
    return i[10] == 6;
}

bool haceTeleworking(individuo i, eph_h th) {
    return realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadosParaElTrabajo(i,th);
}

int cantidadIndividuosQueTrabajan(eph_h th, eph_i ti) {
    int cantidad = 0;
    for (int i = 0; i < ti.size(); i++) {
        if (trabaja(ti[i]) && viveEnHogarValido(ti[i], th)) {
            cantidad++;
        }
    }
    return cantidad;
}

int cantidadIndividuosTeleworking(eph_h th, eph_i ti) {
    int cantidad = 0;
    for (int i = 0; i < ti.size(); i++) {
        if (trabaja(ti[i]) && haceTeleworking(ti[i], th) && viveEnHogarValido(ti[i],th)) {
            cantidad++;
        }
    }
    return cantidad;
}

float proporcionTeleworking(eph_h th, eph_i ti) {
    if (cantidadIndividuosQueTrabajan(th, ti) > 0) {
        return cantidadIndividuosTeleworking(th, ti)/cantidadIndividuosQueTrabajan(th, ti);
    } else {
        return 0;
    }
}

// Auxiliares Problema 9

// Auxiliares Problema 10

double distanciaEuclideana(pair <int ,int> centro, int latitud, int longitud) {
    return sqrt(pow(centro.first - latitud, 2) + pow(centro.second - longitud, 2));
}

bool hogarEnAnillo(int distDesde, int distHasta, pair <int ,int> centro, hogar h) {
    bool resp = distDesde < distanciaEuclideana(centro, h[3], h[4]) && distanciaEuclideana(centro, h[3], h[4]) >= distHasta;
    return resp;
}

int cantidadHogaresEnAnillo(int distDesde, int distHasta, pair <int ,int> centro, eph_h th) {
    int cantidad = 0;
    for (int i = 0; i < th.size(); i++) {
        if (hogarEnAnillo(distDesde, distHasta, centro, th[i])) {
            cantidad++;
        }
    }
    return cantidad;
}