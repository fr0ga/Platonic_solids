#include "MyForm.h"

// Студент: Соловьев Андрей
// Группа: БПИ122(2)
// Семинар 5: 3D моделирование тел вращения и платоновых тел
// Дата: 23.10.2015
// Среда разработки: Visual Studio 2013
// Реализованы алгоритмы вращения, сдвига, масштабирования
// и проецирования тел вращения и платоновых тел.

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Solovev_Platonic_Solids::MyForm MyForm;
	Application::Run(%MyForm);
}


System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemAbout_Click(System::Object^  sender, System::EventArgs^  e)
{
	MyFormAbout^ form = gcnew MyFormAbout;
	form->ShowDialog();
}

System::Void Solovev_Platonic_Solids::MyForm::pictureBoxForDraw_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	if (isConverting) {

		if (((MouseEventArgs^)e)->Button == System::Windows::Forms::MouseButtons::Left) {

			if (radioButtonCarousel->Checked) {
				if (((MouseEventArgs^)e)->Y > y) {


					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, -Phi, nCol, nRows);
						MatrixMethods::rotateOZ(arr_vertex, Rz, -Phi, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi, nCol, nRows);
						MatrixMethods::rotateOX(arr_vertex, Rx, Phi, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {

						MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi, nCol, nRows);
						MatrixMethods::rotateOX(arr_vertex, Rx, Phi, nCol, nRows);
					}


					drawFigure();

					y = ((MouseEventArgs^)e)->Y;
				}
				if (((MouseEventArgs^)e)->Y < y) {


					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi, nCol, nRows);
						MatrixMethods::rotateOZ(arr_vertex, Rz, Phi, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOX(arr_vertexCopy, Rx, -Phi, nCol, nRows);
						MatrixMethods::rotateOX(arr_vertex, Rx, -Phi, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {

						MatrixMethods::rotateOX(arr_vertexCopy, Rx, -Phi, nCol, nRows);
						MatrixMethods::rotateOX(arr_vertex, Rx, -Phi, nCol, nRows);
					}


					drawFigure();

					y = ((MouseEventArgs^)e)->Y;
				}

				if (((MouseEventArgs^)e)->X > x) {


					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOY(arr_vertexCopy, Ry, Phi, nCol, nRows);
						MatrixMethods::rotateOY(arr_vertex, Ry, Phi, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi, nCol, nRows);
						MatrixMethods::rotateOZ(arr_vertex, Rz, Phi, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {

						MatrixMethods::rotateOY(arr_vertexCopy, Ry, Phi, nCol, nRows);
						MatrixMethods::rotateOY(arr_vertex, Ry, Phi, nCol, nRows);
					}

					drawFigure();

					x = ((MouseEventArgs^)e)->X;

				}
				if (((MouseEventArgs^)e)->X < x) {


					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOY(arr_vertexCopy, Ry, -Phi, nCol, nRows);
						MatrixMethods::rotateOY(arr_vertex, Ry, -Phi, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, -Phi, nCol, nRows);
						MatrixMethods::rotateOZ(arr_vertex, Rz, -Phi, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {

						MatrixMethods::rotateOY(arr_vertexCopy, Ry, -Phi, nCol, nRows);
						MatrixMethods::rotateOY(arr_vertex, Ry, -Phi, nCol, nRows);
					}


					drawFigure();

					x = ((MouseEventArgs^)e)->X;
				}
			}
			else if (radioButtonSelfRotating->Checked)
			{
				if (((MouseEventArgs^)e)->Y > y) {

					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, -Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {

						MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}


					drawFigure();

					y = ((MouseEventArgs^)e)->Y;
				}
				if (((MouseEventArgs^)e)->Y < y) {

					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOX(arr_vertexCopy, Rx, -Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {
						MatrixMethods::rotateOX(arr_vertexCopy, Rx, -Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);

					}


					drawFigure();

					y = ((MouseEventArgs^)e)->Y;
				}

				if (((MouseEventArgs^)e)->X > x) {

					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOY(arr_vertexCopy, Ry, Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {

						MatrixMethods::rotateOY(arr_vertexCopy, Ry, Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}


					drawFigure();

					x = ((MouseEventArgs^)e)->X;

				}
				if (((MouseEventArgs^)e)->X < x) {

					if (radioButtonProjX->Checked) {
						MatrixMethods::rotateOY(arr_vertexCopy, Ry, -Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjY->Checked) {
						MatrixMethods::rotateOZ(arr_vertexCopy, Rz, -Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
					}
					else if (radioButtonProjZ->Checked) {
						MatrixMethods::rotateOY(arr_vertexCopy, Ry, -Phi, nCol, nRows);
						copyVertexArray();
						MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);

					}


					drawFigure();

					x = ((MouseEventArgs^)e)->X;
				}
			}

		}


		if (((MouseEventArgs^)e)->Button == System::Windows::Forms::MouseButtons::Right) {
			if (((MouseEventArgs^)e)->Y > y) {

				if (radioButtonProjX->Checked) {
					MatrixMethods::move(arr_vertex, Pd, 0, 1, 0, nCol, nRows);
					dy += 1;
				}
				else if (radioButtonProjY->Checked) {
					MatrixMethods::move(arr_vertex, Pd, 0, 0, 1, nCol, nRows);
					dz += 1;
				}
				else if (radioButtonProjZ->Checked) {

					MatrixMethods::move(arr_vertex, Pd, 0, 1, 0, nCol, nRows);
					dy += 1;
				}


				drawFigure();

				y = ((MouseEventArgs^)e)->Y;

			}
			if (((MouseEventArgs^)e)->Y < y) {

				if (radioButtonProjX->Checked) {
					MatrixMethods::move(arr_vertex, Pd, 0, -1, 0, nCol, nRows);
					dy -= 1;
				}
				else if (radioButtonProjY->Checked) {
					MatrixMethods::move(arr_vertex, Pd, 0, 0, -1, nCol, nRows);
					dz -= 1;
				}
				else if (radioButtonProjZ->Checked) {

					MatrixMethods::move(arr_vertex, Pd, 0, -1, 0, nCol, nRows);
					dy -= 1;
				}


				drawFigure();

				y = ((MouseEventArgs^)e)->Y;

			}

			if (((MouseEventArgs^)e)->X > x) {

				if (radioButtonProjX->Checked) {
					MatrixMethods::move(arr_vertex, Pd, 0, 0, -1, nCol, nRows);
					dz -= 1;
				}
				else if (radioButtonProjY->Checked) {
					MatrixMethods::move(arr_vertex, Pd, 1, 0, 0, nCol, nRows);
					dx += 1;
				}
				else if (radioButtonProjZ->Checked) {

					MatrixMethods::move(arr_vertex, Pd, 1, 0, 0, nCol, nRows);
					dx += 1;
				}


				drawFigure();

				x = ((MouseEventArgs^)e)->X;


			}
			if (((MouseEventArgs^)e)->X < x) {

				if (radioButtonProjX->Checked) {
					MatrixMethods::move(arr_vertex, Pd, 0, 0, 1, nCol, nRows);
					dz += 1;
				}
				else if (radioButtonProjY->Checked) {
					MatrixMethods::move(arr_vertex, Pd, -1, 0, 0, nCol, nRows);
					dx -= 1;
				}
				else if (radioButtonProjZ->Checked) {

					MatrixMethods::move(arr_vertex, Pd, -1, 0, 0, nCol, nRows);
					dx -= 1;
				}


				drawFigure();

				x = ((MouseEventArgs^)e)->X;


			}
		}


	} // end if isConverting

}

System::Void Solovev_Platonic_Solids::MyForm::pictureBoxForDraw_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	/*if (radioButtonCarousel->Checked == false &&
	radioButtonSelfRotating->Checked == false &&
	((MouseEventArgs^)e)->Button == System::Windows::Forms::MouseButtons::Left) {
	MessageBox::Show("Режим вращения не выбран! Пожалуйста, выберите режим.",
	"Режим вращения", MessageBoxButtons::OK,
	MessageBoxIcon::Asterisk);
	}*/
	isConverting = true;
	x = ((MouseEventArgs^)e)->X;
	y = ((MouseEventArgs^)e)->Y;

}

System::Void Solovev_Platonic_Solids::MyForm::pictureBoxForDraw_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	isConverting = false;
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarZ_ValueChanged(System::Object^  sender, System::EventArgs^  e) {


	textBoxInfoZ->Text = "" + hScrollBarZ->Value;

	if (radioButtonCarousel->Checked) {
		MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi * (hScrollBarZ->Value - scrollZ), nCol, nRows);
		MatrixMethods::rotateOZ(arr_vertex, Rz, Phi * (hScrollBarZ->Value - scrollZ), nCol, nRows);
	}
	else if (radioButtonSelfRotating->Checked) {
		MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi * (hScrollBarZ->Value - scrollZ), nCol, nRows);
		copyVertexArray();
		MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
	}

	drawFigure();

	scrollZ = hScrollBarZ->Value;
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	textBoxInfoY->Text = "" + hScrollBarY->Value;

	if (radioButtonCarousel->Checked) {
		MatrixMethods::rotateOY(arr_vertexCopy, Ry, Phi * (hScrollBarY->Value - scrollY), nCol, nRows);
		MatrixMethods::rotateOY(arr_vertex, Ry, Phi * (hScrollBarY->Value - scrollY), nCol, nRows);
	}
	else if (radioButtonSelfRotating->Checked) {
		MatrixMethods::rotateOY(arr_vertexCopy, Ry, Phi * (hScrollBarY->Value - scrollY), nCol, nRows);
		copyVertexArray();
		MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
	}
	drawFigure();

	scrollY = hScrollBarY->Value;
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	textBoxInfoX->Text = "" + hScrollBarX->Value;

	if (radioButtonCarousel->Checked) {
		MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi * (hScrollBarX->Value - scrollX), nCol, nRows);
		MatrixMethods::rotateOX(arr_vertex, Rx, Phi * (hScrollBarX->Value - scrollX), nCol, nRows);
	}
	else if (radioButtonSelfRotating->Checked) {
		MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi * (hScrollBarX->Value - scrollX), nCol, nRows);
		copyVertexArray();
		MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
	}
	drawFigure();

	scrollX = hScrollBarX->Value;
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarS_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	int fig_size = 1;
	if (type == 1) {
		fig_size = pyramid.size / 2;
	}
	else if (type == 2) {
		fig_size = size_oct / 3;
	}
	else if (type == 3) {
		fig_size = size_icos;
	}
	else if (type == 4) {
		fig_size = size_sphere;
	}
	else if (type == 5) {
		fig_size = size_torus;
	}
	else if (type == 6) {
		fig_size = size_sphere;
	}
	else if (type == 7) {
		fig_size = size_torus;
	}

	double s = 0;
	if ((hScrollBarS->Value - scrollS) > 0) {
		s = 1 + ((hScrollBarS->Value - scrollS)*1.0 / (fig_size));
	}
	else {
		s = 1 - ((scrollS - hScrollBarS->Value)*1.0 / (fig_size));
	}

	double p = s;
	double q = s;
	double r = s;

	MatrixMethods::scale(arr_vertexCopy, Ps, p, q, r, 1, nCol, nRows);
	MatrixMethods::scale(arr_vertex, Ps, p, q, r, 1, nCol, nRows);

	drawFigure();
	scrollS = hScrollBarS->Value;
}

