#include "memcache.h"
void initmemor(int a,int bs,int cs){
	c=new mCache(a,bs,cs);
	p=new mPri();
}

void teste1(){
	acessaCache(0,true);
	acessaCache(0,true);
	acessaCache(2,false);
	acessaCache(2,false);
};
void teste2(){
	acessaCache(1,false);
	acessaCache(1,false);
	acessaCache(34,true);
	acessaCache(34,true);
};


int main(int nargs,char** args){
	initmemor(1,32,128);
	teste1();
	c->update();
	teste2();
	return 0;
}
void org::acessaCache(unsigned long endereco,bool inst){
		c->count++;
		int i=0;
		i=endereco>>c->var;
		if(c->blo[i%c->var].dado==p->bloc[endereco].dado)
			cout << "Hit "<<endl;
		else
			acessaMemoria(endereco,inst);
		c->update(endereco);
		
			
	};
void org::acessaMemoria(unsigned long endereco,bool inst){
		p->count++;
		int i=0;
		i=endereco>>c->var;
		c->blo[(i%c->var)]=p->bloc[endereco];
		c->lru[(i%c->var)]=0;
		cout << "Miss "<<endl;
	};
