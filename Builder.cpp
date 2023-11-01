#include <iostream>
#include <string>
using namespace std;
/*Partile masinii*/
class Roata{
    public:
    int diametru;
};
class Motor{
    public:
    int caiputere;
};
class Caroserie{
    public:
    string forma;
};
class Masina{
    public:
    Roata* roti[4];
    Motor* motor;
    Caroserie* caroserie;

    void specificatii(){
    cout<<"caroserie:" <<caroserie->forma<<endl;
    cout<<"caiputere motor:" <<motor->caiputere<<endl;
    cout<<"diametru roti:" <<roti[0]->diametru<<"'"<<endl;
    }
};
class Builder{
    public:
    virtual Roata* getRoata()=0;
    virtual Motor* getMotor()=0;
    virtual Caroserie* getCaroserie()=0;
};
class Director{
    Builder* builder;
    public:
    void setBuilder(Builder* nouBuilder){
        builder = nouBuilder;
    }
    Masina* getMasina(){
        Masina* masina = new Masina();
        masina->caroserie=builder->getCaroserie();
        masina->motor=builder->getMotor();
        masina->roti[0]=builder->getRoata();
        masina->roti[1]=builder->getRoata();
        masina->roti[2]=builder->getRoata();
        masina->roti[3]=builder->getRoata();
        return masina;
    }
};
class NissanBuilder:public Builder{
    public:
    Roata* getRoata(){
        Roata* roata = new Roata();
        roata->diametru = 20;
        return roata;
    }
    Motor* getMotor(){
        Motor* motor = new Motor();
        motor->caiputere = 375;
        return motor;
    }
    Caroserie* getCaroserie(){
        Caroserie* caroserie = new Caroserie();
        caroserie->forma = "Universal";
        return caroserie;
    }
};
class MustangBuilder:public Builder{
    public:
    Roata* getRoata(){
        Roata* roata = new Roata();
        roata->diametru = 17;
        return roata;
    }
    Motor* getMotor(){
        Motor* motor = new Motor();
        motor->caiputere = 565;
        return motor;
    }
    Caroserie* getCaroserie(){
        Caroserie* caroserie = new Caroserie();
        caroserie->forma = "Coupe";
        return caroserie;
    }
};
int main(){
    Masina* masina;
    Director director;
    NissanBuilder nissanBuilder;
    MustangBuilder mustangBuilder;
    cout<<"Nissan"<<endl;
    director.setBuilder(&nissanBuilder);
    masina = director.getMasina();
    masina->specificatii();
    cout<<endl;
    cout<<"Mustang"<<endl;
    director.setBuilder(&mustangBuilder);
    masina = director.getMasina();
    masina->specificatii();
    return 0;
}