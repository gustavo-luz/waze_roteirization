// ------CÓDIGO PARA CÁLCULO DE ROTA OTIMIZADA DE CAMINHÕES QUE REALIZAM A COLETA SELETIVA ----------------------
// --------12/2020 - PROJETO COMPUTACIONAL - COMPUTAÇÃO PARA ENGENHARIA ------------------------------------
// -----------UNIVERSIDADE DE BRASÍLIA - ENGENHARIA ELÉTRICA --------------------------------------------------
// ---------------- GUSTAVO PESSOA, IVAN XXX --------------------------------------------------

// ---------------------------------------------- BIBLIOTECAS ----------------------

#include <iostream>
#include <vector>
// tirar elemento de vetor
#include<bits/stdc++.h>
#include <string>
//converter double em string
#include <sstream>
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
	string base_waze;
	base_waze = "https://www.waze.com/pt-BR/livemap/directions?dir_first=no&navigate=yes&utm_expid=.z332TkT-TdGeMi_l_4XUWA.0&utm_referrer=https%3A%2F%2Fwww.waze.com%2Flivemap%2Fdirections%3Fnavigate%3Dyes%26latlng%3D40.758895%252C-73.985131%26zoom%3D17&to=ll.";
	base_waze = base_waze + lat_dest + "%2C" + long_dest + "&from=ll." + lat_orig + "%2C" + long_orig;
	ShellExecuteA(NULL, "open", base_waze.c_str(), NULL, NULL, SW_SHOWNORMAL);
	cout << base_waze;
}

// imprimir um vetor int
void imprimevetor(std::vector<int> const &input )
{
	
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
cout << "  " << endl;
}

// imprimir um vetor double
void imprimevetordouble(std::vector<double> const &input)
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
char selection;
//pontos a serem inseridos
int p;
// vetor pontos
std::vector<int> pontos;
//para conversao
int i;
// vetor latitudes
std::vector<double> latitudes;
// vetor longitudes
std::vector<double> longitudes;
vector<double>::iterator it;
vector<double>::iterator its;
//for de manipulação dos vetores
int j;
int k;
int pos;
int poss;
int rota;
//variaveis de latitude e longitude - temporário mas correspondem aos pontos reais
double lat1= -15.770963,long1= -47.888502,lat2= -15.720775,long2= -47.883350,lat3= -15.744001,long3= -47.850570,lat4= -15.733281,long4= -47.864906,lat5= -15.716918,long5= -47.880843;
double lat6= -15.752528,long6= -47.928705,lat7= -15.755850,long7= -47.884122,lat8= -15.741696,long8= -47.892770,lat9= -15.716746,long9= -47.883326,lat10= -15.759711,long10= -47.880712;
// coloca latitudes e longitudes em vetores lats e longs
double arraylatitudes[] = {lat1, lat2, lat3, lat4, lat5, lat6, lat7, lat8, lat9, lat10};
std::vector<double> lats(arraylatitudes, arraylatitudes+10);
double arraylongitudes[] = {long1, long2, long3, long4, long5, long6, long7, long8, long9, long10};
std::vector<double> longs(arraylongitudes, arraylongitudes+10);
// RETIRAR imprime pra testar
//imprimevetordouble(lats);
//imprimevetordouble(longs);
// convertidas pra string
// TODO TERMINAR PARA AS 10 LATITUDES E LONGITUDES
ostringstream lat1s,long1s,lat2s,long2s,lat3s,long3s;
lat1s << lat1;
long1s << long1;
lat2s << lat2;
long2s << long2;
lat3s << lat3;
long3s << long3;
//talvez usar um for ou entao uma função
string s_lat1 = lat1s.str();
string s_long1 = long1s.str();
string s_lat2 = lat2s.str();
string s_long2 = long2s.str();
string s_lat3 = lat3s.str();
string s_long3 = long3s.str();
// TODO COLOCAR OUTRO PONTOS

