#include <iostream>
#define SIZE 128
namespace org{
	void acessaMemoria(unsigned long endereco,bool inst);
	void acessaCache(unsigned long endereco,bool inst);
	struct Bloco{
		int dado;
		Bloco(){
			dado=-1;
		};
		Bloco(int i){
		dado=i;
		}
	};
	struct mPri{
		int count;
		Bloco bloc[SIZE];
		mPri(){
			int i=0;
			for(i=0;i<SIZE;i++)
				bloc[i].dado=i;
		}
	};
	struct mCache{
		int count;
		int var;
		Bloco *blo;
		int *lru;
		mCache *c=NULL;
		public:mCache(int as,int bs,int cs){
			bs=bs>>3;
			cs=cs>>3;
			blo=new Bloco[cs]();
			lru=new int[cs];
			var=cs;
			count=0;
		}
		public:void update(unsigned long ender){
			int i;
			i=ender>>var;
			lru[i]=0;
		};
		public:void update(){
			int i;
			for(i=0;i<var;i++)
				lru[i]++;
		};
		
	};
	
};
using namespace std;
using namespace org;
mCache *c=NULL;
mPri *p=NULL;
