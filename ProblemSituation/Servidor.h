#include <iostream>

using namespace std;

class Servidor{
	private:
		string mes, hora, ip, errorReason;
		int dia;

	public:
		Servidor(string mes = "-", int dia = 0, string hora = "-", string ip = "-", string errorReason = "-"){
			this->mes = mes;
			this->dia = dia;
			this->hora = hora;
			this->ip = ip;
			this->errorReason = errorReason;
		}
		friend ostream & operator<<(ostream &salida, const Servidor & Servidor);
};

ostream & operator<<(ostream &salida, const Servidor & Servidor)
{
    salida << Servidor.mes << " : " << Servidor.dia << " : " << Servidor.hora << " : " << Servidor.ip << " : " << Servidor.errorReason << " : ";
    return salida;
}