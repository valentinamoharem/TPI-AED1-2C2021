#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares Problema 1

bool esSuHogar(hogar h, individuo i){
    return h[HOGCODUSU]==i[INDCODUSU];
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
    bool res = false;
    for(int i = 0; i < ti.size(); i++){
        if(ti[i] == ind){
            res = true;
        }
    }
    return res;
}

bool hogarEnTabla (hogar hog, eph_h th){
    bool res = false;
    for(int i = 0; i < th.size(); i++){
        if(th[i] == hog){
            res = true;
        }
    }
    return res;
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
    bool tieneCodigo = false;
    for(int i = 0; i<ti.size(); i++){
        if(individuoEnTabla(ti[i], ti) && ti[i][INDCODUSU] == c){
            tieneCodigo = true;
        };
    }
    return tieneCodigo;
}

bool hayHogarConCodigo (eph_h th, int c){
    bool tieneCodigo = false;
    for(int i = 0; i<th.size(); i++){
        if(hogarEnTabla(th[i], th) && th[i][HOGCODUSU] == c){
            tieneCodigo = true;
        };
    }
    return tieneCodigo;
}

bool hayIndividuosSinHogares (eph_i ti, eph_h th){
    bool res = false;
    for(int i = 0; i<ti.size() && individuoEnTabla(ti[i], ti); i++){
        if(!hayHogarConCodigo(th, ti[i][INDCODUSU])){
            res = true;
        }
    }
    return res;
}

