#include "MyForm.h"

// -------------------------------------------
//   Методы инициализации и рисования фигур:
// -------------------------------------------

// Студент: Соловьев Андрей
// Группа: БПИ122(2)
// Семинар 5: 3D моделирование тел вращения и платоновых тел
// Дата: 23.10.2015
// Среда разработки: Visual Studio 2013
// Реализованы алгоритмы вращения, сдвига, масштабирования
// и проецирования тел вращения и платоновых тел.


System::Void Solovev_Platonic_Solids::MyForm::initializePyramid() {

	nRows = 4;
	type = 1;
	// Инициализация матрицы вершин объекта
	arr_vertex = gcnew cli::array<array<double>^>(nRows);
	arr_vertexCopy = gcnew cli::array<array<double>^>(nRows);
	arrProjection = gcnew cli::array<array<double>^>(nRows);
	for (int i = 0; i < nRows; i++) {
		arr_vertex[i] = gcnew cli::array<double>(nCol);
		arr_vertexCopy[i] = gcnew cli::array<double>(nCol);
		arrProjection[i] = gcnew cli::array<double>(nCol);
	}
	pyramid.initializeMatrix(arr_vertex);
	pyramid.initializeMatrix(arr_vertexCopy);

	// Инициализация матрицы граней
	arr_face = gcnew cli::array<int>(12)
	{
		0, 1, 2,
			0, 2, 3,
			0, 3, 1,
			1, 3, 2
	};
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawPyramid() {

	g->Clear(Color::White);
	z0 = -800;
	drawAxes();
	setProjection();

	// Рисуем пирамиду
	for (int i = 0; i < 12; i += 3) {
		g->DrawLine(pb, w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1],
			w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1],
			w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1],
			w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1]);
	}
	pictureBoxForDraw->Refresh();
}

System::Void Solovev_Platonic_Solids::MyForm::initializeOctahedron() {

	nRows = vcount_oct;
	type = 2;

	arr_vertex = gcnew cli::array<array<double>^>(nRows);
	arr_vertexCopy = gcnew cli::array<array<double>^>(nRows);
	arrProjection = gcnew cli::array<array<double>^>(nRows);
	for (int i = 0; i < nRows; i++) {
		arr_vertex[i] = gcnew cli::array<double>(nCol);
		arr_vertexCopy[i] = gcnew cli::array<double>(nCol);
		arrProjection[i] = gcnew cli::array<double>(nCol);
	}

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCol; j++) {
			if (j < 3) {
				arr_vertex[i][j] = vertices_oct[i][j];
				arr_vertexCopy[i][j] = vertices_oct[i][j];
			}
			else {
				arr_vertex[i][j] = 1;
				arr_vertexCopy[i][j] = 1;
			}
		}
	}

	// Инициализация матрицы граней
	arr_face = gcnew cli::array<int>(icount_oct);
	for (int i = 0; i < icount_oct; i++) {
		arr_face[i] = indices_oct[i];
	}
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawOctahedron() {

	g->Clear(Color::White);
	z0 = -800;
	drawAxes();
	setProjection();


	for (int i = 0; i < icount_oct; i += 3) {
		g->DrawLine(pb, w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1],
			w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1],
			w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1],
			w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1]);
	}
	pictureBoxForDraw->Refresh();
}

System::Void Solovev_Platonic_Solids::MyForm::initializeIcosahedron() {

	nRows = vcount_icos;
	type = 3;

	arr_vertex = gcnew cli::array<array<double>^>(nRows);
	arr_vertexCopy = gcnew cli::array<array<double>^>(nRows);
	arrProjection = gcnew cli::array<array<double>^>(nRows);
	for (int i = 0; i < nRows; i++) {
		arr_vertex[i] = gcnew cli::array<double>(nCol);
		arr_vertexCopy[i] = gcnew cli::array<double>(nCol);
		arrProjection[i] = gcnew cli::array<double>(nCol);
	}

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCol; j++) {
			if (j < 3) {
				arr_vertex[i][j] = vertices_icos[i][j];
				arr_vertexCopy[i][j] = vertices_icos[i][j];
			}
			else {
				arr_vertex[i][j] = 1;
				arr_vertexCopy[i][j] = 1;
			}
		}
	}

	// Инициализация матрицы граней
	arr_face = gcnew cli::array<int>(icount_icos);
	for (int i = 0; i < icount_icos; i++) {
		arr_face[i] = indices_icos[i];
	}
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawIcosahedron() {

	g->Clear(Color::White);
	z0 = -800;
	drawAxes();
	setProjection();


	for (int i = 0; i < icount_icos; i += 3) {
		g->DrawLine(pb, w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1],
			w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1],
			w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1],
			w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1]);
	}


	pictureBoxForDraw->Refresh();
}

