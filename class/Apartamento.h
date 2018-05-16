#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <string>
#include "Imovel.h" // Herda da classe abstrata imovel

class Apartamento : public Imovel{

	private:
		std::string posicao;
		int numeroDeQuartos;
		double valorCondominio;
		int vagasGaragem;
		double area;

	public:
	//Contrutores e destrutores da classe
		Apartamento();
		Apartamento(std::string posicao, int numeroDeQuartos, double valorCondominio,
					int vagasGaragem, double area, int tipoDeOferta, double valor, Endereco endereco);

		virtual ~Apartamento();
		std::string getDescricao();
	//Metodos da classe


};



#endif