#include <iostream>
#include <list>

#include "SistemaImobiliaria.h"
#include "Interface.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Flat.h"
#include "Studio.h"
#include "Terreno.h"
#include "limpaTela.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Interface interface;
	SistemaImobiliaria imobiliaria;
	Imovel *imovel;
	list <Imovel*> meusImoveis;

	int opcaoItem, opcaoSubItem,numero,tipoDeOferta, sair = 0, opcaoInvalida = 0;
	double valor;
	string cidade, bairro, logradouro, cep;

	while(1){
		limpaTela();

		if(opcaoInvalida) cout << "Opcao invalida!" << endl;
		opcaoInvalida = 0;

		interface.ExibeMenuItem();

		cin >> opcaoItem;

		switch(opcaoItem){
			case 1://Cadastra imoveis
				while(1){
					limpaTela();
					if(opcaoInvalida) cout << "Opcao invalida!" << endl;
					opcaoInvalida = 0;
					interface.ExibeMenuSubItem1();

					cin>>opcaoSubItem;
					
					switch(opcaoSubItem){
						case 1:{
							int numeroDePavimentos,numeroDeQuartos;
							double areaDoTerreno,areaConstruida;
							
							cout<<"Indique o endereco do seu imovel, primeiramente a cidade: ";
							cin>>cidade;
							cout<<"Bairro: ";
							cin>>bairro;
							cout<<"Lougradouro: ";
							cin>>logradouro;
							cout<<"CEP: ";
							cin>>cep;
							cout<<"Numero: ";
							cin>>numero;
							cout<<"Valor do imovel: ";
							cin>>valor;
							cout<<"Se o imovel for para vender, digite 1, se for para alugar, digite 2: ";
							cin>>tipoDeOferta;
							cout<<"Agora com algumas informacoes extra, diga o numero de pavimentos da sua casa: ";
							cin>>numeroDePavimentos;
							cout<<"Numero de quarto: ";
							cin>>numeroDeQuartos;
							cout<<"Area total do terreno: ";
							cin>>areaDoTerreno;
							cout<<"Area construida: ";
							cin>>areaConstruida;
							cout<<"Obrigado!" << endl;

							imovel = new Casa(numeroDePavimentos, numeroDeQuartos, areaDoTerreno,
											areaConstruida, tipoDeOferta, valor, cidade,
											bairro, logradouro, cep, numero);
							
							imobiliaria.cadastraImovel(imovel);

							break;
						}
						case 2:{
							string posicao;
							int numeroDeQuartos,vagasGaragem,andar;
							double valorCondominio,area;
							cout<<"Indique o endereco do seu imovel, primeiramente a cidade: ";
							cin>>cidade;
							cout<<"Bairro: ";
							cin>>bairro;
							cout<<"Lougradouro: ";
							cin>>logradouro;
							cout<<"CEP: ";
							cin>>cep;
							cout<<"Numero: ";
							cin>>numero;
							cout<<"Valor do imovel: ";
							cin>>valor;
							cout<<"Se o imovel for para vender, digite 1, se for para alugar, digite 2: ";
							cin>>tipoDeOferta;
							cout<<"Agora algumas informacoes extras, indique a posicao do apartamento (norte, sul, leste, oeste): ";
							cin>>posicao;
							cout<<"Numero de quarto: ";
							cin>>numeroDeQuartos;
							cout<<"Area total do terreno: ";
							cin>>area;
							cout<<"Numero de vagas na garagem: ";
							cin>>vagasGaragem;
							cout<<"Qual o andar: ";
							cin>>andar;
							cout<<"Valor do condominio: ";
							cin>>valorCondominio;
							cout<<"Obrigado!" << endl;
							imovel = new Apartamento(posicao, numeroDeQuartos, valorCondominio,
													vagasGaragem, area, andar, tipoDeOferta, 
													valor, cidade, bairro, logradouro,
													cep, numero);
							imobiliaria.cadastraImovel(imovel);
							break;
						}
						case 3:{
							double area;
							cout<<"Indique o endereco do seu imovel, primeiramente a cidade: ";
							cin>>cidade;
							cout<<"Bairro: ";
							cin>>bairro;
							cout<<"Lougradouro: ";
							cin>>logradouro;
							cout<<"CEP: ";
							cin>>cep;
							cout<<"Numero: ";
							cin>>numero;
							cout<<"Valor do imovel: ";
							cin>>valor;
							cout<<"Se o imovel for para vender, digite 1, se for para alugar, digite 2: ";
							cin>>tipoDeOferta;
							cout<<"Area total do terreno: ";
							cin>>area;
							cout<<"Obrigado!" << endl;
							imovel = new Terreno(tipoDeOferta, valor, area,
												cidade, bairro, logradouro, cep, numero);
							imobiliaria.cadastraImovel(imovel);
							break;
						}
						case 4:{
							double areaFlat,valorCondominio;
							char arCondicionado,internet,tvACabo,lavanderia,limpeza,recepcao24;
							cout<<"Indique o endereco do seu imovel, primeiramente a cidade: ";
							cin>>cidade;
							cout<<"Bairro: ";
							cin>>bairro;
							cout<<"Lougradouro: ";
							cin>>logradouro;
							cout<<"CEP: ";
							cin>>cep;
							cout<<"Numero: ";
							cin>>numero;
							cout<<"Valor do imovel: ";
							cin>>valor;
							cout<<"Se o imovel for para vender, digite 1, se for para alugar, digite 2: ";
							cin>>tipoDeOferta;
							cout<<"Area total do terreno: ";
							cin>>areaFlat;
							cout<<"Valor do condominio: ";
							cin>>valorCondominio;
							cout<<"Agora algumas informacoes extras, diga se tem ar condicionado (se sim: s, se nao: n): ";
							cin>>arCondicionado;
							cout<<"Internet?(se sim: s, se nao: n): ";
							cin>>internet;
							cout<<"TV a cabo?(se sim: s, se nao: n): ";
							cin>>tvACabo;
							cout<<"Lavandeiria?(se sim: s, se nao: n): ";
							cin>>lavanderia;
							cout<<"Limpeza?(se sim: s, se nao: n): ";
							cin>>limpeza;
							cout<<"Recepcao 24 horas?(se sim: s, se nao: n): ";
							cin>>recepcao24;
							cout<<"Obrigado!" << endl;
							imovel = new Flat(areaFlat, valorCondominio, arCondicionado, internet, tvACabo,
											lavanderia, limpeza, recepcao24, tipoDeOferta, valor, cidade,
											bairro, logradouro, cep, numero);
							imobiliaria.cadastraImovel(imovel);
							break;
						}
						case 5:{
							string tipo;
							double areaStudio,valorCondominio;
							char arCondicionado,internet,tvACabo,lavanderia,limpeza,recepcao24,piscina,sauna,salaDeGinastica;
							cout<<"Indique o endereco do seu imovel, primeiramente a cidade: ";
							cin>>cidade;
							cout<<"Bairro: ";
							cin>>bairro;
							cout<<"Lougradouro: ";
							cin>>logradouro;
							cout<<"CEP: ";
							cin>>cep;
							cout<<"Numero: ";
							cin>>numero;
							cout<<"Valor do imovel: ";
							cin>>valor;
							cout<<"Se o imovel for para vender, digite 1, se for para alugar, digite 2: ";
							cin>>tipoDeOferta;
							cout<<"Area total do terreno: ";
							cin>>areaStudio;
							cout<<"Valor do condominio: ";
							cin>>valorCondominio;
							cout<<"Agora algumas informacoes extras, diga se tem ar condicionado (se sim: s, se nao: n): ";
							cin>>arCondicionado;
							cout<<"Internet?(se sim: s, se nao: n): ";
							cin>>internet;
							cout<<"TV a cabo?(se sim: s, se nao: n): ";
							cin>>tvACabo;
							cout<<"Lavandeiria?(se sim: s, se nao: n): ";
							cin>>lavanderia;
							cout<<"Limpeza?(se sim: s, se nao: n): ";
							cin>>limpeza;
							cout<<"Recepcao 24 horas?(se sim: s, se nao: n): ";
							cin>>recepcao24;
							cout<<"Piscina?(se sim: s, se nao: n): ";
							cin>>piscina;
							cout<<"Sauna(se sim: s, se nao: n): ";
							cin>>sauna;
							cout<<"Sala de ginastica?(se sim: s, se nao: n): ";
							cin>>salaDeGinastica;
							cout<<"Obrigado!" << endl;
							imovel = new Studio(areaStudio, valorCondominio, arCondicionado, internet, tvACabo,
												lavanderia, limpeza, recepcao24, piscina, sauna, salaDeGinastica, 
												tipoDeOferta, valor, cidade, bairro, logradouro, cep, numero);
							imobiliaria.cadastraImovel(imovel);
							break;
						}
						case 6:{
							break;
						}
						default:{
							opcaoInvalida = 1;
						}
					}

					//Fim do While
					if(opcaoSubItem == 6){
						break;
					} 

				}//Fim while case 1

				break;

			case 2:{//Consulta imoveis disponíveis por tipo
				while(1){
					limpaTela();
					if(opcaoInvalida) cout << "Opcao invalida!" << endl;
					opcaoInvalida = 0;

					interface.ExibeMenuSubItem2();
					cin>>opcaoSubItem;
							
					switch(opcaoSubItem){
						case 1:{//Todos os Imóveis
							limpaTela();
							if(opcaoInvalida) cout << "Opcao invalida!" << endl;
							opcaoInvalida = 0;

							interface.ExibeMenuSubSubItem2();
							cin >> opcaoSubItem;

							switch(opcaoSubItem){
								case 1: { // Casas disponíveis
									while(1){
										limpaTela();
										meusImoveis = imobiliaria.getDescricaoPorTipo(TIPO_CASA);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;						
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}	
								}
								break;

								case 2:{
									while(1){
										limpaTela();
										meusImoveis = imobiliaria.getDescricaoPorTipo(TIPO_APARTAMENTO);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}	
								}
								break;

								case 3:{
									while(1){
										limpaTela();
										meusImoveis = imobiliaria.getDescricaoPorTipo(TIPO_TERRENO);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 4:{
									while(1){
										limpaTela();
										meusImoveis = imobiliaria.getDescricaoPorTipo(TIPO_FLAT);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}	
								break;							

								case 5:{
									while(1){
										limpaTela();
										meusImoveis = imobiliaria.getDescricaoPorTipo(TIPO_STUDIO);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 6:{
									while(1){
										limpaTela();
										meusImoveis = imobiliaria.getDescricao();
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}
									
										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 7:{
								}
								break;

								default:{
									opcaoInvalida = 1;
								}
							}
						}
						break;

						case 2:{//Imoveis disponíveis por cidade
							string cidade;
							limpaTela();
							if(opcaoInvalida) cout << "Opcao invalida!" << endl;
							opcaoInvalida = 0;
							interface.ExibeMenuSubSubItem2();
							cin >> opcaoSubItem;

							switch(opcaoSubItem){
								cout << "Digite a cidade que deseja procurar: ";
								cin >> cidade;

								case 1: {
									cout << "Digite a cidade que deseja procurar: ";
									cin >> cidade; // Casas disponíveis
									while(1){
										meusImoveis = imobiliaria.getDescricaoPorCidade(cidade, TIPO_CASA);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 2:{
									cout << "Digite a cidade que deseja procurar: ";
									cin >> cidade;
									while(1){
										meusImoveis = imobiliaria.getDescricaoPorCidade(cidade, TIPO_APARTAMENTO);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 3:{
									cout << "Digite a cidade que deseja procurar: ";
									cin >> cidade;
									while(1){
														break;			meusImoveis = imobiliaria.getDescricaoPorCidade(cidade, TIPO_TERRENO);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

															break;		cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 4:{
									cout << "Digite a cidade que deseja procurar: ";
									cin >> cidade;
									while(1){
										meusImoveis = imobiliaria.getDescricaoPorCidade(cidade, TIPO_FLAT);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 5:{
									cout << "Digite a cidade que deseja procurar: ";
									cin >> cidade;
									while(1){
										meusImoveis = imobiliaria.getDescricaoPorCidade(cidade, TIPO_STUDIO);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 6:{
									cout << "Digite a cidade que deseja procurar: ";
									cin >> cidade;
									while(1){
										meusImoveis = imobiliaria.getDescricaoPorCidade(cidade, TIPO_TODOSIMOVEIS);
										Imovel *imovel;

										for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
											imovel = *it;
											cout << imovel->getDescricao() << endl;							
										}

										cout << "Digite '0' para sair: ";
										cin >> sair;

										if(!sair) break;
									}
								}
								break;

								case 7:{
									break;
								}
								break;

								default:{
									opcaoInvalida = 1;
								}
							
							}
							break;
						}
						break;

						case 3:{
						break;
						}	
						

						default:{
							opcaoInvalida = 1;
						}
								
					}
				
					break;
				}
			}break;
			case 3:{//Mostrar descrição de todos os imóveis
				while(1){
					limpaTela();
					meusImoveis = imobiliaria.getDescricao();
					Imovel *imovel;

					for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
						imovel = *it;
						cout << imovel->getDescricao() << endl;							
					}

					cout << "Digite '0' para sair: ";
					cin >> sair;

					if(!sair) break;
				}		
			}
			break;
			
			case 4:{//Consultar imoveis disponiveis para venda por bairro
				while(1){
					limpaTela();
					interface.ExibeMenuSubItem6();
					cout << "Digite o bairro que deseja procurar: ";
					cin >> bairro;

					meusImoveis = imobiliaria.getDescricaoPorBairro(bairro, IMOVEL_PARA_VENDER);
					
					Imovel *imovel;

					for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
						imovel = *it;
						cout << imovel->getDescricao() << endl;							
					}

					cout << "Digite '0' para sair: ";
					cin >> sair;

					if(!sair) break;
				}
			}
			break;

			case 5:{//Consultar imoveis disponíveis para alugar por bairro
				while(1){
					limpaTela();
					interface.ExibeMenuSubItem5();
					cout << "Digite o bairro que deseja procurar: ";
					cin >> bairro;

					meusImoveis = imobiliaria.getDescricaoPorBairro(bairro, IMOVEL_PARA_ALUGAR);
					
					Imovel *imovel;

					for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
						imovel = *it;
						cout << imovel->getDescricao() << endl;							
					}
				
					cout << "Digite '0' para sair: ";
					cin >> sair;

					if(!sair) break;
				}
			} 
			break;

			case 6:{//Consultar imoveis disponiveis para venda
				while(1){
					limpaTela();
					interface.ExibeMenuSubItem6();

					meusImoveis = imobiliaria.getDescricaoPorOferta(IMOVEL_PARA_VENDER);
					
					Imovel *imovel;

					for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
						imovel = *it;
						cout << imovel->getDescricao() << endl;							
					}

					cout << "Digite '0' para sair: ";
					cin >> sair;

					if(!sair) break;
				}

			}
			break;

			case 7:{//Consultar imoveis disponiveis para alugar
				while(1){
					limpaTela();
					interface.ExibeMenuSubItem7();

					meusImoveis = imobiliaria.getDescricaoPorOferta(IMOVEL_PARA_ALUGAR);
					
					Imovel *imovel;

					for(list<Imovel*>::iterator  it = meusImoveis.begin(); it!=meusImoveis.end(); ++it){
						imovel = *it;
						cout << imovel->getDescricao() << endl;							
					}

					cout << "Digite '0' para sair: ";
					cin >> sair;

					if(!sair) break;
				}
			}
			break;

			case 8:{
				break;
			}

			default:{
				opcaoInvalida = 1;
				break;
			}

			break;
		}//Switch maior

		if(opcaoItem == 8) break;

	}

	return 0;
}