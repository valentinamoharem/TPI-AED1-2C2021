#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

bool trabaja(individuo i) {
    return i[ESTADO] == OCUPADO;
}

bool esSuHogar(hogar h, individuo i){
    return h[HOGCODUSU]==i[INDCODUSU];
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

bool esCasa (hogar h){
    return h[IV1] == 1;
}

bool esVacia(vector<vector<int>> t){
    bool vacia = t.size() == 0;
    return vacia;
}

bool esMatriz(vector<vector<int>> t){
    bool matriz = false;
    for(int j=0; j<t.size(); j++ ){
        for(int i=0; i<j; i++ ) {
            if (t[i].size() == t[j].size()) {
                matriz = true;
            }
        }
    }
    return matriz;
}

bool individuoEnTabla (individuo ind, eph_i ti){
    int i=0;
    while( i<ti.size() && ti[i] == ind){
        i++;
    }
    return i< ti.size();
}

bool hogarEnTabla (hogar hog, eph_h th){
    int i=0;
    while( i<th.size() && th[i] == hog){
        i++;
    }
    return i< th.size();
}


bool cantidadCorrectaDeColumnasI(eph_i ti){
    bool res = false;
    for(int i=0; i<ti.size(); i++){
        if(individuoEnTabla(ti[i], ti) && ti[i].size() == FILAS_INDIVIDUO){
            res = true;
        } else {
            res = false;
        }
    }
    return res;
}

bool cantidadCorrectaDeColumnasH(eph_h th){
    bool res = false;
    for(int i=0; i<th.size(); i++){
        if(hogarEnTabla(th[i], th) && th[i].size() == FILAS_HOGAR ){
            res = true;
        } else {
            res = false;
        }
    }
    return res;
}

bool hayIndividuoConCodigo (eph_i ti, int c){
    bool tieneCodigo = false;
    for(int i = 0; i<ti.size(); i++){
        if(individuoEnTabla(ti[i], ti) && ti[i][INDCODUSU]==c){
            tieneCodigo = true;
        } else {
            tieneCodigo = false;
        }
    }
    return tieneCodigo;
}

bool hayHogarConCodigo (eph_h th, int c){
    bool tieneCodigo = false;
    for(int i = 0; i<th.size(); i++){
        if(hogarEnTabla(th[i], th) && th[i][HOGCODUSU]==c){
            tieneCodigo = true;
        } else {
            tieneCodigo = false;
        }
    }
    return tieneCodigo;
}

bool hayIndividuosSinHogares (eph_i ti, eph_h th){
    bool hayIndividuosSinHogares = false;
    for(int i = 0; i<ti.size(); i++){
        if(individuoEnTabla(ti[i], ti) && !hayHogarConCodigo(ti, ti[i][INDCODUSU])){
            hayIndividuosSinHogares = true;
        } else {
            hayIndividuosSinHogares = false;
        }
    }
    return hayIndividuosSinHogares;
}

bool hayHogaresSinIndividuos (eph_i ti, eph_h th){
    bool hayHogaresSinIndividuos = false;
    for(int i = 0; i<th.size(); i++){
        if(hogarEnTabla(th[i], th) && !hayIndividuoConCodigo(ti, th[i][HOGCODUSU])){
            hayHogaresSinIndividuos = true;
        } else {
            hayHogaresSinIndividuos = false;
        }
    }
    return hayHogaresSinIndividuos;
}

bool mismoCodusuYComponente(individuo i1, individuo i2){
    bool mismo = (i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE]==i2[COMPONENTE]);
    return mismo;
}

bool hayRepetidosH (eph_h th){
    bool hayRepetidos = false;
    for(int n1=0; n1<th.size(); n1++){
        for(int n2=0; n2<th.size(); n2++){
            if(n1!=n2 && th[n1][HOGCODUSU]==th[n2][HOGCODUSU]){
                hayRepetidos = true;
            } else {
                hayRepetidos = false;
            }
        }
    }
    return hayRepetidos;
}

