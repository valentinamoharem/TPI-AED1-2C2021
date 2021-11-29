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

int cantidadHabitantes (int codusu, eph_i ti) {
    int habitantes = 0;
    for(int i = 0; i < ti.size(); i++){
        if (codusu == ti[i][INDCODUSU]){
            habitantes++;
        }
    }
    return habitantes;
}

bool esCasa (hogar h){
    return h[IV1] == 1;
}

bool esVacia(vector<vector<int>> t){
    return t.size() == 0;
}

bool esMatriz(vector<vector<int>> t){
    bool matriz = true;
    for(int j=0; j<t.size(); j++){
        for(int i=0; i<j; i++) {
            if(!(t[i].size() == t[j].size())){
                matriz = false;
            };
        }
    }
    return matriz;
}

bool individuoEnTabla (individuo ind, eph_i ti){
    int i=0;
    while(i<ti.size() && ti[i] == ind){
        i++;
    }
    return i < ti.size();
}

bool hogarEnTabla (hogar hog, eph_h th){
    int i=0;
    while( i<th.size() && th[i] == hog){
        i++;
    }
    return i < th.size();
}

bool cantidadCorrectaDeColumnasI(eph_i ti){
    bool res = true;
    for(int i=0; i<ti.size(); i++){
        if(!(individuoEnTabla(ti[i], ti) && ti[i].size() == FILAS_INDIVIDUO)){
            res = false;
        };
    }
    return res;
}

bool cantidadCorrectaDeColumnasH(eph_h th){
    bool res = true;
    for(int i=0; i<th.size(); i++){
        if(!(hogarEnTabla(th[i], th) && th[i].size() == FILAS_HOGAR)){
            res = false;
        };
    }
    return res;
}

bool hayIndividuoConCodigo (eph_i ti, int c){
    bool tieneCodigo = true;
    for(int i = 0; i<ti.size(); i++){
        if(!(individuoEnTabla(ti[i], ti) && ti[i][INDCODUSU] == c)){
            tieneCodigo = false;
        };
    }
    return tieneCodigo;
}

bool hayHogarConCodigo (eph_h th, int c){
    bool tieneCodigo = true;
    for(int i = 0; i<th.size(); i++){
        if(!(hogarEnTabla(th[i], th) && th[i][HOGCODUSU]==c)){
            tieneCodigo = false;
        };
    }
    return tieneCodigo;
}

bool hayIndividuosSinHogares (eph_i ti, eph_h th){
    bool res = false;
    for(int i = 0; i<ti.size() && individuoEnTabla(ti[i], ti); i++){
        if(!(hayHogarConCodigo(ti, ti[i][INDCODUSU]))){
            res = true;
        };
    }
    return res;
}

bool hayHogaresSinIndividuos (eph_i ti, eph_h th){
    bool res = true;
    for(int i = 0; i<th.size() && hogarEnTabla(th[i], th); i++){
        if(!((hayIndividuoConCodigo(ti, th[i][HOGCODUSU])))){
            res = false;
        };
    }
    return res;
}

bool mismoCodusuYComponente(individuo i1, individuo i2){
    return (i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE]==i2[COMPONENTE]);
}

bool hayRepetidosH (eph_h th){
    bool hayRepetidos = false;
    for(int n1=0; n1<th.size(); n1++){
        for(int n2=0; n2<th.size(); n2++){
            if(n1!=n2 && th[n1][HOGCODUSU]==th[n2][HOGCODUSU]){
                hayRepetidos = true;
            };
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
            };
        }
    }
    return hayRepetidos;
}

bool mismoAnioYTrimestre (eph_i ti, eph_h th) {
    bool res = true;
    for(int i=0; i<ti.size(); i++){
        for(int j=0; j<th.size(); j++){
            if(individuoEnTabla(ti[i], ti) && hogarEnTabla(th[j], th)){
                if(!(ti[i][INDANIO]==th[j][HOGANIO] && ti[i][INDTRIMESTRE]==th[j][HOGTRIMESTRE] && th[j][HOGANIO] > 0 && th[j][HOGTRIMESTRE] < 5 && th[j][HOGTRIMESTRE] > 0)){
                    res = false;
                };
            }
        }
    }
    return res;
}

