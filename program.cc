#include "Conjunt_clients.hh"
#include "Conjunt_productes.hh"
#include "Supermercat.hh"

int main() {
    string p;
    Supermercat s;
    Conjunt_productes cp;
    Conjunt_productes cp_aux;   //sempre buit
    Conjunt_clients cc;
    Conjunt_clients cc_aux;     //sempre buit
    int col,rengles, caixes, n;
    cin >> p;
    bool ini_supermercat, ini_clients;
    ini_supermercat = ini_clients = false;
    while (p != "sortir") {
        if (p == "inicialitzar") {
            ini_supermercat = true;
            ini_clients = false;
            cin >> rengles >> col >> caixes >> n;
            s.afegir_parametres_supermercat(rengles,col,caixes,n);
            cp = cp_aux;
            s.afegir_n_productes(n,cp);  
        }
        else if (p == "carregar") {
            int n_clients;
            cin >> n_clients;
            cc = cc_aux;
            if (ini_supermercat)
            {
                ini_clients = true;
                cc.afegir_n_clients(n_clients, cp);
            }
            else
                cout << "error" << endl;
        }
        else if (p == "informacio") {
            string id;
            cin >> id;
            cout << "informacio " << id << ":" << endl;
            if (ini_supermercat)
                cp.informacio_producte(id);
            else
                cout << "error" << endl << endl;
        }
        else if (p == "productes") {
            string seccio;
            cin >> seccio;
            cout << "productes " << seccio << ":" << endl;
            if (ini_supermercat)
            {
                if ((seccio[0] - 'A' > rengles) or (col - int(seccio[1]-'0') < 0)) {
                    cout << "error" << endl << endl;
                }
                else
                    s.productes_seccio(seccio);
            }
            else
                cout << "error" << endl << endl;
        }
        else if (p == "millor") {
            cin >> p;
            if (p == "cami") {
                int comprador_id;
                cin >> comprador_id;
                cout << "millor cami " << comprador_id << ":" << endl;
                if (ini_supermercat and ini_clients)
                    cc.consultar_millor_cami_client(comprador_id,col);
                else
                {
                    //cout << "Supermercat: " << ini_supermercat << " - Clients: " << ini_clients << endl;
                    cout << "error" << endl << endl;
                }
            }
            else cout << "error" << endl << endl;
        }
        else if (p == "simular") {
            cin >> p;
            if (p == "pagament") {
                cout << "simular pagament:" << endl;
                if(ini_supermercat and ini_clients)
                {
                    int n_simulacions;
                    cin >> n_simulacions;
                    s.simulacio(n_simulacions,cc);
                    
                }
                else
                    cout << "error" << endl << endl;
            }
            else cout << "error" << endl << endl;
        }
        
        else cout << "error" << endl << endl;
        cin >> p;
  }

}
