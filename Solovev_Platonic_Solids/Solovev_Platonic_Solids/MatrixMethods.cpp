using namespace System::Drawing;
#include "math.h" // cos, sin

// Студент: Соловьев Андрей
// Группа: БПИ122(2)
// Семинар 5: 3D моделирование тел вращения и платоновых тел
// Дата: 23.10.2015
// Среда разработки: Visual Studio 2013
// Реализованы алгоритмы вращения, сдвига, масштабирования
// и проецирования тел вращения и платоновых тел.

class MatrixMethods {

public:
	static void move(cli::array<array<double>^>^ a, cli::array<array<double>^>^ Pd,
		int dx, int dy, int dz, int col, int row) {

		Pd[3][0] = dx;
		Pd[3][1] = dy;
		Pd[3][2] = dz;

		MatrixMult(a, Pd, col, row);
	}

public:
	static void scale(cli::array<array<double>^>^ a, cli::array<array<double>^>^ Ps,
		double p, double q, double r, double s, int col, int row) {

		Ps[0][0] = p;
		Ps[1][1] = q;
		Ps[2][2] = r;
		Ps[3][3] = s;

		MatrixMult(a, Ps, col, row);
	}



public:
	static void rotateOX(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ R, double Phi, int col, int row) {

		R[0][0] = 1;
		R[1][1] = cos(Phi);
		R[1][2] = sin(Phi);
		R[2][1] = -sin(Phi);
		R[2][2] = cos(Phi);
		R[3][3] = 1;

		MatrixMult(a, R, col, row);

	}

public:
	static void rotateOY(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ R, double Phi, int col, int row) {

		R[0][0] = cos(Phi);
		R[0][2] = -sin(Phi);
		R[1][1] = 1;
		R[2][0] = sin(Phi);
		R[2][2] = cos(Phi);
		R[3][3] = 1;

		MatrixMult(a, R, col, row);

	}

public:
	static void rotateOZ(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ R, double Phi, int col, int row) {

		R[0][0] = cos(Phi);
		R[0][1] = sin(Phi);
		R[1][0] = -sin(Phi);
		R[1][1] = cos(Phi);
		R[2][2] = 1;
		R[3][3] = 1;


		MatrixMult(a, R, col, row);

	}

public:
	static void centralProjection(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ Pz, double z0, int col, int row) {

		Pz[0][0] = 1.0;
		Pz[1][1] = 1.0;
		Pz[2][3] = -1.0 / z0;
		Pz[3][3] = 1.0;

		MatrixMult(a, Pz, col, row);

	}

public:
	static void orthogonalProjection(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ Pz, int col, int row) {

		Pz[0][0] = 1.0;
		Pz[1][1] = 1.0;
		Pz[2][3] = 0.0;
		Pz[3][3] = 1.0;

		MatrixMult(a, Pz, col, row);

	}

public:
	static void MatrixMult(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ b, int numCol, int numRow) {

		cli::array<array<double>^>^ R = gcnew cli::array<array<double>^>(numRow);

		for (int i = 0; i < numRow; i++)
			R[i] = gcnew cli::array<double>(4);

		for (int i = 0; i < numRow; i++) {
			for (int j = 0; j < 4; j++) {
				R[i][j] = 0.0;
				for (int k = 0; k < numCol; k++) {
					R[i][j] += a[i][k] * b[k][j];
				}
			}
		}

		for (int i = 0; i < numRow; i++) {
			for (int j = 0; j < 4; j++) {
				a[i][j] = R[i][j];
			}
		}
	}

public:
	static void localRotateOX(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ R, double l, double m, double n, int col, int row) {

		double d = sqrt(m*m + n*n);

		R[0][0] = 1;
		R[1][1] = n*1.0/d;
		R[1][2] = m*1.0 / d;
		R[2][1] = -m*1.0 / d;
		R[2][2] = n*1.0 / d;
		R[3][3] = 1;

		MatrixMult(a, R, col, row);

	}

public:
	static void localRotateOY(cli::array<array<double>^>^ a,
		cli::array<array<double>^>^ R, double l, double m, double n, int col, int row) {

		double d = sqrt(m*m + n*n);

		R[0][0] = l*1.0;
		R[0][2] = d*1.0;
		R[1][1] = 1;
		R[2][0] = -d*1.0;
		R[2][2] = l*1.0;
		R[3][3] = 1;

		MatrixMult(a, R, col, row);

	}

};