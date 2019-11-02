#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/wait.h>

int main()
{
char c,num[10];
int n,len,i;
while(1)
 {
 printf("\n Bir sayi giriniz");
 gets(num);//Konsoldan giriş oku
 if(strcmp(num,"q")==0)//Girdi q ise çık
 n=atoi(num);// Sayı dönüştürme dizesi
 if(n>2)// Yanlış giriş kontrolü
  {
        collatz(n);// Fonksiyon çağrılıyor
  }
 else
  {
        printf("gecerli bir giris girin ...\n");
  }

 }
return 0;

}

int collatz(int i)// Fonksiyon
 {

  pid_t child_pid, wpid;

  int status = 0;

        if ((child_pid = fork()) == 0)// Çocuk proses oluşturma

   {

    while(i != 1){

        printf("%d\t", i);

        if(i%2 == 0){

            i /= 2;

           }

        else{

          i = 3*i + 1;

         }

       }

   printf("1\n");
   exit(1);

   }
 while ((wpid = wait(&status)) > 0)

   {

   printf("Cocuk prosesten cikildi\n");

   }

return;
}
