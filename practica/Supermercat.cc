#include "Supermercat.hh"
using namespace std;


Supermercat::Supermercat(int rengles_p, int columnes_p, int total_caixes_p, int nombre_productes_p)
{
    rengles = rengles_p;
    nombre_productes = nombre_productes_p;
    columnes = columnes_p;
    total_caixes = total_caixes_p;
    nombre_clients = 0;
    nombre_caixes_rapides = 0;
    nombre_caixes_normals = 0;
    seccions = vector<vector<set<string> > >(rengles_p, vector<set<string> >(columnes_p));
    caixes = vector<Caixa> (total_caixes);
}

    //Destructores
Supermercat::Supermercat(){}
    
Supermercat::~Supermercat(){}

    //Modificadores
void Supermercat::afegir_parametres_supermercat(int r,int col,int x,int n)
{
    rengles = r;
    columnes = col;
    total_caixes = x;
    nombre_productes = n;
    seccions = vector<vector<set<string> > >(r, vector<set<string> >(col));
}


void Supermercat::productes_seccio(string seccio)
{
    int x, y;
    x = seccio[0] - 'A';
    y = seccio[1] - '0' - 1;
    if (x <= rengles and y <= columnes and x >= 0 and y >= 0)
    {
        if (!seccions[x][y].empty())
        {
            set<string>::iterator it = seccions[x][y].begin();
            set<string>::iterator it_aux = seccions[x][y].end();
            while (it != it_aux)
            {
                cout << *it << endl;
                ++it;
            }
        }
        else
            cout << "seccio buida" << endl;
    }
    else
        cout << "error3" << endl;
    cout << endl;
}

void afegir_producte_supermercat(string producte_id, string seccio, vector<vector<set<string> > >& seccions)
{
    int x, y;
    x = seccio[0] - 'A';
    y = seccio[1] - '0' - 1;
    seccions[x][y].insert(producte_id);
}

void Supermercat::afegir_n_productes(int n, Conjunt_productes& cp)
{
    string producte_id, seccio;
    double preu;
    int temps_cobrament;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> producte_id >> preu >> seccio >> temps_cobrament;
        afegir_producte_supermercat(producte_id,seccio,seccions);
        cp.afegir_producte_cjt_productes(producte_id, preu, seccio, temps_cobrament);
    }
}




//SIMULACIO_________________________

void Supermercat::actualitza(Temps hora)
{
    for (int i = 0 ; i < caixes.size() ; ++i)
    {
        while (caixes[i].n_clients > 0 and hora.puc_borrar(caixes[i].instant_proxim))
        {
            --caixes[i].n_clients;
        }
    }
}


Temps temps_espera_aux(Temps t1, Temps t2)  //t1: instant client arriba a la coa
{                                           //t2: instant de pagar del següent client
    Temps t_out(0,0,0);
    if (t1.compara_temps(t2) <= 0)
    {
        double t1_aux = t1.consultar_segons();
        t1_aux += (t1.consultar_minuts())*60;
        t1_aux += (t1.consultar_hores())*3600;
        
        double t2_aux = t2.consultar_segons();
        t2_aux += (t2.consultar_minuts())*60;
        t2_aux += (t2.consultar_hores())*3600;
        
        double out = t2_aux - t1_aux;
        t_out.modificar_segons(out);
        t_out.actualitza_temps();
    }
    
    return t_out;
}

void Supermercat::assigna_caixa(int r, int n, Client& c)
{
    bool menys_deu = (c.consultar_productes_client() <= 10);
    
    int caixa_final = 0;
    if (r != 0)
    {
        if (!menys_deu) caixa_final = r;
    }
    
    bool trobat = false;
    
    int it_out = n+r - 1;
    
    for (int i = n+r-1; i >= caixa_final and !trobat; i--) {
        if (caixes[i].n_clients == 0) {
            trobat = true;
            ++caixes[i].n_clients;
            c.modificar_temps_caminar((n+r)-1 - i);
            c.modificar_caixa(n+r-i);
            Temps t_aux = c.consultar_instant_tiquet();
            t_aux.afegeix_int(n+r-1-i);
            c.modificar_instant_cua(t_aux);
            t_aux.modifica_temps(0,0,0);
            c.modificar_temps_espera_cua(t_aux);
            t_aux.suma_temps(c.consultar_instant_cua(),t_aux,t_aux);
            c.modificar_instant_caixa(t_aux);
            t_aux.suma_temps(t_aux,c.consultar_temps_cobrament(),t_aux);
            c.modificar_instant_acabament(t_aux);
            caixes[i].instant_proxim = t_aux;
            caixes[i].instant_proxim.afegeix_int(1);
        }
        else if (caixes[i].n_clients < caixes[it_out].n_clients) it_out = i;
    }
    if (!trobat) {
        c.modificar_temps_caminar((n+r)-1 - it_out);
        
        //cout << "Temps caminar: " << (n+r)-1 - it_out << endl;
        
        ++caixes[it_out].n_clients;
        c.modificar_caixa(n+r-it_out);
        
       // cout << "Caixa: " << 12 - (n+r) - it_out +1 << endl;
        
        Temps t_aux = c.consultar_instant_tiquet();
        
        /*cout << "Instant_tiquet: ";
        t_aux.escriu_temps();
        cout << endl;*/
        
        t_aux.afegeix_int(n+r-1-it_out);
        c.modificar_instant_cua(t_aux);
        
        /*cout << "Instant cua: ";
        t_aux.escriu_temps();
        cout << endl;*/
        

        t_aux = temps_espera_aux(t_aux,caixes[it_out].instant_proxim);
        c.modificar_temps_espera_cua(t_aux);

        
        /*cout << "Temps espera: ";
        t_aux.escriu_temps();
        cout << endl;*/
        
        t_aux.suma_temps(t_aux,c.consultar_instant_cua(),t_aux);
        t_aux.afegeix_int(-1);
        c.modificar_instant_caixa(t_aux);
        
        /*cout << "Instant caixa: ";
        t_aux.escriu_temps();
        cout << endl;*/
        
        t_aux.suma_temps(t_aux,c.consultar_temps_cobrament(),t_aux);
        c.modificar_instant_acabament(t_aux);
        
        /*cout << "Instant acabament: ";
        t_aux.escriu_temps();
        cout << endl;*/
        
        t_aux.afegeix_int(1);
        caixes[it_out].instant_proxim = t_aux;
        
        /*cout << "Instant proxim: ";
        t_aux.escriu_temps();
        cout << endl;*/
    }

}

void Supermercat::simulacio(int n, Conjunt_clients& cc)
{
    int rap, nor;
    for (int i = 0 ; i < n ; ++i)     //Combinacions de caixes
    {
        cin >> nor >> rap;
        caixes = vector<Caixa> (rap+nor);
        for (int j = 0 ; j < nor+rap ; ++j)
            caixes[j].n_clients = 0;
        int nc = cc.consultar_nombre_clients();
        for (int j = 0 ; j < nc ; ++j)
        {
            Temps t = cc.client_posicio_i(j).consultar_instant_tiquet();
            actualitza(t);
            Client c_aux = cc.client_posicio_i(j);
            assigna_caixa(rap,nor,c_aux);
            cc.modificar_client_i_essim(j, c_aux);

        }
        cc.sortida_clients(total_caixes);
    }
    cout << endl;
}
