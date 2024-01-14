//PRÁCTICA 1 

#ifndef FECHA_HPP_
#define FECHA_HPP_

using namespace std;

class Fecha{
    public:
        static const int AnnoMaximo=3000, AnnoMinimo=2024;
        explicit Fecha (int dia_);
        Fecha (int dia_, int mes_, int anno_);
        Fecha (int dia_, int mes_);
        Fecha ();
        Fecha (const char* cad);
        Fecha (std::string f);

        int dia() const{return dia_;};
        int mes()  const{return mes_;};
        int anno() const{return anno_;};

		const char* cadena()const;
        friend bool operator<(const Fecha &f1, const Fecha &f2);
        friend bool operator<=(const Fecha &f1, const Fecha &f2);
        friend bool operator>(const Fecha &f1, const Fecha &f2);
        friend bool operator>=(const Fecha &f1, const Fecha &f2);
        friend bool operator==(const Fecha &f1, const Fecha &f2);
        friend bool operator!=(const Fecha &f1, const Fecha &f2);
        
        Fecha operator+(int n) const;
        Fecha operator-(int n)const;
        Fecha& operator++();  //PRE-INCREMENTO
        Fecha& operator--();  //PRE-DECRECIMIENTO
        Fecha operator++(int);//POST-INCREMENTO
        Fecha operator--(int);//POST-DECRECIMIENTO
        Fecha& operator+=(int n);
        Fecha& operator-=(int n);

        class Invalida{
            public:
                Invalida(const char* error);
                const char* por_que()const{return error_;};
            private:
                const char* error_;
        };
        
    private:
        int dia_,mes_,anno_;
        tm now_date();    
        void zeroDate(int d, int m, int a);
        static void CheckDate(int dia_, int mes_, int anno_);
        static Fecha sum_days(tm *t1, int n);
        static Fecha sub_days(tm *t1, int n);
};

ostream& operator<<(ostream& os, const Fecha& f);
istream& operator>>(istream& is, Fecha& f);

#endif
