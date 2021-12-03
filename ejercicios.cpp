#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
    return !esVacia(ti) && !esVacia(th) && esMatriz(ti) && esMatriz(th) && cantidadCorrectaDeColumnasI(ti)
           && cantidadCorrectaDeColumnasH(th) && !hayIndividuosSinHogares(ti,th) && !hayHogaresSinIndividuos(ti,th)
           && !hayRepetidosI(ti)&& !hayRepetidosH(th) && mismoAnioYTrimestre(ti,th) && menosDe21MiembrosPorHogar(th,ti)
           && cantidadValidaDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th);
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector<int> histograma;
    for(int i = 0; i < th.size(); i++) {
        if (th[i][REGION] == region) {
            while (histograma.size() < th[i][IV2]) {
                histograma.push_back(0);
            }
            if (esCasa(th[i])) {
                histograma[th[i][IV2]-1]++;
            }
        }
    }
    return histograma;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};

    for(int i = 0; i < resp.size(); i++) {
        for(int j = 0; j < th.size(); j++) {
            if(th[j][REGION] == resp[i].first) {
                resp[i].second = proporcionCasasConHC(th, ti, resp[i].first);
            }
        }
    }
	
  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes (eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    return proporcionTeleworking(t2h,t2i) > proporcionTeleworking(t1h, t1i);
}

// Implementacion Problema 5
int costoSubsidioMejora(eph_h th , eph_i ti, int monto){
    int resp = 0;
    int codusu = 0;
    int cantDeHabitaciones = 0;
    for(int i = 0; i< th.size() ;i++){
        codusu = th[i][HOGCODUSU];
        cantDeHabitaciones = th[i][IV2];
        if(th[i][II7] == 1){
            int cantHab = 0;
            cantHab = cantidadHabitantes(codusu, ti);
            if((cantHab - 2) > cantDeHabitaciones){
                resp += monto;
            }
            cantHab = 0;
        }
        codusu = 0;
        cantDeHabitaciones = 0;
    }
    return resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    join_hi resp;
    vector<pair<vector<dato>, vector<dato>>> temp;
    for(int k=0; k<th.size(); k++){
        for(int j=0; j<ti.size(); j++){
            if(esSuHogar(th[k],ti[j])){
                resp.push_back(make_pair(th[k],ti[j]));
            }
        }
    }
    return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
    ordenarPorRegion(th);
    ordenarPorCODUSU(th);
    ordenarIndividuosPorCODUSUDeHogar(th,ti);
    ordenarIndividuosPorComponente(ti);
    return;
}

// Implementación Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ) {
    vector<hogar> res;
    ordenarPorIngresos(th,ti);
    th = sacarRepetidos(th,ti);
    vector<int> diferencias = buscarDiferencias(th,ti);
    res = listaHogaresConMismaDiferenciaALT(th,ti,diferencias);
    return res;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
    for (int i = 0; i < th.size(); i++) {
        if(th[i][REGION] == 1) {
            for (int k = 0; k < th[i].size(); k++) {
                if (k == 6) {
                    th[i][k] = 43;
                } else {
                    th[i][k] = th[i][k];
                }
            }
        }
    }

    return;
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector<int> resp(distancias.size());
    for(int x = 0; x < distancias.size(); ++x) {
        resp[x] = 0;
    }
    resp[0] = cantidadHogaresEnAnillo(0, distancias[0], centro, th);
    for(int i = 0; i < distancias.size() - 1; i++) {
        resp[i+1] = cantidadHogaresEnAnillo(distancias[i], distancias[i+1], centro, th);
    }
	
	return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h th_out;
    eph_i ti_out;
    eph_h th_res;
    eph_i ti_res;

    for(int ind=0; ind<ti.size(); ind++){
        if(cumpleCondicion(ti[ind], busqueda)){
            ti_res.push_back(ti[ind]);
        } else {
            ti_out.push_back(ti[ind]);
        }
    }

    int codusu_aux = 0;
    for(int i=0; i<ti_res.size(); i++){
        for(int j=0; j<th.size(); j++){
            if(ti_res[i][INDCODUSU] == th[j][HOGCODUSU] && th[j][HOGCODUSU] != codusu_aux){
                codusu_aux = th[j][HOGCODUSU];
                th_res.push_back(th[j]);
            }
        }
    }

    vector<int> hogar_aux= {};
    for(int i=0; i<ti_out.size(); i++){
        for(int j=0; j<th.size(); j++){
            if(ti_out[i][INDCODUSU] == th[j][HOGCODUSU] && th[j] !=  hogar_aux ){
                    hogar_aux = th[j];
                    th_out.push_back(th[j]);
                }
        }
    }

    th = th_out;
    ti = ti_out;
    return make_pair(th_res, ti_res);
}
