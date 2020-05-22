#include "funkcija.h"
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;

bool exists(const char *file){
    ifstream infile(file);
    //cerr << "truksta failo - " << file << endl;
    return infile.good();
}

bool skola(double& i){
    return i>=5;
}

void pgeneravimas(vector <studentas*> &m, int x){
    for(int i=0; i<m[x]->n; i++){
            double z=rand()%10+1;
            m[x]->setnd(z);
        }
        m[x]->sete(rand()%10+1);
}

void naujasFailas(vector <studentas*> &m, int psk, int k){
    string name;
    int fx=1000*pow(10, k);
    name = to_string(fx) + ".txt";
    ofstream fr1(name.c_str());
    fr1 << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
    for(int i=0; i<psk; i++)
    fr1 << "ND" << setw(8) << 1+i;
    fr1 << setw(10) << "Egz." << endl;
    for(int i=0; i<fx; i++){
        m.push_back(new studentas("",""));
        m[i]->n = psk;
        m[i]->setpav("Pavarde");
        m[i]->setvard("Vardas");
    }
    for(int j=0; j<fx; j++){                      //pazymiu generavimas
        for(int i=0; i<m[j]->n; i++){
            int z=rand()%10+1;
            m[j]->setnd(z);
        }
        m[j]->sete(rand()%10+1);
    }
    double bulka = 0;
    for(int i=0; i<fx; i++){                    //Rasymas i faila
        fr1 << m[i]->pavarde() << setw(13) << 1+i << m[i]->vardas() << setw(14) << i+1;
        for(int j=0; j<psk; j++)
            fr1 << setw(10) << m[i]->operator[](j);
        fr1 << setw(10) << m[i]->egzaminas() << endl;

    }
    fr1.close();
}

void nuskaitymas(vector <studentas*> &m, int &C, int k){
    C=0;
    string v, p; int egz;
    char c; int words = -3; bool space = true; int ND;
    int fx=1000*pow(10, k);
    string name = to_string(fx) + ".txt";
    ifstream fd(name.c_str());
    while(fd.get(c) and c!='\n'){           //skaiciuoja kiek nd
        if(std::isspace(c)){
            space=true;
        }
        else if(space){
            words++;
            space=false;
        }
    }
    while(!fd.eof()){                       //nuskaito duomenis is failo
        m.push_back(new studentas("",""));
        m[C]->n=words;
        fd >> v >> p;
        m[C]->setvard(v); m[C]->setpav(p);
        for(int i=0; i<words; i++){
            fd >> ND;
            m[C]->setnd(ND);
        }
        fd >> egz;
        m[C]->sete(egz);
        C++;
    }
    m.pop_back();
    C--;
}

void skaiciavimas(vector <studentas*> &m, int C, string v){
    vector <double> paz;
    for(int j=0; j<C; j++){             //rezultatu skaiciavimai
    m[j]->sum=0;                     //nustato pazymiu suma lygia 0
    for(int i=0; i<m[j]->n; ++i)
       m[j]->sum+=m[j]->operator[](i);
    for(int i=0; i<m[j]->n; i++)
        paz.push_back(m[j]->operator[](i));
    sort(paz.begin(), paz.end());
    for(int i=0; i<m[j]->n; i++){
        if((paz.size())%2>0 and (paz.size())/2==i)
            m[j]->med=paz[i];
        else if((paz.size())/2==i or (paz.size())/2-1==i)
            m[j]->med+=paz[i+1];
    }

    m[j]->vid=m[j]->sum/m[j]->n;
    if((m[j]->n)%2==0)
        m[j]->med=m[j]->med/2.0;
    m[j]->galv=m[j]->vid*0.4+m[j]->egzaminas()*0.6;
    m[j]->galm=m[j]->med*0.4+m[j]->egzaminas()*0.6;
    paz.clear();
    }

    for(int i=0; i<C; i++){
        if(v=="v") m[i]->gal=m[i]->galv;
        if(v=="m") m[i]->gal=m[i]->galm;
    }
}

void paskirstymas(vector <studentas*> &m, int C, int k, int K){
    clock_t start; double duration;
    string name1, name2;
    vector <studentas*> gal, bic;
    int C1=0, C2=0; //galvociu ir biciuliu skaicius
    name1 = "biciuliai" + to_string(k+1) + ".txt";
    name2 = "galvociai" + to_string(k+1) + ".txt";
    ofstream frb(name1.c_str());
        frb << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
        for(int i=0; i<m[0]->n; i++)
        frb << "ND" << setw(8) << 1+i;
        frb << setw(8) << "Egz." << endl;

    ofstream frg(name2.c_str());
        frg << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
        for(int i=0; i<m[0]->n; i++)
        frg << "ND" << setw(8) << 1+i;
        frg << setw(8) << "Egz." << endl;
    start = clock();
    if(K==1){
    for(int i=0; i<C; i++){
        if(m[i]->gal>=5){
            gal.push_back(m[i]);
            gal[C1]=m[i];
            C1++;
        }
        else{
            C2++;
        }
    }
    int c=C;
    while(c>-1){
        if(skola(m[c]->gal)){
            m[c]=NULL;
            c--;
        }
        else
            c--;
    }
    m.erase(remove(begin(m), end(m), nullptr),
             end(m));
    }
    else{
        for(int i=0; i<C; i++){
        if(m[i]->gal>=5){
            gal.push_back(new studentas("",""));
            gal[C1]=m[i];
            C1++;
        }
        else{
            bic.push_back(new studentas("",""));
            bic[C2]=m[i];
            C2++;
        }
    }
    }
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    int eil=100;
    string eilutes;
    for(int i=0; i<k+1; i++) eil=eil*10;
    eilutes = to_string(eil);
        cout << eilutes << " eiluciu failas suskirstytas per: " << duration << endl;
    for(int i=0; i<C1; i++){                                //iraso gudrocius
            frg << setw(20) << gal[i]->pavarde() << setw(20) << gal[i]->vardas();
            for(int j=0; j<gal[i]->n; j++)
                frg << setw(10) << gal[i]->operator[](j);
            frg << setw(10) << gal[i]->egzaminas() << endl;
        }
    if(K==1){
    for(int i=0; i<C2; i++){                               //iraso biciulius
            frb << setw(20) << m[i]->pavarde() << setw(20) << m[i]->vardas();
            for(int j=0; j<m[i]->n; j++)
                frb << setw(10) << m[i]->operator[](j);
            frb << setw(10) << m[i]->egzaminas() << endl;
        }
    }
    else{
    for(int i=0; i<C2; i++){
        frb << setw(20) << bic[i]->pavarde() << setw(20) << bic[i]->vardas();
            for(int j=0; j<bic[i]->n; j++)
                frb << setw(10) << bic[i]->operator[](j);
            frb << setw(10) << bic[i]->egzaminas() << endl;
    }
    }
        eil=100;
        for(int i=0; i<k+1; i++) eil=eil*10;
        eilutes = to_string(eil);
        frb.close(); frg.close();
}