System::Void Solovev_Platonic_Solids::MyForm::resetFigure() {

	if (type == 1) {
		initializePyramid();
	}
	else if (type == 2) {
		initializeOctahedron();
	}
	else if (type == 3) {
		initializeIcosahedron();
	}
	else if (type == 4) {
		initializeSphere();
	}
	else if (type == 5) {
		initializeTorus();
	}
	else if (type == 6) {
		initializeGarlic();
	}
	else if (type == 7) {
		initializeSpring();
	}

	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::buttonReset_Click(System::Object^  sender, System::EventArgs^  e) {

	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::resetAll() {

	initializeMoveScrolls();
	initializeScrollsForRotate();
	initializeXRotationalScroll();
	initializeLRotationalScroll();

	hScrollBarS->Value = 50;
	scrollS = 50;
	isConverting = false;

	x = 0;
	y = 0;
	dx = 0;
	dy = 0;

	resetFigure();

	radioButtonProjX->Checked = false;
	radioButtonProjY->Checked = false;
	radioButtonProjZ->Checked = true;

	radioButtonCarousel->Checked = true;
	radioButtonSelfRotating->Checked = false;

	checkBoxRotatePXCarousel->Checked = true;
}

System::Void Solovev_Platonic_Solids::MyForm::radioButtonCarousel_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	initializeScrollsForRotate();

}

System::Void Solovev_Platonic_Solids::MyForm::radioButtonSelfRotating_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (radioButtonSelfRotating->Checked) {
		copyVertexArray();
		MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
		drawFigure();
		initializeScrollsForRotate();

	}

}