bool hayHogaresSinIndividuos (eph_i ti, eph_h th){
    bool res = false;
    for(int i = 0; i<th.size() && hogarEnTabla(th[i], th); i++){
        if(!hayIndividuoConCodigo(ti, th[i][HOGCODUSU])){
            res = true;
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
                if(!(ti[i][INDANIO]==th[j][HOGANIO] && ti[i][INDTRIMESTRE]==th[j][HOGTRIMESTRE])){
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

// Auxiliares Problema 2

// Auxiliares Problema 3

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

// Auxiliares Problema 4

bool trabaja(individuo i) {
    return i[ESTADO] == OCUPADO;
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

// Auxiliares Problema 5

int cantidadHabitantes (int codusu, eph_i ti) {
    int habitantes = 0;
    for(int i = 0; i < ti.size(); i++){
        if (codusu == ti[i][INDCODUSU]){
            habitantes++;
        }
    }
    return habitantes;
}

// Auxiliares Problema 6

// Auxiliares Problema 7

int hallarMinRegion(eph_h &th, int d, int h){
    int min = d;
    for (int i = d + 1; i < h; i++){
        if (th[i][REGION] <= th[min][REGION]){
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

int findMinCODUSU(vector<hogar> &s, int d, int h){
    int min = d;
    for(int i = d + 1; i < h; i++){
        if(s[i][HOGCODUSU] < s[min][HOGCODUSU] && s[i][REGION] == s[min][REGION]){
            min = i;
        }
    }
    return min;
}

void swapHog(vector<hogar> &s, int i, int j){
    hogar aux = s[i];
    s[i] = s[j];
    s[j] = aux;
}

void ordenarPorCODUSUYRegion(eph_h &th) {
    if(th.size() > 0){
        for(int i = 0; i < th.size(); i++){
            int minPos = findMinCODUSU(th, i, th.size());
            swapHog(th, i, minPos);
        }
    }
}

int posicionDeHogar(eph_h th, int codusu){
    int res;
    for(int i = 0; i < th.size(); i++){
        if(codusu == th[i][HOGCODUSU]){
            res = i;
        }
    }
    return res;
}

int findMinPosicionHogar(vector<individuo> &s, vector<hogar> th, int d, int h){
    int min = d;
    for(int i = d + 1; i < h; i++){
        if(posicionDeHogar(th, s[i][INDCODUSU]) <= posicionDeHogar(th, s[min][INDCODUSU])){
            min = i;
        }
    }
    return min;
}

void ordenarIndividuosPorCODUSUDeHogar(eph_h &th, eph_i &ti) {
    if(th.size() > 0 && ti.size() > 0){
        for(int i = 0; i < ti.size(); i++){
            int minPos = findMinPosicionHogar(ti,th,i,ti.size());
            swapInd(ti,i,minPos);
        }
    }
}

int findMinComponente(vector<individuo> &s, int d, int h){
    int min = d;
    for(int i = d + 1; i < h; i++){
        if(s[i][INDCODUSU] == s[min][INDCODUSU] && s[i][COMPONENTE] <= s[min][COMPONENTE]){
            min = i;
        }
    }
    return min;
}

void ordenarIndividuosPorComponente(eph_i &ti) {
    if(ti.size() > 0){
        for(int i = 0; i < ti.size(); i++){
            int minPos = findMinComponente(ti,i,ti.size());
            swapInd(ti, i, minPos);
        }
    }
}

// Auxiliares Problema 8

vector<hogar> sacarRepetidos(eph_h th,eph_i ti){
    vector<hogar> res = {th[0]};
    for(int i = 1; i < th.size(); i++){
        if(diferenciaDeIngresos(th[i-1],th[i],ti) != 0){
            res.push_back(th[i]);
        }
    }
    return res;
}

int apariciones(vector<int> v, int x) {
    int res = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == x){
            res++;
        }
    }
    return res;
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

int hallarMinIngresos(eph_h &th, int d, int h, eph_i ti){
    int min = d;
    for (int i = d + 1; i < h; i++){
        if (ingresos(th[i], ti) <= ingresos(th[min], ti)){
            min = i;
        }
    }
    return min;
}

void ordenarPorIngresos(eph_h &th, eph_i ti) {
    for (int i = 0; i < th.size() - 1; i++){
        int minIngresos = hallarMinIngresos(th, i, th.size(), ti);
        swap(th, i, minIngresos);
    }
}

int diferenciaDeIngresos(hogar h1, hogar h2, eph_i ti){
    return ingresos(h2,ti) - ingresos(h1,ti);
}

vector<int> buscarDiferencias(eph_h th, eph_i ti){
    vector<int> diferencias;
    for(int i = 0; i < th.size(); i++) {
        for(int j = i+1; j < th.size(); j++) {
            if (diferenciaDeIngresos(th[i], th[j], ti) > 0 && apariciones(diferencias,diferenciaDeIngresos(th[i], th[j], ti)) == 0) {
                diferencias.push_back(diferenciaDeIngresos(th[i], th[j], ti));
            }
        }
    }
    return diferencias;
}

vector<hogar> hogaresQueCumplenDiferencia(hogar h, int pos, eph_h th, eph_i ti, int dif){
    vector<hogar> res = {h};
    for(int k = pos+1; k < th.size(); k++){
        if(diferenciaDeIngresos(res[res.size()-1],th[k],ti) == dif){
            res.push_back(th[k]);
        }
    }
    return res;
}

vector<hogar> listaHogaresConMismaDiferencia(eph_h th, eph_i ti, vector<int> diferencias){
    vector<hogar> res;
    int max = 2;
    for(int i = 0; i < diferencias.size(); i++){
        vector<hogar> aux;
        for(int j = 0; j < th.size(); j++){
            aux = hogaresQueCumplenDiferencia(th[j],j,th,ti,diferencias[i]);
            if(aux.size() > max){
                max = aux.size();
                res = aux;
            }
        }
    }
    return res;
};

// Auxiliares Problema 9

// Auxiliares Problema 10

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

// Auxiliares Problema 11

bool cumpleCondicion(individuo &ind, vector<pair<int, dato>> &busqueda) {
    bool res = true;
    for (int i = 0; i < busqueda.size() && res; i++) {
        if (ind[busqueda[i].first] != busqueda[i].second) {
            res = false;
        }
    }
    return res;
}