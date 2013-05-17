#include <iostream>
#include <string>
using namespace std;

class Avto{
  string *Model;
	unsigned short *kol_mest;
	float *max_skor;
public:
	Avto *NextR;
	Avto *NextL;
	bool visited;
	Avto();
	Avto(string,unsigned short,float);
	Avto(int);
	Avto(const Avto &);
	~Avto();
	void Output();
	void Input();
	void Equals(const Avto &);
	

	unsigned short getkol_mest() const{return *kol_mest;}
	void setkol_mest(unsigned short _kol_mest) {*kol_mest=_kol_mest;}
	string getModel()const {return *Model;}
	void setModel(string a) {*Model=a;}
	float getmax_skor() const {return *max_skor;}
	void setmax_skor(float _max_skor) {*max_skor=_max_skor;}

};

Avto::Avto(){
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	*Model="Mazda";
	*kol_mest=4;
	*max_skor=700;
	NextL=NULL;
	NextR=NULL;
}

Avto::Avto(string a,unsigned short b,float c){
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	*Model=a;
	*kol_mest=b;
	*max_skor=c;
	NextL=NULL;
	NextR=NULL;
}

Avto::Avto(int a){
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	visited=0;
	Input();
	NextL=NULL;
	NextR=NULL;
	
}

Avto::Avto(const Avto & Av){
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	*kol_mest=Av.getkol_mest();
	*max_skor=Av.getmax_skor();
	*Model=Av.getModel();
}
Avto::~Avto(){
	delete kol_mest;
	delete max_skor;
	delete Model;
	kol_mest=0;
	max_skor=0;	
	Model=0;
}

void Avto::Input(){
cout<<"Vv nazv modeli: ";
cin>>*Model;
cout<<endl<<"Vv kol-vo mest: ";
cin>>*kol_mest;
cout<<endl<<"Vv max skorost': ";
cin>>*max_skor;
cout<<endl;
}

void Avto::Output(){
	cout<<"Model:"<<*Model<<endl;
	cout<<"Kol-vo mest: " <<*kol_mest<<endl;
	cout<<"Max skorost': "<<*max_skor<<endl;
}


void Avto::Equals(const Avto &b){
	int x;float z;
	cout <<"Nazvanie: ";
	if (getModel()<b.getModel())
		cout <<getModel()<<"<"<<b.getModel()<<endl;
	else if (getModel()==b.getModel())
		cout <<getModel()<<"="<<b.getModel()<<endl;
	else cout <<getModel()<<">"<<b.getModel()<<endl;
	
	cout<<"Kol-vo mest: ";
	x=(getkol_mest()-b.getkol_mest());
	if (x>0) 
		cout<<getModel()<<" bolshe "<<b.getModel()<<" na "<<x<<endl;
	else if (x<0) 
		cout<<b.getModel()<<" bolshe "<<getModel()<<" na "<<abs(x)<<endl;
	else cout<<"odinakovo = "<<getkol_mest()<<endl;
	
	cout<<"Max Skorost' : ";
	z=(getmax_skor()-b.getmax_skor());
	if (z>0) 
		cout<<getModel()<<" bolshe "<<b.getModel()<<" na "<<z<<endl;
	else if (z<0) 
		cout<<b.getModel()<<" bolshe "<<getModel()<<" na "<<abs(z)<<endl;
	else cout<<"odinakova = "<<getmax_skor()<<endl;
}


void print_tree(Avto *);
void print_it(Avto *);
void print_tree(Avto *p){
	if (p==NULL) return;
	p->Output();
	print_tree(p->NextR);
	print_tree(p->NextL);
	
}

void print_it(Avto * t){
	cout<<"_______________________"<<endl;
	t->visited=0;
	if (t) {
		Avto temp;
		Avto *ptemp=&temp;
		Avto *k=ptemp,*c=t,*w;
			while (c!=ptemp){
			if (c->visited==0)
			{c->Output();
			c->visited=1;}
			w=c->NextL;
			c->NextL=c->NextR;
			if (c==k)
			c->NextR=NULL;
			else
				c->NextR=k;
			k=c;
			if (w) c=w;
		}
	}
}



int main(){
Avto x1(0),x2(0),x3(0),x4(0),x5(0),x6(0);
//x1.Input();
//x2.Input();
//x3.Input();
//x4.Input();
//x5.Input();
//x6.Input();
x1.NextR=&x2;
x1.NextL=&x4;
x2.NextR=&x3;
x2.NextL=&x5;
//x4.NextL=&x1;
//x5.NextL=&x4;
//x5.NextR=&x6;
x3.NextR=&x6;
//x6.NextL=&x5;
print_tree(&x1);
print_it(&x1);





 cin.get();
 cin.get();
 return 0;
}
