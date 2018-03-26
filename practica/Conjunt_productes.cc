#include "Conjunt_productes.hh"
using namespace std;

//Constructores
Conjunt_productes::Conjunt_productes() {
    map<string, Producte> conjunt_prod_p;
    conjunt_prod = conjunt_prod_p;
    nombre_productes = 0;
}

Conjunt_productes::~Conjunt_productes(){}

void Conjunt_productes::afegir_producte_cjt_productes(string producte_id, double preu, string seccio, int temps_cobrament) {

	Producte p(seccio,temps_cobrament,preu,producte_id);
	conjunt_prod.insert(make_pair(producte_id,p));
	++nombre_productes;
}

void Conjunt_productes::informacio_producte(string producte_id) {
    map<string, Producte>::const_iterator it = conjunt_prod.find(producte_id);
    if (it != conjunt_prod.end()) {
        Producte aux = it-> second;
        aux.escriure_producte();
	cout << endl;
    }
    else
		cout << "error" << endl << endl;
}

int Conjunt_productes::id_temps_cobrament(string identificador) {
    map<string, Producte>::const_iterator it = conjunt_prod.find(identificador);
    if (it != conjunt_prod.end()) {
        Producte aux = it -> second;
        return aux.consultar_temps_producte();
    }
    else return 0;
}

string Conjunt_productes::consultar_seccio_producte(string producte_id) {
    map<string, Producte>::const_iterator it = conjunt_prod.find(producte_id);
    if (it != conjunt_prod.end()) {
        Producte aux = it-> second;
        return aux.consulta_graella();
    }
    return 0;
}