bool hayRepetidosI (eph_i ti){
    bool hayRepetidos = false;
    for(int n1=0; n1<ti.size(); n1++){
        for(int n2=0; n2<ti.size(); n2++){
            if(n1!=n2 && mismoCodusuYComponente(ti[n1], ti[n2])){
                hayRepetidos = true;
            } else {
                hayRepetidos = false;
            }
        }
    }
    return hayRepetidos;
}

bool mismoAnioYTrimestre (eph_i ti, eph_h th) {
    bool mismoAnioYTrimestre = false;
    for(int i=0; i<ti.size(); i++){
        for(int j=0; j<th.size(); j++){
            if(individuoEnTabla(ti[i], ti) && hogarEnTabla(th[j], th)){
                int a = ti[i][INDANIO];
                int b = th[j][HOGANIO];
                int c = ti[i][INDTRIMESTRE];
                int d = th[j][HOGTRIMESTRE];
                if(ti[i][INDANIO]==th[j][HOGANIO] && ti[i][INDTRIMESTRE]==th[j][HOGTRIMESTRE]){
                    mismoAnioYTrimestre = true;
                } else {
                    mismoAnioYTrimestre = false;
                }
            }
        }
    }
    return mismoAnioYTrimestre;
}

int cantHabitantes(hogar h, eph_i ti) {
    int k = 0;
    int cantidad = 0;
    while( k < ti.size() ) {
        if(esSuHogar(h,ti[k])){
            cantidad++;
        }
        k++;
    }
    return cantidad;
}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti){
    bool menosDe21Miembros = false;
    for(int i=0; i<th.size(); i++){
        if (cantHabitantes(th[i],ti) < 21){
            menosDe21Miembros = true;
        } else {
            menosDe21Miembros = false;
        }
    }
    return menosDe21Miembros;
}

bool cantidadValidaDormitorios (eph_h th){
    bool cantidadValida = false;
    int i=0;
    while(i<th.size() && hogarEnTabla(th[i], th)){
        if (th[i][IV2]>=th[i][II2]){
            cantidadValida=true;
        } else {
            cantidadValida=false;
        }
        i++;
    }
    return cantidadValida;
}

bool valorRegionValido (int r){
    return (r==1)||(40<=r<=44);
}

bool individuoValido(individuo i){
    return (i[INDCODUSU] > 0) && (i[INDANIO] > 0) && (i[COMPONENTE] > 0) && (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1) &&
           (0 < i[INDTRIMESTRE] <= 4) && (0 < i[CH4] <= 2) && (i[CH6] >= 0)   && (-1 <= i[ESTADO] <= 1) &&
           (0 <= i[CAT_OCUP] <= 4) && (i[p47T] >= 0 || i[p47T] == -1) && (0 <= i[PP04G] <= 10);
}

bool hogarValido(hogar h){
    return  (h[HOGCODUSU] > 0) && ( h[HOGANIO] > 0) && (0 < h[HOGTRIMESTRE] <= 4) && (0 < h[II7] <= 3) &&
            valorRegionValido(h[REGION]) && (h[MAS_500] == 0 || h[MAS_500] == 1) && (0 < h[IV1] <= 5) && (h[IV2] > 0) &&
            (h[II2] >= 1) && (h[II3] == 1 || h[II3] == 2);
}

bool valoresEnRangoI(eph_i ti){
    bool valoresEnRango = false;
    for(int i=0; i<ti.size() && individuoEnTabla(ti[i], ti); i++) {
        vector<int> vec= ti[i];
        if(individuoValido(ti[i])){
            valoresEnRango = true;
        } else {
            valoresEnRango = false;
        }
    }
    return valoresEnRango;
}

bool valoresEnRangoH(eph_h th){
    bool valoresEnRango = false;
    for(int i=0; i<th.size() && hogarEnTabla(th[i],th); i++) {
        if(hogarValido(th[i])){
            valoresEnRango = true;
        } else {
            valoresEnRango = false;
        }
    }
    return valoresEnRango;
}


