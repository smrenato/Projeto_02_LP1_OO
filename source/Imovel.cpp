#include "Imovel.h"
using namespace std;
//Construtores e Destrutores da classe
Imovel::Imovel(){

	tipoDeImovel = 0;	
	tipoDeOferta = "";
	valor = 0;
	endereco = Endereco();
}
Imovel::Imovel(int tipoOferta, double valor, string cidade, string bairro,string logradouro,string cep,int numero)
{
	this->tipoDeImovel = 0;
	this->tipoDeOferta = tipoDeOferta;
	string tipoDeOferta;
	
	if(tipoOferta == IMOVEL_PARA_VENDER){
		this->tipoDeOferta = "Alugar";
	}else if(tipoOferta == IMOVEL_PARA_ALUGAR){
		this->tipoDeOferta = "Vender";
	}else{
		this->tipoDeOferta = "Desconhecida";
	}

	this->valor = valor;
	endereco = Endereco(cidade, bairro, logradouro, cep, numero);
}


Imovel::~Imovel(void){

}

//Metodos da classe

double Imovel::getValor(void){
	return valor;

}
string Imovel::getTipoDeOferta(void){
	return tipoDeOferta;

}

Endereco Imovel::getEndereco(void){
	return endereco;

}
