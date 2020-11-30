#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <shellapi.h>
using namespace std;

 

// exibir no waze os pontos
void waze(string lat_orig, string long_orig, string lat_dest, string long_dest) {
	string base_waze;
	base_waze = "https://www.waze.com/pt-BR/livemap/directions?dir_first=no&navigate=yes&utm_expid=.z332TkT-TdGeMi_l_4XUWA.0&utm_referrer=https%3A%2F%2Fwww.waze.com%2Flivemap%2Fdirections%3Fnavigate%3Dyes%26latlng%3D40.758895%252C-73.985131%26zoom%3D17&to=ll.";
	base_waze = base_waze + lat_dest + "%2C" + long_dest + "&from=ll." + lat_orig + "%2C" + long_orig;
	ShellExecuteA(NULL, "open", base_waze.c_str(), NULL, NULL, SW_SHOWNORMAL);
	cout << base_waze;
}


int main()

{
//variavel de seleção do menu
char selection;
//pontos a serem inseridos
int pontos;
int i;
// vetor pontos
std::vector<int> p;
 

cout<<"\n Menu";

cout<<"\n========";

cout<<"\n a - Adicionar Pontos";

cout<<"\n b - Calcular Trajeto";

cout<<"\n c - Exibir Trajeto";

cout<<"\n x - Sair";

cout<<"\n Escolha a opcao: ";

// read the input

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

cout<<"\n Selecione os pontos que deseja roteirizar (Para parar digite qualquer letra ou insira 10 pontos): ";


while ((cin >> pontos) && pontos <=10)
{
	p.push_back(pontos);
}

//cout << "\n Numero de pontos a roteirizar: " << pontos <<endl;
//imprime vetor
for (i : p){
	cout << i << " ";
}



break;

case 'B' :
system("cls");
case 'b' :{cout<<"\n Calcular Trajeto";}


break;

case 'C' :
system("cls");
case 'c' :{cout<<"\n Exibir Trajeto";}
// le arquivo txt e exibe trajeto de acordo com os pontos mais próximos
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
