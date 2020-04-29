#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>

using namespace std;

class mokinys{
    private:
    string vard, pav;
    vector <double> nd;
    double e;
    public:
    inline string vardas() const {return vard;}
    inline string pavarde() const {return pav;}
    inline double egzaminas() const {return e;}
    const vector<double>& getnd() const{return nd;}
    mokinys() : e(0) { }
    void setnd(double namd){
        this->nd.push_back(namd);
    }
    void setvard(string v){
        vard=v;
    }
    void setpav(string p){
        pav=p;
    }
    void sete(int egz){
        e=egz;
    }
    int sum, n;              //nd suma, nd skaicius
    double vid, med, galv, galm, gal;       //nd vidurkis, nd mediana, galutiniai vidurkiai
    double& operator[](int i) {return nd[i];}   //operatorius skirtas pazymiui gauti
    const double& operator[](int i) const {return nd[i];}
    friend ostream& operator << (ostream& out, const mokinys& a){    //operatorius skirtas mokiniui ir jo duomenims atspausdinti (nenaudoju)
    out << a.vard << " " << a.pav;
    for(int i=0; i<a.n; i++) out << " " << a[i];
    out << " " << a.e << endl;
    }
    friend istream& operator >> (istream& in, mokinys& a){    //operatorius skirtas mokinio vardui ir pavardei ivesti
    in >> a.vard >> a.pav;
    }
    };

bool exists(const char*);
void pgeneravimas(vector <mokinys> &, int);
void naujasFailas(vector <mokinys>, int, int);
void nuskaitymas(vector <mokinys> &, int &, int);
void skaiciavimas(vector <mokinys> &, int, string);
void paskirstymas(vector <mokinys> &, int , int, int);

#endif // FUNCTIONS_H
