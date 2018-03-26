/** @file Conjunt_productes.hh
    @brief Classe Conjunt_productes*/

#ifndef CONJUNT_PRODUCTES_HH
#define CONJUNT_PRODUCTES_HH

#include "Producte.hh"
#ifndef NO_DIAGRAM
#include <map>
#include <string>
#endif
using namespace std;

/** @class Conjunt_productes
    @brief Respresenta un Conjunt de productes con a contenidor de Productes */

class Conjunt_productes{
private:
    map<string, Producte> conjunt_prod; //producte_id i Producte
    int nombre_productes;

public:
    //Creadores
    Conjunt_productes();
    /** @brief crea un conjunt de productes buit
    \pre cert
    \post crea un Conjunt_productes amb nombre_productes = 0 */

    //Destructores
    ~Conjunt_productes();
    /** @brief Destructora per defcte */

    //Modificadores
    void afegir_producte_cjt_productes(string producte_id, double preu, string seccio, int temps_cobrament);
	/** @brief Afegeix un producte al conjunt de productes a partir dels seus atributs
    \pre temps_cobrament > 0
    \post afegeix un producte al conjunt de productes a partir dels seus atributs*/

    //Entrada/Sortida
    void informacio_producte(string producte_id);
    /** @brief Imprimeix la informació d'un producte
    \pre Cert
    \post S'imprimeix la informacio del producte (nom, preu, seccio i temps_cobrament)
    si pertany al p.implicit. Si no, imprimeix "error" pel canal estandard de sortida */

    int id_temps_cobrament(string identificador);
    /** @brief Retorna el temps de cobrament d'un producte
    \pre El producte existeix al conjunt
    \post Retorna el temps que es triga en cobrar el producte
    amb producte_id = identificador */

    string consultar_seccio_producte(string producte_id);
    /** @brief Retorna la seccio d'un producte
    \pre El producte pertany al conjunt de productes
    \post Retorna la seccio en la que es troba un producte */
};

#endif
