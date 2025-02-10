#include<iostream>
using namespace std;

struct ponto {
	int x, y;
};

float area_trigulo(ponto a, ponto b, ponto c){
	float area = a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x;
	area = area / 2;
	return area;
}

int posicao_relativa(ponto a, ponto b, ponto p){
	float area = area_trigulo(a,b,p);
	if(area > 0) {
		return 1;
	} else if(area < 0) {
		return -1;
	} else {
		return 0;
	}
}

int main(){
	
	// ponto a, b, c;
	// a.x = 1;
	// a.y = 2;
	// b.x = 4;
	// b.y = 4;
	// c.x = 4;
	// c.y = 1;
	// 
	// cout << area_trigulo(a,b,c) << endl;

	ponto p = {3,2};
	ponto p1 = {1,2};
	ponto p2 = {4,4};
	ponto p3 = {4,1};
	ponto p4 = {5,5};
	ponto p5 = {6,6};
	
	// float area = area_trigulo(p1,p2,p3);
	// float l1 = area_trigulo(p,p2,p3)/area;
	// float l2 = area_trigulo(p1,p,p3)/area;
	// float l3 = area_trigulo(p1,p2,p)/area;	
	// 
	// cout << l1 << endl;
	// cout << l2 << endl;
	// cout << l3 << endl;
	
	int pos = posicao_relativa(p2,p4,p5);
	
	if(pos == 1) {
		cout << "A esquerda";
	} else if(pos == -1){
		cout << "A direita";
	} else {
		cout << "Colineares";
	}
	cout << endl;
		
	return 0;
}