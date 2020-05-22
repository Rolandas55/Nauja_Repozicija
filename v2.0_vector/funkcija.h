#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class zmogus{
protected:
    string vard, pav;
    zmogus(string va, string pa) : vard{va}, pav{pa} {}
public:
    virtual inline string vardas() const {return vard;}
    virtual inline string pavarde() const {return pav;}
    void setvard(string v){
        vard=v;
    }
    void setpav(string p){
        pav=p;
    }
    int sum, n;              //nd suma, nd skaicius
    double vid, med, galv, galm, gal;       //nd vidurkis, nd mediana, galutiniai vidurkiai
    friend istream& operator >> (istream& in, const zmogus& a);//{in >> a.vard >> a.pav;}
    double& operator[](int i);//{return (nd[i]);}  //operatorius skirtas pazymiui gauti
    //virtual const double& operator[](int i){return nd[i];}
    friend ostream& operator << (ostream& out, zmogus& a);
    inline double egzaminas();
    void setnd(double namd);
    void sete(int egz);
    ~zmogus();
};

class studentas : public zmogus {
private:
    vector <double> nd;
    double e;
public:
    studentas(string va, string pa) : zmogus(va, pa) {}
    inline string vardas() const {return vard;}
    inline string pavarde() const {return pav;}
    inline double egzaminas() const {return e;}
    const vector<double>& getnd() const {return nd;}
    void setnd(double namd){
        this->nd.push_back(namd);
    }
    void sete(int egz){
        e=egz;
    }
    void setvard(string v){
        vard=v;
    }
    void setpav(string p){
        pav=p;
    }
    double& operator[](int i) {assert(i>=0 and i<nd.size()); return nd[i];}   //operatorius skirtas pazymiui gauti  assert(i>=0 && i<nd.size()
    const double& operator[](int i) const{assert(i>=0 and i<nd.size()); return nd[i];}
    friend ostream& operator << (ostream& out, const studentas& b){    //operatorius skirtas mokiniui ir jo duomenims atspausdinti (nenaudoju)
    out << b.vardas() << " " << b.pavarde();
    for(int i=0; i<b.n; i++) out << " " << b[i];
    out << " " << b.egzaminas() << endl;}
    friend istream& operator >> (istream& in, studentas& b){    //operatorius skirtas mokinio vardui ir pavardei ivesti
    in >> b.vard >> b.pav;}
    ~studentas();
};


bool exists(const char*);
void pgeneravimas(vector <studentas*> &, int);
void naujasFailas(vector <studentas*> &,int, int);
void nuskaitymas(vector <studentas*> &, int &, int);
void skaiciavimas(vector <studentas*> &,int, string);
void paskirstymas(vector <studentas*> &, int , int, int);

#endif // FUNCTIONS_H
