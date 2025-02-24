#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<io.h>
typedef struct N{int t;union{int i;float f;char s[20];char c;}v;struct N*l,*r;}N;typedef struct F{char n[20];struct F*l,*r;}F;int c=0;
N*I(int t){N*x=malloc(sizeof(N));x->t=t;if(t==0)x->v.i=rand()%100;else if(t==1)x->v.f=(float)(rand()%100)/10;else if(t==2)sprintf(x->v.s,"S%d",rand()%100);else x->v.c='A'+rand()%26;x->l=x->r=NULL;return x;}
N*S(N*h,N*n){if(!h)return n;if(rand()%2)h->l=S(h->l,n);else h->r=S(h->r,n);return h;}
void R(N*z){if(!z)return;R(z->l);if(z->t==0)printf("I:%d ",z->v.i);else if(z->t==1)printf("F:%.2f ",z->v.f);else if(z->t==2)printf("S:%s ",z->v.s);else printf("C:%c ",z->v.c);R(z->r);}
void C(N*h){if(!h)return;N*p=h;while(p){if(rand()%2)p=p->l;else p=p->r;}if(p){if(p->t==0)p->v.i+=rand()%10;else if(p->t==1)p->v.f+=((float)(rand()%10))/10;}C(h->r);}
F*Q(F*h,F*n){if(!h)return n;if(rand()%2)h->l=Q(h->l,n);else h->r=Q(h->r,n);return h;}
void W(F*h){if(!h)return;FILE*f=fopen(h->n,"w");fprintf(f,"Chaos %d\n",rand()%1000);fclose(f);if(rand()%2)remove(h->n);}
void G(F*h){if(!h)return;W(h);G(h->l);}
void X(){char n[20];sprintf(n,"rand%d.txt",rand()%1000);FILE*f=fopen(n,"w");fprintf(f,"Random Tree Dump\n");fclose(f);char c[40];sprintf(c,"notepad %s",n);system(c);Sleep(2000);remove(n);}
void Y(){char n[20],e[20];int r=rand()%1000;sprintf(n,"rand%d.c",r);sprintf(e,"rand%d.exe",r);FILE*f=fopen(n,"w");fprintf(f,"#include<stdio.h>\nint main(){printf(\"Random C file executed!\\n\");return 0;}");fclose(f);char c[50];sprintf(c,"gcc %s -o %s",n,e);system(c);if(_access(e,0)!=-1)system(e);}
void P(int*n,int*d,int l){for(int i=0;i<l;i++)Beep(n[i],d[i]),Sleep(50);}
int main(){N*h=NULL;F*f=NULL;srand(time(0));
int dtsn[]={659,698,784,880,988,1047,1175,1319,1397,1568,880,988,1047,988,880,784,698,659};int dtd[]={200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200};P(dtsn,dtd,18);
int im[]={440,440,440,349,523,440,349,523,440,659,440,440,440,349,523,440,349,523,440,659};int imd[]={500,500,500,350,150,500,350,150,1000,500,500,500,350,150,500,350,150,1000,500,500};P(im,imd,20);
for(int i=0;i<5;i++)h=S(h,I(rand()%4)),c++;printf("\nInitial Tree: ");R(h);C(h);printf("\nModified Tree: ");R(h);
while(1){char fn[20];printf("\nFile Name (-1 to end): ");scanf("%s",fn);if(strcmp(fn,"-1")==0)break;F*n=malloc(sizeof(F));strcpy(n->n,fn);n->l=n->r=NULL;f=Q(f,n);}G(f);X();Y();
int dtdt[]={392,440,392,349,392,294,392,440,392,349,392,294,440,392,349,392,294,440,392,349};int dtdtd[]={500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500};P(dtdt,dtdtd,20);
int hs[]={392,440,392,349,392,294,392,440,392,349,392,294,440,392,349,392,294,440,392,349};int hsd[]={400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400};P(hs,hsd,20);}