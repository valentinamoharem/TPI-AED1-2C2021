#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares Problema 4

bool trabaja(individuo i) {
    return i[7] == 1;
}

bool esSuHogar(individuo i, hogar h) {
    return h[0] == i[0];
}

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

double proporcionTeleworking(eph_h th, eph_i ti) {
    if (cantidadIndividuosQueTrabajan(th, ti) > 0) {
        return cantidadIndividuosTeleworking(th, ti)/cantidadIndividuosQueTrabajan(th, ti);
    } else {
        return 0;
    }
}

// Auxiliares Problema 5

int cantidadDeHabitantes (int codusu,eph_i ti){
	int habitantes = 0;
	
	for(int i = 0; i < ti.size(); i++){
			
			if (codusu == ti [i][0]){
				
				habitantes++;
				
			}
		
	}
	
	return habitantes;
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
