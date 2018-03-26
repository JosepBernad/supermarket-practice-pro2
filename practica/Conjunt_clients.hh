/** @file Conjunt_clients.hh
    @brief Classe Conjunt_clients*/
    
#ifndef CONJUNT_CLIENTS_HH
#define CONJUNT_CLIENTS_HH

#include "Client.hh"
#include "Conjunt_productes.hh"
#ifndef NO_DIAGRAM
#include <vector>
#endif
using namespace std;

/** @class Conjunt_clients
    @brief Respresenta un Conjunt de clients com a contenidor de Clients.
 */

class Conjunt_clients   {
private:
    vector<Client> cua_clients;
    int nombre_clients;
    
public:
    
//Creadores
    Conjunt_clients();
    /** @brief Crea un Conjunt_clients buit
	\pre cert
	\post Conjunt_clients amb un vector buida */
    
    Conjunt_clients(int nombre_clients_p);
    /** @brief Crea un Conjunt_clients buit de tamany n
     \pre cert
     \post Conjunt_clients amb un vector de n posicions buit */
    
//Destructores
    ~Conjunt_clients();
    /** @brief Destructora per defecte */
    
//Modificadores
    void modificar_instant_acabament_i_essim(int j, Temps t);
    /** @brief Modifica l'instant d'acabament del client a la posicio j del vector
    \pre 0 <= i < nombre_clients
    \post Modifica l'instant d'acabament del client a la posicio j del vector*/
    
    void modificar_caixa_assignada_i_essim(int j, int caixa);
    /** @brief Modifica l'instant d'acabament del client a la posicio j del vector
    \pre 0 <= i < nombr_clients
    \post Modifica l'instant d'acabament del client a la posicio j del vector*/
    
    void modificar_temps_cobrament_i_essim(int i, Temps temps);
    /** @brief Modifica el temps de cobrament del client a la posicio i del vector
    \pre 0 <= i < nombre_clients
    \post Modifica el temps de cobrament del client a la posicio i del vector*/
    
    void modificar_temps_caminar_i_essim(int i, int temps);
    /** @brief Modifica el temps de caminar del client a la posicio i del vector
    \pre 0 <= i < nombre_clients
    \post Modifica el temps de caminar del client a la posicio i del vector*/
    
    void modificar_temps_espera_cua_i_essim(int i, Temps temps);
   	/** @brief Modifica el d'espera a la cua del client a la posicio i del vector
    \pre 0 <= i < nombre_clients
    \post Modifica el temps d'espera a la cua del client a la posicio i del vector*/

     
    void modificar_instant_caixa_i_essim(int i, Temps temps);
   	/** @brief Modifica l'instant de caixa del client a la posicio i del vector
    \pre 0 <= i < nombre_clients
    \post Modifica l'instant de caixa del client a la posicio i del vector*/

    void modificar_client_i_essim(int j, Client c_aux);
   	/** @brief Modifica el Client a la posicio i del vector
    \pre 0 <= i < nombre_clients
    \post Modifica el Client a la posicio i del vector*/
    
//Consultores
    int consultar_nombre_clients();
    /** @brief Retorna el nombre de clients d'un Conjunt de clients
     \pre cert
     \post Retorna el nombre de clients d'un Conjunt de clients */
    
    Client client_posicio_i(int i);
    /** @brief Retorna el Client a la posicio i de la cua
     \pre Cert
     \post Retorna el Client a la posicio i de la cua */
    
    Temps consultar_instant_tiquet_i_essim(int i);
    /** @brief Retorna l'instant en el que Client ha recollit el tiquet
     \pre Cert
     \post Retorna l'instant en el que Client ha recollit el tiquet */
    
    Temps consultar_temps_cobrament_i_essim(int i);
     /** @brief Retorna el temps que es trigara en cobrar a Client
     \pre Cert
     \post Retorna el temps que es trigara en cobrar a Client */
    
//Entrada/Sortida
    void consultar_millor_cami_client(const int identificador,const int columnes);
    /** @brief Imprimeix per pantalla el camí més curt per agafar tots els productes
    \pre Cert
    \post Imprimeix per pantalla el camí més curt per agafar tots els productes */

    void afegir_n_clients(int l, Conjunt_productes& c);
    /** @brief Llegeix l clients pel canal estàndard d'entrada
    \pre Cert
    \post S'han afegit l Clients a la cua_clients del p.implicit amb els sseus prsoductes */
    
    void sortida_clients(int total_caixes);
    /** @brief Imprimeix per pantalla les característiques dels clients que ha passat per caixa
    \pre Cert
    \post Imprimeix per pantalla les característiques dels clients que ha passat per caixa */
};

#endif
