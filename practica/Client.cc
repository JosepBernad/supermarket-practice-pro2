#include "Client.hh"
using namespace std;

Client::Client(){
    
    
}

Client::~Client(){}

int Client::consultar_productes_client() {
    return nombre_productes;
}

int Client::consultar_caixa(){
	return caixa;
}

int Client::consultar_identificador() {
    return identificador;
}

Temps Client::consultar_temps_cobrament() {
    return temps_cobrament;
}

void Client::modificar_instant_cua(Temps t){
    instant_cua = t;
}

Temps Client::consultar_instant_caixa() {
    return instant_caixa;
}

void Client::modificar_instant_caixa(Temps t){
    instant_caixa = t;
}

void Client::modificar_instant_acabament(Temps t) {
    instant_acabament = t;
}


Temps Client::consultar_instant_tiquet() {
    return instant_tiquet;
}

void Client::modificar_caixa(int caixa_p){
	caixa = caixa_p;
}

void Client::llegeix_client(Conjunt_productes& c) {
    cin >> identificador;
    instant_tiquet.llegir_temps();
    int n;
    cin >> n;
    Temps t(0,0,0);
    temps_caminar = 0;
    instant_cua = t;
    temps_espera_cua = t;
    instant_caixa = t;
    temps_cobrament = t;
    instant_acabament = t;
    llegir_conjunt_productes(n,c);

}

void Client::llegir_conjunt_productes(int n, Conjunt_productes& cp) {
    string producte_id;
    int quantitat;
    string p;
    int j = 0;
    vector<seccio> aux(n);
    set<string> llista_auxiliar;
    nombre_productes = 0;
    for (int i = 0; i < n; i++) {
        cin >> producte_id;
        cin >> quantitat;
        nombre_productes += quantitat;
        p = cp.consultar_seccio_producte(producte_id);
        if (llista_auxiliar.find(p) == llista_auxiliar.end()) {
            llista_auxiliar.insert(p);
       	    aux[j].x = p[0];
            aux[j].y = p[1] - '0';
            j++;
        }
        Temps aux(cp.id_temps_cobrament(producte_id)*quantitat,0,0);
        aux.suma_temps(aux, temps_cobrament, temps_cobrament);
        temps_cobrament.actualitza_temps();
    }
	vector<seccio> aux2 (j);
	for (int i = 0; i < j;i++) {
		aux2[i].x = aux[i].x;
		aux2[i].y = aux[i].y;
	}
	productes = aux2;
}



void Client::modificar_temps_cobrament(Temps n){
    temps_cobrament = n;
}

void Client::modificar_temps_espera_cua(Temps n) {
    temps_espera_cua = n;
}

void Client::modificar_temps_caminar(int n) {
    temps_caminar = n;
}

Temps Client::consultar_temps_espera_cua() {
    return temps_espera_cua;
}

Temps Client::consultar_instant_acabament() {
    return instant_acabament;
}

Temps Client::consultar_instant_cua() {
    return instant_cua;
}


// Algorisme millor cami d'un Client

int calcula_cami(const vector<seccio>& productes, int i,const int columnes) {
    int res = 0;
    if (i == 0) res += (abs(productes[i].x - 'A') + abs(productes[i].y - 1));
    else if (i == productes.size()) res += (abs(productes[i-1].x - 'A') + abs(productes[i-1].y - columnes));
    else res += (abs(productes[i-1].x - productes[i].x) + abs(productes[i-1].y - productes[i].y));
    return res;
}

void canvi(vector<seccio>& v, int a, int b) {
    seccio aux;
    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}


bool ordre_lexicografic(const vector<seccio>& a, const vector<seccio>& b) {
    int i = 0;
    while (i != a.size()) {
        if (a[i].x < b[i].x) return true;
        else if (a[i].x > b[i].x) return false;
	else if (a[i].y < b[i].y) return true;
	else if (a[i].y > b[i].y) return false;
        else i++;
    }
    //Cas que siguin iguals (que mai es donara)
    return true;
}

void consultar_millor_cami_aux(vector<seccio>& productes, int i, vector<seccio>& vector_aux, int& min, const int columnes, int actual) {
    if (i != productes.size()) {
        for (int j = i; j < productes.size(); j++) {
            canvi(productes, i, j);
            int aux = calcula_cami(productes,i,columnes);
            actual += aux;
            if (min >=actual) consultar_millor_cami_aux(productes, i+1, vector_aux, min, columnes, actual);
            actual -= aux;
            canvi(productes,i,j);
        }
    }
    else {
        int aux = calcula_cami(productes,productes.size(),columnes);
        actual += aux;
        if (min > actual) {
            min = actual;
            for (int i = 0; i < productes.size(); i++) vector_aux[i] = productes[i];
        }
        else if (min == actual) {
            if (ordre_lexicografic(productes, vector_aux)) {
                for (int i = 0; i < productes.size(); i++) vector_aux[i] = productes[i];
            }
        }
        actual -= aux;
    }
}


pair<int,int> cas_extrem(const vector<seccio>& productes,const int columnes) {
    //Funció auxiliar per mirar si tenim productes a A1 o Acolumnes
    int j = 0;
    int i = productes.size();
    if (productes[0].x == 'A' and productes[0].y == 1) j++;
    if (productes[i-1].x == 'A' and productes[i-1].y == columnes) i--;
    return make_pair(j,i);
}
    
void Client::consulta_millor_cami(const int columnes) {
    int min = 55555555;
    int actual = 0;
    vector<seccio> vector_aux (productes.size());
    consultar_millor_cami_aux(productes,0, vector_aux, min, columnes, actual);
    cout << min << endl;
    cout << "A1" << " "; 
    pair<int,int> i_f = cas_extrem(vector_aux,columnes);
    if (min != 0) {
        for (int i = i_f.first; i < i_f.second ; i++) cout << vector_aux[i].x << vector_aux[i].y << " ";
        cout << "A" << columnes << " " << endl;
    }
    else cout << endl;
}

