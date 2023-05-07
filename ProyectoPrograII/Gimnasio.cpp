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
	system("cls");
	cout << "Administraci" << char(162) << "n General\\Nombre del Gimnasio\\" << endl << endl;
	cout << "Ingrese el nombre del Gimnasio: ";
	cin.ignore();
	getline(cin, nombre);
	cout << endl << endl;

	system("pause");
}

void Gimnasio::montoMensualidad() {
	system("cls");
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
	
	system("cls");
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
	int opcion, state;
	float dato;
	char sexo;

	do {
		do{
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
		} while (opcion < 1 || opcion > 10);

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
			cout << "\n===============================" << endl;
			cout << "\n     - Activo [1]" << endl;
			cout << "     - Inactivo [2]" << endl;
			cout << "     - Moroso [3]" << endl;
			cout << "\n===============================" << endl;
			cout << "\nIngrese el nuevo estado: ";
			cin >> state;
			deportistas->getClienteEsp(cedula)->setEstado(state);
			cout << endl << endl;
			break;
		case 10:
			break;
		}
	}while (opcion != 10);

	system("pause");
}

void Gimnasio::listadoDeportistas() {
	int opcion;

	do {
		system("cls");
		cout << "Control de Deportistas\\Listado de deportistas\\" << endl << endl;
		cout << "\n----------------------------------------------" << endl;
		cout << "\n1. Listado general" << endl;
		cout << "\n2. Listado de deportistas activos" << endl;
		cout << "\n3. Listado de deportistas inactivos" << endl;
		cout << "\n4. Listado de deportista en morosidad" << endl;
		cout << "\n----------------------------------------------" << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 4);

	system("cls");
	switch (opcion) {
	case 1:
		cout << "Control de Deportistas\\Listado de deportistas\\" << endl << endl;
		cout << *deportistas->getLista() << endl;
		break;
	case 2:
		cout << "Control de Deportistas\\Listado de activos\\" << endl << endl;
		cout << deportistas->Activos() << endl;
		break;
	case 3:
		cout << "Control de Deportistas\\Listado de inactivos\\" << endl << endl;
		cout << deportistas->Inactivos() << endl;
		break;
	case 4:
		cout << "Control de Deportistas\\Listado en estado de morososidad\\" << endl << endl;
		//metodo que lo setea
		cout << deportistas->Morosos() << endl;
		break;
	}
	system("pause");
}

void Gimnasio::detalleDeportista() {
	string cedula;

	system("cls");
	cout << "Control de Deportistas\\Detalle de deportista especifico\\" << endl << endl;
	cout << "-> Digite el ID del deportista: "; 
	cin.ignore();
	getline(cin, cedula);
	cout << endl << endl << *deportistas->getClienteEsp(cedula);

	system("pause");
}

//opcion 3
void Gimnasio::controlCursos(){
	int opcion;

	do {
		system("cls");
		cout << "Control de Cursos" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Ingreso de nuevo curso" << endl;
		cout << "\n2. Reporte de curso especifico" << endl;
		cout << "\n3. Modificacion de curso especifico" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 3);

	system("cls");
	switch (opcion) {
	case 1: ingresoCurso(); break;
	case 2: reporteCurso(); break;
	case 3: modifCurso(); break;
	}
}

void Gimnasio::ingresoCurso() {
	string nombre, codigo, descripcion;
	int nivel, cantGrupos;

	system("cls");
	cout << "Control de Cursos\\Ingreso nuevo curso\\" << endl;
	cout << "\n----------------------------------------------" << endl;
	cout << "\nDigite el nombre del curso: "; 
	cin.get();
	getline(cin,nombre);
	cout << "\nDigite el codigo del curso : "; 
	getline(cin, codigo);
	cout << "\nNiveles de curso: ";
	cout << "Principiante [1] - Intermedio [2] - Avanzado [3]" << endl;
	cout << "\nDigite el nivel del curso: ";
	cin >> nivel;
	cout << "\nCantidad de grupos: "; 
	cin >> cantGrupos;
	cout << "\nDescripcion: "; 
	cin.get();
	getline(cin, descripcion);
	cout << "\n----------------------------------------------" << endl;
	
	Curso* materia = new Curso(nombre, codigo, descripcion, nivel, cantGrupos);
	cursos->agregarCurso(materia);

	system("pause");
}

void Gimnasio::reporteCurso() {
	string codigo;
	system("cls");
	cout << "Control de Cursos\\Reporte de curso especifico\\" << endl << endl;
	cout << "\n-------------------------------------\n" << endl;
	cout << cursos->cursoBasicos() << endl;
	cout << "\nDigite el codigo de curso: "; 
	cin >> codigo;
	
	cout << endl << *cursos->getCursoEsp(codigo) << endl;
	if (!cursos->getLista()->esVacia()) {
		cout << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
	}

	system("pause");
}

