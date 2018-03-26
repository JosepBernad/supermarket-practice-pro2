#include "Conjunt_clients.hh"
using namespace std;

    //Creadores
Conjunt_clients::Conjunt_clients()
{
    nombre_clients = 0;
}

Conjunt_clients::Conjunt_clients(int nombre_clients_p)
{
    vector<Client> cua_clients_p(nombre_clients_p);
    cua_clients = cua_clients_p;
    nombre_clients = nombre_clients_p;
}
    //Destructores
Conjunt_clients::~Conjunt_clients(){}

    //Consultores
int Conjunt_clients::consultar_nombre_clients()
{
    return nombre_clients;
}

    //Modificadores
void Conjunt_clients::modificar_instant_acabament_i_essim(int j, Temps t) {

    cua_clients[j].modificar_instant_acabament(t);
}

void Conjunt_clients::modificar_caixa_assignada_i_essim(int j, int caixa) {
    cua_clients[j].modificar_caixa(caixa);
}

void Conjunt_clients::modificar_temps_cobrament_i_essim(int i, Temps t) {
    cua_clients[i].modificar_temps_cobrament(t);
}

void Conjunt_clients::modificar_temps_espera_cua_i_essim(int i, Temps t){
    cua_clients[i].modificar_temps_espera_cua(t);
}

void Conjunt_clients::modificar_temps_caminar_i_essim(int i, int t) {
    cua_clients[i].modificar_temps_caminar(t);
}

void Conjunt_clients::modificar_client_i_essim(int j, Client c_aux) {
    cua_clients[j] = c_aux;
}



void Conjunt_clients::consultar_millor_cami_client(const int identificador,const int columnes) {
	if (identificador <= nombre_clients and identificador > 0) {
	  cua_clients[identificador-1].consulta_millor_cami(columnes);
	  cout << endl;
	}
	else cout << "error" << endl << endl;
}

Temps Conjunt_clients::consultar_instant_tiquet_i_essim(int i){
    return cua_clients[i].consultar_instant_tiquet();

}

Temps Conjunt_clients::consultar_temps_cobrament_i_essim(int i) {
    return cua_clients[i].consultar_temps_cobrament();
}

void Conjunt_clients::modificar_instant_caixa_i_essim(int i, Temps t) {
    cua_clients[i].modificar_instant_caixa(t);
}
    


void Conjunt_clients::afegir_n_clients(int l, Conjunt_productes& c)
{
	nombre_clients = l;
    cua_clients = vector<Client> (l);
    for (int i = 0 ; i < l ; ++i)
    {
        Client aux;
        aux.llegeix_client(c);
        int id = aux.consultar_identificador();
        cua_clients[id-1] = aux;
    }
}

void Conjunt_clients::sortida_clients(int total_caixes)                            
{
	Temps suma(0,0,0);
	Temps inici, fi;
	for (int i = 0 ; i < nombre_clients ; ++i) {
        cout << i+1 << " " << total_caixes - cua_clients[i].consultar_caixa() + 1 << " ";
        inici = cua_clients[i].consultar_instant_caixa();
        inici.escriu_temps();
        cout << " ";
        inici = cua_clients[i].consultar_instant_tiquet();
        fi = cua_clients[i].consultar_instant_acabament();
        fi.afegeix_int(-1);
        fi.escriu_temps();
        cout << endl;
        suma.resta_temps(fi, inici, suma);
        suma.afegeix_int(1);
	}
	suma.escriu_temps();
	cout << endl;
}

Client Conjunt_clients::client_posicio_i(int i) {
    return cua_clients[i];
}
