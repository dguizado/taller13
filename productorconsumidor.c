#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int cola=0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALLIZER;
pthread_cond_t var= PTHREAD_COND_INITIALLIZER;


void *productor(void *arg){
	int i;
	for(i=1;i<cola;i++){
		pthread_mutex_lock(&lock);
			while(cola <=0)
				pthread_cond_wait(&var,&lock);
			cola++;
		pthread_mutex_unlock(&lock);
	}
}

void *consumidor(void *arg2){
int i;
        for(i=1;i<cola;i++){
                pthread_mutex_lock(&lock);
                        while(cola <=0)
                                pthread_cond_wait(&var,&lock);
                        cola--;
		pthread_mutex_unlock(&lock);
        }
}


int main(int argc, char *argv[]){
	int numhilos_poductor=atoi(argv[1]);
	float tiempo_productor=atoi(argv[2]);
	int numhilos_consumidor=atoi(argv[3]);
	float tiempo_consumidor=atoi(argv[4]);
	int tam_cola=atoi(argv[5]);
	int num_items=atoi(argv[6]);

	printf("Numero de Productores %i \n", numhilos_productor);
	printf("Numero de Consumidores %i \n", numhilos_consumidor);
	printf("Tamano de la cola %i \n", tam_cola);
	printf("Tiempo de Consumo %i \n", tiempo_consumidor);
	printf("Numero de Produccion %i \n", tiempo_productor);
	printf("Totalde items a producir %i \n", num_items);


	pthread_t threadsP[numhilos_productor];
	pthread_t threadsC[numhilos_consumidor];
	pthread_create(&threadsP,NULL,(void*)productor,NULL);
	pthread_create(&threadsC,NULL,(void*)consumidor,NULL);





}
