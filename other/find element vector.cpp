#include<iostream>

#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()

{

vector<int> findelement;

vector<int>::iterator it;

int element;

findelement.push_back(1);

findelement.push_back(2);

findelement.push_back(3);

findelement.push_back(4);

cout<<"\n Enter the element to search";

cin>>element;

it=find(findelement.begin(),findelement.end(),element);

if(it != findelement.end())

{

cout<<*it<<"is found at position"<<(it- findelement.begin()+1);

}

else



cout<<"Element not found" <<endl;

}