int cantHabitantes(hogar h, eph_i ti) {
    int k = 0;
    int cantidad = 0;
    while(k < ti.size()) {
        if(esSuHogar(h,ti[k])){
            cantidad++;
        }
        k++;
    }
    return cantidad;
}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti){
    bool res = true;
    for(int i=0; i<th.size(); i++){
        if(cantHabitantes(th[i],ti) >= 21){
            res = false;
        };
    }
    return res;
}

bool cantidadValidaDormitorios (eph_h th){
    bool cantidadValida = true;
    int i=0;
    while(i<th.size() && hogarEnTabla(th[i], th)){
        if(!(th[i][IV2]>=th[i][II2])){
            cantidadValida = false;
        };
        i++;
    }
    return cantidadValida;
}

bool valorRegionValido (int r){
    return (r==1)||(40<=r<=44);
}

bool individuoValido(individuo i){
    return (i[INDCODUSU] > 0) && (i[COMPONENTE] > 0) && (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1) &&
           (0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4) && (0 < i[CH4] &&  i[CH4] <= 2) && (i[CH6] >= 0)   && (-1 <= i[ESTADO] && i[ESTADO] <= 1) &&
           (0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4) && (i[p47T] >= 0 || i[p47T] == -1) && (0 <= i[PP04G] && i[PP04G] <= 10);
}

bool hogarValido(hogar h){
    return  (h[HOGCODUSU] > 0) && (0 < h[HOGTRIMESTRE] && h[HOGTRIMESTRE] <= 4) && (0 < h[II7] && h[II7] <= 3) &&
            valorRegionValido(h[REGION]) && (h[MAS_500] == 0 || h[MAS_500] == 1) && (0 < h[IV1] && h[IV1] <= 5) && (h[IV2] > 0) &&
            (h[II2] >= 1) && (h[II3] == 1 || h[II3] == 2);
}

bool valoresEnRangoI(eph_i ti){
    bool valoresEnRango = true;
    for(int i=0; i<ti.size(); i++) {
        if(!individuoEnTabla(ti[i], ti) || !individuoValido(ti[i])){
            valoresEnRango = false;
        };
    }
    return valoresEnRango;
}

bool valoresEnRangoH(eph_h th){
    bool valoresEnRango = true;
    for(int i=0; i<th.size(); i++) {
        if(!hogarEnTabla(th[i],th) || !hogarValido(th[i])){
            valoresEnRango = false;
        };
    }
    return valoresEnRango;
}

int ingresos (hogar h, eph_i ti) {
    int cantidad = 0;
    for (int i = 0; i < ti.size(); i++) {
        if(ti[i][INDCODUSU] == h[HOGCODUSU] && ti[i][p47T] > -1){
            cantidad += ti[i][p47T];
        }
    }
    return cantidad;
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
    return (h[IV1] == 1 && h[REGION] == region && h[MAS_500] == 0);
}

bool esHogarConHC(hogar h, eph_i ti) {
    return cantidadHabitantes(h[HOGCODUSU],ti) > 3*h[II2];
}

float cantidadHogaresValidosConHC(eph_h th, eph_i ti, int region) {
    float cantidad = 0;
    for(int i = 0; i < th.size(); i++) {
        if(esHogarValido(th[i], region) && esHogarConHC(th[i], ti)){
            cantidad++;
        }
    }
    return cantidad;
}

float cantidadHogaresValidos(eph_h th, eph_i ti, int region) {
    float cantidad = 0;
    for(int i = 0; i < th.size(); i++) {
        if(esHogarValido(th[i], region)){
            cantidad++;
        }
    }
    return cantidad;
}

float proporcionCasasConHC(eph_h th, eph_i ti, int region) {
    float res = 0;
    if(cantidadHogaresValidos(th, ti, region) > 0) {
        res = cantidadHogaresValidosConHC(th, ti, region)/cantidadHogaresValidos(th, ti, region);
    }
    return res;
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

int findMinPosition(vector<int> &s, int d, int h){
    int min = d;
    for(int i = d + 1; i < h; i++){
        if(s[i] <= s[min]){
            min = i;
        }
    }
    return min;
}

void swap(vector<int> &s, int i, int j){
    int aux = s[i];
    s[i] = s[j];
    s[j] = aux;
}

// selection sort
void ordenar(vector<int> &s){
    if(s.size() != 0){
        for(int i = 0; i < s.size() - 1; i++){
            int minPos = findMinPosition(s, i, s.size());
            swap(s, i, minPos);
        }
    }
}

bool pertenece(vector<int> v, int n) {
    bool res = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            res = true;
        }
    }
    return res;
}

