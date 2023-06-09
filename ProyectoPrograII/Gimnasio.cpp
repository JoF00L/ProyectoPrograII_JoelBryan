#include "Gimnasio.h"
#include "Excepciones.h"

Gimnasio::Gimnasio()
{
	nombre = " ";
	montoMensual = 0;
	currentDate = new Fecha;
	deportistas = new ListaClientes;
	cursos = new ListaCursos;
}

Gimnasio::~Gimnasio() { delete currentDate, deportistas, cursos; }

void Gimnasio::setNombre(string nom){
	nombre = nom;
}

void Gimnasio::setMonto(int monto){
	montoMensual = monto;
}

void Gimnasio::menu(){
	bool yes = true;
	int opcion;
	ManejoArchivos* m = new ManejoArchivos;
	cout << m->Logo() << endl;
	system("pause");
	system("cls");

	cout << *currentDate << endl;
	cout << "\nBienvenido al Gimnasio -[ " << nombre << " ]-" << endl << endl;
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
			cin >> opcion;
			try {
				//if (!cin >> opcion) {
				//	throw invalid_argument("Solo se pueden ingresar numeros!!!");
				//}
				IntOutRange(1, 6, opcion, yes);
			}
			catch (invalid_argument &e) {
				system("cls");
				cout << e.what() << "\n" << endl;
				system("pause");
				yes = false;
			}
		} while ((opcion < 1 || opcion > 6) && yes == false);

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
	bool yes = true;
	do {
		system("cls");
		cout << "Administraci" << char(162) << "n General" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Nombre del Gimnasio" << endl;
		cout << "\n2. Monto de mensualidad" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._\n" << endl;
		cout << "\nDigite una opcion: "; 
		cin >> opcion;
		try {
			IntOutRange(1, 2, opcion, yes);
		}
		catch (invalid_argument &e) {
			system("cls");
			cout << e.what() << endl;
			yes = false;
			system("pause");
		}
	} while ((opcion < 1 || opcion > 2) && yes == false);

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
	bool pass = true;
	do {
		system("cls");
		cout << "Administraci" << char(162) << "n General\\Monto de mensualidad\\" << endl << endl;
		cout << "Ingrese el monto de mensualidad: ";

		//Hacer excepcion de CARACTER y STRING
		try {
			cin >> montoMensual;
			intNegative(montoMensual);
		}
		catch (invalid_argument& e) {
			cout << e.what() << endl << endl;
			pass = false;
		}
		if (montoMensual) {
			pass = true;
		}
	} while (!pass);

	system("pause");
}

