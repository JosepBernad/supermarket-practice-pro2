/** @file Temps.hh
    @brief Classe Temps*/

#ifndef TEMPS_HH
#define TEMPS_HH
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

/** @class Temps
    @brief Respresentacio del temps en hores,minuts i segons */

class Temps{
private:
	int segons,minuts,hores;

public:
    //Constructores
    Temps();
    /** @brief Constructora per defecte */

    Temps(int segons_p,int minuts_p,int hores_p);
    /** @brief Crea un Temps amb els parametres donats
	\pre segons > 0, minuts > 0, hores > 0
	\post crea un Temps amb els parametres donats */

    //Consultores
    int consultar_segons();
    /** @brief Consulta els segons del p.implicit
    \pre cert
    \post retorna segons del p.implicit */
    
    int consultar_minuts();
    /** @brief Consulta els minuts del p.implicit
    \pre cert
    \post retorna minuts del p.implicit */
    
    int consultar_hores();
    /** @brief Consulta les hores del p.implicit
    \pre cert
    \post retorna hores del p.implicit */

    int compara_temps(const Temps& a);
    /** @brief Retorna si el p.implicit es major que el Temps a
	\pre cert
	\post Si el p.implicit > a, retorna 1. Si es menor, retorna -1.
	En cas que siguin iguals, retorna 0 */

	int temps_cobrament_producte();
    /** @brief Retorna el segons del parametre implicit
	\pre cert
	\post Retorna el segons del parametre implicit */

    bool puc_borrar(const Temps& a);
    /** @brief Retorna si a >= b
	\pre cert
	\post Retorna si a >= b  */

	//Entrada/Sortida
	void escriu_temps();
    /** @brief Escriu els valors del p.implicit en format HH:MM:SS
	\pre cert
	\post Els valors de p.implicit han set escrits pel canal estandard
	de sortida en format HH:MM:SS */
    
    void llegir_temps();
    /** @brief Llegeix un temps en format HH:MM:SS
    \pre cert
    \post El parametre implicit passa a tenir
    els valors HH:MM:SS */
    

	//Modificadores
    
    void modificar_segons(int n);
   	/** @brief Modifica els segons del p.implicit
	\pre n >= 0
	\post el p.implicit passa a tenir n com a segons */
    
    void modificar_minuts(int n);
   	/** @brief Modifica els minuts del p.implicit
	\pre n >= 0
	\post el p.implicit passa a tenir n com a minuts */    

    void modificar_hores(int n);
   	/** @brief Modifica les hores del p.implicit
	\pre n >= 0
	\post el p.implicit passa a tenir n com a hores */

	void modifica_temps(int segons_p,int minuts_p,int hores_p);
    /** @brief Modifica al p.implicit amb els parametres donats
	\pre segons_p > 0, minuts_p > 0, hores_p > 0
	\post Modifica al p.implicit amb els parametres donats */
    
    void modifica_segons(int segons_p);
     /** @brief Modifica els segons del p.implicit
    \pre cert
    \post Modifica els segons del p.implicit amb segons_p */
     
    void afegeix_int(int i);
    /** @brief Afegeix i segons al p.implicit
    \pre i >= -1
    \post Afegeix i segons al p.implicit, en format HH:MM:SS */

	void actualitza_temps();
    /** @brief Actualitza al p.implicit donant-li valors s < 60,
    m < 60, sumant adequadament els minuts i les hores
	\pre cert
	\post Si el p.implicit tenia s/m > 59, s'han afegit els/les m/s
	respectius */

    void suma_temps(Temps a, Temps b, Temps& resultat);
    /** @brief Retorna el Temps fi+inici en format H:M:S
	\pre Cert

	\post Retorna el Temps fi+inici en format H:M:S */

	void resta_temps(Temps fi, Temps inici, Temps& resultat);
    /** @brief Retorna el Temps fi-inici en format H:M:S

	\pre fi >= inici
	\post Retorna el Temps fi-inici en format H:M:S */



};

#endif