System::Void Solovev_Platonic_Solids::MyForm::initializeScrollsForRotate() {

	scrollX = 0;
	hScrollBarX->Value = 0;
	textBoxInfoX->Text = "0";

	scrollY = 0;
	hScrollBarY->Value = 0;
	textBoxInfoY->Text = "0";

	scrollZ = 0;
	hScrollBarZ->Value = 0;
	textBoxInfoZ->Text = "0";

}

System::Void Solovev_Platonic_Solids::MyForm::copyVertexArray() {
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCol; j++) {
			arr_vertex[i][j] = arr_vertexCopy[i][j];
		}
	}
}


System::Void Solovev_Platonic_Solids::MyForm::initializeMatrices() {
	Rx = gcnew cli::array<array<double>^>(4);
	Ry = gcnew cli::array<array<double>^>(4);
	Rz = gcnew cli::array<array<double>^>(4);
	Pd = gcnew cli::array<array<double>^>(4);
	Ps = gcnew cli::array<array<double>^>(4);
	Pz = gcnew cli::array<array<double>^>(4);
	for (int i = 0; i < 4; i++) {
		Rx[i] = gcnew cli::array<double>(4);
		Ry[i] = gcnew cli::array<double>(4);
		Rz[i] = gcnew cli::array<double>(4);
		Pd[i] = gcnew cli::array<double>(4);
		Ps[i] = gcnew cli::array<double>(4);
		Pz[i] = gcnew cli::array<double>(4);
		for (int j = 0; j < 4; j++) {
			Rx[i][j] = 0.0;
			Ry[i][j] = 0.0;
			Rz[i][j] = 0.0;
			if (i == j) {
				Pd[i][j] = 1.0;
			}
			else {
				Pd[i][j] = 0.0;
			}
			Ps[i][j] = 0.0;
			Pz[i][j] = 0.0;
		}
	}
}



