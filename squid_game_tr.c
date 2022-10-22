#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void red() {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset() {
  printf("\033[0m");
}


int main()
{
  int i,l=1,k,m=1,cana=3,canb=3,canc=3;
    char kutucuk[50];
    int secim,krk,sut=1,oync=1;
    int kr[10];
    int saglam[11];
    int konuma=0,konumb=0,konumc=0;
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t----Kırık Cam Oyunumuza Hoşgeldiniz----");
    printf("\n\n\n\tOyunun kurallarını görmek için <ENTER> tuşuna basınız");
    getchar();
    printf("\nOyunumuzda 4 satır ve 10 sütundan oluşan ve camdan oluşan  bir köprümüz bulunmaktadır.\n");
    printf("İsimleri 'A' , 'B' ve 'C' olan 3 oyuncumuz bu sütünlardaki camlardan kırık cama basmadan geçip 'FINISH' çizgisine ulaşmaya çalışacaklardır\n");                     // Oyunun Kuralları
    printf("Her bir oyuncunun 3 adet canı vardır ve kırık cama basan oyuncu en baştan başlar ve 1 canını kaybeder. Canı 0 olan oyuncu ise oyuna devam edemez.\n");
    printf("\nKöprüyü görmek için <ENTER> tuşuna basınız...\n\n");
    getchar();
    for(i=0;i<10;i++)printf("\n");
    printf("\n");
    for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Sütun   ",i);}
    printf("\tFINISH\t\t CANLAR : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            if(m<10){printf("|     %d      ",kutucuk[m]);}                                                                                                                          //KÖPRÜ TASARIMI
            else
            printf("|    %d      ",kutucuk[m]);
            m+=4;       }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
    
    srand(time(NULL));
    
    
    for(l=1;l<100;l+=4)                                                                                                                                                             //OYUN BAŞLANGICI
    {
        printf("\n\n\nDevam etmek için <ENTER> Tuşuna basınız");
        getchar();
    for(i=0;i<10;i++)printf("\n");
        printf("\n\n%d. Oyuncu %d.sütundan sayı seçecek.",oync,sut);
        secim=rand()% 4+l;
        krk=rand()% 4+l;
    
    if(secim==krk){                                                                                                                                                             //Oyuncu kırık cama denk gelirse
            kr[sut]=secim;
            
        printf("\n%d. Oyuncu %d.sütundaki %d numaralı cama atladı ve cam kırıldı.",oync,sut,secim);
        if(oync==1){
            cana-=1;
            if(cana==0){printf("\n1. Oyuncunun canı kalmadığı için yarışa devam edemeyecek...\n");}
            if(sut==2){
                konumb++;
            }
            if(sut>=3){
                konumb++;konumc++;printf("Arkadaki oyuncular birer adım ilerliyor...");
            }
            
        }
        else if(oync==2){
            canb-=1;
            if(canb==0){printf("\n2. Oyuncunun canı kalmadığı için yarışa devam edemeyecek...\n");}
            if(sut==2){
                konumc++;
            }
             if(sut>=3){
                konumc++;konuma++;printf("Arkadaki oyuncular birer adım ilerliyor...");
            }
            
        }
        else {canc-=1;
            if(canc==0){printf("\n3. Oyuncunun canı kalmadığı için yarışa devam edemeyecek...\n");}
            if(sut==2){
                konuma++;
            }
             if(sut>=3){
                konuma++;konumb++;printf("Arkadaki oyuncular birer adım ilerliyor...");
            }
            
        }
        if(cana!=0 && oync==1){printf("\n\n1. Oyuncu başlangıç çizgisinden tekrar oyuna başlayacak ve en son oynayacak...\n");konuma=0;}
        if(canb!=0 && oync==2){printf("\n\n2. Oyuncu başlangıç çizgisinden tekrar oyuna başlayacak ve en son oynayacak...\n");konumb=0;}
        if(canc!=0 && oync==3){printf("\n\n3. Oyuncu başlangıç çizgisinden tekrar oyuna başlayacak ve en son oynayacak...\n");konumc=0;}
        oync+=1;
        
         if(sut>=3){
                if(sut-konuma>1 && sut-konumb>1 && sut-konumc>1 ){
                if(oync==1&&cana!=0){printf("\nEn son kalınan noktaya kadar karakterler sırayı bozmadan ve kırık camlara basmadan tekrar geliyor.(%d ADIM)",sut-konuma-1);konumc+=sut-1-konuma;konumb+=sut-1-konuma;konuma=sut-1;}
                if(oync==2&&canb!=0){printf("\nEn son kalınan noktaya kadar karakterler sırayı bozmadan ve kırık camlara basmadan tekrar geliyor.(%d ADIM)",sut-konumb-1);konuma+=sut-1-konumb;konumc+=sut-1-konumb;konumb=sut-1;}
                if(oync==3&&canc!=0){printf("\nEn son kalınan noktaya kadar karakterler sırayı bozmadan ve kırık camlara basmadan tekrar geliyor.(%d ADIM)",sut-konumc-1);konumb+=sut-1-konumc;konuma+=sut-1-konumc;konumc=sut-1;}
                }}
                
        
        do{secim=rand() % 4+l;}while(secim==krk);                                                                                                           //Bir sonraki oyuncunun kırık olmayan herhangi bir cama atlaması
        saglam[sut]=secim;
        if(cana==0 && oync==1){oync+=1;}
        if(canb==0 && oync==2){oync+=1;}
        if(canc==0 && oync==3){oync+=1;}
        if(oync>3 && cana!=0 ){oync=1;}
        if(oync>3 && cana==0 ){oync=2;}
        printf("\nSırada %d. Oyuncumuz var.\n",oync);
        printf("\n\n%d. Oyuncu %d. sütundaki %d numaralı cama başarılı bir şekilde atladı.",oync,sut,secim);
        if(sut==1){
            if(oync==1)konuma++;
            if(oync==2)konumb++;
            if(oync==3)konumc++;
        }
                                                                                                                                                        //Oyuncuların birer adım ilerlemesi
        if(sut==2){
            if(oync==1){konumb++;konuma++;}
        
            if(oync==2){konumc++;konumb++;}
        
            if(oync==3){konuma++;konumc++;printf("\n1 Oyuncu ise %d. Stundaki %d numaralı kırık olmayan cama atlayarak takip ediyor\n\n",sut-1,saglam[sut-1]);}
            if(oync!=3)printf("\n%d. Oyuncu ise %d. Stundaki %d numaralı kırık olmayan cama atlayarak takip ediyor\n\n",oync+1,sut-1,saglam[sut-1]);}
        
        if(sut>=3){
                konuma++;konumb++;konumc++;
                if(cana==0)konuma=0;
                if(canb==0)konumb=0;
                if(canc==0)konumc=0;
                if(oync==1&&canb!=0&&canc!=0){printf("\n\n2. Oyuncumuz %d.sütundaki %d numaralı cama,3. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konumb,saglam[konumb],konumc,saglam[konumc]);}
                if(oync==2&&cana!=0&&canc!=0){printf("\n\n3. Oyuncumuz %d.sütundaki %d numaralı cama,1. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konumc,saglam[konumc],konuma,saglam[konuma]);}
                if(oync==3&&canb!=0&&cana!=0){printf("\n\n1. Oyuncumuz %d.sütundaki %d numaralı cama,2. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konuma,saglam[konuma],konumb,saglam[konumb]);}
                if(oync==1&&canc!=0&&cana==0){printf("\n\n3. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konumc,saglam[konumc]);}
                if(oync==2&&canc!=0&&cana==0){printf("\n\n3. Oyuncumuz ise %d.sütundaki %d numaralı cama ilerliyor.\n",konumc,saglam[konumc]);}
                if(oync==3&&canb!=0&&cana==0){printf("\n\n2. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konumb,saglam[konumb]);}
        }
        
        printf("\n\n\n%d. Turun Sonunda oyuncularımızın canlarını ve köprüyü görmek için <ENTER> tuşuna basınız",sut);                                                  //Her turun sonunda köprünün son hali ve can gösterimi
        getchar();
    for(i=0;i<10;i++)printf("\n");
         printf("\n\n");
        for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Sütun   ",i);}
    printf("\tFINISH\t\t CANLAR : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    m=1;
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            
            if(m==saglam[konuma]){
                if(cana>0){printf("|");yellow();printf("     A      ");reset();}
                else if(m>=10&&cana==0) printf("|    %d      ",kutucuk[m]);
                else if(m<10 &&cana==0) printf("|     %d      ",kutucuk[m]);
               }
            if(m==saglam[konumb]){
                if(canb>0){printf("|");yellow();printf("     B      ");reset();}
                else if(m>=10&&canb==0) printf("|    %d      ",kutucuk[m]);
                else if(m<10 &&canb==0) printf("|     %d      ",kutucuk[m]);
                
                }
            if(m==saglam[konumc]){
                if(canc>0){printf("|");yellow();printf("     C      ");reset();}
                else if(m>=10&&canc==0) printf("|    %d      ",kutucuk[m]);
                else if(m<10 &&canc==0) printf("|     %d      ",kutucuk[m]);
            }
            if(kr[1]==m || kr[2]==m || kr[3]==m || kr[4]==m || kr[5]==m || kr[6]==m || kr[7]==m || kr[8]==m || kr[9]==m || kr[10]==m) {printf("|");red();printf("     K      ");reset();}
            
            
            if(m<10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m ){printf("|     %d      ",kutucuk[m]);}                                                                                                              
            if(m>=10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && m>=10  && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m)
            printf("|    %d      ",kutucuk[m]);
            
            m+=4;      
            }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
        printf("\n");
        sut+=1;
    }
    else                                                                                                                                                                        //Oyuncu sağlam cama denk gelirse
    {
        saglam[sut]=secim;
            printf("\n\n%d. Oyuncu %d. Sütundaki %d numaralı cama başarılı bir şekilde atladı ve cam kırılmadı.\n",oync,sut,secim);
            if(sut==1)konuma++;
            if(sut==2){if(oync==1){konumb++;konuma++;}
        if(oync==2){konumc++;konumb++;}
        if(oync==3){konuma++;konumc++;}
                printf("\n%d. Oyuncu ise %d. Stundaki %d numaralı kırık olmayan cama atlayarak takip ediyor\n",oync+1,sut-1,saglam[sut-1]);}
            if(sut>=3){
                konuma++;konumb++;konumc++;                                                                                                                                     //Arkadaki oyuncuların takip etmesi.
                if(cana==0)konuma=0;
                if(canb==0)konumb=0;
                if(canc==0)konumc=0;
                if(oync==1&&canb!=0&&canc!=0){printf("\n\n2. Oyuncumuz %d.sütundaki %d numaralı cama,3. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konumb,saglam[konumb],konumc,saglam[konumc]);}
                if(oync==2&&cana!=0&&canc!=0){printf("\n\n3. Oyuncumuz %d.sütundaki %d numaralı cama,1. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konumc,saglam[konumc],konuma,saglam[konuma]);}
                if(oync==3&&canb!=0&&cana!=0){printf("\n\n1. Oyuncumuz %d.sütundaki %d numaralı cama,2. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n",konuma,saglam[konuma],konumb,saglam[konumb]);}
                if(oync==1&&canc!=0&&cana==0){printf("\n\n3. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n\n\n\n",konumc,saglam[konumc]);}
                if(oync==2&&canc!=0&&cana==0){printf("\n\n3. Oyuncumuz ise %d.sütundaki %d numaralı cama ilerliyor.\n\n\n\n",konumc,saglam[konumc]);}
                if(oync==3&&canb!=0&&cana==0){printf("\n\n2. Oyuncumuz ise %d. sütundaki %d numaralı cama ilerliyor\n\n\n\n",konumb,saglam[konumb]);}}
                
                printf("\nKöprüyü görmek için <ENTER> tuşuna basınız...");
                getchar();
    for(i=0;i<10;i++)printf("\n");
             printf("\n\n");
                for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Sütun   ",i);}
    printf("\tFINISH\t\t CANLAR : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    m=1;
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            
            if(m==saglam[konuma]){
                if(cana>0){printf("|");yellow();printf("     A      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                 if(m<10) printf("|     %d      ",kutucuk[m]);}
               }
            if(m==saglam[konumb]){
                if(canb>0){printf("|");yellow();printf("     B      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                if(m<10) printf("|     %d      ",kutucuk[m]);}
                }
            if(m==saglam[konumc]){
                if(canc>0){printf("|");yellow();printf("     C      ");reset();}
                else 
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                    if(m<10 ) printf("|     %d      ",kutucuk[m]);}
            }
            if(kr[1]==m || kr[2]==m || kr[3]==m || kr[4]==m || kr[5]==m || kr[6]==m || kr[7]==m || kr[8]==m || kr[9]==m || kr[10]==m) {printf("|");red();printf("     K      ");reset();}
            
            
            if(m<10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m ){printf("|     %d      ",kutucuk[m]);}                                                                                                              
            if( m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && m>=10  && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m)
            printf("|    %d      ",kutucuk[m]);
            
            m+=4;      
            }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
        printf("\n"); 
    sut+=1;
    }
     if(sut>10){                                                                                                                                            //Oyunculardan birinin son sütuna geçip oyunu bitirmesi durumu...
    for(i=0;i<10;i++)printf("\n");
            printf("\n\n%d numaralı oyuncu başarılı bir şekilde <FINISH> çizgisine ulaşarak oyunu kazandı",oync);
            printf("\n\nTEBRIKLER %d. OYUNCU",oync);
            
            if(sut==11){                                                                                                                                    //Son sütunda yanılması halinde oluşacak sıra bozulmasını önlemek için son düzeltme...
                if(sut-konuma>0 && sut-konumb>0 && sut-konumc>0 ){
                if(oync==1&&cana!=0&&konuma!=10){konumc+=sut-konuma-1;konumb+=sut-konuma-1;konuma=sut-1;}
                if(oync==2&&canb!=0&&konumb!=10){konuma+=sut-konumb-1;konumc+=sut-konumb-1;konumb=sut-1;}
                if(oync==3&&canc!=0&&konumc!=10){konumb+=sut-konumc-1;konuma+=sut-konumc-1;konumc=sut-1;}
                }}
                
                printf("\n\t\t\t----- KÖPRÜ SON DURUM -----");
            printf("\n\n");
                for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Sütun   ",i);}
    printf("\tFINISH\t\t CANLAR : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    m=1;
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            
            if(m==saglam[konuma]){
                if(cana>0){printf("|");yellow();printf("     A      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                 if(m<10) printf("|     %d      ",kutucuk[m]);}
               }
            if(m==saglam[konumb]){
                if(canb>0){printf("|");yellow();printf("     B      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                if(m<10) printf("|     %d      ",kutucuk[m]);}
                }
            if(m==saglam[konumc]){
                if(canc>0){printf("|");yellow();printf("     C      ");reset();}
                else 
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                    if(m<10 ) printf("|     %d      ",kutucuk[m]);}
            }
            if(kr[1]==m || kr[2]==m || kr[3]==m || kr[4]==m || kr[5]==m || kr[6]==m || kr[7]==m || kr[8]==m || kr[9]==m || kr[10]==m) {printf("|");red();printf("     K      ");reset();}
            
            
            if(m<10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m ){printf("|     %d      ",kutucuk[m]);}                                                                                                              
            if( m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && m>=10  && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m)
            printf("|    %d      ",kutucuk[m]);
            
            m+=4;      
            }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
        printf("\n"); 
            
            break;
            
        }
}
    printf("\n\t CREATOR: ÖMER CEVHER \n\n");
    
}






