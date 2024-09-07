#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define R 1
#define H 0
void netmask();
char* form_bin(int decimal);
char* form_dec(char* chaine,char bin);
int occurence(char* input,char point);
void title();
int main()
{
    netmask();
    return 0;
}

void netmask()
{
    char* ip_cidr=(char*)malloc(100*sizeof(char));
    char* adresse_ip=(char*)malloc(100*sizeof(char));
    char* bitsR=(char*)malloc(100*sizeof(char));
    char* bitIp=(char*)malloc(100*sizeof(char));
    char* net=(char*)malloc(100*sizeof(char));
    //char* decnet=(char*)malloc(100*sizeof(char));
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int i;
    char* A=(char*)malloc(100*sizeof(char));
    char* B=(char*)malloc(100*sizeof(char));
    char* C=(char*)malloc(100*sizeof(char));
    char* D=(char*)malloc(100*sizeof(char));
    char* E=(char*)malloc(100*sizeof(char));
    char* F=(char*)malloc(100*sizeof(char));
    char* G=(char*)malloc(100*sizeof(char));
    char* I=(char*)malloc(100*sizeof(char));
    int count=0;
    //char* msr=(char*)malloc(100*sizeof(char));
    int nbR;
    int bit_total=32;
    int bitH;
    title();
    printf("Entrer l'adresse CIDR :");
    scanf("%s",ip_cidr);
    adresse_ip=strtok(ip_cidr,"/");
    bitsR=strtok(NULL,"\n");
    nbR=atoi(bitsR);
    
    
    sscanf(adresse_ip,"%d.%d.%d.%d",&a,&b,&c,&d);
    count=occurence(adresse_ip,'.');
    
    if( count!= 3 || (a<0 || a>255) || (b<0 || b>255) || (c<0 || c>255) || (d<0 || d>255 || nbR>35))
    {
        printf("\033[31m->\033[0m %s/%d \033[31m<-\033[0m\n",adresse_ip,nbR);
        printf("Veulliez reprendre l'IP cidr:\n");
        netmask();
    }
    else
    {
    bitH=(bit_total)- (nbR);
    printf("Le nombre de bits Réseau est : %d\nLe nombre de bits hote est   : %d\n%d.%d.%d.%d:\n->",nbR,bitH,a,b,c,d);
    if(a<128)
    {
        printf("class A\n");
    }
    else if(a>=128 && a<192)
    {
        printf("class B\n");
    }
    else if(a>=192 && a<224)
    {
        printf("class C\n");
    }
    A=form_bin(a);
    B=form_bin(b);
    C=form_bin(c);
    D=form_bin(d);
    bitIp=strcpy (bitIp,A);
    bitIp=strcat(bitIp,".");
    bitIp=strcat(bitIp,B);
    bitIp=strcat(bitIp,".");
    bitIp=strcat(bitIp,C);
    bitIp=strcat(bitIp,".");
    bitIp=strcat(bitIp,D);
    printf("\nbits IP :      %s\nbits netmask : ",bitIp);
    
    for(i=0;i<35;i++)
    {    
        if(nbR<=8)
        {
            if(i==8 || i==17 || i==26)
            {
                net[i]='.';
                printf("%c",net[i]);
            }
            else
            {
                if(i<nbR)
                {
                    net[i]='1';
                    printf("%c",net[i]);
                }
                else if(i>nbR || i<35)
                {
                    net[i]='0';
                    printf("%c",net[i]);
                }
            }
        }
        else if(nbR>8 && nbR<=16) 
        {
            
        if(i==8 || i==17 || i==26)
        {
            net[i]='.';
            printf("%c",net[i]);
        }
        else
        {
        if(i<=nbR)
        {
            net[i]='1';
            printf("%c",net[i]);
        }
        else if(i>nbR || i<35)
        {
            net[i]='0';
            printf("%c",net[i]);
        }
        }
        }

        else if(nbR>16 && nbR<=24) 
        {
            
        if(i==8 || i==17 || i==26)
        {
            net[i]='.';
            printf("%c",net[i]);
        }
        else
        {
        if(i<=nbR+1)
        {
            net[i]='1';
            printf("%c",net[i]);
        }
        else if(i>nbR || i<35)
        {
            net[i]='0';
            printf("%c",net[i]);
        }
        }
        }
        else if(nbR>24 && nbR<=35) 
        {
            
        if(i==8 || i==17 || i==26)
        {
            net[i]='.';
            printf("%c",net[i]);
        }
        else
        {
        if(i<=nbR+2)
        {
            net[i]='1';
            printf("%c",net[i]);
        }
        else if(i>nbR+2 && i<35)
        {
            net[i]='0';
            printf("%c",net[i]);
        }
        }
        }
    }
    printf("\n");
    }
    E=strtok(net,".");
    F=strtok(NULL,".");
    G=strtok(NULL,".");
    I=strtok(NULL,".");
    //printf("\n%s.%s.%s.%s",E,F,G,I);
    if(nbR<=8)
    {
    E=form_dec(E,'1');
    F="0";
    G="0";
    I="0";
    }
    else if(nbR>8 && nbR<=16)
    {
        E=form_dec(E,'1');
        F=form_dec(F,'1');
        G="0";
        I="0";
    }
    else if(nbR>16 && nbR<=24)
    {
        E=form_dec(E,'1');
        F=form_dec(F,'1');
        G=form_dec(G,'1');
        I="0";
    }
    else if(nbR>24 && nbR<=35)
    {
        E=form_dec(E,'1');
        F=form_dec(F,'1');
        G=form_dec(G,'1');
        I=form_dec(I,'1');
    }
    printf("netmask decimal: %s.%s.%s.%s\n",E,F,G,I);



}
char* form_dec(char* chaine,char bin)
{
    char* decnet=(char*)malloc(100*sizeof(char));
    int count=0;
    count=occurence(chaine,bin);
    //printf("%d",count);
    if( count==8 )
    {
        decnet=strcpy(decnet,"255");
        //printf("decnet : %s",decnet);
    }
    else if( count==7 )
    {
        decnet=strcpy(decnet,"254");
       // printf("decnet : %s",decnet);
    }
    else if( count==6 )
    {
        decnet=strcpy(decnet,"252");
        //printf("decnet : %s",decnet);
    }

    else if( count==5 )
    {
        decnet=strcpy(decnet,"248");
        //printf("decnet : %s",decnet);
    }
    else if( count==4 )
    {
        decnet=strcpy(decnet,"240");
       // printf("decnet : %s",decnet);
    }
    else if( count==3 )
    {
        decnet=strcpy(decnet,"224");
        //printf("decnet : %s",decnet);
    }
    else if( count==2 )
    {
        decnet=strcpy(decnet,"192");
        //printf("decnet : %s",decnet);
    }
    else if( count==1 )
    {
        decnet=strcpy(decnet,"128");
        //printf("decnet : %s",decnet);
    }
    else if(count==0)
    {
        decnet=strcpy(decnet,"0");
    }
    return (decnet);
}
char* form_bin(int decimal)
{
    char* reste=(char*)malloc(100*sizeof(char));
    int i;
      
    for(i=7;i>=0;i--)
    {
        if(decimal%2==1)
        {
            reste[i] = '1';
            decimal=(decimal-1)/2;
        }
        else if(decimal%2==0)
        {
            reste[i] = '0';
            decimal=(decimal-0)/2;
        }
    }
    return (reste);
}
int occurence(char* input,char point){
    int count=0;
    while(*input){
        if(*input == point){
            count++;
        }
        input++;
   }
    return (count);
}
void title()
{
    printf("\033[3m\t\t 🂡 🂻 🂡 ");
    fflush(stdout);
    sleep(1);
    printf("INTERNET");
    fflush(stdout);
    sleep(1);
    printf(" PROTOCOL");
    fflush(stdout);
    sleep(1);
    printf(" 🂡 🂻 🂡\033[0m\n\n");
}
/*void number()
{
    int e;
    int f;
    int i;
    printf("R : ");
    scanf("%d",&e);
    f=32-e;
    if(e<=32)
    {
        for(i=0;i<e;i++)
        {
            net[]
        }
    }
}*/