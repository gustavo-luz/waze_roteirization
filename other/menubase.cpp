#include <iostream>

using namespace std;

 

int main(void)

{

char selection;

 

cout<<"\n Menu";

cout<<"\n========";

cout<<"\n a - Adicionar Ponto";

cout<<"\n b - Calcular Trajeto";

cout<<"\n c - Exibir Trajeto";

cout<<"\n x - Sair";

cout<<"\n Escolha a opcao: ";

// read the input

cin>>selection;

 

switch(selection)

{

case 'A' :

case 'a' :{cout<<"\n Adicionar Ponto\n";}

break;

case 'B' :

case 'b' :{cout<<"\n Calcular Trajeto";}


break;

case 'C' :

case 'c' :{cout<<"\n Calcular Trajeto";}


break;

case 'X' :

case 'x' :{cout<<"\n Sair";}

break;


default : cout<<"\n Selecao invalida";



}

cout<<"\n";

 

return 0;

}
