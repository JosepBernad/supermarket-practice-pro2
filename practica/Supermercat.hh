/** @file Supermercat.hh
    @brief Classe Supermercat*/

#ifndef SUPERMERCAT_HH
#define SUPERMERCAT_HH

#ifndef NO_DIAGRAM
#include <list>
#include <vector>
#include <set>
#include <string>
#endif

#include "Conjunt_clients.hh"
#include "Conjunt_productes.hh"
using namespace std;

struct Caixa{
    int n_clients;
    Temps instant_proxim;
};

/** @class Supermercat
    @brief Respresenta un Supermercat com a contenidor de Matriu de sets i un vector de Caixes
 */

class Supermercat{
private:
	//1 <= Rengles <= 26
	//1 <= columnes <= 9
	//1 <= caixes <= 20
    int rengles;
    int nombre_productes;
    int columnes;
    int total_caixes;
    int nombre_clients;
    int nombre_caixes_rapides;
    int nombre_caixes_normals;
    vector<vector<set<string> > > seccions;
    vector<Caixa> caixes;
    

public:
//Constructores
	Supermercat();
	/** @brief Consutructora per defecte */

	Supermercat(int rengles_p, int columnes_p, int total_caixes_p, int nombre_productes_p);
    /** @brief Crea un Supermercat amb els parametres rebuts
	\pre rengles_p...nombre_productes_p > 0
	\post crea un Supermercat amb tots els parametres rebuts, nombre_caixes_normals =
	= nombre_caixes_rapides = 0 i Conjunt_productes buit */

//Destructores
    ~Supermercat();
	/** @brief Destructora per defecte */

//Modificadores
    void afegir_parametres_supermercat(int r,int col,int x,int n);
	/** @brief Afegeix els paràmetres de inicialitzacio al supermercat
    \pre el supermercat ha estat inicialitzat, i r .. n > 0
    \post afegeix els paràmetres de inicialitzacio al supermercat*/

//Entrada/Sortida
    void actualitza(Temps hora);
    /** @brief Actualitza les caixes a la hora actual
    \pre hora.hores ... hora.segons > 0
    \post Actualitza les caixes a l'hora actual de Client seguent no assignat*/
    
    void assigna_caixa(int r, int n, Client& c);
    /** @brief Actualitza les caixes a la hora actual
    \pre r,n > 0
    \post Assigna una caixa al Client c, que passa a tenir una caixa assignada*/
    
    void simulacio(int n, Conjunt_clients& c);
    /** @brief Simula diferents configuracions amb x caixes rapides i y caixes normals
    \pre nombre_simulacions > 0, caixes_rapides+caixes_normals = total_caixes
    \post imprimieix per pantalla els temps en mitjana del temps mitja de pagaments dels Clients en
    les n configuracions*/

    void productes_seccio(string seccio);
    /** @brief Imprimeix per pantalla els productes d'una determinada seccio
     \pre Exiteix la seccio al Supermercat
     \post imprimieix per pantalla els productes de la seccio*/

     void afegir_n_productes(int n, Conjunt_productes& cp);
     /** @brief Afegeix n productes a la matriu del supermercat i al map del Conjunt_productes
     \pre Cert
     \post El Conjunt_productes i la matriu del supermercat queden carregats*/
};


#endif
