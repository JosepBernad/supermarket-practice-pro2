#include "Temps.hh"

Temps::Temps(){
}

Temps::Temps(int segons_p,int minuts_p,int hores_p) {
    segons = segons_p;
    minuts = minuts_p;
    hores = hores_p;
}

int Temps::compara_temps(const Temps& a) {
    if (hores > a.hores) return 1;
    else if (hores < a.hores) return -1;
    else if (minuts > a.minuts) return 1;
    else if (minuts < a.minuts) return -1;
    else if (segons > a.segons) return 1;
    else if (segons < a.segons) return -1;
    else return 0;
}

void Temps::modifica_temps(int segons_p,int minuts_p,int hores_p) {
    segons = segons_p;
    minuts = minuts_p;
    hores = hores_p;
}


void Temps::actualitza_temps() {
	if (segons >= 60){
        minuts += segons/60;
        segons = segons%60;
    }
    if (minuts >= 60) {
        hores += minuts/60;
        minuts = minuts%60;
    }
}

void Temps::llegir_temps() {
    char aux;
    cin >> hores >> aux >> minuts >> aux >> segons;
}

void Temps::escriu_temps() {
    if (hores/10 == 0)
        cout << 0;
    cout << hores << ':';
    if (minuts/10 == 0)
        cout << 0;
    cout << minuts << ':';
    if (segons/10 == 0)
        cout << 0;
    cout << segons;
}

int Temps::temps_cobrament_producte() {
    return segons;
}

void Temps::afegeix_int(int i) {
    if (i < 0 and segons == 0) {
        if (minuts == 0) {
            hores--;
            minuts = 59;
        }
        else minuts--;
        segons = 59;
    }
    
    else segons += i;
    actualitza_temps();
}

void Temps::resta_temps(Temps fi,Temps inici, Temps& resultat) {
    
    resultat.segons += (fi.minuts*60 + fi.hores*3600 + fi.segons) -(inici.minuts*60 + inici.hores*3600 + inici.segons) ;
    resultat.actualitza_temps();
}

bool Temps::puc_borrar(const Temps& a){
    if (hores >= a.hores)
    {
        if (hores > a.hores)
            return true;
        else
            if (minuts >= a.minuts)
            {
                if (minuts > a.minuts)
                    return true;
                else
                    return (segons >= a.segons);
            }
            else return false;
    }
    else return false;
}

void Temps::suma_temps(Temps a,Temps b, Temps& resultat) {
    resultat.segons = a.segons + b.segons;
    resultat.minuts = a.minuts + b.minuts;
    resultat.hores = a.hores + b.hores;
    resultat.actualitza_temps();
}

int Temps::consultar_segons() {
    return segons;
}

int Temps::consultar_minuts() {
    return minuts;
}

int Temps::consultar_hores() {
    return hores;
}

void Temps::modificar_segons(int n) {
    segons = n;
}

void Temps::modificar_minuts(int n) {
    minuts = n;
}

void Temps::modificar_hores(int n) {
    hores = n;
}
