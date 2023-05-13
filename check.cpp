#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
inline double Max(double a,double b){
    if(a>b) return a;
    else return b;
}
int main(){
    double max1=0,max2=0;
    double allt1=0,allt2=0;
    for(int T=1;T<=100;T++){
        system("random.exe");
        double st=clock();
        system("java -jar mine.jar < in.txt > out1.txt");
        double ed=clock();
        system("std.exe");
        // system("java -jar std.jar < in.txt > out2.txt");
        double ed2=clock();
        if(system("fc out1.txt std.txt")){
            puts("Wrong Answer");
            return 0;
        }
        else{
            max1=Max(ed-st,max1),max2=Max(ed2-ed,max2);
            allt1+=ed-st,allt2+=ed2-ed;
            printf("AC, case #%d, time %.0lfms %.0lfms\n",T,ed-st,ed2-ed);
        }
    }
    printf("maxtim1:%.0lfms maxtim2:%.0lfms\n",max1, max2);
    printf("alltime1:%.0fms alltime2:%.0lfms\n",allt1, allt2);
    return 0;
}