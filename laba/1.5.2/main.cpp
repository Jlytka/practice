#include<iostream>
#include "bioobj1.h"
#include "bioobj2.h"
#include "bioobj3.h"
#include "bioobj4.h"
#include "bioobj5.h"
#include "bioobj6.h"
using namespace std;


int main(){
    Mam1 a("mother mary");
    a.input();
    a.output();
    Mam2 b("mother mandy");
    b.speak();
    b.worksAt("hospital");
    Dauther1 c("noita");
    c.speak();
    c.input();
    c.output();
    c.IfWorking();
    Dauther2 d("effy");
    d.speak();
    d.input();
    d.zazaInfo();
    d.torh();
    d.output();
    Boyfriend e("yura kapelan");
    e.input();
    e.output();
    Son f("oleg");
    f.input();
    f.output();


}