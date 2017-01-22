using namespace System::Drawing;

// Студент: Соловьев Андрей
// Группа: БПИ122(2)
// Семинар 5: 3D моделирование тел вращения и платоновых тел
// Дата: 23.10.2015
// Среда разработки: Visual Studio 2013
// Реализованы алгоритмы вращения, сдвига, масштабирования
// и проецирования тел вращения и платоновых тел.

class MyPyramid {

public:
	int size;
	
	double x1;
	double x2;
	double x3;
	double x4;

	double y1;
	double y2;
	double y3;
	double y4;

	double z1;
	double z2;
	double z3;
	double z4;
	

public:
	MyPyramid() {

		// Задаем размер пирамиды
		size = 100;

		// Инициализация координат
		x1 = 1.0 * size;
		y1 = 0.0 * size;
		z1 = -0.70710678 * size;

		x2 = -1.0 * size;
		y2 = 0.0 * size;
		z2 = -0.70710678 * size;

		x3 = 0.0 * size;
		y3 = 1.0 * size;
		z3 = 0.70710678 * size;

		x4 = 0.0 * size;
		y4 = -1.0 * size;
		z4 = 0.70710678 * size;
		
	}

	void initializeMatrix(cli::array<array<double>^>^ arr) {

		// Формирование матрицы вершин объекта 

		arr[0][0] = x1;
		arr[0][1] = y1;
		arr[0][2] = z1;
		arr[0][3] = 1;

		arr[1][0] = x2;
		arr[1][1] = y2;
		arr[1][2] = z2;
		arr[1][3] = 1;

		arr[2][0] = x3;
		arr[2][1] = y3;
		arr[2][2] = z3;
		arr[2][3] = 1;

		arr[3][0] = x4;
		arr[3][1] = y4;
		arr[3][2] = z4;
		arr[3][3] = 1;
	}



};