bool esValida(eph_i ti, eph_h th){
    return  !esVacia(ti) && !esVacia(th) && esMatriz(ti) && esMatriz(th) && cantidadCorrectaDeColumnasI(ti)
            && cantidadCorrectaDeColumnasH(th) && !hayIndividuosSinHogares(ti,th) && !hayHogaresSinIndividuos(ti,th)
            && !hayRepetidosI(ti)&& !hayRepetidosH(th) && mismoAnioYTrimestre(ti,th) && menosDe21MiembrosPorHogar(th,ti)
            && cantidadValidaDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th);
}

int cantHogaresCasaConNHabitaciones (eph_h th, int region, int habitaciones){
    int i=0;
    int cantidad = 0;
    while(i<th.size()){
        if(esCasa(th[i]) && th[i][IV2]==habitaciones && th[i][REGION]==region){
            cantidad++;
        }
        i++;
    }
    return cantidad;
}

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

hogar suHogar(individuo i, eph_h th){
    hogar h;
    for (int k = 0; k < th.size(); k++) {
        if(esSuHogar(i,th[k])) {
            h = th[k];
        }
    }
    return h;
}

bool viveEnHogarValido(individuo i, hogar h) {
    return h[MAS_500]==1 && (h[IV1]==CASA || h[IV1]==2);
}

bool haceTeleworking(individuo i, hogar h) {
    return i[PP04G] == 6 && h[II3] == 1;
}

float individuosQueTrabajan(eph_h th, eph_i ti) {
    float cantidad = 0;
    for (int i = 0; i < ti.size(); i++) {
        hogar h = suHogar(ti[i],th);
        if (trabaja(ti[i]) && viveEnHogarValido(ti[i], h)) {
            cantidad++;
        }
    }
    return cantidad;
}

float individuosTeleworking(eph_h th, eph_i ti) {
    float cantidad = 0;
    for (int i = 0; i < ti.size(); i++) {
        hogar h = suHogar(ti[i],th);
        if (trabaja(ti[i]) && viveEnHogarValido(ti[i], h) && haceTeleworking(ti[i], h)) {
            cantidad++;
        }
    }
    return cantidad;
}

float proporcionTeleworking(eph_h th, eph_i ti) {
    return individuosQueTrabajan(th, ti) > 0 ? individuosTeleworking(th, ti)/individuosQueTrabajan(th, ti) : 0;
}

int cantidadDeHabitantes (int codusu,eph_i ti){
    int habitantes = 0;

    for(int i = 0;i<18;i++){

        if (codusu == ti [i][0]){

            habitantes = habitantes + 1;

        }

    }

    return habitantes;
}

double distanciaEuclideana(pair <int ,int> centro, int latitud, int longitud) {
    return sqrt(pow(centro.first - latitud, 2) + pow(centro.second - longitud, 2));
}

bool hogarEnAnillo(int distDesde, int distHasta, pair <int ,int> centro, hogar h) {
    bool resp = distDesde < distanciaEuclideana(centro, h[HOGLATITUD], h[HOGLONGITUD]) && distanciaEuclideana(centro, h[HOGLATITUD], h[HOGLONGITUD]) <= distHasta;
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

int maximaCantidadHabitaciones (eph_h th, int region){
    int i =0;
    int max = th[0][IV2];
    for (i = 1; i < th.size(); i++){
        if (th[i][REGION]==region && max<th[i][IV2]){
            max = th[i][IV2];
        }
    }
    return max;
}

bool sinRepetidos(vector < par_hi > pair){
    bool sinRepetidos = false;
    for(int i=0; i<pair.size()-1; i++){
        if(pair[i]!=pair[i+1]){
            sinRepetidos= true;
        } else {
            sinRepetidos=false;
        }
    }
    return sinRepetidos;
}

bool cumpleCondicion(vector < pair < int, dato > >  busqueda, individuo i){
    bool cumple = false;
    int k =0;
    while(k<busqueda.size() && i[busqueda[k].first] == busqueda[k].second){
        cumple = true;
        k++;
    }
    return cumple;
}