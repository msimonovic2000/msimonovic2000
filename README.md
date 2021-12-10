@@ -0,0 +1,239 @@
import java.util.Scanner;
import java.util.Arrays;
/*
Да се дефинира интерфејс IMaraton со методи:
  -  Atleticar najdobroVreme() - го враќа победникот на маратонот
 -   int atleticariOd(String s) - го враќа бројот на атлетичари со земја на потекло s.
Да се дефинира класа Atleticar. За секој атлетичар се чуваат податоци за име String, пол String,
возраст int и време на истрчување изразено во секунди double и земја на потекло String.
За оваа класа треба да се на располагање следните методи:
  -  конструктори (default и со параметри)
   - set и get методи
 -   toString() - формат: име / возраст / земја на потекло / време на истрчување
                (сите параметри одделени со празно место)
Да се дефинира класа Maraton што го имплементира интерфејсот IMaraton.
За секој маратонот се чуваат податоци за местото на одржување String, година int,
низа од атлетичари Atleticar[].
 За оваа класа да се имплементираат:
   - конструктори (default и со параметри)
   - set и get методи
   - toString() - место на одржување / година / атлетичарите учесници на маратонот
                  (сите параметри одделени со нов ред)
    -najdobroVreme()
   - atleticariOd(String s)
 */

interface IMaraton{
    public Atleticar najdobroVreme(); //Interface e kako apstraktna klasa vo c++
    //Go vrakja pobednikot od maratonot;


    public int atleticariOd(String s);
}

class Atleticar {
    private String ime;
    private String pol;
    private int vozrast;
    private double vreme; //vreme na istrcuvanje
    private String zemja; //zemja poteklo

    public Atleticar(){}

    public Atleticar(String ime, String pol, int vozrast, double vreme, String zemja) {
        super();
        this.ime = ime;
        this.pol = pol;
        this.vozrast = vozrast;
        this.vreme = vreme;
        this.zemja = zemja;
    }


    public String getIme() {
        return ime;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public String getPol() {
        return pol;
    }

    public void setPol(String pol) {
        this.pol = pol;
    }

    public int getVozrast() {
        return vozrast;
    }

    public void setVozrast(int vozrast) {
        this.vozrast = vozrast;
    }

    public double getVreme() {
        return vreme;
    }

    public void setVreme(double vreme) {
        this.vreme = vreme;
    }

    public String getZemja() {
        return zemja;
    }

    public void setZemja(String zemja) {
        this.zemja = zemja;
    }



    @Override
    public String toString() {
        return ime +"\n"+vozrast+"\n"+zemja+"\n"+vreme;
    }


}

class Maraton implements IMaraton {

    private String mesto;
    private int godina;
    private Atleticar atleticari[];

//mesto, godina, atleticari

    public Maraton(){}
    public Maraton(String mesto, int godina, Atleticar atleticari[]){
        this.mesto=mesto;
        this.godina=godina;
        this.atleticari=atleticari;

    }

    public String getMesto() {
        return mesto;
    }
    public void setMesto(String mesto) {
        this.mesto = mesto;
    }
    public int getGodina() {
        return godina;
    }
    public void setGodina(int godina) {
        this.godina = godina;
    }
    public Atleticar[] getAtleticari() {
        return atleticari;
    }
    public void setAtleticari(Atleticar[] atleticari) {
        this.atleticari = atleticari;
    }

    //  @Override
//	public String toString() {
    //	return mesto+"\n"
    //	+ godina+"\n"
    //	+ Arrays.toString(atleticari) + "\n";
//	}
    @Override
    public String toString() {
        String print;
        print = mesto + "\n" + godina + "\n";
        for (int i=0;i<atleticari.length;i++) {
            print=print+atleticari[i].toString() + "\n";
        }
        return print;
    }




    public Atleticar najdobroVreme(){
        Atleticar najdobar=atleticari[0];
        //го враќа победникот на маратонот

        for(int i=1;i<atleticari.length;i++) //spored getVreme()
        {
            if(atleticari[i].getVreme()<najdobar.getVreme()){
                najdobar=atleticari[i];
                //    najdobar.getIme()=atleticari[i].getIme();

            }
        }
        return najdobar;
    }

    public int atleticariOd(String s){
        //go vrakja brojot na atleticari so zemja na poteklo s
        int br_atleticari=0;
        for(int i=0;i<atleticari.length;i++){
            if(atleticari[i].getZemja().equals(s)){
                br_atleticari++;

            }

        }
        return br_atleticari;
    }


}


public class ZadacaMaraton {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        Atleticar[] atleticari = new Atleticar[n];

        String ime;
        String pol;
        int vozrast;
        double vreme;
        String zemja;

        input.nextLine();

        for(int i=0;i<n;i++)
        {
            ime = input.nextLine();
            pol = input.nextLine();
            vozrast = input.nextInt();
            vreme = input.nextDouble();
            input.nextLine();
            zemja = input.nextLine();
            atleticari[i]=new Atleticar(ime,pol,vozrast,vreme,zemja);
        }

        String mesto;
        int godina;
        String zemjaP;
        mesto = input.nextLine();
        godina = input.nextInt();
        input.nextLine();

        Maraton m1 = new Maraton(mesto, godina, atleticari);
        System.out.print(m1.toString());

        zemjaP = input.nextLine();
        System.out.println("Prvo mesto: " + m1.najdobroVreme().toString());
        System.out.println("\nIma vkupno " + m1.atleticariOd(zemjaP) + " atleticar/i od " + zemjaP);
    }
}
