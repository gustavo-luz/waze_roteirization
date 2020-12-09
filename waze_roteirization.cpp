// ------CÓDIGO PARA CÁLCULO DE ROTA OTIMIZADA DE CAMINHÕES QUE REALIZAM A COLETA SELETIVA ----------------------
// --------12/2020 - PROJETO COMPUTACIONAL - COMPUTAÇÃO PARA ENGENHARIA ------------------------------------
// -----------UNIVERSIDADE DE BRASÍLIA - ENGENHARIA ELÉTRICA --------------------------------------------------
// ---------------- GUSTAVO PESSOA, IVAN CUNHA --------------------------------------------------

// ---------------------------------------------- BIBLIOTECAS ----------------------

#include <iostream>
#include <vector>
// tirar elemento de vetor
#include <algorithm>
#include<bits/stdc++.h>
#include <string>
//converter double/int em string
#include <sstream>
#include <iterator> 
// para a api
#include <windows.h>
#include <shellapi.h>
// para escrever arquivos
#include <fstream>
//para o calculo da distancia entre os pontos
#include <cmath> 
//precisão casas decimais
#include <iomanip>
using namespace std;



// ---------------------------------------------- FUNÇÕES ----------------------



// função de calculo de quantos km tem entre duas latitudes e longitudes
static double haversine(double lat1, double lon1, 
						double lat2, double lon2) 
	{ 
		// distancia entre duas latitudes e longitudes
		double dLat = (lat2 - lat1) * 
					M_PI / 180.0; 
		double dLon = (lon2 - lon1) * 
					M_PI / 180.0; 

		// converter para radianos
		lat1 = (lat1) * M_PI / 180.0; 
		lat2 = (lat2) * M_PI / 180.0; 

		// aplicar fórmula
		double a = pow(sin(dLat / 2), 2) + 
				pow(sin(dLon / 2), 2) * 
				cos(lat1) * cos(lat2); 
		double rad = 6371; 
		double c = 2 * asin(sqrt(a)); 
		return rad * c; 
	}  

