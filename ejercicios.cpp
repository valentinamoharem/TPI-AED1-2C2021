#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
	bool resp = false;
	
	// TODO
	
	return resp;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector < int > resultado = {-1, -1, -1, -1, -1, -1};
	
	// TODO
	
	return resultado;
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
            if(th[j][6] == resp[i].first) {
                resp[i].second = proporcionCasasConHC(th, ti, resp[i].first);
            }
        }
    }
	
  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    bool resp = proporcionTeleworking(t2h,t2i) > proporcionTeleworking(t1h, t1i);
    return resp;
}

// Implementacion Problema 5
int costoSubsidioMejora(eph_h th , eph_i ti, int monto){
    int resp = monto;
    int codusu = 0;
    int cantDeHabitaciones = 0;


    for(int i = 0; i< 4;i++){

        codusu = th[i][0];
        cantDeHabitaciones = th[i][10];

        if(th[i][5] == 1){

            int cantHab = 0;
            cantHab = cantidadDeHabitantes (codusu, ti);

            if((cantHab - 2) > cantDeHabitaciones){

                resp = resp + monto;

            }

        }

        codusu = 0;
        cantDeHabitaciones=0;
    }


    return resp-monto;


}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	join_hi resp = {make_pair(h,i)};
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
	
	// Ordeno por region

		for(int n=0; n<4; n++){
			for(int i=0; i<4; i++){
				if(i==3){
					if(th[i][6] > th[i-3][6]){

						for(int j=0; j<12; j++){
							int aux=0;

							aux = th[i-3][j];
							th[i-3][j] = th[i-3][j];
							th[i-3][j] = aux;
						}

					}
				}else{

					if(th[i][6] > th[i+1][6]){

						for(int j=0; j<12; j++){
							int aux=0;

							aux = th[i][j];
							th[i][j] = th[i+1][j];
							th[i+1][j] = aux;


						}
					}
				}
			}
		}

		// Ordena el CODUSU

		for(int n=0; n<4; n++){
			for(int i=0; i<4; i++){
				if(i==3){
					if(th[i][6] == th[i-3][6] && th[i][0] > th[i-3][0]){

						for(int j=0; j<12; j++){
							int aux=0;

							aux = th[i-3][j];
							th[i-3][j] = th[i-3][j];
							th[i-3][j] = aux;
						}

					}
				}else{

					if(th[i][6] == th[i+1][6] && th[i][0] > th[i+1][0]){

						for(int j=0; j<12; j++){
							int aux=0;

							aux = th[i][j];
							th[i][j] = th[i+1][j];
							th[i+1][j] = aux;


						}
					}
				}
			}
		}


		return;
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
    for (int i = 0; i < th.size(); i++) {
        if(th[i][6] == 1) {
            for (int k = 0; k < th[i].size(); k++) {
                if (k == 6) {
                    th[i][k] = 43;
                } else {
                    th[i][k] = th[i][k];
                }
            }
        } else {
            th[i] = th[i];
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
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
		
	// TODO
	
	return resp;
}