System::Void Solovev_Platonic_Solids::MyForm::initializeSphere() {

	nRows = vcount_sphere;
	type = 4;

	arr_vertex = gcnew cli::array<array<double>^>(nRows);
	arr_vertexCopy = gcnew cli::array<array<double>^>(nRows);
	arrProjection = gcnew cli::array<array<double>^>(nRows);
	for (int i = 0; i < nRows; i++) {
		arr_vertex[i] = gcnew cli::array<double>(nCol);
		arr_vertexCopy[i] = gcnew cli::array<double>(nCol);
		arrProjection[i] = gcnew cli::array<double>(nCol);
	}

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCol; j++) {
			if (j < 3) {
				arr_vertex[i][j] = vertices_sphere[i][0][j];
				arr_vertexCopy[i][j] = vertices_sphere[i][0][j];
			}
			else {
				arr_vertex[i][j] = 1;
				arr_vertexCopy[i][j] = 1;
			}
		}
	}

	// Инициализация матрицы граней
	arr_face = gcnew cli::array<int>(icount_sphere);
	for (int i = 0; i < icount_sphere; i++) {
		arr_face[i] = indices_sphere[i];
	}
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawSphere() {

	g->Clear(Color::White);
	z0 = -800;
	drawAxes();
	setProjection();


	// Рисуем cферу
	for (int i = 0; i < icount_sphere; i += 3) {
		g->DrawLine(pb, w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1],
			w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1],
			w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1],
			w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1]);
	}
	pictureBoxForDraw->Refresh();
}

System::Void Solovev_Platonic_Solids::MyForm::initializeTorus() {

	nRows = vcount_torus;
	type = 5;

	arr_vertex = gcnew cli::array<array<double>^>(nRows);
	arr_vertexCopy = gcnew cli::array<array<double>^>(nRows);
	arrProjection = gcnew cli::array<array<double>^>(nRows);
	for (int i = 0; i < nRows; i++) {
		arr_vertex[i] = gcnew cli::array<double>(nCol);
		arr_vertexCopy[i] = gcnew cli::array<double>(nCol);
		arrProjection[i] = gcnew cli::array<double>(nCol);
	}

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCol; j++) {
			if (j < 3) {
				arr_vertex[i][j] = vertices_torus[i][0][j];
				arr_vertexCopy[i][j] = vertices_torus[i][0][j];
			}
			else {
				arr_vertex[i][j] = 1;
				arr_vertexCopy[i][j] = 1;
			}
		}
	}

	// Инициализация матрицы граней
	arr_face = gcnew cli::array<int>(icount_torus);
	for (int i = 0; i < icount_torus; i++) {
		arr_face[i] = indices_torus[i];
	}
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawTorus() {

	g->Clear(Color::White);
	z0 = -800;
	drawAxes();
	setProjection();

	for (int i = 0; i < icount_torus; i += 3) {
		g->DrawLine(pb, w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1],
			w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1],
			w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1],
			w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1]);
	}




	pictureBoxForDraw->Refresh();
}

System::Void Solovev_Platonic_Solids::MyForm::initializeGarlic() {

	nRows = vcount_sphere;
	type = 6;

	arr_vertex = gcnew cli::array<array<double>^>(nRows);
	arr_vertexCopy = gcnew cli::array<array<double>^>(nRows);
	arrProjection = gcnew cli::array<array<double>^>(nRows);
	for (int i = 0; i < nRows; i++) {
		arr_vertex[i] = gcnew cli::array<double>(nCol);
		arr_vertexCopy[i] = gcnew cli::array<double>(nCol);
		arrProjection[i] = gcnew cli::array<double>(nCol);
	}

	long double alpha = 0.0;
	long double beta = 0.0;
	long double R = 0.0;
	long double R2 = 0.0;
	long double x2y2;


	for (int i = 0; i < nRows; i++) {

		R2 = vertices_sphere[i][0][0] * vertices_sphere[i][0][0] +
			vertices_sphere[i][0][1] * vertices_sphere[i][0][1] +
			vertices_sphere[i][0][2] * vertices_sphere[i][0][2];
		R = sqrt(R2);
		x2y2 = vertices_sphere[i][0][0] * vertices_sphere[i][0][0] +
			vertices_sphere[i][0][2] * vertices_sphere[i][0][2];

		beta = acos(sqrt(x2y2 / (R2)));
		if (vertices_sphere[i][0][1] < 0.0) {
			beta = -beta;
		}

		if (vertices_sphere[i][0][2] != 0) {
			alpha = atan(vertices_sphere[i][0][0] / (-vertices_sphere[i][0][2]));
		}
		else {

			if (vertices_sphere[i][0][0] >= 0) {
				alpha = PI / 2;
			}
			else {
				alpha = -PI / 2;
			}
		}

		arr_vertex[i][0] = vertices_sphere[i][0][0] * (1 + 0.5 * abs(sin(2 * alpha)));
		arr_vertex[i][1] = -vertices_sphere[i][0][2] * (1 + 0.5 * abs(sin(2 * alpha)));

		if (beta > 0) {
			arr_vertex[i][2] = vertices_sphere[i][0][1] + R * pow(beta / (PI / 2), 5);
		}
		else {
			arr_vertex[i][2] = vertices_sphere[i][0][1];
		}

		arr_vertex[i][3] = 1;

		for (int j = 0; j < nCol; j++) {
			arr_vertexCopy[i][j] = arr_vertex[i][j];
		}
	}

	MatrixMethods::rotateOX(arr_vertex, Rx, 90 * Phi, nCol, nRows);
	MatrixMethods::rotateOX(arr_vertexCopy, Rx, 90 * Phi, nCol, nRows);
	MatrixMethods::scale(arr_vertex, Ps, 0.6, 0.6, 0.6, 1, nCol, nRows);
	MatrixMethods::scale(arr_vertexCopy, Ps, 0.6, 0.6, 0.6, 1, nCol, nRows);

	// Инициализация матрицы граней
	arr_face = gcnew cli::array<int>(icount_sphere);
	for (int i = 0; i < icount_sphere; i++) {
		arr_face[i] = indices_sphere[i];
	}
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawGarlic() {

	g->Clear(Color::White);
	z0 = -800;
	drawAxes();
	setProjection();



	for (int i = 0; i < icount_sphere; i += 3) {
		g->DrawLine(pb, w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1],
			w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1],
			w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1],
			w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1]);
	}
	pictureBoxForDraw->Refresh();
}

