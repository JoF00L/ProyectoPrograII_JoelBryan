#include "Gimnasio.h"

Gimnasio::Gimnasio()
{
	nombre = " ";
	montoMensual = 0;
	currentDate = new Fecha;
	deportistas = new ListaClientes;
	cursos = new ListaCursos;
	grupos = new ListaGrupos;
}

Gimnasio::~Gimnasio() { delete currentDate, deportistas, cursos, grupos; }

void Gimnasio::menu(){
	
	int opcion;

	cout << *currentDate << endl;
	cout << "\nBienvenido al Gimnasio " << nombre << endl << endl; 
	system("pause");

	do{
		do {
			system("cls");
			cout << "\t     Menu Principal" << endl;
			cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
			cout << "\n1. Administraci" << char(162) << "n General" << endl;
			cout << "\n2. Control de Deportistas" << endl;
			cout << "\n3. Control de Cursos" << endl;
			cout << "\n4. Control de Grupos" << endl;
			cout << "\n5. Control Pagos" << endl;
			cout << "\n6. Guardar en Archivos y salir" << endl;
			cout << "\n_._._._._._._._._._._._._._._._._._._._\n" << endl;
			cout << "\nDigite una opcion: ";
			//AGREGAR EXCEPCION
			cin >> opcion;
		} while (opcion < 1 || opcion > 6);

		system("cls");
		switch (opcion) {
		case 1: adminGeneral(); break;
		case 2: controlDeportistas(); break;
		case 3: controlCursos(); break;
		case 4: controlGrupos(); break;
		case 5: controlPagos(); break;
		case 6: guardarArchSalir(); break;
		}
	} while (opcion != 6);
	
}

//opcion 1
void Gimnasio::adminGeneral(){
	int opcion;

	do {
		system("cls");
		cout << "Administraci" << char(162) << "n General" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Nombre del Gimnasio" << endl;
		cout << "\n2. Monto de mensualidad" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._\n" << endl;
		cout << "\nDigite una opcion: "; 
		cin >> opcion;
	} while (opcion < 1 || opcion > 2);

	system("cls");
	switch (opcion) {
	case 1: nombreGim(); break;
	case 2: montoMensualidad(); break;
	}
}

void Gimnasio::nombreGim() {
	cout << "Administraci" << char(162) << "n General\\Nombre del Gimnasio\\" << endl << endl;
	cout << "Ingrese el nombre del Gimnasio: ";
	cin.ignore();
	getline(cin, nombre);
	cout << endl << endl;

	system("pause");
}

void Gimnasio::montoMensualidad() {
	cout << "Administraci" << char(162) << "n General\\Monto de mensualidad\\" << endl << endl;
	cout << "Ingrese el monto de mensualidad: ";
	//Hacer excepcion 
	cin >> montoMensual; 
	cout << endl << endl;

	system("pause");
}

//opcion 2
void Gimnasio::controlDeportistas(){
	int opcion;

	do {
		system("cls");
		cout << "Control de Deportistas" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Ingreso nuevo deportista" << endl;
		cout << "\n2. Modificacion de deportista" << endl;
		cout << "\n3. Listado de deportistas" << endl;
		cout << "\n4. Detalle de deportista especifico" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\nDigite una opcion: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 4);

	system("cls");
	switch (opcion) {
	case 1: ingresoDeportista(); break;
	case 2: modifDeportista(); break;
	case 3: listadoDeportistas(); break;
	case 4: detalleDeportista(); break;
	}
}

