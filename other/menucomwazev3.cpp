#include <iostream>
#include <vector>
#include <string>
// para a api
#include <windows.h>
#include <shellapi.h>
// para escrever arquivos
#include <fstream>
//para o calculo da distancia entre os pontos
#include <cmath> 
using namespace std;

// fun��o de calculo de quantos km tem entre duas latitudes e longitudes
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

		// aplicar f�rmula
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

// imprimir um vetor
void imprimevetor(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main()

{
//variavel de sele��o do menu
char selection;
//pontos a serem inseridos
int p;
// vetor pontos
std::vector<int> pontos;

//variaveis de latitude e longitude - tempor�rio mas correspondem aos pontos reais
double lat1= -15.770963,long1= -47.888502,lat2= -15.720775,long2= -47.883350,lat3= -15.744001,long3= -47.850570,lat4= -15.733281,long4= -47.864906,lat5= -15.716918,long5= -47.880843;
double lat6= -15.752528,long6= -47.928705,lat7= -15.755850,long7= -47.884122,lat8= -15.741696,long8= -47.892770,lat9= -15.716746,long9= -47.883326,lat10= -15.759711,long10= -47.880712;
 

cout<<"\n Menu";

cout<<"\n========";

cout<<"\n a - Adicionar Pontos";

cout<<"\n b - Calcular Trajeto";

cout<<"\n c - Exibir Trajeto";

cout<<"\n x - Sair";

cout<<"\n Escolha a opcao: ";

// le a sele��o
cin>>selection;


switch(selection)

{

case 'A' :
// l� pontos e escreve arquivo txt
case 'a' :{cout<<"\n Adicionar Pontos\n";}
//limpa os dados da tela
system("cls");
cout<<"\n Lista de pontos ";
cout<<"\n========";
cout<<"\n 1 - Dona de Casa, Via W Tr�s Norte - Asa Norte, Bras�lia - DF, 70297-400 ";
cout<<"\n 2 - BIG BOX - St. de Habita��es Individuais Norte CA 1 bloco B loja 82 - Lago Norte, Bras�lia - DF, 71503-501  ";
cout<<"\n 3 - Big Box Estrada Parque Pen�nsula Norte lt 90 sl /N, Bras�lia, DF, 71503-507";
cout<<"\n 4 - BIG BOX - St. SHIN EPPN Canteiro Central lote 06 loja 18 - Lago Norte, Bras�lia - DF, 71505-70";
cout<<"\n 5 - Comercial Reis de Alimentos - St. de Habita��es Individuais Norte CA 2 Bloco F Lt F, Loja 2 - Lago Norte, Bras�lia - DF, 70634-400";
cout<<"\n 6 - Leroy Merlin Bras�lia Norte, SOFN - �rea Especial, Bras�lia - DF, 70634-120";
cout<<"\n 7 - Superquadra Norte 210 - Asa Norte, Bras�lia - DF, 70862-000";
cout<<"\n 8 - Superquadra Norte 115 - Asa Norte, Bras�lia - DF, 70297-400";
cout<<"\n 9 - Administra��o Regional de Lago Norte - St. de Habita��es Individuais Norte CA 5 - Lago Norte, Bras�lia - DF, 71503-507";
cout<<"\n 10 - Evolua Mercado Sustent�vel - SHCN CLN 409 - Asa Norte, Bras�lia - DF, 70297-400";

cout<<"\n========";

cout<<"\n Selecione os pontos que deseja roteirizar (Para parar digite 0): ";

  do {
    std::cin >> p;
    pontos.push_back (p);
  } while (p);
  
system("cls");
// fala quantos pontos foram colocados
  std::cout << "foram inseridos " << int(pontos.size()-1) << " pontos.\n";
// imprime vetor pontos
imprimevetor(pontos);
//TODO lidar com esse 0 no final do vetor
// TODO converter vetor de pontos em vetor de latitudes e longitudes


//cria um arquivo txt e coloca nele o vetor latitudes e longitudes
//ofstream myfile;
 // myfile.open("pontos.txt");
 // if (myfile.is_open()){
  //  myfile << "Isto e uma linha de texto.\n";
   // myfile << pontos;

 //   myfile.close();
 // }
  //else
  //  cout << "Nao foi possivel abrir o arquivo";


break;

case 'B' :
system("cls");
case 'b' :{cout<<"Calcular Trajeto";}
// TODO abrir arquivo com vetor latitudes e longitudes e calcular o trajeto ideal

//aplicar a fun��o haversine
cout << "\n" << haversine(lat1,long1,lat2,long2) << "km";

break;

case 'C' :
system("cls");
case 'c' :{cout<<"\n Exibir Trajeto";}

// le arquivo txt e exibe trajeto de acordo com os pontos mais pr�ximos
waze("-15.80893626", "-48.01985621", "-15.810104", "-48.016411");


break;

case 'X' :
system("cls");
case 'x' :{cout<<"\n Sair";}

break;
default : cout<<"\n Selecao invalida";

}

cout<<"\n";

return 0;

}
