#include <iostream>
#include <cstring>
using namespace std;
class Pica {
private:
    char ime[15];
    int cena;
    char *sostojki;
    int namaluvanje;
public:
    Pica() {
        sostojki = new char[0];
    }
 
    Pica(char *ime, int cena, char *s, int n) {
        strcpy(this->ime, ime);
        this->cena=cena;
        sostojki=new char [strlen(s)+1];
        strcpy(sostojki,s);
        namaluvanje=n;
    }
 
    Pica(const Pica &p) {
        strcpy(ime,p.ime);
        cena=p.cena;
        sostojki=new char [strlen(p.sostojki)+1];
        strcpy(sostojki,p.sostojki);
        namaluvanje=p.namaluvanje;
    }
 
    Pica& operator= (const Pica &p) { // preoptovaruvanje na =
        if(this!=&p) {
            delete[] sostojki;
            strcpy(ime,p.ime);
            cena=p.cena;
            sostojki=new char [strlen(p.sostojki)+1];
            strcpy(sostojki,p.sostojki);
            namaluvanje=p.namaluvanje;
        }
        return *this;
    }
 
    ~Pica() {
        delete[] sostojki;   // destructor
    }
    int getNamaluvanje() {
        return namaluvanje;
    }
    char* getSostojki() {
        return sostojki;
    }
 
    void pecati() {
        cout<<ime<<" - "<<sostojki<<", "<<cena<<" "<<cena-cena*namaluvanje/100;
    }
 
    bool istiSe(Pica p) {
        if(strcpy(p.sostojki,sostojki)==0)
            return 1;
        else return 0;
    }
 
};
 
 
class Picerija {
private:
    char ime[15];
    Pica *pici;
    int brPici;
 
public:
    Picerija() {
        pici=new Pica[0];
    }
    Picerija(char *ime, Pica *p, int brP) {
        strcpy(this->ime,ime);
        pici=new Pica[brP];
        for(int i=0; i<brP; i++)
            pici[i]=p[i];
        brPici=brP;
    }
 
    Picerija(char *ime) {
        strcpy(this->ime,ime);
        pici=new Pica[0];
        brPici=0;
    }
 
    Picerija(const Picerija &p) {
        strcpy(ime,p.ime);
        pici=new Pica [p.brPici];
        for(int i=0; i<p.brPici; i++)
            pici[i]=p.pici[i];
        brPici=p.brPici;
    }
 
    Picerija& operator= (const Picerija &p) {
        if(this!=&p) {
            delete [] pici;
            strcpy(ime,p.ime);
            pici=new Pica [p.brPici];
            for(int i=0; i<p.brPici; i++)
                pici[i]=p.pici[i];
            brPici=p.brPici;
        }
        return *this;
    }
 
    ~Picerija() {
        delete[] pici;
    }
 
    void setIme(char *ime) {
        strcpy(this->ime,ime);
    }
    char* getIme() {
        return ime;
    }
    void dodadi(Pica P) {
        for(int i=0; i<brPici; i++)
            if(strcmp(P.getSostojki(),pici[i].getSostojki())==0)
                return;
        Pica *tmp;
        tmp=new Pica[brPici];
        for(int i=0; i<brPici; i++)
            tmp[i]=pici[i];
        delete[] pici;
        pici=new Pica[brPici+1];
        for(int i=0; i<brPici; i++)
            pici[i]=tmp[i];
        pici[brPici]=P;
        brPici++;
        delete [] tmp;
    }
 
    void piciNaPromocija() {
        for(int i=0; i<brPici; i++)
            if(pici[i].getNamaluvanje()>0) {
                pici[i].pecati();
                cout<<endl;
            }
    }
};
int main () {
    int n;
    char ime[15];
    cin >> ime;
    cin >> n;
    Picerija p1(ime);
    for(int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }
 
    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);
 
    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();
 
    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();
    return 0;
}
