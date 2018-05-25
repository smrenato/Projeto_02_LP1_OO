#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include <fstream>
#include <list>

#include "SistemaImobiliaria.h"
#include "Imovel.h"

class GerenteDePersistencia {
    private:

	    std::ifstream arquivoDeEntrada;
		std::ofstream arquivoDeSaida; 
		
    
    public:
        GerenteDePersistencia();
        virtual ~GerenteDePersistencia();

        int salvaListaDeImoveis(std::list<Imovel*> salvarMeusImoveis);
        int recuperaListaDeImoveis(void);

};

#endif