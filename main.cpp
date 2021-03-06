#include "memcache.h"
void initmemor(int a,int bs,int cs){
	cd=new mCache(a,bs,cs);
	ci=new mCache(a,bs,cs);
	p=new mPri();
	ci->c=new mCache(a,bs<<3,cs<<3);
	cd->c=ci->c;
}

void teste1(){
	acessaCache(0,true);
	acessaCache(0,true);
	acessaCache(2,false);
	acessaCache(2,false);
	acessaCache(7,true);
	acessaCache(8,true);
	acessaCache(0,true);
	acessaCache(0,true);
	acessaCache(7,true);
	acessaCache(8,true);
	acessaCache(0,true);
	acessaCache(0,true);
	acessaCache(2,false);
	acessaCache(3,false);
	acessaCache(0,true);
	acessaCache(3,false);
};
void teste2(){
	acessaCache(1,false);
	acessaCache(1,false);
	acessaCache(34,true);
	acessaCache(34,true);
};
void stats(){
	cout <<"Acessos: "<<cd->count+ci->count<<", Hits: "<< cd->count+ci->count+cd->c->count-p->count<<endl;
};


int main(int nargs,char** args){
	initmemor(1,32,64);
	teste1();
	stats();
	return 0;
}
void org::acessaCache(unsigned long endereco,bool inst){
		if(inst){
			ci->count++;
			int i=0;
			i=endereco%ci->var;
			if(ci->blo[i].dado==p->bloc[endereco].dado){
				cout << "Hit "<<endl;
			}
			else{
				acessaMemoria(endereco,inst);
			};
			ci->update();
			ci->update(endereco);
		}
		else{
			cd->count++;
			int i=0;
			i=endereco%ci->var;
			if(cd->blo[i].dado==p->bloc[endereco].dado){
				cout << "Hit "<<endl;
			}
			else
				acessaMemoria(endereco,inst);
			cd->update();
			cd->update(endereco);
		};
			
	};
void org::acessaMemoria(unsigned long endereco,bool inst){
		if(inst){
			p->count++;
			int i=0;
			i=endereco%ci->var;
			ci->blo[i]=p->bloc[endereco];
			ci->lru[i]=0;
			cout << "Miss "<<endl;
		}
		else{
			p->count++;
			int i=0;
			i=endereco%cd->var;
			cd->blo[i]=p->bloc[endereco];
			cd->lru[i]=0;
			cout << "Miss "<<endl;
		}
};