int hallarMinRegion(eph_h &th, int d, int h){
    int min = d;
    for (int i = d + 1; i < h; i++){
        if (th[i][REGION] <= th[min][REGION]){
            min = i;
        }
    }
    return min;
}

int hallarMinHOGCODUSU(eph_h &th, int d, int h){
    int min = d;
    for (int i = d + 1; i < h; i++){
        if(th[i][COMPONENTE] <= th[min][COMPONENTE]){
            min = i;
        }
    }
    return min;
}

int hallarMinComponente(eph_i &ti, int d, int h){
    int min = d;
    for (int i = d + 1; i < h; i++){
        if(ti[i][HOGCODUSU] <= ti[min][HOGCODUSU]){
            min = i;
        }
    }
    return min;
}

void swap(eph_h &th, int i, int j){
    hogar aux = th[i];
    th[i] = th[j];
    th[j] = aux;
}

void swapInd(eph_i &ti, int i, int j){
    individuo aux = ti[i];
    ti[i] = ti[j];
    ti[j] = aux;
}

void ordenarPorRegion(eph_h &th) {
    for (int i = 0; i < th.size() - 1; i++){
        int minRegion = hallarMinRegion(th, i, th.size());
        swap(th, i, minRegion);
    }
}

void ordenarPorCODUSUPorRegion(eph_h &th) {
    for (int i = 0; i < th.size() - 1; i++){
        int minCODUSU = hallarMinHOGCODUSU(th, i, th.size());
        swap(th, i, minCODUSU);
    }
}

void ordenarPorCODUSUPorComponente(eph_i &ti) {
    for (int i = 0; i < ti.size() - 1; i++){
        int minComponente = hallarMinComponente(ti, i, ti.size());
        swapInd(ti, i, minComponente);
    }
}

eph_h subVectorPorRegion(eph_h th, int region) {
    eph_h res;
    for (int i = 0; i < th.size(); i++) {
        if (th[i][REGION] == region) {
            res.push_back(th[i]);
        }
    }
    return res;
}

eph_i subVectorPorINDCODUSU(eph_i ti, int INDCODUSU) {
    eph_i res;
    for (int i = 0; i < ti.size(); i++) {
        if (ti[i][INDCODUSU] == INDCODUSU) {
            res.push_back(ti[i]);
        }
    }
    return res;
}

void ordenarPorCODUSU(eph_h &th) {
    vector<int> regiones;
    eph_h thOrdenado;
    for (int i = 0; i < th.size(); i++) {
        if (!pertenece(regiones, th[i][REGION])) {
            regiones.push_back(th[i][REGION]);
        }
    }
    ordenar(regiones);
    for (int i = 0; i < regiones.size(); i++) {
        eph_h thPorRegion = subVectorPorRegion(th, regiones[i]);
        ordenarPorCODUSUPorRegion(thPorRegion);
        for (int j = 0; j < thPorRegion.size(); j++) {
            thOrdenado.push_back(thPorRegion[j]);
        }
    }
    th = thOrdenado;
}

void ordenarIndividuosPorCODUSUDeHogar(eph_h &th, eph_i &ti) {
    eph_i tiOrdenado;
    for (int i = 0; i < th.size(); i++) {
        for (int j = 0; j < ti.size(); j++) {
            if (th[i][HOGCODUSU] == ti[i][INDCODUSU]) {
                tiOrdenado.push_back(ti[i]);
            }
        }
    }
    ti = tiOrdenado;
}

void ordenarIndividuosPorComponente(eph_i &ti) {
    vector<int> INDCODUSUS;
    eph_i tiOrdenado;
    for (int i = 0; i < ti.size(); i++) {
        if (!pertenece(INDCODUSUS, ti[i][INDCODUSU])) {
            INDCODUSUS.push_back(ti[i][INDCODUSU]);
        }
    }
    for (int i = 0; i < INDCODUSUS.size(); i++) {
        eph_i tiPorINDCODUSU = subVectorPorINDCODUSU(ti, INDCODUSUS[i]);
        ordenarPorCODUSUPorComponente(tiPorINDCODUSU);
        for (int j = 0; j < tiPorINDCODUSU.size(); j++) {
            tiOrdenado.push_back(tiPorINDCODUSU[j]);
        }
    }
    ti = tiOrdenado;
}