#include <iostream>
 #include <pthread.h>

using namespace std;
// #define THREADS_MAX     4
#define TAM 10000

int adder=0, cont=0;

pthread_mutex_t trava;

void *adiciona(void *param){
  int max = *((int *) param);
  pthread_mutex_lock(&trava);
  for (int i=0; i<max;i++) {
    adder=adder+1;
    cout<<"Destravou " << adder << endl;
  }
  pthread_mutex_unlock(&trava);
}

void *rm(void *param){
  int max= *((int *) param);
  pthread_mutex_lock(&trava);
  for (int i=0; i<max;i++) {
    adder--;
    cout<<"Destravou2 " << adder << endl;
  }
  pthread_mutex_unlock(&trava);

}
//
// void *buged(void *param){
//   while (1) {
//     cout << "cont " << cont << endl;
//     cont++;
//   }
//   cout << "2o\n";
// }

int main(){
  pthread_t add_t, sub_t, buged_t;
  // pthread_mutex_init;
  long val = TAM;
  pthread_mutex_init(&trava, NULL);   //inicia mutex
  pthread_create(&add_t, NULL, adiciona, (void*) &val);
  pthread_create(&sub_t, NULL, rm, (void*) &val);
  // pthread_create(&buged_t, NULL, buged, NULL);
  // while (cont > 100);
  // cout << "asd" << endl;
  // pthread_exit(&buged_t);


  pthread_join(add_t, NULL);
  pthread_join(sub_t, NULL);
  // pthread_join(buged_t, NULL);

  pthread_mutex_destroy(&trava);
  cout << adder << endl;
  return 0;


}


// ----PTHREAD----
//
// ----GERAL
// void *funct(void* PARAM);
// pthread_t exemplo_t;  //declaraÃ§Ã£o bÃ¡sica
// pthread_create(&exemplo_t, NULL, funct, (void*) &param);  //inicializa thread com funct
// pthread_join(exemplo_t, NULL);  //trava o fluxo atÃ© o tÃ©rmino de exemplo_t
// pthread_exit(NULL);    //encerra imediatamente (`break`) a thread que estÃ¡ chamando o mÃ©todo
//
// ----MUTEX
// pthread_mutex_t exemplo_t;    //declaraÃ§Ã£o bÃ¡sica
// pthread_mutex_init(&exemplo_t, NULL);   //inicia mutex
// pthread_mutex_lock(&exemplo_t);        //impede 'paralelismo' em alguma parte, se nÃ£o puder bloquear o mutex o fluxo pausa atÃ© puder
// pthread_mutex_unlock(&exemplo_t);     //liberar 'paralelismo'
// pthread_mutex_destroy(&exemplo_t);