void Gimnasio::ingresoDeportista() {
	string name, cedula, telefono;
	int d = 0, m = 0, a = 0;
	float estatura, peso, grasa, masa;
	char sexo;
	
	cout << "Control de Deportistas\\Ingreso nuevo deportista\\" << endl;
	cout << "\nDatos generales: " << endl << endl;
	cout << "-> Nombre: ";
	cin.ignore();
	getline(cin, name);
	cout << "-> ID: "; 
	getline(cin, cedula);
	cout << "-> Telefono: "; 
	getline(cin, telefono);
	cout << "-> Fecha de nacimiento (DD/MM/AAAA) ";
	cout << "\nD" << char(161) << "a: ";
	cin >> d; 
	cout << "Mes: "; 
	cin >> m; 
	cout << "A" << char(164) << "o: "; 
	cin >> a;
	cout << "-> Sexo (M o F): "; 
	cin >> sexo;
	cout << "\n--------------------------------------" << endl;
	cout << "\nDatos biometricos basicos (0.00): " << endl;
	cout << "-> Estatura: "; 
	cin >> estatura;
	cout << "-> Peso: ";
	cin >> peso;
	cout << "-> Grasa Corporal: "; 
	cin >> grasa;
	cout << "-> Masa Muscular: "; 
	cin >> masa;
	cout << endl << endl;

	Fecha* date = new Fecha(d, m, a);
	Biometricos* bioDato = new Biometricos(peso, estatura, masa, grasa);
	Cliente* nuevo = new Cliente(name, cedula, telefono, date, sexo, bioDato);

	cout << *nuevo << endl << endl;
	deportistas->agregarCliente(nuevo);

	system("pause");
}

void Gimnasio::modifDeportista() {
	string cedula, temp;
	int opcion;
	float dato;
	char sexo;
	bool estado;

	do {
		system("cls");
		cout << "Control de Deportistas\\Modificacion deportista\\" << endl << endl;
		cout << "Digite la cedula del deportista: ";
		cin >> cedula;
		system("cls");
		// HACER condicion si la lista esta vacia para que ni siquiera lo deje entrar
		cout << "Que dato desea modificar: " << endl;
		cout << "\n----------------------------------------------" << endl;
		cout << "\n  ->  1. Nombre" << endl;
		cout << "\n  ->  2. Telefono" << endl;
		cout << "\n  ->  3. Fecha de nacimiento" << endl;
		cout << "\n  ->  4. Sexo" << endl;
		cout << "\n  ->  5. Estatura" << endl;
		cout << "\n  ->  6. Peso" << endl;
		cout << "\n  ->  7. Porcentaje de grasa corporal" << endl;
		cout << "\n  ->  8. Porcentaje de masa muscular" << endl;
		cout << "\n  ->  9. Estado" << endl;
		cout << "\n  -> 10. Volver al menu principal" << endl;
		cout << "\n----------------------------------------------" << endl;
		cout << "\nDigite una opcion: ";
		cin >> opcion;

		system("cls");
		switch (opcion) {
		case 1:
			cout << "Control de Deportistas\\Modificacion deportista\\Nombre" << endl << endl;
			cout << "Nombre actual del deportista: " << deportistas->getClienteEsp(cedula)->getNombre() << endl;
			cout << "Ingrese el nuevo nombre: ";
			cin.ignore();
			getline(cin, temp);
			deportistas->getClienteEsp(cedula)->setNombre(temp);
			cout << endl << endl;
			break;
		case 2:
			cout << "Control de Deportistas\\Modificacion deportista\\Telefono" << endl << endl;
			cout << "Telefono actual del deportista: " << deportistas->getClienteEsp(cedula)->getTelefono() << endl;
			cout << "Ingrese el nuevo telefono: ";
			cin.ignore();
			getline(cin, temp);
			deportistas->getClienteEsp(cedula)->setTelefono(temp);
			cout << endl << endl;
			break; 
		case 3:
			{Fecha* date = new Fecha;
			int d, m, a;
			cout << "Control de Deportistas\\Modificacion deportista\\Fecha" << endl << endl;
			cout << "Fecha de nacimiento actual del deportista: " << *deportistas->getClienteEsp(cedula)->getFechaNacimiento() << endl;
			cout << "Ingrese la nueva fecha de nacimiento (DD/MM/AAAA) ";
			cout << "\nD" << char(161) << "a: ";
			cin >> d;
			cout << "Mes: ";
			cin >> m;
			cout << "A" << char(164) << "o: ";
			cin >> a;
			date->setDia(d);
			date->setMes(m);
			date->setAnio(a);
			deportistas->getClienteEsp(cedula)->setFechaNacimiento(date);
			cout << endl << endl;
			break;}
		case 4:
			cout << "Control de Deportistas\\Modificacion deportista\\Sexo" << endl << endl;
			cout << "Sexo actual del deportista: " << deportistas->getClienteEsp(cedula)->getSexo() << endl;
			cout << "Ingrese el nuevo sexo: ";
			cin >> sexo;
			deportistas->getClienteEsp(cedula)->setSexo(sexo);
			cout << endl << endl;
			break;
		case 5:
			cout << "Control de Deportistas\\Modificacion deportista\\Estatura" << endl << endl;
			cout << "Estatura actual del deportista: " << deportistas->getClienteEsp(cedula)->getAltura() << endl;
			cout << "Ingrese la nueva estatura: ";
			cin >> dato;
			deportistas->getClienteEsp(cedula)->setAltura(dato);
			cout << endl << endl;
			break;
		case 6:
			cout << "Control de Deportistas\\Modificacion deportista\\Deportista" << endl << endl;
			cout << "Peso actual del deportista: " << deportistas->getClienteEsp(cedula)->getPeso() << endl;
			cout << "Ingrese el nuevo peso: ";
			cin >> dato;
			deportistas->getClienteEsp(cedula)->setPeso(dato);
			break;
		case 7:
			cout << "Control de Deportistas\\Modificacion deportista\\Grasa corporal" << endl << endl;
			cout << "Grasa corporal actual del deportista: " << deportistas->getClienteEsp(cedula)->getGrasaCorporal() << endl;
			cout << "Ingrese la nueva grasa corporal: ";
			cin >> dato;
			deportistas->getClienteEsp(cedula)->setGrasaCorporal(dato);
			cout << endl << endl;
			break;
		case 8:
			cout << "Control de Deportistas\\Modificacion deportista\\Masa muscular" << endl << endl;
			cout << "Masa muscular actual del deportista: " << deportistas->getClienteEsp(cedula)->getMasaMuscular() << endl;
			cout << "Ingrese el nuevo telefono: ";
			cin >> dato;
			deportistas->getClienteEsp(cedula)->setMasaMuscular(dato);
			cout << endl << endl;
			break;
		case 9:
			cout << "Control de Deportistas\\Modificacion deportista\\Estado" << endl << endl;
			cout << "Estado actual del deportista: " << deportistas->getClienteEsp(cedula)->getEstado() << endl;
			cout << "Ingrese el nuevo estado: ";
			cin.ignore();
			getline(cin, temp);
			deportistas->getClienteEsp(cedula)->setEstado(temp);
			cout << endl << endl;
			break;
		case 10:
			break;
		}
	} while (opcion < 1 || opcion > 10);

	system("pause");
}