//opcion 2
void Gimnasio::controlDeportistas(){
	int opcion;
	bool yes = true;

	do {
		system("cls");
		cout << "Control de Deportistas" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Ingreso nuevo deportista" << endl;
		cout << "\n2. Modificacion de deportista" << endl;
		cout << "\n3. Listado de deportistas" << endl;
		cout << "\n4. Detalle de deportista espec" << char(161) << "fico" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\nDigite una opcion: ";
		cin >> opcion;
		try {
			IntOutRange(1, 4, opcion, yes);
		}
		catch (invalid_argument &e) {
			system("cls");
			cout << e.what() << endl << endl;
			yes = false;
			system("pause");
		}
	} while ((opcion < 1 || opcion > 4 && !yes));

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
	bool pass = true;
	
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
	try {
		intNegative(d);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "Mes: "; 
	cin >> m; 
	try {
		intNegative(m);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "A" << char(164) << "o: "; 
	cin >> a;
	try {
		intNegative(a);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "-> Sexo (M o F): "; 
	cin >> sexo;
	cout << "\n--------------------------------------" << endl;
	cout << "\nDatos biometricos basicos (0.00): " << endl;
	cout << "-> Estatura: "; 
	cin >> estatura;
	try {
		intNegative(estatura);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "-> Peso: ";
	cin >> peso;
	try {
		intNegative(peso);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "-> Grasa Corporal: "; 
	cin >> grasa;
	try {
		intNegative(grasa);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "-> Masa Muscular: "; 
	cin >> masa;
	try {
		intNegative(masa);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << endl << endl;
	
	if (pass) {
		Fecha* date = new Fecha(d, m, a);
		Biometricos* bioDato = new Biometricos(peso, estatura, masa, grasa);
		Cliente* nuevo = new Cliente(name, cedula, telefono, date, sexo, bioDato);
		Pago* ingreso = new Pago(montoMensual);
		
		nuevo->getListaPagos()->nuevoPago(ingreso);
		cout << *nuevo;
		deportistas->agregarCliente(nuevo);
	}

	cout << endl << endl;
	system("pause");
}

void Gimnasio::modifDeportista() {
	string cedula, temp;
	int opcion, state;
	float dato;
	char sexo;
	bool yes = true;

	do {
		do{
			system("cls");
			cout << "Control de Deportistas\\Modificacion deportista\\" << endl << endl;
			cout << "Digite el ID del deportista: ";
			cin >> cedula;
			try {
				if (deportistas->getLista()->esVacia()) {
					throw invalid_argument("Lista Vacia!!!");
				}
				else {
					try {
						deportistas->getClienteEsp(cedula);
					}
					catch (invalid_argument& e) {
						system("cls");
						cout << e.what() << endl << endl;
						system("pause");
						return;
					}
				}
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
			try {
				cout << endl << endl << *deportistas->getClienteEsp(cedula);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl << endl;
			}
			system("cls");
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
			try {
				IntOutRange(1, 10, opcion, yes);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				yes = false;
				system("pause");
			}
		} while ((opcion < 1 || opcion > 10 && !yes));

		system("cls");
		switch (opcion) {
		case 1:
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Nombre" << endl << endl;
			cout << "Nombre actual del deportista: " << deportistas->getClienteEsp(cedula)->getNombre() << endl;
			cout << "Ingrese el nuevo nombre: ";
			cin.ignore();
			getline(cin, temp);
			deportistas->getClienteEsp(cedula)->setNombre(temp);
			cout << endl << endl;
			break;
		case 2:
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Telefono" << endl << endl;
			cout << "Telefono actual del deportista: " << deportistas->getClienteEsp(cedula)->getTelefono() << endl;
			cout << "Ingrese el nuevo telefono: ";
			cin.ignore();
			getline(cin, temp);
			deportistas->getClienteEsp(cedula)->setTelefono(temp);
			cout << endl << endl;
			break; 
		case 3:
		{
			int d, m, a;
			bool yes = true;
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Fecha" << endl << endl;
			cout << "Fecha de nacimiento actual del deportista: " << *deportistas->getClienteEsp(cedula)->getFechaNacimiento() << endl;
			cout << "Ingrese la nueva fecha de nacimiento (DD/MM/AAAA): " << endl;
			cout << "\n- Dia: "; cin >> d;
			cout << "\n- Mes: "; cin >> m;
			cout << "\n- A" << char(164) << "o: "; cin >> a;
			try {
				IntOutRange(0, 31, d, yes);
				IntOutRange(0, 12, m, yes);
				intNegative(a);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl << endl;
				system("pause");
				break;
			}
			if (yes) {
				Fecha* date = new Fecha(d, m, a);
				deportistas->getClienteEsp(cedula)->setFechaNacimiento(date);
			}
			cout << endl << endl;
			
			break;
		}
		case 4:
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Sexo" << endl << endl;
			cout << "Sexo actual del deportista: " << deportistas->getClienteEsp(cedula)->getSexo() << endl;
			cout << "Ingrese el nuevo sexo: ";
			cin >> sexo;
			deportistas->getClienteEsp(cedula)->setSexo(sexo);
			cout << endl << endl;
			break;
		case 5:
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Estatura" << endl << endl;
			cout << "Estatura actual del deportista: " << deportistas->getClienteEsp(cedula)->getAltura() << endl;
			cout << "Ingrese la nueva estatura: ";
			cin >> dato;
			try {
				intNegative(dato);
			}
			catch(invalid_argument& e){
				cout << e.what() << endl << endl;
				system("pause");
				yes = false;
				system("cls");
			}
			if (yes) {
				deportistas->getClienteEsp(cedula)->setAltura(dato);
			}
			cout << endl << endl;
			break;

		case 6:
			system("cls");
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Deportista" << endl << endl;
			cout << "Peso actual del deportista: " << deportistas->getClienteEsp(cedula)->getPeso() << endl;
			cout << "Ingrese el nuevo peso: ";
			cin >> dato;
			try {
				intNegative(dato);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl << endl;
				system("pause");
				yes = false;
				system("cls");
			}
			if (dato > 0) {
				deportistas->getClienteEsp(cedula)->setPeso(dato);
			}
			cout << endl << endl;
			break;

		case 7:
			system("cls");
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Grasa corporal" << endl << endl;
			cout << "Grasa corporal actual del deportista: " << deportistas->getClienteEsp(cedula)->getGrasaCorporal() << endl;
			cout << "Ingrese la nueva grasa corporal: ";
			cin >> dato;
			try {
				intNegative(dato);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl << endl;
				system("pause");
				yes = false;
				system("cls");
			}
			if (dato > 0) {
				deportistas->getClienteEsp(cedula)->setGrasaCorporal(dato);
			}
			cout << endl << endl;
			break;
		case 8:
			system("cls");
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Masa muscular" << endl << endl;
			cout << "Masa muscular actual del deportista: " << deportistas->getClienteEsp(cedula)->getMasaMuscular() << endl;
			cout << "Ingrese el nuevo telefono: ";
			cin >> dato;
			try {
				intNegative(dato);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl << endl;
				system("pause");
				yes = false;
				system("cls");
			}
			if (dato > 0) {
				deportistas->getClienteEsp(cedula)->setMasaMuscular(dato);
			}
			cout << endl << endl;
			break;
		case 9:
			cout << "Control de Deportistas\\Modificaci" << char(162) << "n deportista\\Estado" << endl << endl;
			cout << "Estado actual del deportista: " << deportistas->getClienteEsp(cedula)->getEstado() << endl;
			cout << "\n===============================" << endl;
			cout << "\n     - Activo [1]" << endl;
			cout << "     - Inactivo [2]" << endl;
			cout << "     - Moroso [3]" << endl;
			cout << "\n===============================" << endl;
			cout << "\nIngrese el nuevo estado: ";
			cin >> state; 
			try {
				IntOutRange(1, 10, state, yes);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				yes = false;
				system("pause");
				}
			if (yes) {
				deportistas->getClienteEsp(cedula)->setEstado(state);
			}
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

	try {
		if (deportistas->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
	}
	catch(invalid_argument &e){
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}

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
		deportistas->setMorosos();
		cout << deportistas->Morosos() << endl;
		break;
	}
	system("pause");
}// excLst

void Gimnasio::detalleDeportista() {
	string cedula;

	system("cls");
	cout << "Control de Deportistas\\Detalle de deportista espec" << char(161) << "fico\\" << endl << endl;
	cout << "-> Digite el ID del deportista: "; 
	cin.ignore();
	getline(cin, cedula);
	try {
		if (deportistas->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				deportistas->getClienteEsp(cedula);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	try {
		cout << endl << endl << *deportistas->getClienteEsp(cedula);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
	}
	system("pause");
} // excLst

//opcion 3
void Gimnasio::controlCursos(){
	int opcion;
	bool pass = true;
	do {
		system("cls");
		cout << "Control de Cursos" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Ingreso de nuevo curso" << endl;
		cout << "\n2. Reporte de curso espec" << char(161) << "fico" << endl;
		cout << "\n3. Modificaci" << char(162) << "n de curso espec" << char(161) << "fico" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
		try {
			IntOutRange(1, 3, opcion, pass);
		}
		catch (invalid_argument& e) {
			system("cls");
			cout << e.what() << endl << endl;
			pass = false;
			system("pause");
		}
	} while ((opcion < 1 || opcion > 3 && !pass));
	
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
	bool pass = true;

	system("cls");
	cout << "Control de Cursos\\Ingreso nuevo curso\\" << endl;
	cout << "\n----------------------------------------------" << endl;
	cout << "\nDigite el nombre del curso: "; 
	cin.get();
	getline(cin,nombre);
	cout << "\nDigite el codigo del curso: "; 
	getline(cin, codigo);
	cout << "\nNiveles de curso: ";
	cout << "Principiante [1] - Intermedio [2] - Avanzado [3]" << endl;
	cout << "\nDigite el nivel del curso: ";
	cin >> nivel;
	try {
		IntOutRange(1, 3, nivel, pass);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "\nCantidad de grupos: "; 
	cin >> cantGrupos;
	try {
		intNegative(cantGrupos);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		pass = false;
		system("pause");
		return;
	}
	cout << "\nDescripcion: "; 
	cin.get();
	getline(cin, descripcion);
	cout << "\n----------------------------------------------" << endl;
	
	if (pass) {
		Curso* materia = new Curso(nombre, codigo, descripcion, nivel, cantGrupos);
		cursos->agregarCurso(materia);
	}
	
	system("pause");
}

void Gimnasio::reporteCurso() {
	string codigo;
	system("cls");
	cout << "Control de Cursos\\Reporte de curso espec" << char(161) << "fico\\" << endl << endl;
	cout << "\n-------------------------------------\n" << endl;
	cout << cursos->cursoBasicos() << endl;
	cout << "\nDigite el codigo de curso: "; 
	cin >> codigo;
	try {
		if (cursos->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				cursos->getCursoEsp(codigo);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	try {
		cout << endl << endl << *cursos->getCursoEsp(codigo);
		cout << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
	}

	system("pause");
}

void Gimnasio::modifCurso() {
	string codigo, temp;
	int opcion, aux;
	bool yes = true;
	do {
		do {
			system("cls");
			cout << "Control de Cursos\\Modificaci" << char(162) << "n curso espec" << char(161) << "fico\\" << endl << endl;
			cout << "\n----------------------------------------------\n" << endl;
			cout << cursos->cursoBasicos() << endl;
			cout << "Digite el codigo de curso: ";
			cin >> codigo;
			try {
				if (cursos->getLista()->esVacia()) {
					throw invalid_argument("Lista Vacia!!!");
				}
				else {
					try {
						cursos->getCursoEsp(codigo);
					}
					catch (invalid_argument& e) {
						system("cls");
						cout << e.what() << endl << endl;
						system("pause");
						return;
					}
				}
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
			cout << "\nCual dato desea modificar: " << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "  -> 1. Nombre del curso" << endl;
			cout << "  -> 2. Codigo de curso" << endl;
			cout << "  -> 3. Nivel" << endl;
			cout << "  -> 4. Descripcion" << endl;
			cout << "  -> 5. Cantidad de grupos" << endl;
			cout << "  -> 6. Volver al menu principal" << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "Digite una opcion: "; 
			cin >> opcion;
			try {
				IntOutRange(1, 6, opcion, yes);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				yes = false;
				system("pause");
			}
		} while ((opcion < 1 || opcion > 6) && !yes);

		system("cls");
		switch (opcion) {
		case 1:
			cout << "Control de Cursos\\Modificaci" << char(162) << "n curso espec" << char(161) << "fico\\Nombre" << endl << endl;
			cout << "Nombre actual del curso: " << cursos->getCursoEsp(codigo)->getNombre() << endl;
			cout << "Ingrese el nuevo nombre: ";
			cin.ignore();
			getline(cin, temp);
			cursos->getCursoEsp(codigo)->setNombre(temp);
			cout << endl << endl;
			system("pause");
			break;
		case 2:
			cout << "Control de Cursos\\Modificaci" << char(162) << "n curso espec" << char(161) << "fico\\Codigo" << endl << endl;
			cout << "Codigo actual del curso: " << cursos->getCursoEsp(codigo)->getCodigo() << endl;
			cout << "Ingrese el nuevo codigo: ";
			cin.ignore();
			getline(cin, temp);
			cursos->getCursoEsp(codigo)->setCodigo(temp);
			cout << endl << endl;
			system("pause");
			break;
		case 3:
		{
			bool yes = true;
			cout << "Control de Cursos\\Modificaci" << char(162) << "n curso espec" << char(161) << "fico\\Nivel" << endl << endl;
			cout << "Nivel actual del curso: " << cursos->getCursoEsp(codigo)->getNivel() << endl;
			cout << "\n===============================" << endl;
			cout << "\n     - Principiante [1]" << endl;
			cout << "     - Intermedio [2]" << endl;
			cout << "     - Avanzado [3]" << endl;
			cout << "\n===============================" << endl;
			cout << "Ingrese el nuevo nivel: ";
			cin >> aux;
			try {
				IntOutRange(1, 3, aux, yes);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				yes = false;
			}
			if (yes) {
				cursos->getCursoEsp(codigo)->setNivel(aux);
			}
			cout << endl << endl;
			system("pause");
			break; 
		}
		case 4:
			cout << "Control de Cursos\\Modificaci" << char(162) << "n curso espec" << char(161) << "fico\\Descripcion" << endl << endl;
			cout << "Descripcion actual del curso: " << cursos->getCursoEsp(codigo)->getDescripcion() << endl;
			cout << "Ingrese la nueva descripcion: ";
			cin.ignore();
			getline(cin, temp);
			cursos->getCursoEsp(codigo)->setDescripcion(temp);
			cout << endl << endl;
			system("pause");
			break;
		case 5:
		{
			bool yes = true;
			cout << "Control de Cursos\\Modificaci" << char(162) << "n curso espec" << char(161) << "fico\\Cantidad Grupos" << endl << endl;
			cout << "Cantidad de grupos actual del curso: " << cursos->getCursoEsp(codigo)->getCantGrupo() << endl;
			cout << "Ingrese la nueva cantidad de grupos: ";
			cin >> aux;
			try{
				intNegative(aux);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl;
				yes = false;
			}
			if(yes){
				cursos->getCursoEsp(codigo)->setCantGrupo(aux);
			}
			cout << endl << endl;
			system("pause");
			break;
		}
		case 6:
			break;
		}
	} while (opcion != 6);

}

//opcion 4
void Gimnasio::controlGrupos() {
	int opcion;
	bool yes = true;
	do {
		system("cls");
		cout << "Control de Grupos" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Ingreso nuevo grupo" << endl;
		cout << "\n2. Modificaci" << char(162) << "n de grupo espec" << char(161) << "fico" << endl;
		cout << "\n3. Matricula en grupo espec" << char(161) << "fico" << endl;
		cout << "\n4. Reporte de grupo espec" << char(161) << "fico" << endl;
		cout << "\n5. Reporte deportistas matriculados en grupo" << endl;
		cout << "\n6. Cancelaci" << char(162) << "n de matricula en grupo" << endl << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\nDigite una opcion: "; 
		cin >> opcion;
		try {
			IntOutRange(1, 4, opcion, yes);
		}
		catch (invalid_argument& e) {
			system("cls");
			cout << e.what() << endl << endl;
			yes = false;
			system("pause");
		}
	} while ((opcion < 1 || opcion > 6) && !yes);


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
	cout << "\n- D" << char(161) << "a: ";
	cin >> d;
	cout << "- Mes: ";
	cin >> m;
	cout << "- A" << char(164) << "o: ";
	cin >> a;
	cout << "\n-------------- Horario -----------------" << endl;
	cout << "\nDigite el dia de la semana (L-K-M-J-V-S-D): ";
	cin >> dia;
	cout << "\nDigite la hora de inicio (hora militar): " << endl;
	cout << "\nHora (1-24): ";
	cin >> horaI;
	cout << "\nMinutos (0-59): ";
	cin >> minI;
	cout << "\nDigite la hora de finalizaci" << char(162) << "n (hora militar): " << endl;
	cout << "\nHora (1-24): ";
	cin >> horaF;
	cout << "\nMinutos (0-59): ";
	cin >> minF;
	cout << endl << endl;

	Fecha* inicio = new Fecha(d, m, a);
	Grupo* nuevo = new Grupo(dia, cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getSize() + 1, cupoMax, nombreIns, id, inicio);
	nuevo->setHorario(horaI, minI, horaF, minF);

	cursos->getCursoEsp(codigo)->nuevoGrupo(nuevo);

	system("pause");
}

void Gimnasio::modifGrupo() {
	string codigo, temp, temp2;
	int opcion,num, aux;
	bool yes = true;
		do {
			system("cls");
			cout << "Control de Grupos\\Modificaci" << char(162) << "n Grupo espec" << char(161) << "fico\\" << endl << endl;
			cout << cursos->cursoBasicos() << endl;
			cout << "Digite el codigo de curso: ";
			cin >> codigo;
			cout << endl << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
			cout << "Digite el numero de grupo: ";
			cin >> num;
			cout << "Cual dato desea modificar: " << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "  -> 1. Datos del instructor" << endl;
			cout << "  -> 2. Cupo m" << char(160) << "ximo" << endl;
			cout << "  -> 3. Fecha de inicio" << endl;
			cout << "  -> 4. D" << char(161) << "a de la semana" << endl;
			cout << "  -> 5. Horario de curso" << endl;
			cout << "  -> 6. Volver al menu principal" << endl;
			cout << "\n-----------------------------\n" << endl;
			cout << "Digite una opcion: "; 
			cin >> opcion;
			try {
				IntOutRange(1, 6, opcion, yes);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				yes = false;
				system("pause");
			}
		} while ((opcion < 1 || opcion > 6) && !yes);


		system("cls");
		switch (opcion) {
		case 1:
			cout << "Control de Grupos\\Modificaci" << char(162) << "n Grupo espec" << char(161) << "fico\\Datos instructor" << endl << endl;
			cout << "Nombre actual del instructor: " << cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->getNomInst() << endl;
			cout << "ID actual del instructor: " << cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->getIdInst() << endl;
			cout << "\n===============================" << endl;
			cout << "\n  - Nombre [1]" << endl;
			cout << "  - ID [2]" << endl;
			cout << "\n===============================" << endl;
			cout << "Digite una opcion: "; 
			cin >> opcion;
			try {
				IntOutRange(1, 6, opcion, yes);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				yes = false;
				system("pause");
			}
			if (yes) {
				cin.ignore();
				if (opcion == 1) {
					cout << "\nIngrese el nuevo nombre: ";
					getline(cin, temp);
					cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->setNomInst(temp); //NOM
				}
				else {
					cout << "\nDigite el nuevo ID: ";
					getline(cin, temp2);
					cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->setIdInst(temp2); //ID
				}
				cout << endl << endl;
				system("pause");
				break;
			}
		case 2:
			cout << "Control de Grupos\\Modificaci" << char(162) << "n Grupo espec" << char(161) << "fico\\Cupo m" << char(160) << "ximo" << endl << endl;
			cout << "Cupo m" << char(160) << "ximo actual: " << cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->getCupoMaximo() << endl;
			cout << "\nIngrese el nuevo cupo m" << char(161) << "ximo: ";
			cin >> aux;
			try {
				intNegative(aux);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl << endl;
				system("pause");
				break;
			}
			cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->setCupoMaximo(aux);
			system("pause");
			break;
		case 3:
			{int d, m, a;
			cout << "Control de Grupos\\Modificaci" << char(162) << "n Grupo espec" << char(161) << "fico\\Fecha de inicio" << endl << endl;
			cout << "Fecha de inicio actual: " << cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->getInicio() << endl;
			cout << "\nIngrese la nueva fecha de inicio (DD/MM/AAAA): ";
			cout << "\n- D" << char(161) << "a: ";
			cin >> d;
			cout << "- Mes: ";
			cin >> m;
			cout << "- A" << char(164) << "o: ";
			cin >> a;
			Fecha* i = new Fecha(d, m, a);
			cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->setInicio(i);
			system("pause");
			break; }
		case 4:
			{char a;
			cout << "Control de Grupos\\Modificaci" << char(162) << "n Grupo espec" << char(161) << "fico\\D" << char(161) << "a de la semana" << endl << endl;
			cout << "D" << char(161) << "a de la semana actual: " << cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->getDia() << endl;
			cout << "\nIngrese el nuevo d" << char(161) << "a de la semana (L-K-M-J-V-S-D): ";
			cin >> a;
			cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->setDia(a);
			break; }
		case 5:
			int horaI, minI, horaF, minF;
			cout << "Control de Grupos\\Modificacin Grupo especifico\\Horario de curso" << endl << endl;
			cout << "Horario de curso actual: " << cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->getHorario() << endl;
			cout << "\nIngrese la nueva hora de inicio (hora militar): " << endl;
			cout << "\nHora (1-24): ";
			cin >> horaI;
			cout << "\nMinutos (0-59): ";
			cin >> minI;
			cout << "\nIngrese la nueva hora de finalizacion (hora militar): " << endl;
			cout << "\nHora (1-24): ";
			cin >> horaF;
			cout << "\nMinutos (0-59): ";
			cin >> minF;
			cursos->getCursoEsp(codigo)->getGrupos()->getLista()->getNodoEsp(num)->getDato()->setHorario(horaI,minI,horaF,minF);
			system("pause");
			break;
		case 6:
			break;
		}
}

void Gimnasio::matriculaGrupo() {
	string cedula, codigo;
	int numGrupo;
	cout << "Control de Grupos\\Matricula de grupo espec" << char(161) << "fico\\" << endl << endl;
	cout << "Digite la cedula del deportista: ";
	cin.get();
	getline(cin, cedula);
	try {
		if (cursos->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				cursos->getCursoEsp(codigo);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << endl << cursos->cursoBasicos() << endl;
	cout << "\nDigite el c" << char(162) << "digo del curso: ";
	getline(cin, codigo);
	try {
		if (cursos->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				cursos->getCursoEsp(codigo);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	try {
		cout << endl << endl << *cursos->getCursoEsp(codigo);
		cout << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}

	cout << "\n\nPara el curso selecionado existen los siguientes grupos disponibles: " << endl;
	
	cout << "\n---------------------------------------------------------------------\n" << endl;
	if (!cursos->getLista()->esVacia()) {
		cout << cursos->getCursoEsp(codigo)->masDetalleGrupos() << endl;
	}

	cout << "---------------------------------------------------------------------\n" << endl;
	cout << "Digite el n" << char(163) << "mero de grupo deseado: ";
	cin >> numGrupo;
	try {
		cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo);
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}

	//Hacer excepcion si el cupo esta lleno
	cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo)->agregarCliente(deportistas->getClienteEsp(cedula));
	deportistas->getClienteEsp(cedula)->agregarCurso(cursos->getCursoEsp(codigo));
	
	cout << endl << endl;
	system("pause");
}

void Gimnasio::reporteGrupo() {
	string cedula, codigo;
	int numGrupo;
	cout << "Control de Grupos\\Reporte de grupo espec" << char(161) << "fico\\" << endl << endl;
	cout << endl << cursos->cursoBasicos() << endl;
	cout << "\nDigite el c" << char(162) << "digo del curso: ";
	cin.get();
	getline(cin, codigo);
	try {
		if (cursos->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				cursos->getCursoEsp(codigo);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << endl << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
	cout << "Digite el n" << char(163) << "mero de grupo deseado: ";
	cin >> numGrupo;
	try {
		cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo);
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	try {
		intNegative(numGrupo);
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << "\n----------------------------------------------------------------------------------\n" << endl;
	cout << "A continuaci" << char(162) << "n se muestra la informaci" << char(162) << "n del grupo deseado: " << endl;
	cout << "\n" << *cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo) << endl << endl;

	system("pause");
}

void Gimnasio::reporteDepMat(){
	string codigo;
	int numGrupo;
	cout << "Control de Grupos\\Reporte deportistas matriculados por grupo\\" << endl << endl;
	cout << endl << cursos->cursoBasicos() << endl;
	cout << "\nDigite el c" << char(163) << "digo del curso: ";
	cin.get();
	getline(cin, codigo);
	try {
		if (cursos->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				cursos->getCursoEsp(codigo);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << endl << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
	cout << "\nDigite el n" << char(163) << "mero de grupo deseado: ";
	cin >> numGrupo;
	try {
		cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo);
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	try {
		intNegative(numGrupo);
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << "\n------------------------------------------------\n" << endl;
	cout << "Listado de matriculados en el grupo #" << numGrupo << " del curso " << codigo << ": \n" << endl;
	cout << cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo)->getLista()->sencilloClientes() << endl;

	system("pause");
}

void Gimnasio::cancelacionMatricula(){
	string cedula, codigo;
	int numGrupo;
	cout << "Control de Grupos\\Matricula de grupo espec" << char(161) << "fico\\" << endl << endl;
	cout << "Digite la cedula del deportista: ";
	cin.get();
	getline(cin, cedula);
	try {
		if (deportistas->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				deportistas->getClienteEsp(cedula);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << endl << cursos->cursoBasicos() << endl;
	cout << "\nDigite el c" << char(162) << "digo del curso: ";
	getline(cin, codigo);
	try {
		if (cursos->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				cursos->getCursoEsp(codigo);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}

	cout << endl << cursos->getCursoEsp(codigo)->detalleGrupos() << endl;
	cout << "\nDigite el n" << char(163) << "mero de grupo deseado: ";
	cin >> numGrupo;
	try {
		cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo);
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}	
	try {
		intNegative(numGrupo);
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << "\nSe ha retirado la matr" << char(161) << "cula del deportista del grupo\n" << endl;

	cursos->getCursoEsp(codigo)->getGrupos()->getGrupoEsp(numGrupo)->getLista()->eliminarCliente(cedula);
	deportistas->getClienteEsp(cedula)->getListaCursos()->eliminarCurso(codigo);
	system("pause");
}

//opcion 5
void Gimnasio::controlPagos() {
	int opcion;
	bool yes = true;
	do {
		system("cls");
		cout << "Control de Pagos" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
		cout << "\n1. Registro de nuevo pago" << endl;
		cout << "\n2. Reporte de pagos por deportista" << endl;
		cout << "\n_._._._._._._._._._._._._._._._._._._._\n" << endl;
		cout << "\nDigite una opcion: ";
		cin >> opcion;
		try {
			IntOutRange(1, 2, opcion, yes);
		}
		catch (invalid_argument& e) {
			system("cls");
			cout << e.what() << endl << endl;
			yes = false;
			system("pause");
		}
	} while ((opcion < 1 || opcion > 2) && !yes);

	system("cls");
	switch (opcion) {
	case 1: registroPago(); break;
	case 2: reportePagos(); break;
	}
}

void Gimnasio::registroPago(){
	string temp;
	int aux;
	cout << "Control de Pagos\\Registro de nuevo pago\\" << endl;
	cout << "\nFecha actual: " << *currentDate << endl;
	cout << "\nDigite el ID del deportista: ";
	cin.get();
	getline(cin, temp);
	try {
		if (deportistas->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				deportistas->getClienteEsp(temp);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << "\n\nEl deportista " << deportistas->getClienteEsp(temp)->getNombre() << " tiene cancelado hasta el mes de ";
	cout << deportistas->getClienteEsp(temp)->getListaPagos()->retornaMesCancelado() << endl;
	cout << "\nCu" << char(160) << "ntas cuotas desea cancelar o pagar: ";
	cin >> aux;
	try {
		intNegative(aux);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << "\nMonto a pagar " << (montoMensual * aux) << " ( " << montoMensual << " x " << aux << " meses)" << endl;
	cout << deportistas->getClienteEsp(temp)->getListaPagos()->pagosCancelados(aux, montoMensual);
	cout << "\nEl deportista " << deportistas->getClienteEsp(temp)->getNombre() << " ahora tiene cancelado hasta el mes de ";
	cout << deportistas->getClienteEsp(temp)->getListaPagos()->retornaMesCancelado() << endl;

	cout << endl << endl;

	system("pause");
}

void Gimnasio::reportePagos(){

	string temp;
	cout << "Control de Pagos\\Reporte de pagos por deportista\\" << endl;
	cout << "\nFecha actual: " << *currentDate << endl;
	cout << "\nDigite el ID del deportista: ";
	cin.ignore();
	getline(cin, temp);
	try {
		if (deportistas->getLista()->esVacia()) {
			throw invalid_argument("Lista Vacia!!!");
		}
		else {
			try {
				deportistas->getClienteEsp(temp);
			}
			catch (invalid_argument& e) {
				system("cls");
				cout << e.what() << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (invalid_argument& e) {
		system("cls");
		cout << e.what() << endl << endl;
		system("pause");
		return;
	}
	cout << "\nA continuaci" << char(162) << "n se detalla el historial de pagos: " << endl;
	cout << "\n-----------------------------------------------------\n" << endl;
	cout << "  Fecha de pago\t     Mes-cancelado\tMonto cancelado" << endl;
	cout << deportistas->getClienteEsp(temp)->getListaPagos()->toString() << endl;
	cout << "\n-----------------------------------------------------\n" << endl << endl;

	system("pause");
}

//opcion 6
void Gimnasio::guardarArchSalir(){
	guardarGimnasio();
	cout << "Se ha salido correctamente!!!" << endl << endl;
}

void Gimnasio::guardarGimnasio(){
	ofstream salida; 
	salida.open("../Gimnasio.txt"); 
	if (salida.good()) {
		deportistas->guardarListaClientes();
		cursos->guardarListaGrupos();
		salida << nombre << '\t';
		salida << montoMensual << '\n';
		cout << "Los datos se han guardado correctamente!!!" << endl << endl;
	}
	else {
		cout << "Error de intento para guardar datos!!!" << endl << endl;
	}
	system("pause");
	system("cls");
	salida.close(); 
}

void Gimnasio::leerGimnasio(){

	deportistas->leerListaClientes();
	cursos->leerListaCursos();

	string _nom = "", _monto = "";  

	ifstream entrada; 
	entrada.open("../Gimnasio.txt"); 
	if (entrada.good()) {
		getline(entrada, _nom, '\t'); 
		getline(entrada, _monto, '\n');
		int monto = convertirInt(_monto);
		setNombre(_nom);
		setMonto(monto);
	}
	entrada.close();
}