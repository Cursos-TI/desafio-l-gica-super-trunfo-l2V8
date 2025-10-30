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
#include <stdio.h>

int main() {
    // Cartas fixas (reaproveitando o cadastro anterior)
    char p1[]="Brasil", p2[]="Argentina";
    int pop1=214000000, pop2=46000000, pts1=25, pts2=18;
    float area1=8515767, area2=2780400, pib1=2.1, pib2=0.6;

    // Cálculos automáticos
    float dens1=pop1/area1, dens2=pop2/area2, ppc1=pib1*1e12/pop1, ppc2=pib2*1e12/pop2;

    int modo,a1,a2; float v1a,v2a,v1b,v2b,s1=0,s2=0;
    printf("1-Um atributo\n2-Dois atributos\nEscolha: "); scanf("%d",&modo);
    printf("1-Pop 2-Area 3-PIB 4-Pts 5-Dens 6-PIBcap\nAtributo: "); scanf("%d",&a1);
    if(modo==2){ printf("Outro: "); scanf("%d",&a2); if(a1==a2) return 0; }

    float vals[6][2]={{pop1,pop2},{area1,area2},{pib1,pib2},{pts1,pts2},{dens1,dens2},{ppc1,ppc2}};
    v1a=vals[a1-1][0]; v2a=vals[a1-1][1];

    if(modo==1){ // comparação simples
        printf("\n%.2f x %.2f\n",v1a,v2a);
        if(v1a==v2a) printf("Empate!\n");
        else printf("Vencedor: %s\n",(a1==5?v1a<v2a:v1a>v2a)?p1:p2);
    } else { // dois atributos
        v1b=vals[a2-1][0]; v2b=vals[a2-1][1];
        s1+=(a1==5?v1a<v2a:v1a>v2a); s2+=(a1==5?v1a>v2a:v1a<v2a);
        s1+=(a2==5?v1b<v2b:v1b>v2b); s2+=(a2==5?v1b>v2b:v1b<v2b);
        printf("\nSoma %s=%.0f | %s=%.0f\n",p1,s1,p2,s2);
        if(s1==s2) printf("Empate!\n");
        else printf("Vencedor: %s\n",(s1>s2)?p1:p2);
    }
}