// ---------------------------------------------- CÁLCULO DO TRAJETO ----------------------
  do{
cout<<"\n Menu";

cout<<"\n========";

cout<<"\n a - Adicionar Pontos";

cout<<"\n b - Calcular Trajeto";

cout<<"\n c - Exibir Trajeto";

cout<<"\n x - Sair";

cout<<"\n Escolha a opcao: ";

// le a seleção
cin>>selection;


switch(selection)

{

case 'A' :
// lê pontos e escreve arquivo txt
case 'a' :{cout<<"\n Adicionar Pontos\n";}
//limpa os dados da tela
system("cls");
cout<<"\n Lista de pontos ";
cout<<"\n========";
cout<<"\n 1 - Dona de Casa, Via W Três Norte - Asa Norte, Brasília - DF, 70297-400 ";
cout<<"\n 2 - BIG BOX - St. de Habitações Individuais Norte CA 1 bloco B loja 82 - Lago Norte, Brasília - DF, 71503-501  ";
cout<<"\n 3 - Big Box Estrada Parque Península Norte lt 90 sl /N, Brasília, DF, 71503-507";
cout<<"\n 4 - BIG BOX - St. SHIN EPPN Canteiro Central lote 06 loja 18 - Lago Norte, Brasília - DF, 71505-70";
cout<<"\n 5 - Comercial Reis de Alimentos - St. de Habitações Individuais Norte CA 2 Bloco F Lt F, Loja 2 - Lago Norte, Brasília - DF, 70634-400";
cout<<"\n 6 - Leroy Merlin Brasília Norte, SOFN - Área Especial, Brasília - DF, 70634-120";
cout<<"\n 7 - Superquadra Norte 210 - Asa Norte, Brasília - DF, 70862-000";
cout<<"\n 8 - Superquadra Norte 115 - Asa Norte, Brasília - DF, 70297-400";
cout<<"\n 9 - Administração Regional de Lago Norte - St. de Habitações Individuais Norte CA 5 - Lago Norte, Brasília - DF, 71503-507";
cout<<"\n 10 - Evolua Mercado Sustentável - SHCN CLN 409 - Asa Norte, Brasília - DF, 70297-400";

cout<<"\n========";

cout<<"\n Selecione os pontos que deseja roteirizar (Para parar digite 0): ";

//coloca os pontos lidos em um vetor pontos
  do {
    std::cin >> p;
    pontos.push_back (p);
  } while (p);
  
system("cls");

//tira o 0 do vetor - ultimo elemento inserido
pontos.pop_back();

// fala quantos pontos foram colocados
  std::cout << "foram inseridos " << int(pontos.size()) << " pontos.\n";

// imprime vetor pontos
imprimevetor(pontos);

// TODO converter vetor de pontos em vetor de latitudes e longitudes
// duplica o vetor criando um vetor de latitudes e outro de longitudes
   for ( i=0; i<pontos.size(); i++) 
        latitudes.push_back(pontos[i]); 

  for ( i=0; i<pontos.size(); i++) 
      longitudes.push_back(pontos[i]); 

// imprime para mostrar que os dois são iguais       
//imprimevetordouble(latitudes);

//imprimevetordouble(longitudes);

//TODO encontrar o onde tem os valores 1,2,3... e substitituir o valor em lat1,lat2 ou long1,long2

//latitudes
//TODO COLOCAR NAS POSIÇÕES CERTAS

// encontra valores 
	for (j=0; j<10 ; j++){

	it=find(latitudes.begin(),latitudes.end(),j);
	if(it != latitudes.end())
	{
	cout<<*it<<" esta na posicao "<<(it- latitudes.begin()) << endl;
	pos = it- latitudes.begin();
	latitudes[pos]=lats[j];
	imprimevetordouble(latitudes);
}
	}
	
//
cout << "começando longitudes" << endl;
//longitudes
	for (k=0; k<10 ; k++){

	its=find(longitudes.begin(),longitudes.end(),k);
	if(its != longitudes.end())
	{
	cout<<*its<<" esta na posicao "<<(its- longitudes.begin()) << endl;
	poss = its- longitudes.begin();
	longitudes[poss]=longs[k];
	imprimevetordouble(longitudes);
}
	}
cout << latitudes.size() << endl;
cout << longitudes.size() << endl;
// ver https://learntechway.com/find-in-c-find-an-element-in-a-vector/
// e https://stackoverflow.com/questions/9904976/how-to-replace-specific-values-in-a-vector-in-c


//colocar o primeiro e o ultimo ponto sendo da origem



break;
// ---------------------------------------------- CÁLCULO DO TRAJETO ----------------------
case 'B' :
system("cls");
case 'b' :{cout<<"Calcular Trajeto";}
// TODO abrir arquivo com vetor latitudes e longitudes e calcular o trajeto ideal ex: 1-2-5-7

//aplicar a função haversine pra cada dupla
cout << "\n" << haversine(lat1,long1,lat2,long2) << " km";

break;

// ---------------------------------------------- EXIBIÇÃO ----------------------
case 'C' :
system("cls");
case 'c' :{cout<<"\n Exibir Trajeto" << endl;}

// le arquivo txt e exibe trajeto de acordo com os pontos mais próximos

// usa a função waze com as latitudes e longitudes convertidas de int pra string
waze(s_lat1,s_long1,s_lat2,s_long2);
cout << endl;
cout << "Pressione 1 para ver proxima rota: " << endl;
cin >> rota;
if (rota == 1);
//Sleep(30);
waze(s_lat2,s_long2,s_lat3,s_long3);
break;


// ---------------------------------------------- SAIR ----------------------
case 'X' :
system("cls");
case 'x' :{cout<<"\n Sair";}

break;
default : cout<<"\n Selecao invalida";

}
}
while(selection != 'x');
cout<<"\n";
system("pause");
return 0;

}
