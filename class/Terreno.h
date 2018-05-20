#ifndef TERRENO_H
#define TERRENO_H
#include "Imovel.h"
#include <string>

using namespace std;

class Terreno : public Imovel{
	private:

		double area;

	public:
		Terreno();
		Terreno(int tipoDeOferta, double valor, Endereco endereco, double area, string cidade, string bairro,string logradouro,string cep,int numero);
		virtual ~Terreno();

		double getArea();
		void setArea(double area);
		
		string getDescricao();
};

#endif
