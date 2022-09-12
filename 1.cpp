#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string palabra_original;
string palabra_mostrar;
int vidas=5,acertado=0;
char x;

void mostrar_palabra_adivinar(){
	palabra_original="Felices vacaciones.";
	for(int i=0;i<palabra_original.length();i++){
		if(palabra_original[i]>='A' && palabra_original[i]<='Z'){
			palabra_original[i]+=32;
		}
	}
	for(int i=0;i<palabra_original.length();i++){
		if(palabra_original[i]>='a' && palabra_original[i]<='z'){
			palabra_mostrar+='-';
		}
			else{
				palabra_mostrar+=palabra_original[i];
			}
	}
}

void mostrar(){
	cout<<"Oportunidades restantes: "<<vidas<<endl;
	cout<<"Letras acertadas: "<<acertado<<endl;
	cout<<palabra_mostrar<<endl;
}

void validar(char x){
	bool perdiVidas=true;
	for(int i=0;i<palabra_original.length();i++){
		if(x==palabra_original[i]){
			perdiVidas=false;
			palabra_mostrar[i]=x;
			acertado++;
		}
	}
	if(perdiVidas==true){
		vidas--;
	}
}

int main(int argc, char** argv) {
	char i;
	mostrar_palabra_adivinar();
	mostrar();
	while(vidas>0 && palabra_mostrar!=palabra_original){
		cin>>x;
		system("cls");
		validar(x);
		mostrar();
	}
	if(vidas>0){
		cout<<"Has ganado esta vez!";
	}
		else{
			cout<<"Has perdido esta vez, la palabra era: "<<palabra_original;
		}
	return 0;
}