System::Void Solovev_Platonic_Solids::MyForm::initializeSpring() {

	nRows = vcount_torus;
	type = 7;

	long double xy = 0.0;
	long double beta = 0.0;

	arr_vertex = gcnew cli::array<array<double>^>(nRows);
	arr_vertexCopy = gcnew cli::array<array<double>^>(nRows);
	arrProjection = gcnew cli::array<array<double>^>(nRows);
	for (int i = 0; i < nRows; i++) {
		arr_vertex[i] = gcnew cli::array<double>(nCol);
		arr_vertexCopy[i] = gcnew cli::array<double>(nCol);
		arrProjection[i] = gcnew cli::array<double>(nCol);
	}


	beta = nRows * PI / 30;
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCol; j++) {

			if (j < 3) {
				arr_vertex[i][j] = vertices_torus[i][0][j];
				arr_vertexCopy[i][j] = vertices_torus[i][0][j];
			}
			else {
				arr_vertex[i][j] = 1;
				arr_vertexCopy[i][j] = 1;
			}

		}

		if (i - 8 >= nRows / 2) {
			beta = beta - PI / 15;
			arr_vertex[i][1] = arr_vertex[i][1] + beta;
		}
	}

	for (int i = 0; i < nRows; i++) {

		if (!(i - 8 >= nRows / 2)) {
			beta = beta - PI / 15;
			arr_vertex[i][1] = arr_vertex[i][1] + beta;
		}

		arr_vertexCopy[i][1] = arr_vertex[i][1];
	}

	// Инициализация матрицы граней
	arr_face = gcnew cli::array<int>(icount_torus);
	for (int i = 0; i < icount_torus; i++) {
		arr_face[i] = indices_torus[i];
	}

	// Расположение вдоль оси X
	MatrixMethods::rotateOZ(arr_vertex, Rz, 90 * Phi, nCol, nRows);
	MatrixMethods::rotateOZ(arr_vertexCopy, Rz, 90 * Phi, nCol, nRows);

	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawSpring() {

	g->Clear(Color::White);
	z0 = -800;
	drawAxes();
	setProjection();

	for (int i = 0; i < icount_torus; i += 3) {

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1],
			w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 1]][0], h + (int)arrProjection[arr_face[i + 1]][1],
			w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1]);

		g->DrawLine(pb, w + (int)arrProjection[arr_face[i + 2]][0], h + (int)arrProjection[arr_face[i + 2]][1],
			w + (int)arrProjection[arr_face[i]][0], h + (int)arrProjection[arr_face[i]][1]);
	}




	pictureBoxForDraw->Refresh();
}

System::Void Solovev_Platonic_Solids::MyForm::drawFigure() {
	if (type == 1) {
		drawPyramid();
	}
	else if (type == 2) {
		drawOctahedron();
	}
	else if (type == 3) {
		drawIcosahedron();
	}
	else if (type == 4) {
		drawSphere();
	}
	else if (type == 5) {
		drawTorus();
	}
	else if (type == 6) {
		drawGarlic();
	}
	else if (type == 7) {
		drawSpring();
	}
}