/** @file Producte.hh
    @brief Classe Producte*/

#ifndef PRODUCTE_HH
#define PRODUCTE_HH

#include "Temps.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#endif
using namespace std;

/** @class Producte
    @brief Respresenta un Producte com a contenidor d'un id, la seva posició a la graella, 
	un temps de cobrament i un preu.
 */

class Producte{
private:
    string producte_id;
    string graella;
    Temps temps_de_cobrament;
    double preu;

public:
    //Constructores
    Producte();
    /** @brief crea un Producte buit
    \pre cert
    \post cert */

    Producte(string graella_p, int temps_de_cobrament_p, double preu_p, string producte_id_p);
    /** @brief crea un producte amb els parametres donats
    \pre graella_p està dins del Supermercat, temps_de_cobrament_p > 0, preu_p > 0
    \post crea un Client amb els parametres donats */

    //Destructores
    ~Producte();
    /** @brief Destructora per defecte */

    //Consultores
    int consultar_temps_producte();
    /** @brief Consulta el temps que es triga en cobrar un producte a caixa
    \pre Cert
    \post Retorna el temps_de_cobrament del parametre implícit */

    //Entrada/Sortida

    void llegir_producte();
    /** @brief Llegeix un producte pel canal estandard d'entrada
    \pre graella_p està dins del Supermercat, temps_de_cobrament_p > 0, preu_p > 0
    \post el parametre implicit te com a valors els de l'entrada */

    void escriure_producte();
    /** @brief Escriu un producte pel canal estandard de soritda
    \pre cert
    \post el valors del p.implicit s'han escrit pel canal estandard de sortida */

    string consulta_graella();
    /** @brief Retorna on es troba un producte a la graella
    \pre Cert
    \post Retorna a quina seccio de la graella del supermercat es troba
    el p.implicit*/

    string consultar_nom();
    /** @brief Retorna l'identificador del p. implicit
    \pre Cert
    \post Retorna l'identificador del p. implicit*/

};

#endif
