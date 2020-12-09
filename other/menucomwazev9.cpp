// ------C�DIGO PARA C�LCULO DE ROTA OTIMIZADA DE CAMINH�ES QUE REALIZAM A COLETA SELETIVA ----------------------
// --------12/2020 - PROJETO COMPUTACIONAL - COMPUTA��O PARA ENGENHARIA ------------------------------------
// -----------UNIVERSIDADE DE BRAS�LIA - ENGENHARIA EL�TRICA --------------------------------------------------
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
//precis�o casas decimais
#include <iomanip>
using namespace std;



// ---------------------------------------------- FUN��ES ----------------------



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
	
// ---------------------------------------------- INICIALIZA��O DAS VARI�VEIS ----------------------
//variavel de sele��o do menu
int selection;
//pontos a serem inseridos
int p;
//Vetor distancias
vector< vector<float> > distancias;
//Indice minimo
int min, v_min, v_atual, elem;
// Vetor Trajeto
std::vector<int> trajeto;
//Vetor posicao
std::vector<int> posicao;
// vetor pontos
std::vector<int> pontos;
std::vector<int> pontosstrings;
//para conversao
int i;
// vetor latitudes
std::vector<double> latitudes;
// vetor longitudes
std::vector<double> longitudes;
vector<double>::iterator it;
vector<int>::iterator its;

//for de manipula��o dos vetores
int j;
int k;
int pos;
int poss;
int rota;
// se precisar de outras, descomentar
//int l;
//int m;
//int o;

