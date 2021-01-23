#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct komsu{
	int plaka;
	struct komsu* next;
}komsu;

typedef struct sehir{
	int plaka;
	char name[15];
	char bolge[2];
	int komsuSayisi;
	struct sehir* next;
	struct komsu* komsu;
}sehir;

void komsuSil(sehir **sehirler,int plaka,char * name){
    sehir *temp,*temp2;
    komsu *yeniDugum,*tmpKomsu;
    yeniDugum = (komsu*)malloc(sizeof(komsu));
    temp = *sehirler;
    temp2 = *sehirler;
    while(temp != NULL){
        if(!strcmp(temp->name,name)){
            tmpKomsu = temp->komsu;
            if(tmpKomsu->plaka==plaka){
                temp->komsu = tmpKomsu->next;
            }else{
                while(tmpKomsu->next->plaka != plaka){
                    tmpKomsu = tmpKomsu->next;
                }
                tmpKomsu->next = tmpKomsu->next->next;
            }
            return;
        }
        temp = temp->next;
    }
}

void komsuEkle(sehir **sehirler,int plaka,char * name){
    sehir *temp,*temp2;
    komsu *yeniDugum,*tmpKomsu;
    yeniDugum = (komsu*)malloc(sizeof(komsu));
    temp = *sehirler;
    temp2 = *sehirler;
    while(temp != NULL){
        if(!strcmp(temp->name,name)){
            yeniDugum->plaka = temp->plaka;
            yeniDugum->next = NULL;
            while(temp2 != NULL){
                if(temp2->plaka==plaka){
                    if(temp2->komsu == NULL){
                        temp2->komsu = yeniDugum;
                        return;
                    }
                    tmpKomsu = temp2->komsu;
                    while(tmpKomsu->next != NULL){
                        tmpKomsu = tmpKomsu->next;
                    }

                    tmpKomsu->next = yeniDugum;
                    return;
                }
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}
int sehirEkle(sehir **sehirler,sehir yeniSehir,FILE *output){
    sehir *yeniDugum,*temp;
    yeniDugum = (sehir*)malloc(sizeof(sehir));

    yeniDugum->plaka = yeniSehir.plaka;
    yeniDugum->komsuSayisi = yeniSehir.komsuSayisi;
    strcpy(yeniDugum->name,yeniSehir.name);
    strcpy(yeniDugum->bolge,yeniSehir.bolge);
    yeniDugum->komsu = NULL;
    yeniDugum->next = NULL;

    temp = *sehirler;
    if(temp == NULL)
    {
        temp = yeniDugum;
        *sehirler = temp;
        return 1;
    }
    while(temp->next != NULL){
        if(!strcmp(temp->name,yeniSehir.name) || temp->plaka==yeniSehir.plaka){
            printf("Bu plaka veya isim ile bir sehir bulunuyor: %d %s\n",temp->plaka,temp->name);
            return 0;
        }
        temp = temp->next;
    }

    if(!strcmp(temp->name,yeniSehir.name) || temp->plaka==yeniSehir.plaka){
        printf("Bu plaka veya isim ile bir sehir bulunuyor: %d %s\n",temp->plaka,temp->name);
        return 0;
    }
    temp->next = yeniDugum;
    return 1;
}


void yazBolge(sehir *sehirler,char *bolge,FILE *output){
    sehir *temp;
    komsu *tempKomsu;
    temp = sehirler;
    while(temp != NULL){
        if(!strcmp(temp->bolge,bolge)){
            printf("%d %s %d",temp->plaka,temp->name,temp->komsuSayisi);
            fprintf(output,"%d %s %d",temp->plaka,temp->name,temp->komsuSayisi);
            /*if(temp->komsu!=NULL){
                tempKomsu = temp->komsu;
                while(tempKomsu !=NULL){
                    printf("%d ",tempKomsu->plaka);
                    tempKomsu = tempKomsu->next;
                }
            }*/
            printf("\n");
            fprintf(output,"\n");
        }
        temp = temp->next;
    }
}
int yazSehirByPlaka(sehir *sehirler,int plaka,FILE *output){
    sehir *iter,*iter2;
    komsu *tempKomsu;
    iter = sehirler;
    while(iter != NULL){
        if(iter->plaka==plaka){
            printf("%d %s %s %d Komsusu:\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
            fprintf(output,"%d %s %s %d Komsusu:\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
            if(iter->komsu!=NULL){
                tempKomsu = iter->komsu;
                while(tempKomsu !=NULL){
                    iter2 = sehirler;
                    while(iter2!=NULL){
                        if(iter2->plaka==tempKomsu->plaka){
                            printf("%d %s %s\n",iter2->plaka,iter2->name,iter2->bolge);
                            fprintf(output,"%d %s %s\n",iter2->plaka,iter2->name,iter2->bolge);
                        }
                        iter2 = iter2->next;
                    }
                    tempKomsu = tempKomsu->next;
                }
            }
            printf("\n");
            fprintf(output,"\n");
            return 1;
        }
        iter = iter->next;
    }
}
int yazSehirByAdi(sehir *sehirler,char * name,FILE *output){
    sehir *iter,*iter2;
    komsu *tempKomsu;
    iter = sehirler;
    while(iter != NULL){
        if(!strcmp(iter->name,name)){
            printf("%d %s %s %d Komsusu:\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
            fprintf(output,"%d %s %s %d Komsusu:\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
            if(iter->komsu!=NULL){
                tempKomsu = iter->komsu;
                while(tempKomsu !=NULL){
                    iter2 = sehirler;
                    while(iter2!=NULL){
                        if(iter2->plaka==tempKomsu->plaka){
                            printf("%d %s %s\n",iter2->plaka,iter2->name,iter2->bolge);
                            fprintf(output,"%d %s %s\n",iter2->plaka,iter2->name,iter2->bolge);
                        }
                        iter2 = iter2->next;
                    }
                    tempKomsu = tempKomsu->next;
                }
            }
            printf("\n");
            fprintf(output,"\n");
            return 1;
        }
        iter = iter->next;
    }
}
void yazSehir(sehir *sehirler,char type,int sayi,FILE *output){
    sehir *iter,*iter2;
    komsu *tempKomsu;
    iter = sehirler;
    while(iter != NULL){
        if(type=='k'){
            if(iter->komsuSayisi<sayi){
                printf("%d %s %s %d\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
                fprintf(output,"%d %s %s %d\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
            }
        }else if(type=='e'){
            if(iter->komsuSayisi==sayi){
                printf("%d %s %s %d\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
                fprintf(output,"%d %s %s %d\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
            }
        }else if(type=='b'){
            if(iter->komsuSayisi>sayi){
                printf("%d %s %s %d\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
                fprintf(output,"%d %s %s %d\n",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
            }
        }
        iter = iter->next;
    }
    return;
}
int main()
{
    FILE *output;
    output = fopen("cikti.txt","w");
    sehir * sehirler = NULL;;
    FILE *dosya;
    dosya = fopen("sehirler.txt","r");

    char line[90];
    char * pt;
    while(fgets(line,100,dosya)!='\0')
    {
        pt = strtok(line,",");
        int i = 0;
        sehir tmp;
        while (pt != NULL)
        {
            if(i<3){
                if(i==0)
                    tmp.plaka = atoi(pt);
                else if(i==1)
                    strcpy(tmp.name,pt);
                else if(i==2){
                    strcpy(tmp.bolge,pt);
                }
            }
            ++i;
            pt = strtok (NULL, ",");
        }
		tmp.komsuSayisi = i-3;
    	sehirEkle(&sehirler,tmp,output);
    }
    fclose(dosya);
    dosya = fopen("sehirler.txt","r");
    while(fgets(line,100,dosya)!='\0')
    {
        char *p = line;
        p[strlen(p)-1] = 0;
        pt = strtok(line,",");
        int i = 0;
        int tmpPlaka=0;
        while (pt != NULL)
        {
            if(i==0){
                tmpPlaka=atoi(pt);
            }else if(i>=3){
                komsuEkle(&sehirler,tmpPlaka,pt);
            }
            ++i;
            pt = strtok (NULL, ",");
        }
    }


    sehir *iter = sehirler;
    komsu *iterKomsu;


    iter = sehirler;
    int secim;
    char satir[100];
    sehir addCity;
    char secimBolge[2];
    char komsular[10][30];
    char komsu1[30],komsu2[30];
    int plaka1,plaka2;
    sehir *iter2,*iter3;
    do{
        printf("MENU\n");
        printf("1 - Yeni Sehir Ekleme\n");
        printf("2 - Yeni Komsuluk Ekleme\n");
        printf("3 - Sehir Arama\n");
        printf("4 - Komsuluk Silme\n");
        printf("5 - Bolge Listeleme\n");
        printf("6 - Komsu sayisina gore arama\n");
        printf("7 - Listeyi cikti.txt'e yaz\n");
        printf("8 - Program Sonlandýr\n");
        fprintf(output,"MENU\n");
        fprintf(output,"1 - Yeni Sehir Ekleme\n");
        fprintf(output,"2 - Yeni Komsuluk Ekleme\n");
        fprintf(output,"3 - Sehir Arama\n");
        fprintf(output,"4 - Komsuluk Silme\n");
        fprintf(output,"5 - Bolge Listeleme\n");
        fprintf(output,"6 - Komsu sayisina gore arama\n");
        fprintf(output,"7 - Listeyi cikti.txt'e yaz\n");
        fprintf(output,"8 - Program Sonlandýr\n");

 		scanf("%d",&secim);
        fprintf(output,"%d\n",secim);
 		fflush(stdin);
        switch(secim){
            case 1:
                printf("Yeni Sehir Bilgileri:[PLAKA,ADI,BOLGE,KOMSU,KOMSU...] ");
                fprintf(output,"Yeni Sehir Bilgileri:[PLAKA,ADI,BOLGE,KOMSU,KOMSU...] ");
                gets(&satir);
                fprintf(output,"%s\n",satir);
                pt = strtok(satir,",");
                int i = 0;
                while (pt != NULL)
                {
                    if(i<3){
                        if(i==0)
                            addCity.plaka = atoi(pt);
                        else if(i==1)
                            strcpy(addCity.name,pt);
                        else if(i==2){
                            strcpy(addCity.bolge,pt);
                        }
                    }else{
                        strcpy(komsular[i-3],pt);
                    }
                    ++i;
                    pt = strtok (NULL, ",");
                }
                addCity.komsuSayisi = i-3;
                int control = sehirEkle(&sehirler,addCity,output);
                if(control){
                    for(i=0;i<addCity.komsuSayisi;i++){
                        komsuEkle(&sehirler,addCity.plaka,komsular[i]);
                    }
                    printf("Sehir Eklendi\n");
                    fprintf(output,"Sehir Eklendi\n");
                }
            break;
            case 2:
                printf("Komsu olan sehirlerin isimleri:[ADI ADI]");
                fprintf(output,"Komsu olan sehirlerin isimleri:[ADI ADI]");
                scanf("%s %s",&komsu1,&komsu2);
                fprintf(output,"%s %s\n",komsu1,komsu2);
                iter = sehirler;
                plaka1=0;
                plaka2=0;
                while(iter !=NULL){
                    if(!strcmp(iter->name,komsu1)){
                        plaka1 = iter->plaka;
                        iter2 = iter;
                    }else if(!strcmp(iter->name,komsu2)){
                        plaka2 = iter->plaka;
                        iter3 = iter;
                    }
                    iter = iter->next;
                }
                if(plaka1!=0 & plaka2!=0){
                    iter2->komsuSayisi++;
                    iter3->komsuSayisi++;
                    komsuEkle(&sehirler,plaka2,komsu1);
                    komsuEkle(&sehirler,plaka1,komsu2);
                    printf("Komsuluk Eklendi\n");
                    fprintf(output,"Komsuluk Eklendi\n");
                }else{
                    printf("Yanlis Sehir ismi girdiniz.\n");
                    fprintf(output,"Yanlis Sehir ismi girdiniz.\n");
                }
            break;
            case 3:
                printf("Plaka Veya Sehir Adi Ile Arama Yapin: ");
                fprintf(output,"Plaka Veya Sehir Adi Ile Arama Yapin: ");
                gets(&satir);
                fprintf(output,"%s\n",satir);
                int number = atoi(satir);
                int cntrl = 0;
                if(number==0){
                    cntrl = yazSehirByAdi(sehirler,satir,output);
                }else{
                    cntrl = yazSehirByPlaka(sehirler,number,output);
                }
                if(!cntrl){
                    printf("Sehir listede yok, eklemek ister misiniz? [1/0]");
                    fprintf(output,"Sehir listede yok, eklemek ister misiniz? [1/0]");
                    scanf("%d",&cntrl);
                    fprintf(output,"%d\n",cntrl);
                    if(cntrl){
                        printf("Yeni Sehir Bilgileri:[PLAKA,ADI,BOLGE,KOMSU,KOMSU...] ");
                        fprintf(output,"Yeni Sehir Bilgileri:[PLAKA,ADI,BOLGE,KOMSU,KOMSU...] ");
                        fflush(stdin);
                        gets(&satir);
                        fprintf(output,"%s\n",satir);
                        pt = strtok(satir,",");
                        int i = 0;
                        while (pt != NULL)
                        {
                            if(i<3){
                                if(i==0)
                                    addCity.plaka = atoi(pt);
                                else if(i==1)
                                    strcpy(addCity.name,pt);
                                else if(i==2){
                                    strcpy(addCity.bolge,pt);
                                }
                            }else{
                                strcpy(komsular[i-3],pt);
                            }
                            ++i;
                            pt = strtok (NULL, ",");
                        }
                        addCity.komsuSayisi = i-3;
                        int control = sehirEkle(&sehirler,addCity,output);
                        if(control){
                            for(i=0;i<addCity.komsuSayisi;i++){
                                komsuEkle(&sehirler,addCity.plaka,komsular[i]);
                            }
                            printf("Sehir Eklendi\n");
                            fprintf(output,"Sehir Eklendi\n");
                        }
                    }
                }
            break;
            case 4:
                printf("Silmek istediginiz komsu sehirlerin isimleri:[ADI ADI]");
                fprintf(output,"Silmek istediginiz komsu sehirlerin isimleri:[ADI ADI]");
                scanf("%s %s",&komsu1,&komsu2);
                fprintf(output,"%s %s\n",komsu1,komsu2);
                iter = sehirler;
                plaka1=0;
                plaka2=0;
                while(iter !=NULL){
                    if(!strcmp(iter->name,komsu1)){
                        plaka1 = iter->plaka;
                        iter2 = iter;
                    }else if(!strcmp(iter->name,komsu2)){
                        plaka2 = iter->plaka;
                        iter3 = iter;
                    }
                    iter = iter->next;
                }
                if(plaka1!=0 & plaka2!=0){
                    iter2->komsuSayisi--;
                    iter3->komsuSayisi--;
                    komsuSil(&sehirler,plaka2,komsu1);
                    komsuSil(&sehirler,plaka1,komsu2);
                    printf("Komsuluk Silindi\n");
                    fprintf(output,"Komsuluk Silindi\n");
                }else{
                    printf("Yanlis Sehir ismi girdiniz.\n");
                    fprintf(output,"Yanlis Sehir ismi girdiniz.\n");
                }
            break;
            case 5:
                printf("Bolge: ");
                fprintf(output,"Bolge: ");
                gets(&secimBolge);
                fprintf(output,"%s\n",secimBolge);
                printf("%s\n",secimBolge);
                fprintf(output,"%s\n",secimBolge);
                yazBolge(sehirler,secimBolge,output);
            break;
            case 6:
                printf("Komsu sayisina gore arama yapmak icin kriter ve sayi giriniz:[k/e/b n] ");
                fprintf(output,"Komsu sayisina gore arama yapmak icin kriter ve sayi giriniz:[k/e/b n] ");
                char type;
                int sayi;
                scanf("%c %d",&type,&sayi);
                fprintf(output,"%c %d\n",type,sayi);
                yazSehir(sehirler,type,sayi,output);
            break;
            case 7:
                iter = sehirler;
                while(iter!=NULL){
                    fprintf(output,"%d,%s,%s,%d",iter->plaka,iter->name,iter->bolge,iter->komsuSayisi);
                    if(iter->komsu!=NULL){
                        iterKomsu = iter->komsu;
                        while(iterKomsu!=NULL){
                            fprintf(output," -> %d",iterKomsu->plaka);
                            iterKomsu = iterKomsu->next;
                        }
                    }
                    if(iter->next!=NULL)
                        fprintf(output,"\n|\n");

                    iter = iter->next;
                }
                fprintf(output,"\n");
                printf("Liste cikti.txt'e yazdirildi.\n");
                fprintf(output,"Liste cikti.txt'e yazdirildi.\n");
            break;
        }
    }while(secim!=8);
}

