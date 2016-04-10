#define L 10
#define m1 147.0
#define m2 146.7
#define mK 50.0
#define uL 0.011547
#define uM 0.1732051
#define ubT 0.0057735
#include<stdio.h>
#include<math.h>
int main()
{
  int i;
  double t1[5],t2[5],t3[5],tt1=0,tt2=0,tt3=0,uaT1=0,uaT2=0,uaT3=0,urP0,urP,ucP,ucP0,P,P0,uT1=0,uT2=0,uT3=0,BFWC,HFXS,DNB,XXX,YYY;
  puts("input t1");
  for(i=0;i<5;i++) scanf("%lf",&t1[i]);
  puts("input t2");
  for(i=0;i<5;i++) scanf("%lf",&t2[i]);
  puts("input t3");
  for(i=0;i<5;i++) scanf("%lf",&t3[i]);
  for(i=0;i<5;i++) tt1=tt1+t1[i];
  tt1=tt1/5;
  for(i=0;i<5;i++) tt2=tt2+t2[i];
  tt2=tt2/5;
  for(i=0;i<5;i++) tt3=tt3+t3[i];
  tt3=tt3/5;
  for(i=0;i<5;i++) uaT1=uaT1+pow(t1[i]-tt1,2);
  uaT1=uaT1/20;
  uaT1=sqrt(uaT1);
  uT1=sqrt(pow(uaT1,2)+pow(ubT,2));
  for(i=0;i<5;i++) uaT2=uaT2+pow(t2[i]-tt2,2);
  uaT2=uaT2/20;
  uaT2=sqrt(uaT2);
  uT2=sqrt(pow(uaT2,2)+pow(ubT,2));
  for(i=0;i<5;i++) uaT3=uaT3+pow(t3[i]-tt3,2);
  uaT3=uaT3/20;
  uaT3=sqrt(uaT3);
  uT3=sqrt(pow(uaT3,2)+pow(ubT,2));
  P0=m1*L/tt1;
  P=m2*L/tt2;
  ucP0=sqrt(2*pow(L*uM/tt1,2)+pow((m1+mK)*uL/tt1,2)+pow((m1+mK)*L*uT1/tt1/tt1,2));
  urP0=ucP0/P0;
  ucP=sqrt(pow(L*uM/tt2,2)+pow(m2*uL/tt2,2)+pow(m2*L*uT2/tt2/tt2,2)+2*pow(L*uM/tt3,2)+pow((m1+mK)*uL/tt3,2)+pow((m1+mK)*L*uT3/tt3/tt3,2));
  urP=ucP/P;
  printf("P0 %lf\nP %lf\nucP0 %lf\nucP %lf\nurP0 %lf\nurP %lf",P0,P,ucP0,ucP,urP0,urP);
  BFWC=(P-P0)/P0;
  HFXS=tt1/tt2-tt1/tt3;
  DNB=pow(tt2/tt3,2)+m2/m1*pow(tt1/tt2,2);
  XXX=P-P0;
  YYY=3*sqrt(pow(ucP0,2)+pow(ucP,2));
  printf("\n������ %lf\n3���� %lf\nBFWC %lf\nHFXS %lf\nDNB %lf\n",XXX,YYY,BFWC,HFXS,DNB);
  getchar();
  getchar();
  return 0;
}

