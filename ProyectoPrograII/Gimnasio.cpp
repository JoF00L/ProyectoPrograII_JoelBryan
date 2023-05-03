#include "Gimnasio.h"

Gimnasio::Gimnasio()
{
}

Gimnasio::~Gimnasio()
{
}

void Gimnasio::menu(){
	int opcion;

	cout << "\tBienvenido al Gimnasio" << endl << endl; //podríamos ponerle un nombre jaja

	do {
		system("cls");
		cout << "\tMenu Principal" << endl << endl;
		cout << "1. Administración General" << endl;
		cout << "\n2. Control de Deportistas" << endl;
		cout << "\n3. Control de Cursos" << endl;
		cout << "\n4. Control de Grupos" << endl;
		cout << "\n5. Control Pagos" << endl;
		cout << "\n6. Guardar en Archivos y salir" << endl << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
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
}

void Gimnasio::adminGeneral(){
	int opcion;

	do {
		system("cls");
		cout << "\t( 1 ) Administración General" << endl << endl;
		cout << "\n1. Nombre del Gimnasio" << endl;
		cout << "\n2. Monto de mensualidad" << endl << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 2);

	system("cls");
	switch (opcion) {
	case 1: nombreGim(); break;
	case 2: montoMensualidad(); break;
	}
}

void Gimnasio::controlDeportistas(){
	int opcion;

	do {
		system("cls");
		cout << "\t( 2 ) Control de Deportistas" << endl << endl;
		cout << "\n1. Ingreso nuevo deportista" << endl;
		cout << "\n2. Modificacion de deportista" << endl;
		cout << "\n3. Listado de deportistas" << endl;
		cout << "\n4. Detalle de deportista especifico" << endl << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 4);

	system("cls");
	switch (opcion) {
	case 1: nombreGim(); break;
	case 2: montoMensualidad(); break;
	case 3: montoMensualidad(); break;
	case 4: montoMensualidad(); break;
	}
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
	} while (opcion < 1 || opcion > 2);

	system("cls");
	switch (opcion) {
	case 1: ingresoCurso(); break;
	case 2: reporteCurso(); break;
	case 3: modifCurso(); break;
	}
}

void Gimnasio::controlGrupos()
{
}

void Gimnasio::controlPagos(){

}

void Gimnasio::guardarArchSalir()
{
}

void Gimnasio::nombreGim() {
	string nomG;
	cout << "<( 1 ) Administracion General> <( 1 ) Nombre del Gimnasio>" << endl << endl;
	cout << "Ingrese el nombre del Gimnasio: ";
	cin >> nomG; cout << endl << endl;

	system("pause");
}

void Gimnasio::montoMensualidad(){
	int monto;
	cout << "<( 1 ) Administracion General> <( 2 ) Monto de mensualidad>" << endl << endl;
	cout << "Ingrese el monto de mensualidad: ";
	cin >> monto; cout << endl << endl;

	system("pause");
}

void Gimnasio::ingresoDeportista(){
	string nombre, cedula, telefono;
	int d, m, a;
	float estatura, peso, grasa, masa;
	char sexo;
	cout << "<( 2 ) Control de Deportistas> <( 1 ) Ingreso nuevo deportista>" << endl << endl;
	cout << "Datos generales: " << endl << endl;
	cout << "\tNombre: "; cin >> nombre;
	cout << "\n\tID: "; cin >> cedula;
	cout << "\n\tTelefono: "; cin >> telefono;
	cout << "\n\tFecha de nacimiento (DD/MM/AAAA): ";
	cin >> d; cout << " / "; cin >> m; cout << " / "; cin >> a;
	Fecha* nacimiento = new Fecha(d, m, a);
	cout << "\n\tSexo: "; cin >> sexo;
	cout << "\n\nDatos biometricos basicos: " << endl << endl;
	cout << "\n\tEstatura: "; cin >> estatura;
	cout << "\n\tPeso: "; cin >> peso;
	cout << "\n\tGrasa Corporal: "; cin >> grasa;
	cout << "\n\tMasa Muscular: "; cin >> masa;
	cout << endl << endl;

	system("pause");
	delete nacimiento;
}

void Gimnasio::modifDeportista(){
	string nombre, cedula, telefono;
	int d, m, a, opcion;
	float estatura, peso, grasa, masa;
	char sexo;
	bool estado;
	do {
		system("cls");
		cout << "<( 2 ) Control de Deportistas> <( 2 ) Modificacion deportista>" << endl << endl;
		cout << "\tDigite el ID del deportista: "; cin >> cedula;
		cout << "\tQue dato desea modificar: " << endl << endl;
		cout << "\t\t1. Nombre" << endl;
		cout << "\t\t2. Telefono" << endl;
		cout << "\t\t3. Fecha de nacimiento" << endl;
		cout << "\t\t4. Sexo" << endl;
		cout << "\t\t5. Estatura" << endl;
		cout << "\t\t6. Peso" << endl;
		cout << "\t\t7. Porcentaje de grasa corporal" << endl;
		cout << "\t\t8. Porcentaje de masa muscular" << endl;
		cout << "\t\t9. Estado" << endl << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 9);

}

void Gimnasio::listadoDeportistas(){
	int opcion;

	do {
		system("cls");
		cout << "<( 2 ) Control de Deportistas> <( 3 ) Listado de deportistas>" << endl << endl;
		cout << "\n1. Listado general" << endl;
		cout << "\n2. Listado de deportistas activos" << endl;
		cout << "\n3. Listado de deportistas inactivos" << endl;
		cout << "\n4. Listado de deportista en morosidad" << endl << endl;
		cout << "\nDigite una opcion: "; cin >> opcion;
	} while (opcion < 1 || opcion > 4);

	system("pause");
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
