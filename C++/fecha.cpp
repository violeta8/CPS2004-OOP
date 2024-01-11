#include "fecha.hpp"

using namespace std;

Fecha::Fecha(int dia,int mes, int anno){
    this->dia_=dia;
    this->mes_=mes;
    this->anno_=anno;
    zeroDate(dia,mes,anno);
    CheckDate(dia_,mes_,anno_);
} 

Fecha::Fecha (int dia, int mes){
    this->dia_=dia;
    this->mes_=mes;
    this->anno_=now_date().tm_year+1900;
    zeroDate(dia_,mes_,anno_);
    CheckDate(dia_,mes_,anno_);
}

Fecha::Fecha (int dia){ 
    this->dia_=dia;
    this->mes_=now_date().tm_mon+1;
    this->anno_=now_date().tm_year+1900;
    zeroDate(dia_,mes_,anno_);
    CheckDate(dia_,mes_,anno_);
}

Fecha::Fecha(){
    dia_=now_date().tm_mday;
    mes_=now_date().tm_mon+1;
    anno_=now_date().tm_year+1900;
    CheckDate(dia_,mes_,anno_);
}

Fecha::Fecha(const char* cad){
    int d, m, a;
    if(sscanf(cad, "%d/%d/%d", &d, &m, &a)!=3){
        throw Invalida("Fecha incorrecta");
    }
    else{
        dia_=d;
        mes_=m;
        anno_=a;
        zeroDate(dia_,mes_,anno_);
        CheckDate(dia_,mes_,anno_);
    }    
}

void Fecha::zeroDate(int d, int m, int a){
    if(d==0){
        dia_=now_date().tm_mday;
    }
    if(m==0){
        mes_=now_date().tm_mon+1;
    }
    if(a==0){
        anno_=now_date().tm_year+1900;
    }
   	
}

tm Fecha::now_date(){
    time_t now = time(nullptr);
    tm *time = localtime(&now);
    return *time;
}

Fecha Fecha::sum_days(tm *t1, int n){
    time_t timesince=mktime(t1)+(60*60*24*n);
    t1 = localtime(&timesince);
    return Fecha(t1->tm_mday,t1->tm_mon+1,t1->tm_year+1900);
}   

Fecha Fecha::sub_days(tm *t1, int n){
    time_t timesince=mktime(t1)-(60*60*24*n);
    t1 = localtime(&timesince);
    return Fecha(t1->tm_mday,t1->tm_mon+1,t1->tm_year+1900);
}

Fecha Fecha::operator+(int n) const{
    Fecha tmp = *this;
    tmp+=n;
    return tmp;
}

Fecha Fecha::operator-(int n) const{
    Fecha tmp = *this;
    tmp-=n;
    return tmp;
}

Fecha& Fecha::operator+=(int n){

    tm tmp ={0,0,0,dia_,mes_-1,anno_-1900, 0, 0, 0};
    *this = sum_days(&tmp,n);
    return *this;
}

Fecha& Fecha::operator-=(int n){
    tm tmp ={0,0,0,dia_,mes_-1,anno_-1900, 0, 0, 0};
    *this = sub_days(&tmp,n);
    return *this;
}

Fecha& Fecha::operator++(){
    return *this += 1;
}

Fecha& Fecha::operator--(){
    return *this -= 1;
}


Fecha Fecha:: operator++(int){
    Fecha tmp = *this;
    *this += 1;
    return tmp;
}

Fecha Fecha::operator--(int){
    Fecha tmp = *this;
    *this -= 1;
    return tmp;
}

Fecha::Invalida::Invalida(const char* error){
    this->error_=error;
}

void Fecha::CheckDate(int dia_, int mes_, int anno_){
	{
    static const int dias [] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int esBisiesto = static_cast<int>(anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0));

    if(anno_ > Fecha::AnnoMaximo || anno_ < Fecha::AnnoMinimo)
    {
        throw Invalida("Anno invalido");
    }

    if(mes_ > 12 || mes_ < 1)
    {
        throw Invalida("Mes invalido");
    }

    if(mes_ == 2){
        if(dia_ > dias[mes_] + esBisiesto || dia_ < 1)
        {
            throw Invalida("Dia invalido");
        }
    }
    else{
        if(dia_ > dias[mes_] || dia_ < 1)
        {
            throw Invalida("Dia invalido");
        }
    }

}
}

const char* Fecha::cadena() const{
    const char* m[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
    const char* d[]={"domingo","lunes","martes","miércoles","jueves","viernes","sábado"};

    static char date[40];

    tm tmp={0,0,0,dia_,mes_-1,anno_-1900, 0, 0, 0};
    mktime(&tmp);

    sprintf(date,"%s %d de %s de %d", d[tmp.tm_wday], dia_, m[mes_-1], anno_);
    
    return date;
}

bool operator<(const Fecha &f1, const Fecha &f2){
    bool less=true;
    if(f1.anno_<f2.anno_)
        return less;
    else if(f1.anno_==f2.anno_&&f1.mes_<f2.mes_){
        return less;
    }
    else if(f1.anno_==f2.anno_&&f1.mes_==f2.mes_&&f1.dia_<f2.dia_){
        return less;
    }
    else return !less;
}

bool operator<=(const Fecha &f1, const Fecha &f2){
    bool less_equal=true;
    if(f1.anno_==f2.anno_&&f1.mes_==f2.mes_&&f1.dia_==f2.dia_){
        return less_equal;
    }
    else if(f1.anno_<f2.anno_){
        return less_equal;
    }
    else if(f1.anno_==f2.anno_&&f1.mes_<f2.mes_){
        return less_equal;
    }
    else if(f1.anno_==f2.anno_&&f1.mes_==f2.mes_&&f1.dia_<f2.dia_){
        return less_equal;
    }
    else return !less_equal;
}

bool operator>(const Fecha &f1, const Fecha &f2){
    return !(f1<=f2);
}

bool operator>=(const Fecha &f1, const Fecha &f2){
    return !(f1<f2);
}

bool operator==(const Fecha &f1, const Fecha &f2){
    bool equal=true;
    if(f1.anno_==f2.anno_&&f1.mes_==f2.mes_&&f1.dia_==f2.dia_){
        return equal;
    }
    else return !equal;
}

bool operator!=(const Fecha &f1, const Fecha &f2){
    return !(f1==f2);
}

istream& operator >>(istream& is, Fecha& date){
	char* str = new char[11];
	is.getline(str,11);
	
	try{
		date = Fecha(str);
	}catch(Fecha::Invalida invalid){
		is.setstate(ios_base::failbit);
        delete[]str;
		throw invalid;
	}
    delete[]str;
	return is;
}

ostream& operator <<(ostream& os, const Fecha& date){
	os<<date.cadena();
	return os;
}
