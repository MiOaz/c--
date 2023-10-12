#include <iostream>
using namespace std;
class Motor{
    public:
    virtual void eliberareMotor()=0;
};
class MotorJaponez : public Motor{
    public:
    void eliberareMotor() override{
        cout<<"motor japonez"<<endl;
    }
};
class MotorRus : public Motor{
    public:
    void eliberareMotor() override{
        cout<<"motor rus"<<endl;
    }
};
class Masina{
    public:
    virtual void eliberareMasina(Motor*motor)=0;
};
class MasinaJaponeza : public Masina{
    public:
    void eliberareMasina(Motor*motor) override{
        cout<<"Asamblare masina japoneza: ";
        motor->eliberareMotor();
    }
};
class MasinaRusa : public Masina{
    public:
    void eliberareMasina(Motor*motor) override{
        cout<<"Asamblare masina rusa: ";
        motor->eliberareMotor();
    }
};
class Fabrica{
    public:
    virtual Motor*creareMotor()=0;
    virtual Masina*creareMasina()=0; 
};
class FabricaJaponeza : public Fabrica{
    public:
    Motor*creareMotor() override{
        return new MotorJaponez();
    }
    Masina*creareMasina() override{
        return new MasinaJaponeza();
    }
};
class FabricaRusa : public Fabrica{
    public:
    Motor*creareMotor() override{
        return new MotorRus();
    }
        Masina*creareMasina() override{
            return new MasinaRusa();
        }
    };
    int main(){
        Fabrica* Fabrica1 = new FabricaJaponeza();
        Motor* Motor1 = Fabrica1->creareMotor();
        Masina* Masina1 = Fabrica1->creareMasina();
        Masina1->eliberareMasina(Motor1);

        Fabrica* Fabrica2 = new FabricaRusa();
        Motor* Motor2 = Fabrica2->creareMotor();
        Masina* Masina2 = Fabrica2->creareMasina();
        Masina2->eliberareMasina(Motor2);
    };