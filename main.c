/* fgets3 -- использование функции fgets() */
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define STLEN 128
#define MAX 10


char* trovaparole(FILE* file, char*** parole,int* trovate){
    char line[STLEN];
    int index[MAX];
    int lens[MAX];
    int i;
    int k=0;
    int q=0;
    int reset=0;
    char* result;
    //char* parole[MAX];

    for(i=0;i<sizeof(lens);i++){
        lens[i]=0;
    }
    for(i=0;i<sizeof(index);i++){
        index[i]=0;
    }

    result=fgets(line, STLEN, file);
	for(i=0;i<STLEN;i++){
		if(line[i]==' ' && reset == 0){ //spazi all'inizio
			reset=0;
			continue;
		}
		if((line[i]==' '||line[i]=='\n') && reset == 1){ //spazio dopo parola
			reset=0;
            k++;
            if(line[i]==' '){
			    continue;
            }
            if(line[i]=='\n'){
			  break;
            }
		}
		if(reset!=0 && line[i]!=' '){ // durante la parola
			lens[k]++;
			continue;	
		}
		if(reset==0 && line[i]!=' '){ // inizio parola
			index[k]=i;
			lens[k]++;
			reset=1;
		}

	}	
	//printf("line:%s i:%d\n",line,i);
    for(q=0;q<k;q++){
        //printf("pippo\n");
        parole[q]=malloc(lens[q]+1);
        memcpy(parole[q],&line[index[q]],lens[q]);
	    //printf("parola trovata in posizione %d lunga %d parola:%s\n",index[q],lens[q],parole[q]);
        //free(parole[q]);
    }
    reset=0;
    *trovate=k;
    k=0;
    q=0;
    for(i=0;i<sizeof(lens);i++){
        lens[i]=0;
    }
    for(i=0;i<sizeof(index);i++){
        index[i]=0;
    }
    return result;
}


void main(){
    char* p[MAX];
    int trovate=0;
    char* res;
    while(trovaparole(stdin,(char***) p,&trovate)!=NULL){
        printf("trovate nella linea: %d\n",trovate);
        int t;
        for(t=0;t<trovate;t++){
            printf("parola trovata:%s\n",p[t]);
        }
    }
}

