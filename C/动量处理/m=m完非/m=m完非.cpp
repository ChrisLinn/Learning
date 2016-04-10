#define L 10
#define m1 146.7
#define m2 146.7
#define uL 0.011547
#define uM 0.1732051
#define ubT 0.0057735
#include<stdio.h>
#include<math.h>
int main()
{
  int i;
  double t1[5],t2[5],tt1=0,tt2=0,uaT1=0,uaT2=0,urP0,urP,ucP,ucP0,P,P0,uT1=0,uT2=0,BFWC,HFXS,DNB,XXX,YYY;
  puts("input t1");
  for(i=0;i<5;i++) scanf("%lf",&t1[i]);
  puts("input t2");
  for(i=0;i<5;i++) scanf("%lf",&t2[i]);
  for(i=0;i<5;i++) tt1=tt1+t1[i];
  tt1=tt1/5;
  for(i=0;i<5;i++) tt2=tt2+t2[i];
  tt2=tt2/5;
  for(i=0;i<5;i++) uaT1=uaT1+pow(t1[i]-tt1,2);
  uaT1=uaT1/20;
  uaT1=sqrt(uaT1);
  uT1=sqrt(pow(uaT1,2)+pow(ubT,2));
  for(i=0;i<5;i++) uaT2=uaT2+pow(t2[i]-tt2,2);
  uaT2=uaT2/20;
  uaT2=sqrt(uaT2);
  uT2=sqrt(pow(uaT2,2)+pow(ubT,2));
  P0=m1*L/tt1;
  P=(m1+m2)*L/tt2;
  urP0=sqrt(pow(uM/m1,2)+pow(uL/L,2)+pow(uT1/tt1,2));
  ucP0=P0*urP0;
  ucP=sqrt(2*pow(L*uM/tt2,2)+pow((m1+m2)*uL/tt2,2)+pow((m1+m2)*L*uT2/tt2/tt2,2));
  urP=ucP/P;
  printf("P0 %lf\nP %lf\nucP0 %lf\nucP %lf\nurP0 %lf\nurP %lf",P0,P,ucP0,ucP,urP0,urP);
  BFWC=(P-P0)/P0;
  HFXS=0;
  DNB=(m1+m2)/m1*pow(tt1/tt2,2);
  XXX=P-P0;
  YYY=3*sqrt(pow(ucP0,2)+pow(ucP,2));
  printf("\n动量差 %lf\n3根数 %lf\nBFWC %lf\nHFXS %lf\nDNB %lf\n",XXX,YYY,BFWC,HFXS,DNB);
  getchar();
  getchar();
  return 0;
}
