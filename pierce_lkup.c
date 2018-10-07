#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define c_dep 500
#define degree 101

struct reverb_lkup;

int build_struct(char *fname, struct reverb_lkup *r);

struct reverb_lkup{
    float time[c_dep][degree];
    float dist[c_dep][degree];
};

int main(int argv, char *argc[]){

    if (argv != 2){
        printf("Usage: pierce_lkup <evdp>\n");
        exit(0);
    }
    int h,c,j;
    const char *reverb[12];
    char fname[40];
    struct reverb_lkup r;

    h = atoi(argc[1]);

    reverb[0] = "_ScS^XScS.gmt";

    reverb[1] = "_ScS^XScSScS.gmt";
    reverb[2] = "_ScSScS^XScS.gmt";

    reverb[3] = "_sSvXSScS.gmt";
    reverb[4] = "_sScSSvXS.gmt";

    reverb[5] = "_sSvXSScSScS.gmt";
    reverb[6] = "_sScSSvXSScS.gmt";
    reverb[7] = "_sScSScSSvXS.gmt";

    reverb[8] =  "_sSvXSScSScSScS.gmt";
    reverb[9] =  "_sScSSvXSScSScS.gmt";
    reverb[10] = "_sScSScSSvXSScS.gmt";
    reverb[11] = "_sScSScSScSSvXS.gmt";

    build_struct("60_ScS^232ScS.gmt",&r);
    //for (i=220;i<725;i+=5){
    //    for (j=0;i<12;i++){
    //        char fname[60];
    //        strcat(fname,itoa(i));
            //strcat(fname,);
            
     //   }
    //}
    return 1;
}

int build_struct(char *fname, struct reverb_lkup *r){
    FILE *fp;
    char c[220],sa[300],sb[50],sc[10],sd[10],se[10],sf[200];
    char c[220],sa[300],sb[50],sc[10],sd[10],se[10],sf[200];
    float time, deg;
    int i=0;

    fp = fopen(fname,"r");
    while(fgets(c,sizeof(c),fp)){
        if (strstr(c,">")){
            // get extract time and st_gcarc
            sscanf(c,"%s %f %s %s %f %s",
                   sa,&time,sd,se,&deg,sf);
            printf("%f %f\n",time,deg);
            
        }
        else{
            sscanf(
       
        }
    }

    fclose(fp);
    return 1;
}