void Gimnasio::listadoDeportistas() {
	int opcion;

	do {
		system("cls");
		cout << "Control de Deportistas\\Listado de deportistas\\" << endl << endl;
		cout << "\n1. Listado general" << endl;
		cout << "\n2. Listado de deportistas activos" << endl;
		cout << "\n3. Listado de deportistas inactivos" << endl;
		cout << "\n4. Listado de deportista en morosidad" << endl << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
		system("cls");
	} while (opcion < 1 || opcion > 4);

	switch (opcion) {
	case 1:
		cout << "Control de Deportistas\\Listado de deportistas\\" << endl << endl;
		cout << *deportistas->getLista() << endl;
		break;
	case 2:
		cout << "Control de Deportistas\\Listado de activos\\" << endl << endl;
		break;
	case 3:
		cout << "Control de Deportistas\\Listado de inactivos\\" << endl << endl;
		break;
	}
	system("pause");
}

void Gimnasio::controlCursos(){
	int opcion;

	do {
		system("cls");
		cout << "\t( 3 ) Control de Cursos" << endl << endl;
		cout << "\n1. Ingreso de nuevo curso" << endl;
		cout << "\n2. Repote de curso especifico" << endl;
		cout << "\n3. Modificacion de curso especifico" << endl << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 3);

	system("cls");
	switch (opcion) {
	case 1: ingresoCurso(); break;
	case 2: reporteCurso(); break;
	case 3: modifCurso(); break;
	}
}

void Gimnasio::controlGrupos(){
	int opcion;

	do {
		system("cls");
		cout << "\t( 4 ) Control de Grupos" << endl << endl;
		cout << "\n1. Ingreso nuevo grupo" << endl;
		cout << "\n2. Modificacion de grupo especifico" << endl;
		cout << "\n3. Matricula en grupo especifico" << endl;
		cout << "\n4. Reporte de grupo especifico" << endl;
		cout << "\n5. Reporte deportistas matriculados en grupo" << endl;
		cout << "\n6. Cancelacion de matricula en grupo" << endl << endl;
		
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 6);


	system("cls");
	switch (opcion) {
	case 1: ingresoGrupo(); break;
	case 2:	modifGrupo(); break;
	case 3: matriculaGrupo(); break;
	case 4: reporteGrupo(); break;
	case 5: reporteDepMat(); break;
	case 6: cancelacionMatricula(); break;
	}
}

