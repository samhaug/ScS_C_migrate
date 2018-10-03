#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Use to convert hdf5 reverb ascii to binary C structure 
 * needs an ascii file made with h5_to_ascii. */

struct reverb{
    char stat[20];
    double ScSScS[5501];
    double ScSScSScS[5501];
    double sScS[5501];
    double sScSScS[5501];
    double sScSScSScS[5501];
    double stla,stlo,evla,evlo,evdp,gcarc;
};

int main(int argv,char **argc){
    struct reverb r[2];
    FILE *fp,*outfile;  
    char c[40];
    int i,j;

    fp = fopen("reverb.txt","r");

    int r_count = -1;
    while (fgets(c,sizeof(c),fp) != NULL){
        if (strstr(c,"ScS")){j=0;continue;}
        if (strstr(c,"NEW")){i=0;r_count++;continue;}
        i++;
        if (i<5509 && i>8){
            r[r_count].ScSScS[j] = atof(c);
            j++;
            continue;
        }
        if (i<11010 && i>5509){
            r[r_count].ScSScSScS[j] = atof(c);
            j++;
            continue;
        }
        if (i<16511 && i>11010){
            r[r_count].sScS[j] = atof(c);
            j++;
            continue;
        }
        if (i<22012 && i>16511){
            r[r_count].sScSScS[j] = atof(c);
            j++;
            continue;
        }
        if (i>22012){
            r[r_count].sScSScSScS[j] = atof(c);
            j++;
            continue;
        }

        if (i==1){strcpy(r[r_count].stat,c); continue;}
        if (i==2){r[r_count].gcarc = atof(c); continue;}
        if (i==3){r[r_count].evdp = atof(c);  continue;}
        if (i==4){r[r_count].stla = atof(c);  continue;}
        if (i==5){r[r_count].stlo = atof(c);  continue;}
        if (i==6){r[r_count].evla = atof(c);  continue;}
        if (i==7){r[r_count].evlo = atof(c);  continue;}
    }
    puts(r[0].stat);
    puts(r[1].stat);
    printf("%f %f\n",r[0].stla,r[0].stlo);
    printf("%f %f\n",r[1].stla,r[1].stlo);
    outfile = fopen("reverb.dat","wb");
    fwrite(&r,sizeof(struct reverb),2,outfile); 
    return 0;
}