void Gimnasio::modifCurso() {
	string codigo, temp;
	int opcion, aux;

	do {
		do {
			system("cls");
			cout << "Control de Cursos\\Modificacion curso especifico\\" << endl << endl;
			cout << "\n----------------------------------------------\n" << endl;
			cout << cursos->cursoBasicos() << endl;
			cout << "Digite el codigo de curso: ";
			cin >> codigo;
		
			cout << "Cual dato desea modificar: " << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "  -> 1. Nombre del curso" << endl;
			cout << "  -> 2. Codigo de curso" << endl;
			cout << "  -> 3. Nivel" << endl;
			cout << "  -> 4. Descripcion" << endl;
			cout << "  -> 5. Cantidad de grupos" << endl;
			cout << "  -> 6. Volver al menu principal" << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "Digite una opcion: "; cin >> opcion;

		} while (opcion < 1 || opcion > 6);


		system("cls");
		switch (opcion) {
		case 1:
			cout << "Control de Cursos\\Modificacion curso especifico\\Nombre" << endl << endl;
			cout << "Nombre actual del curso: " << cursos->getCursoEsp(codigo)->getNombre() << endl;
			cout << "Ingrese el nuevo nombre: ";
			cin.ignore();
			getline(cin, temp);
			cursos->getCursoEsp(codigo)->setNombre(temp);
			cout << endl << endl;
			system("pause");
			break;
		case 2:
			cout << "Control de Cursos\\Modificacion curso especifico\\Codigo" << endl << endl;
			cout << "Codigo actual del curso: " << cursos->getCursoEsp(codigo)->getCodigo() << endl;
			cout << "Ingrese el nuevo codigo: ";
			cin.ignore();
			getline(cin, temp);
			cursos->getCursoEsp(codigo)->setNombre(temp);
			cout << endl << endl;
			system("pause");
			break;
		case 3:
			cout << "Control de Cursos\\Modificacion curso especifico\\Nivel" << endl << endl;
			cout << "Nivel actual del curso: " << cursos->getCursoEsp(codigo)->getNivel() << endl;
			cout << "\n===============================" << endl;
			cout << "\n     - Principiante [1]" << endl;
			cout << "     - Intermedio [2]" << endl;
			cout << "     - Avanzado [3]" << endl;
			cout << "\n===============================" << endl;
			cout << "Ingrese el nuevo nivel: ";
			cin >> aux;
			cursos->getCursoEsp(codigo)->setNivel(aux);
			cout << endl << endl;
			system("pause");
			break;
		case 4:
			cout << "Control de Cursos\\Modificacion curso especifico\\Descripcion" << endl << endl;
			cout << "Descripcion actual del curso: " << cursos->getCursoEsp(codigo)->getDescripcion() << endl;
			cout << "Ingrese la nueva descripcion: ";
			cin.ignore();
			getline(cin, temp);
			cursos->getCursoEsp(codigo)->setDescripcion(temp);
			cout << endl << endl;
			system("pause");
			break;
		case 5:
			cout << "Control de Cursos\\Modificacion curso especifico\\Cantidad Grupos" << endl << endl;
			cout << "Cantidad de grupos actual del curso: " << cursos->getCursoEsp(codigo)->getCantGrupo() << endl;
			cout << "Ingrese la nueva cantidad de grupos: ";
			cin >> aux;
			cursos->getCursoEsp(codigo)->setCantGrupo(aux);
			cout << endl << endl;
			system("pause");
			break;
		case 6:
			break;
		}
	} while (opcion != 6);

}