void Gimnasio::controlPagos(){

}

void Gimnasio::guardarArchSalir()
{
}

void Gimnasio::detalleDeportista(){
	int cedula;
	cout << "<( 2 ) Control de Deportistas> <( 4 ) Detalle de deportista especifico>" << endl << endl;
	cout << "\tDigite el ID del deportista: "; cin >> cedula;
	//mostrar toString del deportista especifico
}

void Gimnasio::ingresoCurso(){
	string nombre, codigo, descripcion;
	int nivel, cupoMax, cantGrupos;

	cout << "<( 3 ) Control de Cursos> <( 1 ) Ingreso nuevo curso>" << endl << endl;
	cout << "\tDigite el nombre del curso: "; cin >> nombre;
	cout << "\n\tDigite el codigo del curso : "; cin >> codigo;
	cout << "\n\tDigite el nivel: " << endl;
	do {
		cout << "\t[1] Principiantes - [2] Intermedio - [3] Avanzado" << endl;
		cin >> nivel;
	} while (nivel < 1 || nivel > 3);
	cout << "\n\tCantidad de grupos: "; cin >> cantGrupos;
	cout << "\n\tDescripcion: "; cin >> descripcion;
	cout << endl << endl;

	system("pause");
}

void Gimnasio::reporteCurso(){
	string codigo;
	cout << "<( 3 ) Control de Cursos> <( 2 ) Reporte de curso especifico>" << endl << endl;
	cout << "\tListado de cursos: " << endl << endl;
	//mostramos los cursos
	cout << "\tDigite el codigo de curso: "; cin >> codigo;
	//encontramos curso e indicamos que curso es
	//toString del curso
	//hay que mostrar el numero de grupo, cupo y cantidad
}

void Gimnasio::modifCurso(){
	string codigo;
	int opcion;

	cout << "<( 3 ) Control de Cursos> <( 3 ) Modificacion de curso especifico>" << endl << endl;
	cout << "\tDigite el codigo de curso: "; cin >> codigo;
	cout << "Cual dato desea modificar: " << endl << endl;
	do {
		cout << "\t\t1. Nombre del curso" << endl;
		cout << "\t\t2. Codigo de curso" << endl;
		cout << "\t\t3. Nivel" << endl;
		cout << "\t\t4. Descripcion" << endl;
		cout << "\t\t5. Cantidad de grupos" << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 5);

}

void Gimnasio::ingresoGrupo(){
	string codigo, id, nombre;
	int cupoMax,d, m, a, semanas;
	char dia;
	cout << "<( 4 ) Control de Grupos> <( 1 ) Ingreso nuevo grupo>" << endl << endl;
	cout << "\tListado de cursos: " << endl << endl;
	//mostramos los cursos
	cout << "\tDigite el codigo de curso: "; cin >> codigo;
	//encontramos curso e indicamos que curso es

	cout << "\n\tDigite el ID del instructor: "; cin >> id;
	cout << "\n\tDigite el nombre del instructor: "; cin >>nombre;
	cout << "\n\tDigite el ID del instructor: "; cin >> id;
	cout << "\n\tDigite el cupo maximo: "; cin >> cupoMax;
	cout << "\n\tFecha de inicio (DD/MM/AAAA): ";
	cin >> d; cout << " / "; cin >> m; cout << " / "; cin >> a;
	Fecha* inicio = new Fecha(d, m, a);
	cout << "\n\tSemanas de duracion: "; cin >> semanas;
	cout << "\n\tHorario: " << endl;


	cout << endl << endl;

	system("pause");
	delete inicio;
}

void Gimnasio::modifGrupo()
{
}

void Gimnasio::matriculaGrupo()
{
}

void Gimnasio::reporteGrupo()
{
}

void Gimnasio::reporteDepMat()
{
}

void Gimnasio::cancelacionMatricula()
{
}
