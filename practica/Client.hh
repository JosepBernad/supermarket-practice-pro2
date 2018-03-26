/** @file Client.hh
    @brief Classe Client */

#ifndef CLIENT_HH
#define CLIENT_HH

#include "Conjunt_productes.hh"
#include "Producte.hh"
#include "Temps.hh"
#ifndef NO_DIAGRAM
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#endif
using namespace std;

/** @class Client
    @brief Respresenta un Client com a contenidor de Seccions i Temps.
 */

struct seccio {
    char x;
    int y;
};

class Client {
private:
    int identificador;
    int nombre_productes;
    int caixa;
    int temps_caminar;
    vector<seccio> productes;
    Temps instant_tiquet;
    Temps instant_cua;
    Temps temps_espera_cua;
    Temps instant_caixa;
    Temps temps_cobrament;
    Temps instant_acabament;

public:
    //Constructores
    Client();
	/** @brief Constructora per defecte */

    Client(int identificador_p, Temps t_p, int nombre_productes_p);
    /** @brief Crea un client amb els parametres rebuts
    \pre cert
    \post crea un Client amb els parametres identificador, t... rebuts. */

    //Destructores
    ~Client();
	/** @brief Destructora per defecte */

    //Consultores
    int consultar_identificador();
    /** @brief Retorna l'identificador d'un client
     \pre cert
     \post retorna l'identificador del client del p. implicit */

    int consultar_caixa();
    /** @brief Retorna la caixa assignada d'un client
     \pre cert
     \post retorna la caixa assignada d'un client */
    
    Temps consultar_instant_tiquet();
    /** @brief Retorna el moment de recollida del tiquet
     \pre El Client ha recollit el tiquet
     \post retorna l'instant de recollida del parametre implicit */
    
    Temps consultar_instant_caixa();
    /** @brief Consulta l'instant de caixa del p.implicit
	\pre Cert
	\post Retorna l'instan de caixa del p.implicit */

    int consultar_productes_client();
    /** @brief Retorna el nombre de productes d'un Client
    \pre cert
    \post retorna el nombre de productes que te el p. implicit */

    Temps consultar_temps_cobrament();
    /** @brief Consulta el temps total que trigara el p. implicit en pagar
    \pre Cert
    \post retorna el temps_cobrament del p.implicit */

    Temps consultar_temps_espera_cua();
    /** @brief Consulta el temps d'espera que trigara el p. implicit a la cua
    \pre Cert
    \post retorna el temps_espera del p.miplicit */

    
    Temps consultar_instant_cua();
    /** @brief Consulta l'instant en el que el p.implicit arriba a la cua
	\pre Cert
	\post Retorna l'instant de cua del p.implicit */
    
    Temps consultar_instant_acabament();
    /** @brief Consulta l'instant en el que el p.implicit acaba
	\pre Cert
	\post Retorna l'instant d'acabament del p.implicit */
    
    //Modificadores

    void modificar_instant_cua(Temps t);
	/** @brief Modifica l'instant en el que el p.implicit arriba a la cua
	\pre Cert
	\post El p.implicit passa a tenir com a instant_cua t */

    void modificar_instant_acabament(Temps instant_acabament_p);
    /** @brief Modifica al P.I. l'instant d'acabament
    \pre cert
    \post modifica al P.I. l'instant d'acabament */

    void modificar_caixa(int caixa_p);
    /** @brief Modifica la caixa assignada del p.implicit
    \pre cert
    \post la caixa assignada del p.implicit passa a ser caixa_p */

    void modificar_temps_cobrament(Temps n);
    /** @brief Modifica el temps de cobrament del p.implicit
    \pre cert
    \post el temps de cobrament del p.implicit passa a ser n*/

    void modificar_temps_espera_cua(Temps n);
    /** @brief Modifica el temps d'espera a la cua del p.implicit
    \pre cert
    \post el temps d'espera_cua dl p.implicit passa a ser n*/

    void modificar_temps_caminar(int t);
    /** @brief Modifica el temps de caminar del p.implicit
	\pre Cert
	\post Modifica el temps de caminar del p.implicit */
    
    void modificar_instant_caixa(Temps t);
    /** @brief Modifica l'instant de caixa del p.implicit
	\pre Cert
	\post Modifica el temps de caixa del p.implicit */

    //Entrada/Sortida
    void llegeix_client(Conjunt_productes& cp);
    /** @brief Llegeix un client pel canal estandard
    \pre Cert
    \post llegeix un client per el canal estandard */

    void llegir_conjunt_productes(int n,Conjunt_productes&c);
    /** @brief Llegeix un conjunt de productes i s'afegeix al Client
    \pre cert
    \post el parametre implicit passa a tenir els n productes llegits com a productes */

    void consulta_millor_cami(int rengles);
    /** @brief Imprimeix el millor camí per a recollir els productes del client
    \pre nombre_de_productes del parametre implicit > 1, on rengles es el nombre
    de rengles del supermercat
    \post Imprimeix pel canal estandard "llargada_millor_cami" seguit
    del cami mes curt per obtenir els Conjunt_productes de c */
};

#endif