System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemPyramid_Click(System::Object^  sender, System::EventArgs^  e) {
	initializePyramid();
	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemSphere_Click(System::Object^  sender, System::EventArgs^  e) {
	initializeSphere();
	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemTorus_Click(System::Object^  sender, System::EventArgs^  e) {
	initializeTorus();
	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemOctahedron_Click(System::Object^  sender, System::EventArgs^  e) {
	initializeOctahedron();
	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemIcosahedron_Click(System::Object^  sender, System::EventArgs^  e) {
	initializeIcosahedron();
	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemGarlic_Click(System::Object^  sender, System::EventArgs^  e) {
	initializeGarlic();
	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::ToolStripMenuItemSpring_Click(System::Object^  sender, System::EventArgs^  e) {
	initializeSpring();
	resetAll();
}

System::Void Solovev_Platonic_Solids::MyForm::radioButtonOP_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::radioButtonCP_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::drawAxes() {
	// Рисуем оси координат

	g->FillEllipse(sp, w - 2, h - 2, 4, 4);

	if (radioButtonProjX->Checked) {
		g->DrawString("Z", font, sb, (float)(w - 218), (float)h);
		g->DrawString("Y", font, sb, (float)(w + 8), (float)(h + 180));
		g->DrawString("X", font, sb, (float)(w + 2), (float)(h - 18));

		g->DrawLine(pp, w, h, w - 200, h);
		g->DrawLine(pp, w - 192, h + 5, w - 200, h);
		g->DrawLine(pp, w - 192, h - 5, w - 200, h);


		g->DrawLine(pp, w, h, w, h + 200);
		g->DrawLine(pp, w + 5, h + 192, w, h + 200);
		g->DrawLine(pp, w - 5, h + 192, w, h + 200);
	}
	else if (radioButtonProjY->Checked) {
		g->DrawString("X", font, sb, (float)(w + 200), (float)h);
		g->DrawString("Z", font, sb, (float)(w + 8), (float)(h + 180));
		g->DrawString("Y", font, sb, (float)(w - 18), (float)(h - 18));

		g->DrawLine(pp, w, h, w + 200, h);
		g->DrawLine(pp, w + 192, h + 5, w + 200, h);
		g->DrawLine(pp, w + 192, h - 5, w + 200, h);

		g->DrawLine(pp, w, h, w, h + 200);
		g->DrawLine(pp, w + 5, h + 192, w, h + 200);
		g->DrawLine(pp, w - 5, h + 192, w, h + 200);
	}
	else if (radioButtonProjZ->Checked) {

		g->DrawString("X", font, sb, (float)(w + 200), (float)h);
		g->DrawString("Y", font, sb, (float)(w + 8), (float)(h + 180));
		g->DrawString("Z", font, sb, (float)(w - 18), (float)(h - 18));

		g->DrawLine(pp, w, h, w + 200, h);
		g->DrawLine(pp, w + 192, h + 5, w + 200, h);
		g->DrawLine(pp, w + 192, h - 5, w + 200, h);

		g->DrawLine(pp, w, h, w, h + 200);
		g->DrawLine(pp, w + 5, h + 192, w, h + 200);
		g->DrawLine(pp, w - 5, h + 192, w, h + 200);
	}

}

System::Void Solovev_Platonic_Solids::MyForm::setProjection() {

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCol; j++) {
			arrProjection[i][j] = arr_vertex[i][j];
		}
	}

	if (radioButtonProjX->Checked) {
		MatrixMethods::rotateOY(arrProjection, Ry, -PI / 2, nCol, nRows);
	}
	else if (radioButtonProjY->Checked) {
		MatrixMethods::rotateOX(arrProjection, Rx, -PI / 2, nCol, nRows);
	}

	if (radioButtonCP->Checked) {
		MatrixMethods::centralProjection(arrProjection, Pz, z0, nCol, nRows);
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < 2; j++) {
				arrProjection[i][j] /= arrProjection[i][3];
			}
		}
	}
	else if (radioButtonOP->Checked) {
		MatrixMethods::orthogonalProjection(arrProjection, Pz, nCol, nRows);
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < 2; j++) {
				arrProjection[i][j] /= arrProjection[i][3];
			}
		}
	}


}

