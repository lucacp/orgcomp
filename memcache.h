#include <iostream>

namespace org{
	void acessaMemoria(unsigned long endereco,bool inst);
	struct Bloco{
		unsigned char dado[2];
	};
	struct mPri{
		int count;
		Bloco bloc[128];
		Bloco getBlocoP(int a){
			count++;
			return bloc[a];
		};
	};
	struct mCache{
		int count;
		mCache(int i,int a,int d){
			
		}
		void update(int ender){
			int i,o;
			for(i=0;i<4;i++)
				for(o=0;o<4;o++)
					c[i].lru[o]++;
		
		};
	};

	void acessaMemoria(unsigned long endereco,bool inst){



	}
};
