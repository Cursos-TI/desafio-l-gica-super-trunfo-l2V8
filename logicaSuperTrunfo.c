#include <stdio.h>

typedef struct{char e[20],c[5],ci[30];int p,pontos;float a,pib,d,dpc;}Carta;
float get(Carta c,int o){switch(o){case 1:return c.p;case 2:return c.a;case 3:return c.pib;case 4:return c.pontos;case 5:return c.d;case 6:return c.dpc;default:return-1;}}

int main(){
    Carta c1={"SP","A01","São Paulo",12300000,30,1521,699000,0,0},c2={"RJ","A02","Rio de Janeiro",6000000,25,1182,421000,0,0};
    c1.d=c1.p/c1.a;c1.dpc=c1.pib/c1.p; c2.d=c2.p/c2.a; c2.dpc=c2.pib/c2.p;
    int o1,o2; float v1,v2,s1=0,s2=0;
    printf("Carta1:%s (%s)\nCarta2:%s (%s)\n",c1.ci,c1.e,c2.ci,c2.e);
    printf("1-Pop 2-Area 3-PIB 4-Pontos 5-Dens 6-PIBpc\n> "); scanf("%d",&o1);
    printf("2º atributo dif do 1º\n> "); scanf("%d",&o2); if(o2==o1){printf("Iguais!\n");return 0;}

    for(int i=0;i<2;i++){
        int o=i?o2:o1; v1=get(c1,o); v2=get(c2,o); s1+=v1; s2+=v2;
        printf("Atributo %d: C1=%.2f C2=%.2f | Vencedor:%s\n",i+1,v1,v2,(o==5?v1<v2?c1.ci:c2.ci:v1>v2?c1.ci:c2.ci));
    }
    printf("Soma final C1=%.2f C2=%.2f -> %s\n",s1,s2,s1>s2?c1.ci:s2>s1?c2.ci:"Empate");
}