System::Void Solovev_Platonic_Solids::MyForm::initializeMoveScrolls() {
	scrollMoveX = w;
	scrollMoveY = h;
	scrollMoveZ = 0;

	hScrollBarMoveX->Minimum = 0;
	hScrollBarMoveY->Minimum = 0;
	hScrollBarMoveZ->Minimum = -500;

	hScrollBarMoveX->Maximum = width;
	hScrollBarMoveY->Maximum = height;
	hScrollBarMoveZ->Maximum = 500;

	hScrollBarMoveX->Value = w;
	hScrollBarMoveY->Value = h;
	hScrollBarMoveZ->Value = 0;
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarMoveX_Scroll(System::Object^  sender,
	System::Windows::Forms::ScrollEventArgs^  e) {

	MatrixMethods::move(arr_vertex, Pd, hScrollBarMoveX->Value - scrollMoveX, 0, 0, nCol, nRows);
	dx += hScrollBarMoveX->Value - scrollMoveX;

	scrollMoveX = hScrollBarMoveX->Value;
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarMoveY_Scroll(System::Object^  sender,
	System::Windows::Forms::ScrollEventArgs^  e) {

	MatrixMethods::move(arr_vertex, Pd, 0, hScrollBarMoveY->Value - scrollMoveY, 0, nCol, nRows);
	dy += hScrollBarMoveY->Value - scrollMoveY;

	scrollMoveY = hScrollBarMoveY->Value;
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarMoveZ_Scroll(System::Object^  sender,
	System::Windows::Forms::ScrollEventArgs^  e) {

	MatrixMethods::move(arr_vertex, Pd, 0, 0, hScrollBarMoveZ->Value - scrollMoveZ, nCol, nRows);
	dz += hScrollBarMoveZ->Value - scrollMoveZ;

	scrollMoveZ = hScrollBarMoveZ->Value;
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::initializeXRotationalScroll() {
	// Вращение вокруг прямой Х
	scrollPXrotate = 0;
	hScrollBarParX->Value = 0;
	textBoxXPcoordY->Text = "0";
	textBoxXPcoordZ->Text = "0";
	pxCoordY = 0.0;
	pxCoordZ = 0.0;
	hScrollBarParX->Enabled = true;
}

System::Void Solovev_Platonic_Solids::MyForm::textBoxXPcoordY_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	try
	{
		pxCoordY = Double::Parse(textBoxXPcoordY->Text);
		pxCoordZ = Double::Parse(textBoxXPcoordZ->Text);
		hScrollBarParX->Enabled = true;



		if (checkBoxRotatePXCarousel->Checked == false) {
			copyVertexArray();
			MatrixMethods::move(arr_vertex, Pd, 0, (int)pxCoordY, (int)pxCoordZ, nCol, nRows);
		}
		else {
			copyVertexArray();
			MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
		}

	}
	catch (...)
	{
		hScrollBarParX->Enabled = false;
	}

}

System::Void Solovev_Platonic_Solids::MyForm::textBoxXPcoordZ_TextChanged(System::Object^  sender,
	System::EventArgs^  e) {
	try
	{
		pxCoordY = Double::Parse(textBoxXPcoordY->Text);
		pxCoordZ = Double::Parse(textBoxXPcoordZ->Text);
		hScrollBarParX->Enabled = true;


		if (checkBoxRotatePXCarousel->Checked == false) {
			copyVertexArray();
			MatrixMethods::move(arr_vertex, Pd, 0, (int)pxCoordY, (int)pxCoordZ, nCol, nRows);
		}
		else {
			copyVertexArray();
			MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);
		}

	}
	catch (...)
	{
		hScrollBarParX->Enabled = false;
	}
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarParX_ValueChanged(System::Object^  sender,
	System::EventArgs^  e) {

	if (checkBoxRotatePXCarousel->Checked) {
		//copyVertexArray();
		MatrixMethods::move(arr_vertex, Pd, 0, (int)-pxCoordY, (int)-pxCoordZ, nCol, nRows);
		MatrixMethods::rotateOX(arr_vertex, Rx, Phi * (hScrollBarParX->Value - scrollPXrotate), nCol, nRows);
		//MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi * (hScrollBarParX->Value - scrollPXrotate), nCol, nRows);
		MatrixMethods::move(arr_vertex, Pd, 0, (int)pxCoordY, (int)pxCoordZ, nCol, nRows);
		//MatrixMethods::move(arr_vertex, Pd, dx, dy, dz, nCol, nRows);

	}
	else {
		MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi * (hScrollBarParX->Value - scrollPXrotate), nCol, nRows);
		copyVertexArray();
		MatrixMethods::move(arr_vertex, Pd, 0, (int)pxCoordY, (int)pxCoordZ, nCol, nRows);
	}

	scrollPXrotate = hScrollBarParX->Value;
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::hScrollBarLRotate_ValueChanged(System::Object^  sender,
	System::EventArgs^  e) {

	double norm = sqrt(l*l + m*m + n*n);
	l /= norm;
	m /= norm;
	n /= norm;

	double d = sqrt(m*m + n*n);

	if (m == 0.0 && n == 0.0) {
		MatrixMethods::rotateOX(arr_vertexCopy, Rx, Phi * (hScrollBarLRotate->Value - scrollLRotate), nCol, nRows);
	}
	else if (l == 0.0 && n == 0.0) {
		MatrixMethods::rotateOY(arr_vertexCopy, Ry, Phi * (hScrollBarLRotate->Value - scrollLRotate), nCol, nRows);
	}
	else if (l == 0.0 && m == 0.0) {
		MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi * (hScrollBarLRotate->Value - scrollLRotate), nCol, nRows);
	}
	else {
		MatrixMethods::rotateOX(arr_vertexCopy, Rx, (asin(m *1.0 / d)), nCol, nRows);
		MatrixMethods::rotateOY(arr_vertexCopy, Ry, (asin(-d*1.0)), nCol, nRows);
		MatrixMethods::rotateOZ(arr_vertexCopy, Rz, Phi * (hScrollBarLRotate->Value - scrollLRotate), nCol, nRows);
		MatrixMethods::rotateOY(arr_vertexCopy, Ry, -(asin(-d*1.0)), nCol, nRows);
		MatrixMethods::rotateOX(arr_vertexCopy, Rx, -(asin(m *1.0 / d)), nCol, nRows);
	}

	copyVertexArray();
	MatrixMethods::move(arr_vertex, Pd, (int)a, (int)b, (int)c, nCol, nRows);

	scrollLRotate = hScrollBarLRotate->Value;
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::textBox_a_TextChanged(System::Object^  sender,
	System::EventArgs^  e) {
	checkLCoordinates();
}

System::Void Solovev_Platonic_Solids::MyForm::textBox_b_TextChanged(System::Object^  sender,
	System::EventArgs^  e) {
	checkLCoordinates();
}

System::Void Solovev_Platonic_Solids::MyForm::textBox_c_TextChanged(System::Object^  sender,
	System::EventArgs^  e) {
	checkLCoordinates();
}

System::Void Solovev_Platonic_Solids::MyForm::textBox_l_TextChanged(System::Object^  sender,
	System::EventArgs^  e) {
	checkLCoordinates();
}

System::Void Solovev_Platonic_Solids::MyForm::textBox_m_TextChanged(System::Object^  sender,
	System::EventArgs^  e) {
	checkLCoordinates();
}

System::Void Solovev_Platonic_Solids::MyForm::textBox_n_TextChanged(System::Object^  sender,
	System::EventArgs^  e) {
	checkLCoordinates();
}

System::Void Solovev_Platonic_Solids::MyForm::checkLCoordinates() {
	try
	{
		a = Double::Parse(textBox_a->Text);
		b = Double::Parse(textBox_b->Text);
		c = Double::Parse(textBox_c->Text);

		l = Double::Parse(textBox_l->Text);
		m = Double::Parse(textBox_m->Text);
		n = Double::Parse(textBox_n->Text);

		hScrollBarLRotate->Enabled = true;

		copyVertexArray();
		MatrixMethods::move(arr_vertex, Pd, (int)a, (int)b, (int)c, nCol, nRows);
	}
	catch (...)
	{
		hScrollBarLRotate->Enabled = false;
	}
}

System::Void Solovev_Platonic_Solids::MyForm::initializeLRotationalScroll() {
	// Вращение вокруг прямой L
	scrollLRotate = 0;
	hScrollBarLRotate->Value = 0;

	textBox_a->Text = "0";
	textBox_b->Text = "0";
	textBox_c->Text = "0";
	textBox_l->Text = "1";
	textBox_m->Text = "1";
	textBox_n->Text = "0";

	a = 0.0;
	b = 0.0;
	c = 0.0;
	l = 1.0;
	m = 1.0;
	n = 0.0;

	hScrollBarLRotate->Enabled = true;
}


System::Void Solovev_Platonic_Solids::MyForm::radioButtonProjZ_CheckedChanged(System::Object^  sender,
	System::EventArgs^  e) {
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::radioButtonProjY_CheckedChanged(System::Object^  sender,
	System::EventArgs^  e) {
	drawFigure();
}

System::Void Solovev_Platonic_Solids::MyForm::radioButtonProjX_CheckedChanged(System::Object^  sender,
	System::EventArgs^  e) {
	drawFigure();
}