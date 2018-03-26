#include "Producte.hh"

Producte::Producte(string graella_p, int temps_de_cobrament_p, double preu_p, string producte_id_p) {
    producte_id = producte_id_p;
    graella = graella_p;
    int aux = temps_de_cobrament_p;
    Temps temps_aux(0,0,temps_de_cobrament_p);
    temps_de_cobrament = temps_aux;
    temps_de_cobrament.modificar_segons(aux);
    preu = preu_p;
}

Producte::~Producte(){}

int Producte::consultar_temps_producte() {
    return temps_de_cobrament.temps_cobrament_producte();
}

void Producte::escriure_producte() {
    cout << producte_id << " " << preu << " " << graella << " " << temps_de_cobrament.temps_cobrament_producte() << endl;
}

void Producte::llegir_producte() {
    int n;
    cin >> producte_id >> preu >> graella >> n;
    temps_de_cobrament.modificar_segons(n);
}

string Producte::consulta_graella() {
    return graella;
}

string Producte::consultar_nom() {
    return producte_id;
}
