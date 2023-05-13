#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory>
#define Random 0
#define Valid 1
#define Targeted 2
using namespace std;
int init_plus(int);
void generate_plus(int, int);
void targetedTest(int, int);
inline int random(int n){
    if (n <= 0) {
        return rand() & 0xff;
    }
    return (rand()*rand())%n+1;
}
inline int random(int l, int r){
    return (rand()*rand())%(r-l+1)+l;
}
auto randomString(int len) {
    auto temps = unique_ptr<char[]>(new char[len+1]);
    for (int i = 0; i < len; ++ i) {
        temps[i] = random(25) + 'a';
    }
    temps[len] = '\0';
    return temps;
}
/*
ap, ar, qv, qci, qbs, qts, ag, atg, dfg, qgvs, qgav, mr, qba, qcs, am, sm, qsv, qrm, arem, anm, cn, aem, sei, qp, dce, qm, qlm
*/
char instr[][7]={"ap","ar","qv","qci","qbs","qts", "ag", "atg", "dfg", "qgvs", "qgav", "mr", "qba",
 "qcs", "am", "sm", "qsv", "qrm", "arem", "anm", "cn", "aem", "sei", "qp", "dce", "qm", "qlm"};

int idx=0;
/*This function call generates 4.5*n instructions for initialization.*/
void init(int n){
    const int lim=n;
    while (n--){
        printf("ap %d p%d %d\n",random(lim), ++idx, random(100));
        if (n & 1) 
            printf("ag %d\n",random(lim));
    }
    n=lim;
    while (n--){
        printf("ar %d %d %d\n",random(lim), random(lim), random(100));
    }
    n=lim;
    while (n--){
        printf("atg %d %d\n",random(lim), random(lim));
    }
    n=lim;
    while (n--) {
        printf("dfg %d %d\n",random(lim), random(lim));
    }
}
void balance_generate(int m, int n){
    while(m--){
        int f=random(n)%27;
        switch(f){
            case 0:{
                printf("ap %d p%d %d\n",random(n), ++idx, random(100));
                break;
            }
            case 1:{
                printf("ar %d %d %d\n",random(n), random(n), random(100));
                break;
            }
            case 2:
            case 3:{
                printf("%s %d %d\n",instr[f],random(n),random(n));
                break;
            }
            case 4:
            case 5:{
                printf("%s\n",instr[f]);
                break;
            }
            case 6:{
                printf("ag %d\n",random(n));
                break;
            }
            case 7:
            case 8:{
                printf("%s %d %d\n",instr[f],random(n),random(n));
                break;
            }
            case 9:
            case 10:{
                printf("%s %d\n",instr[f],random(n));
                break;
            }
            case 11:{
                printf("%s %d %d %d\n",instr[f],random(n), random(n), random(200)-100);
                break;
            }
            case 12:{
                printf("%s %d\n",instr[f],random(n));
                break;
            }
            case 13:{
                printf("%s\n",instr[f]);
                break;
            }
            case 14:{
                printf("%s %d %d %d %d %d\n",instr[f],random(n),random(n),random(n)&1,random(n),random(n));
                break;
            }
            case 15:
            case 16:
            case 17:{
                printf("%s %d\n",instr[f],random(n));
                break;
            }
            case 18:{
                printf("%s %d %d %d %d %d\n",instr[f], random(n), random(100), random(2), random(n), random(n));
                break;
            }
            case 19:{
                printf("%s %d %s %d %d %d\n", instr[f], random(n), randomString(7).get(), 
                            random(2), random(n), random(n));
                break;
            }
            case 20:{
                printf("%s %d\n", instr[f], random(n));
                break;
            }
            case 21:{
                printf("%s %d %d %d %d %d\n", instr[f], random(n), random(100), random(2), random(n), random(n));
                break;
            }
            case 22:
            case 23:{
                printf("%s %d\n", instr[f], random(n));
                break;
            }
            case 24:{
                printf("%s %d\n", instr[f], random(15));
                break;
            }
            case 25:
            case 26:{
                printf("%s %d\n", instr[f], random(n));
                break;
            }
        }
    }
}
int main(){
    srand((unsigned int)time(0));
    // printf("%s\n",randomString(6).get());
    freopen("in.txt","w",stdout);
    int mode = Targeted;//Random or Valid or Targeted
    int m=random(300);
    int n=random(1000);
    switch (mode) {
        case Random: {
            init(n);
            balance_generate(m, n);
            break;
        }
        case Valid: {
            generate_plus(n, m);
            break;
        }
        case Targeted: {
            targetedTest(n, m);
            break;
        }
        default:{
            init(n);
            balance_generate(m, n);
        }
    }
    fclose(stdout);
    return 0;
}
/*This function call generates 3.8*n instructions for initialization.*/
int init_plus(int n){
    int cntp=0;
    int cntgroup=0;
    const int lim=n;
    while (n--){
        printf("ap %d p%d %d\n",++cntp, ++idx, random(100));
        if (n % 3 == 0) 
            printf("ag %d\n",++cntgroup);
    }
    n=lim;
    while (n--){
        printf("ar %d %d %d\n",random(cntp), random(cntp), random(100));
    }
    n=lim;
    while (n--){
        printf("atg %d %d\n",random(cntp), random(cntgroup));
    }
    n=lim>>1;
    while (n--) {
        printf("dfg %d %d\n",random(cntp), random(cntgroup));
    }
    return cntp;
}
void generate_plus(int n, int m) {
    int cntmsg = 0;
    int cntemj = 0;
    int cntp = init_plus(n);
    int cntgroup = n / 3;
    while(m--){
        int f=random(n)%27;
        switch(f){
            case 0:
            case 1:{
                printf("ar %d %d %d\n",random(cntp), random(cntp), random(100));
                break;
            }
            case 2:
            case 3:{
                printf("%s %d %d\n",instr[f],random(cntp),random(cntp));
                break;
            }
            case 4:
            case 5:{
                printf("%s\n",instr[f]);
                break;
            }
            case 6: f=7;
            case 7:
            case 8:{
                printf("%s %d %d\n",instr[f],random(cntp),random(cntgroup));
                break;
            }
            case 9:
            case 10:{
                printf("%s %d\n",instr[f],random(cntgroup));
                break;
            }
            case 11:{
                printf("%s %d %d %d\n",instr[f],random(cntp), random(cntp), random(200)-100);
                break;
            }
            case 12:{
                printf("%s %d\n",instr[f],random(cntp));
                break;
            }
            case 13:{
                printf("%s\n",instr[f]);
                break;
            }
            case 14:{
                printf("%s %d %d %d %d %d\n",instr[f],++cntmsg,random(n),random(n)&1,random(cntp),random(cntp));
                break;
            }
            case 15:{
                printf("%s %d\n",instr[f],random(cntmsg));
                break;
            }
            case 16:
            case 17:{
                printf("%s %d\n",instr[f],random(cntp));
                break;
            }
            case 18:{
                printf("%s %d %d %d %d %d\n",instr[f], ++cntmsg, random(100), random(2), random(cntp), random(cntp));
                break;
            }
            case 19:{
                printf("%s %d %s %d %d %d\n", instr[f], ++cntmsg, randomString(7).get(), 
                            random(2), random(cntp), random(cntp));
                break;
            }
            case 20:{
                printf("%s %d\n", instr[f], random(cntp));
                break;
            }
            case 21:{
                printf("%s %d %d %d %d %d\n", instr[f], random(cntemj), random(100), random(2), random(cntp), random(cntp));
                break;
            }
            case 22:
            case 23:{
                printf("%s %d\n", instr[f], ++cntemj);
                break;
            }
            case 24:{
                printf("%s %d\n", instr[f], random(6));
                break;
            }
            case 25:
            case 26:{
                printf("%s %d\n", instr[f], random(cntp));
                break;
            }
        }
    }
}
void targetedTest(int n,int m) {
    if (n < 3) n = 3;
    for (int i = 1; i <= n; ++ i)
        printf("ap %d p%d %d\n",i, i, random(100));
    for (int i = 1; i <= n; ++ i) {
        int x, y;
        do {
            x=random(n);
            y=random(n);
        } while (x==y);
        printf("ar %d %d %d\n", x, y, random(500));
    }
    for (int i = 1; i <= m; ++ i) {
        int x, y;
        do {
            x=random(n);
            y=random(n);
        } while (x==y);
        printf("ar %d %d %d\n", x, y, random(500));
        printf("qlm %d\n", random(n));
    }
}
/*
The instruction format:
  add_person id(int) name(String) age(int)
  add_relation id(int) id(int) value(int)
  query_value id(int) id(int)
  query_circle id(int) id(int)
  query_block_sum
  query_triple_sum 

  add_group id(int)
  add_to_group id(int) id(int)
  del_from_group id(int) id(int)
  query_group_value_sum id(int)
  query_group_age_var id(int)
  modify_relation id(int) id(int) value(int)
  modify_relation_ok_test
  query_best_acquaintance id(int)
  query_couple_sum
  add_message id(int) socialValue(int) type(int)
      person_id1(int) person_id2(int)|group_id(int)
  send_message id(int)
  query_social_value id(int)
  query_received_messages id(int)

  add_red_envelope_message id(int) money(int) type(int)
  person_id1(int) person_id2(int)|group_id(int)
  add_notice_message id(int) string(String) type(int)
  person_id1(int) person_id2(int)|group_id(int)
  clear_notices id(int)
  add_emoji_message id(int) emoji_id(int) type(int)
  person_id1(int) person_id2(int)|group_id(int)
  store_emoji_id id(int)
  query_popularity id(int)
  delete_cold_emoji limit(int)
  query_money id(int)
  query_least_moment id(int)

  age:[1, 100]; (ap)
  value: [1, 100]; (ar)
  value: [-100, 100];(mr)
  type: [0, 1]; socialValue: [-1000, 1000];
*/