//opcion 4
void Gimnasio::controlGrupos() {
	int opcion;

	do {
		system("cls");
		cout << "Control de Grupos" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Ingreso nuevo grupo" << endl;
		cout << "\n2. Modificacion de grupo especifico" << endl;
		cout << "\n3. Matricula en grupo especifico" << endl;
		cout << "\n4. Reporte de grupo especifico" << endl;
		cout << "\n5. Reporte deportistas matriculados en grupo" << endl;
		cout << "\n6. Cancelacion de matricula en grupo" << endl << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;

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

void Gimnasio::ingresoGrupo() {
	string codigo, id, nombreIns;
	int cupoMax, d, m, a, horaI, minI, horaF, minF;
	char dia;
	cout << "Control de Grupos\\Ingreso nuevo grupo\\" << endl;
	cout << cursos->cursoBasicos() << endl;
	cout << "Digite el codigo de curso: ";
	cin.get();
	getline(cin, codigo);
	cout << "\n\n" << *cursos->getCursoEsp(codigo) << endl;

	cout << "\nDigite el nombre del instructor: ";
	getline(cin, nombreIns);
	cout << "\nDigite el ID del instructor: ";
	getline(cin, id);
	cout << "\nDigite el cupo m" << char(160) << "ximo: ";
	cin >> cupoMax;
	cout << "\nFecha de inicio (DD/MM/AAAA): ";
	cout << "\nD" << char(161) << "a: ";
	cin >> d;
	cout << "Mes: ";
	cin >> m;
	cout << "A" << char(164) << "o: ";
	cin >> a;
	cout << "\n-------------- Horario -----------------" << endl;
	cout << "\nDigite el dia de la semana (L-K-M-J-V-S-D): ";
	cin >> dia;
	cout << "\nDigite la hora de inicio (hora militar): " << endl;
	cout << "\nHora (1-24): ";
	cin >> horaI;
	cout << "\nMinutos (0-59): ";
	cin >> minI;
	cout << "\nDigite la hora de finalizacion (hora militar): " << endl;
	cout << "\nHora (1-24): ";
	cin >> horaF;
	cout << "\nMinutos (0-59): ";
	cin >> minF;
	cout << endl << endl;

	Fecha* inicio = new Fecha(d, m, a);
	Grupo* nuevo = new Grupo(dia, grupos->getLista()->getSize() + 1, cupoMax, nombreIns, id, inicio);
	
	cursos->getCursoEsp(codigo)->nuevoGrupo(nuevo);

	system("pause");
}

void Gimnasio::modifGrupo() {
	string codigo, temp;
	int opcion,num, aux;

	do {
		do {
			system("cls");
			cout << "Control de Grupos\\Modificacion Grupo especifico\\" << endl << endl;
			cout << cursos->cursoBasicos() << endl;
			cout << "Digite el codigo de curso: ";
			cin >> codigo;
			cout << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
			cout << "Cual dato desea modificar: " << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "  -> 1. Datos del instructor" << endl;
			cout << "  -> 2. Cupo máximo" << endl;
			cout << "  -> 3. Fecha de inicio" << endl;
			cout << "  -> 4. Dia de la semana" << endl;
			cout << "  -> 5. Horario de curso" << endl;
			cout << "  -> 6. Volver al menu principal" << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "Digite una opcion: "; cin >> opcion;

		} while (opcion < 1 || opcion > 6);


		/*system("cls");
		switch (opcion) {
		case 1:
			cout << "Control de Grupos\\Modificacion Grupo especifico\\Datos instructor" << endl << endl;
			cout << "Nombre actual del curso: " << grupos->getGrupoEsp() << endl;
			cout << "ID actual del curso: " << grupos->getGrupoEsp() << endl;
			cout << "Ingrese el nuevo nombre: ";
			cin.ignore();
			getline(cin, temp);
			grupos->getGrupoEsp(1);
			cout << endl << endl;
			system("pause");
			break;
		case 2:
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			break;
		case 6:
			break;
		}*/
	} while (opcion != 6);

}

void Gimnasio::matriculaGrupo() {
	string cedula, codigo;
	int numGrupo;
	cout << "Control de Grupos\\Matricula de grupo espec" << char(161) << "fico\\" << endl << endl;
	cout << "Digite la cedula del deportista: ";
	cin.ignore();
	getline(cin, cedula);
	cout << "\nDigite el c" << char(163) << "digo del curso: ";
	cin.ignore();
	getline(cin, codigo);

	cout << "\n\nPara el curso selecionado existen los siguientes grupos disponibles: " << endl;
	cout << "\n----------------------------------------------\n" << endl;

}

void Gimnasio::reporteGrupo() {

}

void Gimnasio::reporteDepMat(){
	
}

void Gimnasio::cancelacionMatricula()
{
}

//opcion 5
void Gimnasio::registroPago(){
	cout << "Control de Pagos\\Registro de nuevo pago\\" << endl;
	cout << "\nFecha actual: " << *currentDate << endl;
}

void Gimnasio::reportePagos()
{
}

void Gimnasio::controlPagos() {
	int opcion;

	do {
		system("cls");
		cout << "Control de Pagos" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Registro de nuevo pago" << endl;
		cout << "\n2. Reporte de pagos por deportista" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._\n" << endl;
		cout << "\nDigite una opcion: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 2);

	system("cls");
	switch (opcion) {
	case 1: registroPago(); break;
	case 2: reportePagos(); break;
	}
}

//opcion 6
void Gimnasio::guardarArchSalir()
{
}