//variaveis de latitude e longitude - tempor�rio mas correspondem aos pontos reais
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
// convertidas pra string PODE TIRAR ISSO TUDO TALVEZ - ANALISAR
ostringstream lat1s,long1s,lat2s,long2s,lat3s,long3s,lat4s,long4s,lat5s,long5s,lat6s,long6s,lat7s,long7s,lat8s,long8s,lat9s,long9s,lat10s,long10s;
lat1s << lat1;
long1s << long1;
lat2s << lat2;
long2s << long2;
lat3s << lat3;
long3s << long3;
lat3s << lat4;
long3s << long4;
lat3s << lat5;
long3s << long5;
lat3s << lat6;
long3s << long6;
lat3s << lat7;
long3s << long7;
lat3s << lat8;
long3s << long8;
lat3s << lat9;
long3s << long9;
lat3s << lat10;
long3s << long10;
//termina a convers�o
string s_lat1 = lat1s.str();
string s_long1 = long1s.str();
string s_lat2 = lat2s.str();
string s_long2 = long2s.str();
string s_lat3 = lat3s.str();
string s_long3 = long3s.str();
string s_lat4 = lat4s.str();
string s_long4 = long4s.str();
string s_lat5 = lat5s.str();
string s_long5 = long5s.str();
string s_lat6 = lat6s.str();
string s_long6 = long6s.str();
string s_lat7 = lat7s.str();
string s_long7 = long7s.str();
string s_lat8 = lat8s.str();
string s_long8 = long8s.str();
string s_lat9 = lat9s.str();
string s_long9 = long9s.str();
string s_lat10 = lat10s.str();
string s_long10 = long10s.str();
// armazena em vetor
//std::vector<string> numerostring{ '1', "2", "3","4","5","6","7","8","9","10" };
//cria o array e dps armazena em vetor numerostring
std::string arraystrings[] = {"1", "2", "3","4","5","6","7","8","9","10"};
std::vector<string> numerostring(arraystrings, arraystrings+10);
std::ostringstream vts;	
// ---------------------------------------------- C�LCULO DO TRAJETO ----------------------
  do{
cout<<"\n Menu";

cout<<"\n========";

cout<<"\n 1 - Adicionar Pontos";

cout<<"\n 2 - Calcular Trajeto";

cout<<"\n 3 - Exibir Trajeto";

cout<<"\n 4 - Sair";

cout<<"\n Escolha a opcao: ";

// le a sele��o
cin>>selection;


if (selection == 1)
{

// l� pontos e escreve arquivo txt
cout<<"\n Adicionar Pontos\n";
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
cout << "vetor pontos em int: " << endl;
imprimevetor(pontos);

//duplicapontos em pontostrings
   for ( i=0; i<pontos.size(); i++) 
        pontosstrings.push_back(pontos[i]); 


if (!pontosstrings.empty()) 
  { 
    // Convert all but the last element to avoid a trailing "," 
    std::copy(pontosstrings.begin(), pontosstrings.end()-1, 
        std::ostream_iterator<int>(vts, ", ")); 
  
    // Now add the last element with no delimiter 
    vts << pontosstrings.back(); 
  } 
// imprime vetor vts no formato string
cout << "vetor pontos em string: " << endl;
  std::cout << vts.str() << std::endl; 


/*
std::ofstream output_file("./example.txt");
 std::ostream_iterator<std::string> output_iterator(output_file, "\n");
 //erro da aqui
std::copy(pontos.begin(), pontos.end(), output_iterator);
*/

//std::stringstream result;
//std::copy(pontosstrings.begin(), pontosstrings.end(), std::ostream_iterator<int>(result, " "));


// TODO converter vetor de pontos em vetor de latitudes e longitudes
// duplica o vetor criando um vetor de latitudes e outro de longitudes
   for ( i=0; i<pontos.size(); i++) 
        latitudes.push_back(pontos[i]); 

  for ( i=0; i<pontos.size(); i++) 
      longitudes.push_back(pontos[i]); 

// imprime para mostrar que os dois s�o iguais       
//imprimevetordouble(latitudes);

//imprimevetordouble(longitudes);

//TODO encontrar o onde tem os valores 1,2,3... e substitituir o valor em lat1,lat2 ou long1,long2

//latitudes
//TODO COLOCAR NAS POSI��ES CERTAS

// encontra valores e substitui
	for (j=0; j<=10 ; j++){

	it=find(latitudes.begin(),latitudes.end(),j);
	if(it != latitudes.end())
	{
	cout<<*it<<" esta na posicao "<<(it- latitudes.begin()) << endl;
	pos = it- latitudes.begin();
	latitudes[pos]=lats[j-1];
	imprimevetordouble(latitudes);
}
	}
	
//
cout << "come�ando longitudes" << endl;
//longitudes
	for (k=0; k<=10 ; k++){

	it=find(longitudes.begin(),longitudes.end(),k);
	if(it != longitudes.end())
	{
	cout<<*it<<" esta na posicao "<<(it- longitudes.begin()) << endl;
	poss = it- longitudes.begin();
	longitudes[poss]=longs[k-1];
	imprimevetordouble(longitudes);
}
	}
cout << latitudes.size() << endl;
cout << longitudes.size() << endl;


cout << "tentando parte do ivan" << endl;
// ver https://learntechway.com/find-in-c-find-an-element-in-a-vector/
// e https://stackoverflow.com/questions/9904976/how-to-replace-specific-values-in-a-vector-in-c


vector< vector<double> > res;
res.push_back(latitudes);
res.push_back(longitudes);
for( i = 0; i < res.size(); i++)
    {

        for( j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << ",";
        }

        cout << endl;
    }

cout << "tentando parte do ivan" << endl;

cout << haversine(latitudes[1],longitudes[1],latitudes[2],longitudes[2]) << endl;
cout << "tentando parte do ivan" << endl;

for(i = 0; i < latitudes.size(); i++){
	for(k = 0; k < latitudes.size(); k++){
		distancias[i][k] = double(haversine(latitudes[i],longitudes[i],latitudes[k],longitudes[k]));
	}
}



cout << "tentando parte do ivan" << endl;

for(i = 0; i < latitudes.size(); i++){
	for(k = 0; k < latitudes.size(); k++){
		distancias[i][k] = float(haversine(latitudes[i],longitudes[i],latitudes[k],longitudes[k]));
	}
}


cout << "tentando parte do ivan" << endl;
for ( i=0; i<=10; i++) posicao.push_back(i);
posicao.resize(latitudes.size());
cout << "tentando parte do ivan" << endl;
trajeto.push_back(0); // Primeiro ponto � sempre o da posi��o 0.
imprimevetor(trajeto);
cout << "chegou aqui" << endl;
for( i = 0; i < latitudes.size(); i++){
	elem = trajeto.back();
	posicao.erase(std::remove(posicao.begin(), posicao.end(), elem), posicao.end());
	for( k = 0;  k < posicao.size(); k++){
		if(k == 0){
			v_min = distancias[elem][posicao[k]];
			min = posicao[k];
		}
		else{
			v_atual = distancias[elem][posicao[k]];
			if(v_atual < v_min){
				v_min = v_atual;
				min = posicao[k];
			}
		}
	}
	trajeto.push_back(min);
}
trajeto.push_back(0);
cout << "chegou aqui 2" << endl;
cout << trajeto[1] << endl;
cout << "chegou aqui 3" << endl;
imprimevetor(trajeto);
cout << "chegou aqui 4" << endl;



//colocar o primeiro e o ultimo ponto sendo da origem

}

else if (selection == 2)
{

// ---------------------------------------------- C�LCULO DO TRAJETO ----------------------

//system("cls");
cout<< "Calcular Trajeto" <<endl;
// TODO abrir arquivo com vetor latitudes e longitudes e calcular o trajeto ideal ex: 1-2-5-7
for(i = 0; i < latitudes.size(); i++){
	for(k = 0; k < latitudes.size(); k++){
		distancias[i][k] = float(haversine(latitudes[i],longitudes[i],latitudes[k],longitudes[k]));
	}
}


for ( i=0; i<=10; i++) posicao.push_back(i);
posicao.resize(latitudes.size());
trajeto.push_back(0); // Primeiro ponto � sempre o da posi��o 0.
imprimevetor(trajeto);
cout << "chegou aqui" << endl;
for( i = 0; i < latitudes.size(); i++){
	elem = trajeto.back();
	posicao.erase(std::remove(posicao.begin(), posicao.end(), elem), posicao.end());
	for( k = 0;  k < posicao.size(); k++){
		if(k == 0){
			v_min = distancias[elem][posicao[k]];
			min = posicao[k];
		}
		else{
			v_atual = distancias[elem][posicao[k]];
			if(v_atual < v_min){
				v_min = v_atual;
				min = posicao[k];
			}
		}
	}
	trajeto.push_back(min);
}
trajeto.push_back(0);
cout << "chegou aqui 2" << endl;
cout << trajeto[1] << endl;
cout << "chegou aqui 3" << endl;
imprimevetor(trajeto);
cout << "chegou aqui 4" << endl;

}
else if (selection == 3)
{
// ---------------------------------------------- EXIBI��O ----------------------

system("cls");
cout<<"\n Exibir Trajeto" << endl;

// le arquivo txt e exibe trajeto de acordo com os pontos mais pr�ximos

// usa a fun��o waze com as latitudes e longitudes convertidas de int pra string
waze(s_lat1,s_long1,s_lat2,s_long2);
cout << endl;
cout << "Pressione 1 para ver proxima rota: " << endl;
cin >> rota;
if (rota == 1);
//Sleep(30);
waze(s_lat2,s_long2,s_lat3,s_long3);


}
else if (selection == 4)
{
// ---------------------------------------------- SAIR ----------------------

system("cls");
cout<<"\n Sair";
}
else
{
	 cout<<"\n Selecao invalida";
}



}

while(selection != '4');
cout<<"\n";

return 0;

}