// exibir no waze os pontos
void waze(string lat_orig, string long_orig, string lat_dest, string long_dest) {
	string base_waze, final_waze;
	base_waze = "https://www.waze.com/pt-BR/livemap/directions?dir_first=no&navigate=yes&utm_expid=.z332TkT-TdGeMi_l_4XUWA.0&utm_referrer=https%3A%2F%2Fwww.waze.com%2Flivemap%2Fdirections%3Fnavigate%3Dyes%26latlng%3D40.758895%252C-73.985131%26zoom%3D17&to=ll.";
	final_waze = base_waze + lat_dest + "%2C" + long_dest + "&from=ll." + lat_orig + "%2C" + long_orig;
	ShellExecuteA(NULL, "open", final_waze.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

// imprimir um vetor int
void imprimevetor(std::vector<int> const &input )
{
	
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
cout << "  " << endl;
}

int main()

{
	
// ---------------------------------------------- INICIALIZAÇÃO DAS VARIÁVEIS ----------------------
//variavel de seleção do menu
int selection;
//pontos a serem inseridos
int p;
int size;
//Vetor distancias
vector< vector<double> > distancias;
//Indice minimo
int min, v_min, v_atual, elem;
// Vetor Trajeto
std::vector<int> trajeto;
//Vetor posicao
std::vector<int> posicao;
// vetor pontos
std::vector<int> pontos;
std::vector<int> pontosstrings;
//para conversao, outras variaveis
int i,j,k,pos,poss,rota;
// vetor latitudes
std::vector<double> latitudes;
// vetor longitudes
std::vector<double> longitudes;
vector<double>::iterator it;

//variaveis de latitude e longitude - correspondem aos pontos reais
double lat1= -15.770963,long1= -47.888502,lat2= -15.720775,long2= -47.883350,lat3= -15.744001,long3= -47.850570,lat4= -15.733281,long4= -47.864906,lat5= -15.716918,long5= -47.880843;
double lat6= -15.752528,long6= -47.928705,lat7= -15.755850,long7= -47.884122,lat8= -15.741696,long8= -47.892770,lat9= -15.716746,long9= -47.883326,lat10= -15.759711,long10= -47.880712;
// coloca latitudes e longitudes em vetores lats e longs
double arraylatitudes[] = {lat1, lat2, lat3, lat4, lat5, lat6, lat7, lat8, lat9, lat10};
std::vector<double> lats(arraylatitudes, arraylatitudes+10);
double arraylongitudes[] = {long1, long2, long3, long4, long5, long6, long7, long8, long9, long10};
std::vector<double> longs(arraylongitudes, arraylongitudes+10);

// ---------------------------------------------- CÁLCULO DO TRAJETO ----------------------
  do{
cout<<"\n Menu";

cout<<"\n========";

cout<<"\n 1 - Adicionar Pontos e Calcular Trajeto";

cout<<"\n 2 - Exibir Trajeto";

cout<<"\n 3 - Sair";

cout<<"\n Escolha a opcao: ";

// le a seleção
cin>>selection;


if (selection == 1)
{

// lê pontos e escreve arquivo txt
cout<<"\n Adicionar Pontos\n";
//limpa os dados da tela
system("cls");
cout<<"\n Lista de pontos ";
cout<<"\n========";
cout<<"\n 1 - Dona de Casa, Via W Tres Norte - Asa Norte, Brasilia - DF, 70297-400 ";
cout<<"\n 2 - BIG BOX - St. de Habitações Individuais Norte CA 1 bloco B loja 82 - Lago Norte, Brasilia - DF, 71503-501  ";
cout<<"\n 3 - Big Box Estrada Parque Peninsula Norte lt 90 sl /N, Brasilia, DF, 71503-507";
cout<<"\n 4 - BIG BOX - St. SHIN EPPN Canteiro Central lote 06 loja 18 - Lago Norte, Brasilia - DF, 71505-70";
cout<<"\n 5 - Comercial Reis de Alimentos - St. de Habitacoes Individuais Norte CA 2 Bloco F Lt F, Loja 2 - Lago Norte, Brasilia - DF, 70634-400";
cout<<"\n 6 - Leroy Merlin Brasilia Norte, SOFN - Area Especial, Brasilia - DF, 70634-120";
cout<<"\n 7 - Superquadra Norte 210 - Asa Norte, Brasilia - DF, 70862-000";
cout<<"\n 8 - Superquadra Norte 115 - Asa Norte, Brasilia - DF, 70297-400";
cout<<"\n 9 - Administracao Regional de Lago Norte - St. de Habitações Individuais Norte CA 5 - Lago Norte, Brasilia - DF, 71503-507";
cout<<"\n 10 - Evolua Mercado Sustentavel - SHCN CLN 409 - Asa Norte, Brasilia - DF, 70297-400";

cout<<"\n========";

cout<<"\n Selecione os pontos que deseja roteirizar (Para parar digite 0): " << endl;
cout << "Obs: O primeiro ponto selecionado sera a saida e a chegada" << endl;

//coloca os pontos lidos em um vetor pontos
  do {
    std::cin >> p;
    pontos.push_back (p);
  } while (p);
  

//tira o 0 do vetor - ultimo elemento inserido
pontos.pop_back();


// fala quantos pontos foram colocados
  std::cout << "Foram inseridos " << int(pontos.size()) << " pontos:\n";

// imprime vetor pontos
imprimevetor(pontos);

// duplica o vetor criando um vetor de latitudes e outro de longitudes
   for ( i=0; i<pontos.size(); i++) 
        latitudes.push_back(pontos[i]); 

  for ( i=0; i<pontos.size(); i++) 
      longitudes.push_back(pontos[i]); 


//latitudes
// encontra valores e substitui
	for (j=0; j<=10 ; j++){

	it=find(latitudes.begin(),latitudes.end(),j);
	if(it != latitudes.end())
	{
	pos = it- latitudes.begin();
	latitudes[pos]=lats[j-1];
}
	}
	
//longitudes
	for (k=0; k<=10 ; k++){

	it=find(longitudes.begin(),longitudes.end(),k);
	if(it != longitudes.end())
	{
	poss = it- longitudes.begin();
	longitudes[poss]=longs[k-1];
}
	}
	
// cria matriz de distâncias entre os pontos selecionados
size = latitudes.size();
double dist[size][size];

// aplica a função haversine pra chegar de latitudes e longitudes em Km
for(i = 0; i < size; i++){
	for(k = 0; k < size; k++){
		dist[i][k] = haversine(latitudes[i],longitudes[i],latitudes[k],longitudes[k]);
	}
}

for ( i=0; i<=10; i++) posicao.push_back(i);

posicao.resize(size);

trajeto.push_back(0); // Primeiro ponto é sempre o da posição 0.

cout << endl;
cout << "Melhor Trajeto:" << endl;

//calcula menor distância entre cada um dos pontos a partir do ponto de início indicado
for( i = 0; i < size; i++){
	elem = trajeto.back();
	posicao.erase(std::remove(posicao.begin(), posicao.end(), elem), posicao.end());
	for(k = 0;  k < posicao.size(); k++){
		if(k == 0){
			v_min = dist[elem][posicao[k]];
			min = posicao[k];
		}
		else{
			v_atual = dist[elem][posicao[k]];
			if(v_atual < v_min){
				v_min = v_atual;
				min = posicao[k];
			}
		}
	}
	trajeto.push_back(min);
}
trajeto.pop_back();
trajeto.push_back(0);

//exibe os pontos 1 a 1 até o tamanho do vetor trajeto
for(i = 0; i < trajeto.size(); i++){
	cout <<"Ponto " << i << ": " <<pontos[trajeto[i]] << endl;
}
}

else if (selection == 2)
{
// ---------------------------------------------- EXIBIÇÃO ----------------------

system("cls");
cout<<"\n Exibir Trajeto" << endl;

for(i = 0; i < trajeto.size() - 1; i++){
	// cria as strings das latitudes e longitudes
	ostringstream lat1s,long1s,lat2s,long2s;
	lat1s << latitudes[trajeto[i]];
	long1s << longitudes[trajeto[i]];
	lat2s << latitudes[trajeto[i+1]];
	long2s << longitudes[trajeto[i+1]];
	
	//termina a conversão
	string s_lat1 = lat1s.str();
	string s_long1 = long1s.str();
	string s_lat2 = lat2s.str();
	string s_long2 = long2s.str();
	waze(s_lat1, s_long1 , s_lat2, s_long2);
	rota = 0;
	while(rota != 1){
		cout << "Pressione 1 para ver a proxima rota: " <<  endl;
		cin >> rota;
	}
}

}
else if (selection == 3)
{
// ---------------------------------------------- SAIR ----------------------

system("cls");
cout<<"\n Sair";
break;
}
else
{
	 cout<<"\n Selecao invalida";
}

}

while(selection != '3');
cout<<"\n";

return 0;

}
