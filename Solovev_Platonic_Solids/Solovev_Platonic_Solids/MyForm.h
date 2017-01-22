#pragma once


#include "MyFormAbout.h"
#include "MyPyramid.cpp"
#include "MatrixMethods.cpp"
#include "math.h"
#include "sphere.h"
#include "torus.h"
#include "octahedron.h"
#include "icosahedron.h"


// Студент: Соловьев Андрей
// Группа: БПИ122(2)
// Семинар 5: 3D моделирование тел вращения и платоновых тел
// Дата: 23.10.2015
// Среда разработки: Visual Studio 2013
// Реализованы алгоритмы вращения, сдвига, масштабирования
// и проецирования тел вращения и платоновых тел.

namespace Solovev_Platonic_Solids {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Для использования одних и тех же переменных в разных .cpp файлах
	// (избежание множественной инициализации)
	namespace  
	{
		// Для инициализации координат пирамиды
		MyPyramid pyramid;

		// Число "Пи"
		double PI = 3.1415926535897932384626433832795;
	}

	// Число столбцов в матрицах преобразований
	const int nCol = 4;

	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:
		Bitmap^ bm;
		Graphics^ g;
		Pen^ pb;
		Pen^ pp;
		SolidBrush^ sb;
		SolidBrush^ sp;
		System::Drawing::Font^ font;

		// Ширина и высота области для рисования
		int width;
		int height;

		// Ширина и высота области для рисования, деленные на 2
		int w;
		int h;


		// переменная, равная одному градусу в радианах
		double Phi;

		// Считывание координат мыши для вращения и перемещения
		int x;
		int y;

		// Определение того, что мышь нажата и необходимо изменять фигуру
		bool isConverting;


		int scrollZ; // вращение по оси Z
		int scrollY; // вращение по оси Y
		int scrollX; // вращение по оси X

		int scrollMoveZ; // перемещение по оси Z
		int scrollMoveY; // перемещение по оси Y
		int scrollMoveX; // перемещение по оси X

		// Вращение относительно параллельной прямой Х
		int scrollPXrotate;
		double pxCoordY;
		double pxCoordZ;

		// Вращение относителньо произвольной прямой L
		int scrollLRotate;
		double a;
		double b;
		double c;
		double l;
		double m;
		double n;


		int scrollS; // масштабирование

		// Матрица вершин объекта:
		cli::array<array<double>^>^ arr_vertex;
		int nRows;
		int type;

		// Матрица вершин объекта в начале координат (используется для вращения):
		cli::array<array<double>^>^ arr_vertexCopy;

		// Матрица проекций
		cli::array<array<double>^>^ arrProjection;
		int z0;

		int dx;
		int dy;
		int dz;

		// Матрица граней:
		cli::array<int>^ arr_face;

		// Матрицы вращения:
		cli::array<array<double>^>^ Rx;
		cli::array<array<double>^>^ Ry;
		cli::array<array<double>^>^ Rz;

		// Матрица сдвига:
		cli::array<array<double>^>^ Pd;

		// Матрица для центрального и ортогонального проецирования
		cli::array<array<double>^>^ Pz;

		// Матрица масштабирования:
		cli::array<array<double>^>^ Ps;
	private: System::Windows::Forms::HScrollBar^  hScrollBarZ;
	private: System::Windows::Forms::GroupBox^  groupBoxRotate;

	private: System::Windows::Forms::Button^  buttonReset;
	private: System::Windows::Forms::GroupBox^  groupBoxRotationType;
	private: System::Windows::Forms::RadioButton^  radioButtonSelfRotating;

	private: System::Windows::Forms::RadioButton^  radioButtonCarousel;
	private: System::Windows::Forms::Label^  labelInfoZ;

	private: System::Windows::Forms::GroupBox^  groupBoxScaling;
	private: System::Windows::Forms::HScrollBar^  hScrollBarS;
	private: System::Windows::Forms::TextBox^  textBoxInfoX;
	private: System::Windows::Forms::TextBox^  textBoxInfoY;
	private: System::Windows::Forms::Label^  labelInfoX;
	private: System::Windows::Forms::Label^  labelInfoY;
	private: System::Windows::Forms::HScrollBar^  hScrollBarX;
	private: System::Windows::Forms::HScrollBar^  hScrollBarY;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemPyramid;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemOctahedron;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemIcosahedron;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemSphere;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemTorus;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemGarlic;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemSpring;
	private: System::Windows::Forms::GroupBox^  groupBoxProjection;
	private: System::Windows::Forms::RadioButton^  radioButtonCP;
	private: System::Windows::Forms::RadioButton^  radioButtonOP;
	private: System::Windows::Forms::GroupBox^  groupBoxMove;
	private: System::Windows::Forms::Label^  labelMoveZ;
	private: System::Windows::Forms::Label^  labelMoveY;
	private: System::Windows::Forms::Label^  labelMoveX;
	private: System::Windows::Forms::HScrollBar^  hScrollBarMoveZ;
	private: System::Windows::Forms::HScrollBar^  hScrollBarMoveY;
	private: System::Windows::Forms::HScrollBar^  hScrollBarMoveX;
	private: System::Windows::Forms::GroupBox^  groupBoxXParallelRotate;


	private: System::Windows::Forms::HScrollBar^  hScrollBarParX;
	private: System::Windows::Forms::TextBox^  textBoxXPcoordZ;
	private: System::Windows::Forms::TextBox^  textBoxXPcoordY;
	private: System::Windows::Forms::Label^  labelXParallelZcoord;
	private: System::Windows::Forms::Label^  labelXParallelYcoord;
	private: System::Windows::Forms::GroupBox^  groupBoxLRotate;

	private: System::Windows::Forms::Label^  label_vec;
	private: System::Windows::Forms::Label^  label_Ades;

	private: System::Windows::Forms::TextBox^  textBox_n;

	private: System::Windows::Forms::TextBox^  textBox_m;

	private: System::Windows::Forms::TextBox^  textBox_l;

	private: System::Windows::Forms::TextBox^  textBox_c;
	private: System::Windows::Forms::TextBox^  textBox_b;
	private: System::Windows::Forms::TextBox^  textBox_a;
	private: System::Windows::Forms::Label^  label_c;

	private: System::Windows::Forms::Label^  label_b;

	private: System::Windows::Forms::Label^  label_a;
	private: System::Windows::Forms::HScrollBar^  hScrollBarLRotate;
	private: System::Windows::Forms::Label^  label_n;
	private: System::Windows::Forms::Label^  label_m;
	private: System::Windows::Forms::Label^  label_l;
	private: System::Windows::Forms::CheckBox^  checkBoxRotatePXCarousel;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButtonProjZ;
	private: System::Windows::Forms::RadioButton^  radioButtonProjY;
	private: System::Windows::Forms::RadioButton^  radioButtonProjX;







	private: System::Windows::Forms::TextBox^  textBoxInfoZ;


	public:
		MyForm(void)
		{
			InitializeComponent();
			bm = gcnew Bitmap(pictureBoxForDraw->Width, pictureBoxForDraw->Height);
			pictureBoxForDraw->Image = bm;
			g = Graphics::FromImage(bm);
			g->Clear(Color::White);
			pb = gcnew Pen(Color::Black, 1);
			pp = gcnew Pen(Color::Purple, 1);

			sb = gcnew SolidBrush(Color::Black);
			sp = gcnew SolidBrush(Color::Purple);
			font = gcnew System::Drawing::Font("Arial", 12);


			width = pictureBoxForDraw->Width;
			height = pictureBoxForDraw->Height;
			w = width / 2;
			h = 5*height / 12;
			isConverting = false;
			Phi = (PI *1.0) / 180.0;
			initializeMoveScrolls();
			initializeScrollsForRotate();
			initializeXRotationalScroll();
			initializeLRotationalScroll();
			hScrollBarS->Value = 50;
			scrollS = 50;

			x = 0;
			y = 0;
			dx = 0;
			dy = 0;

			// Инициализация матриц вращения, сдвига и масштабирования
			initializeMatrices();
			initializeGarlic();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			delete bm;
			delete g;
			delete pb;
			delete pp;
			delete sb;
			delete sp;
			delete font;


			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBoxForDraw;
	protected:

	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemAbout;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBoxForDraw = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ToolStripMenuItemAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemPyramid = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemOctahedron = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemIcosahedron = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemSphere = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemTorus = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemGarlic = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemSpring = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxInfoZ = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBarZ = (gcnew System::Windows::Forms::HScrollBar());
			this->groupBoxRotate = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxInfoX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxInfoY = (gcnew System::Windows::Forms::TextBox());
			this->labelInfoX = (gcnew System::Windows::Forms::Label());
			this->labelInfoY = (gcnew System::Windows::Forms::Label());
			this->hScrollBarX = (gcnew System::Windows::Forms::HScrollBar());
			this->groupBoxRotationType = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonSelfRotating = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonCarousel = (gcnew System::Windows::Forms::RadioButton());
			this->hScrollBarY = (gcnew System::Windows::Forms::HScrollBar());
			this->labelInfoZ = (gcnew System::Windows::Forms::Label());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->groupBoxScaling = (gcnew System::Windows::Forms::GroupBox());
			this->hScrollBarS = (gcnew System::Windows::Forms::HScrollBar());
			this->groupBoxProjection = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonCP = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonOP = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxMove = (gcnew System::Windows::Forms::GroupBox());
			this->labelMoveZ = (gcnew System::Windows::Forms::Label());
			this->labelMoveY = (gcnew System::Windows::Forms::Label());
			this->labelMoveX = (gcnew System::Windows::Forms::Label());
			this->hScrollBarMoveZ = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBarMoveY = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBarMoveX = (gcnew System::Windows::Forms::HScrollBar());
			this->groupBoxXParallelRotate = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxRotatePXCarousel = (gcnew System::Windows::Forms::CheckBox());
			this->hScrollBarParX = (gcnew System::Windows::Forms::HScrollBar());
			this->textBoxXPcoordZ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxXPcoordY = (gcnew System::Windows::Forms::TextBox());
			this->labelXParallelZcoord = (gcnew System::Windows::Forms::Label());
			this->labelXParallelYcoord = (gcnew System::Windows::Forms::Label());
			this->groupBoxLRotate = (gcnew System::Windows::Forms::GroupBox());
			this->hScrollBarLRotate = (gcnew System::Windows::Forms::HScrollBar());
			this->label_n = (gcnew System::Windows::Forms::Label());
			this->label_m = (gcnew System::Windows::Forms::Label());
			this->label_l = (gcnew System::Windows::Forms::Label());
			this->label_c = (gcnew System::Windows::Forms::Label());
			this->label_b = (gcnew System::Windows::Forms::Label());
			this->label_a = (gcnew System::Windows::Forms::Label());
			this->label_vec = (gcnew System::Windows::Forms::Label());
			this->label_Ades = (gcnew System::Windows::Forms::Label());
			this->textBox_n = (gcnew System::Windows::Forms::TextBox());
			this->textBox_m = (gcnew System::Windows::Forms::TextBox());
			this->textBox_l = (gcnew System::Windows::Forms::TextBox());
			this->textBox_c = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b = (gcnew System::Windows::Forms::TextBox());
			this->textBox_a = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonProjZ = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonProjY = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonProjX = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxForDraw))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBoxRotate->SuspendLayout();
			this->groupBoxRotationType->SuspendLayout();
			this->groupBoxScaling->SuspendLayout();
			this->groupBoxProjection->SuspendLayout();
			this->groupBoxMove->SuspendLayout();
			this->groupBoxXParallelRotate->SuspendLayout();
			this->groupBoxLRotate->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBoxForDraw
			// 
			this->pictureBoxForDraw->Location = System::Drawing::Point(12, 363);
			this->pictureBoxForDraw->Name = L"pictureBoxForDraw";
			this->pictureBoxForDraw->Size = System::Drawing::Size(1060, 580);
			this->pictureBoxForDraw->TabIndex = 0;
			this->pictureBoxForDraw->TabStop = false;
			this->pictureBoxForDraw->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBoxForDraw_MouseDown);
			this->pictureBoxForDraw->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBoxForDraw_MouseMove);
			this->pictureBoxForDraw->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBoxForDraw_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->ToolStripMenuItemAbout,
					this->ToolStripMenuItemPyramid, this->ToolStripMenuItemOctahedron, this->ToolStripMenuItemIcosahedron, this->ToolStripMenuItemSphere,
					this->ToolStripMenuItemTorus, this->ToolStripMenuItemGarlic, this->ToolStripMenuItemSpring
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1084, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ToolStripMenuItemAbout
			// 
			this->ToolStripMenuItemAbout->Name = L"ToolStripMenuItemAbout";
			this->ToolStripMenuItemAbout->Size = System::Drawing::Size(116, 24);
			this->ToolStripMenuItemAbout->Text = L"О программе";
			this->ToolStripMenuItemAbout->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemAbout_Click);
			// 
			// ToolStripMenuItemPyramid
			// 
			this->ToolStripMenuItemPyramid->Name = L"ToolStripMenuItemPyramid";
			this->ToolStripMenuItemPyramid->Size = System::Drawing::Size(84, 24);
			this->ToolStripMenuItemPyramid->Text = L"Тетраэдр";
			this->ToolStripMenuItemPyramid->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemPyramid_Click);
			// 
			// ToolStripMenuItemOctahedron
			// 
			this->ToolStripMenuItemOctahedron->Name = L"ToolStripMenuItemOctahedron";
			this->ToolStripMenuItemOctahedron->Size = System::Drawing::Size(77, 24);
			this->ToolStripMenuItemOctahedron->Text = L"Октаэдр";
			this->ToolStripMenuItemOctahedron->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemOctahedron_Click);
			// 
			// ToolStripMenuItemIcosahedron
			// 
			this->ToolStripMenuItemIcosahedron->Name = L"ToolStripMenuItemIcosahedron";
			this->ToolStripMenuItemIcosahedron->Size = System::Drawing::Size(87, 24);
			this->ToolStripMenuItemIcosahedron->Text = L"Икосаэдр";
			this->ToolStripMenuItemIcosahedron->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemIcosahedron_Click);
			// 
			// ToolStripMenuItemSphere
			// 
			this->ToolStripMenuItemSphere->Name = L"ToolStripMenuItemSphere";
			this->ToolStripMenuItemSphere->Size = System::Drawing::Size(65, 24);
			this->ToolStripMenuItemSphere->Text = L"Сфера";
			this->ToolStripMenuItemSphere->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemSphere_Click);
			// 
			// ToolStripMenuItemTorus
			// 
			this->ToolStripMenuItemTorus->Name = L"ToolStripMenuItemTorus";
			this->ToolStripMenuItemTorus->Size = System::Drawing::Size(47, 24);
			this->ToolStripMenuItemTorus->Text = L"Тор";
			this->ToolStripMenuItemTorus->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemTorus_Click);
			// 
			// ToolStripMenuItemGarlic
			// 
			this->ToolStripMenuItemGarlic->Name = L"ToolStripMenuItemGarlic";
			this->ToolStripMenuItemGarlic->Size = System::Drawing::Size(71, 24);
			this->ToolStripMenuItemGarlic->Text = L"Чеснок";
			this->ToolStripMenuItemGarlic->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemGarlic_Click);
			// 
			// ToolStripMenuItemSpring
			// 
			this->ToolStripMenuItemSpring->Name = L"ToolStripMenuItemSpring";
			this->ToolStripMenuItemSpring->Size = System::Drawing::Size(85, 24);
			this->ToolStripMenuItemSpring->Text = L"Пружина";
			this->ToolStripMenuItemSpring->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItemSpring_Click);
			// 
			// textBoxInfoZ
			// 
			this->textBoxInfoZ->Location = System::Drawing::Point(443, 75);
			this->textBoxInfoZ->Name = L"textBoxInfoZ";
			this->textBoxInfoZ->ReadOnly = true;
			this->textBoxInfoZ->Size = System::Drawing::Size(44, 22);
			this->textBoxInfoZ->TabIndex = 2;
			this->textBoxInfoZ->TabStop = false;
			// 
			// hScrollBarZ
			// 
			this->hScrollBarZ->LargeChange = 1;
			this->hScrollBarZ->Location = System::Drawing::Point(13, 75);
			this->hScrollBarZ->Maximum = 360;
			this->hScrollBarZ->Minimum = -360;
			this->hScrollBarZ->Name = L"hScrollBarZ";
			this->hScrollBarZ->Size = System::Drawing::Size(203, 21);
			this->hScrollBarZ->TabIndex = 4;
			this->hScrollBarZ->ValueChanged += gcnew System::EventHandler(this, &MyForm::hScrollBarZ_ValueChanged);
			// 
			// groupBoxRotate
			// 
			this->groupBoxRotate->Controls->Add(this->textBoxInfoX);
			this->groupBoxRotate->Controls->Add(this->textBoxInfoY);
			this->groupBoxRotate->Controls->Add(this->labelInfoX);
			this->groupBoxRotate->Controls->Add(this->labelInfoY);
			this->groupBoxRotate->Controls->Add(this->hScrollBarX);
			this->groupBoxRotate->Controls->Add(this->groupBoxRotationType);
			this->groupBoxRotate->Controls->Add(this->hScrollBarY);
			this->groupBoxRotate->Controls->Add(this->labelInfoZ);
			this->groupBoxRotate->Controls->Add(this->hScrollBarZ);
			this->groupBoxRotate->Controls->Add(this->textBoxInfoZ);
			this->groupBoxRotate->Location = System::Drawing::Point(14, 42);
			this->groupBoxRotate->Name = L"groupBoxRotate";
			this->groupBoxRotate->Size = System::Drawing::Size(493, 180);
			this->groupBoxRotate->TabIndex = 5;
			this->groupBoxRotate->TabStop = false;
			this->groupBoxRotate->Text = L"Вращение ";
			// 
			// textBoxInfoX
			// 
			this->textBoxInfoX->Location = System::Drawing::Point(443, 21);
			this->textBoxInfoX->Name = L"textBoxInfoX";
			this->textBoxInfoX->ReadOnly = true;
			this->textBoxInfoX->Size = System::Drawing::Size(44, 22);
			this->textBoxInfoX->TabIndex = 11;
			this->textBoxInfoX->TabStop = false;
			// 
			// textBoxInfoY
			// 
			this->textBoxInfoY->Location = System::Drawing::Point(443, 49);
			this->textBoxInfoY->Name = L"textBoxInfoY";
			this->textBoxInfoY->ReadOnly = true;
			this->textBoxInfoY->Size = System::Drawing::Size(44, 22);
			this->textBoxInfoY->TabIndex = 10;
			this->textBoxInfoY->TabStop = false;
			// 
			// labelInfoX
			// 
			this->labelInfoX->AutoSize = true;
			this->labelInfoX->Location = System::Drawing::Point(219, 22);
			this->labelInfoX->Name = L"labelInfoX";
			this->labelInfoX->Size = System::Drawing::Size(208, 17);
			this->labelInfoX->TabIndex = 9;
			this->labelInfoX->Text = L"Поворот в градусах для оси X:";
			// 
			// labelInfoY
			// 
			this->labelInfoY->AutoSize = true;
			this->labelInfoY->Location = System::Drawing::Point(219, 48);
			this->labelInfoY->Name = L"labelInfoY";
			this->labelInfoY->Size = System::Drawing::Size(208, 17);
			this->labelInfoY->TabIndex = 8;
			this->labelInfoY->Text = L"Поворот в градусах для оси Y:\r\n";
			// 
			// hScrollBarX
			// 
			this->hScrollBarX->LargeChange = 1;
			this->hScrollBarX->Location = System::Drawing::Point(13, 18);
			this->hScrollBarX->Maximum = 360;
			this->hScrollBarX->Minimum = -360;
			this->hScrollBarX->Name = L"hScrollBarX";
			this->hScrollBarX->Size = System::Drawing::Size(203, 21);
			this->hScrollBarX->TabIndex = 7;
			this->hScrollBarX->ValueChanged += gcnew System::EventHandler(this, &MyForm::hScrollBarX_ValueChanged);
			// 
			// groupBoxRotationType
			// 
			this->groupBoxRotationType->Controls->Add(this->radioButtonSelfRotating);
			this->groupBoxRotationType->Controls->Add(this->radioButtonCarousel);
			this->groupBoxRotationType->Location = System::Drawing::Point(6, 103);
			this->groupBoxRotationType->Name = L"groupBoxRotationType";
			this->groupBoxRotationType->Size = System::Drawing::Size(481, 69);
			this->groupBoxRotationType->TabIndex = 7;
			this->groupBoxRotationType->TabStop = false;
			this->groupBoxRotationType->Text = L"Режим вращения";
			// 
			// radioButtonSelfRotating
			// 
			this->radioButtonSelfRotating->AutoSize = true;
			this->radioButtonSelfRotating->Location = System::Drawing::Point(264, 30);
			this->radioButtonSelfRotating->Name = L"radioButtonSelfRotating";
			this->radioButtonSelfRotating->Size = System::Drawing::Size(177, 21);
			this->radioButtonSelfRotating->TabIndex = 1;
			this->radioButtonSelfRotating->Text = L"Вокруг центра фигуры";
			this->radioButtonSelfRotating->UseVisualStyleBackColor = true;
			this->radioButtonSelfRotating->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonSelfRotating_CheckedChanged);
			// 
			// radioButtonCarousel
			// 
			this->radioButtonCarousel->AutoSize = true;
			this->radioButtonCarousel->Checked = true;
			this->radioButtonCarousel->Location = System::Drawing::Point(19, 30);
			this->radioButtonCarousel->Name = L"radioButtonCarousel";
			this->radioButtonCarousel->Size = System::Drawing::Size(182, 21);
			this->radioButtonCarousel->TabIndex = 0;
			this->radioButtonCarousel->TabStop = true;
			this->radioButtonCarousel->Text = L"Вокруг осей координат";
			this->radioButtonCarousel->UseVisualStyleBackColor = true;
			this->radioButtonCarousel->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonCarousel_CheckedChanged);
			// 
			// hScrollBarY
			// 
			this->hScrollBarY->LargeChange = 1;
			this->hScrollBarY->Location = System::Drawing::Point(13, 48);
			this->hScrollBarY->Maximum = 360;
			this->hScrollBarY->Minimum = -360;
			this->hScrollBarY->Name = L"hScrollBarY";
			this->hScrollBarY->Size = System::Drawing::Size(203, 21);
			this->hScrollBarY->TabIndex = 6;
			this->hScrollBarY->ValueChanged += gcnew System::EventHandler(this, &MyForm::hScrollBarY_ValueChanged);
			// 
			// labelInfoZ
			// 
			this->labelInfoZ->AutoSize = true;
			this->labelInfoZ->Location = System::Drawing::Point(219, 75);
			this->labelInfoZ->Name = L"labelInfoZ";
			this->labelInfoZ->Size = System::Drawing::Size(208, 17);
			this->labelInfoZ->TabIndex = 5;
			this->labelInfoZ->Text = L"Поворот в градусах для оси Z:";
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(973, 60);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(100, 64);
			this->buttonReset->TabIndex = 6;
			this->buttonReset->Text = L"Исходное положение";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &MyForm::buttonReset_Click);
			// 
			// groupBoxScaling
			// 
			this->groupBoxScaling->Controls->Add(this->hScrollBarS);
			this->groupBoxScaling->Location = System::Drawing::Point(513, 171);
			this->groupBoxScaling->Name = L"groupBoxScaling";
			this->groupBoxScaling->Size = System::Drawing::Size(303, 51);
			this->groupBoxScaling->TabIndex = 8;
			this->groupBoxScaling->TabStop = false;
			this->groupBoxScaling->Text = L"Масштабирование";
			// 
			// hScrollBarS
			// 
			this->hScrollBarS->LargeChange = 1;
			this->hScrollBarS->Location = System::Drawing::Point(14, 18);
			this->hScrollBarS->Name = L"hScrollBarS";
			this->hScrollBarS->Size = System::Drawing::Size(270, 21);
			this->hScrollBarS->TabIndex = 0;
			this->hScrollBarS->Value = 50;
			this->hScrollBarS->ValueChanged += gcnew System::EventHandler(this, &MyForm::hScrollBarS_ValueChanged);
			// 
			// groupBoxProjection
			// 
			this->groupBoxProjection->Controls->Add(this->radioButtonCP);
			this->groupBoxProjection->Controls->Add(this->radioButtonOP);
			this->groupBoxProjection->Location = System::Drawing::Point(822, 42);
			this->groupBoxProjection->Name = L"groupBoxProjection";
			this->groupBoxProjection->Size = System::Drawing::Size(145, 97);
			this->groupBoxProjection->TabIndex = 9;
			this->groupBoxProjection->TabStop = false;
			this->groupBoxProjection->Text = L"Проекция";
			// 
			// radioButtonCP
			// 
			this->radioButtonCP->AutoSize = true;
			this->radioButtonCP->Location = System::Drawing::Point(6, 61);
			this->radioButtonCP->Name = L"radioButtonCP";
			this->radioButtonCP->Size = System::Drawing::Size(118, 21);
			this->radioButtonCP->TabIndex = 1;
			this->radioButtonCP->Text = L"Центральная";
			this->radioButtonCP->UseVisualStyleBackColor = true;
			this->radioButtonCP->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonCP_CheckedChanged);
			// 
			// radioButtonOP
			// 
			this->radioButtonOP->AutoSize = true;
			this->radioButtonOP->Checked = true;
			this->radioButtonOP->Location = System::Drawing::Point(6, 30);
			this->radioButtonOP->Name = L"radioButtonOP";
			this->radioButtonOP->Size = System::Drawing::Size(131, 21);
			this->radioButtonOP->TabIndex = 0;
			this->radioButtonOP->TabStop = true;
			this->radioButtonOP->Text = L"Ортогональная";
			this->radioButtonOP->UseVisualStyleBackColor = true;
			this->radioButtonOP->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonOP_CheckedChanged);
			// 
			// groupBoxMove
			// 
			this->groupBoxMove->Controls->Add(this->labelMoveZ);
			this->groupBoxMove->Controls->Add(this->labelMoveY);
			this->groupBoxMove->Controls->Add(this->labelMoveX);
			this->groupBoxMove->Controls->Add(this->hScrollBarMoveZ);
			this->groupBoxMove->Controls->Add(this->hScrollBarMoveY);
			this->groupBoxMove->Controls->Add(this->hScrollBarMoveX);
			this->groupBoxMove->Location = System::Drawing::Point(14, 228);
			this->groupBoxMove->Name = L"groupBoxMove";
			this->groupBoxMove->Size = System::Drawing::Size(493, 129);
			this->groupBoxMove->TabIndex = 10;
			this->groupBoxMove->TabStop = false;
			this->groupBoxMove->Text = L"Перемещение";
			// 
			// labelMoveZ
			// 
			this->labelMoveZ->AutoSize = true;
			this->labelMoveZ->Location = System::Drawing::Point(382, 91);
			this->labelMoveZ->Name = L"labelMoveZ";
			this->labelMoveZ->Size = System::Drawing::Size(105, 17);
			this->labelMoveZ->TabIndex = 5;
			this->labelMoveZ->Text = L"Сдвиг по оси Z";
			// 
			// labelMoveY
			// 
			this->labelMoveY->AutoSize = true;
			this->labelMoveY->Location = System::Drawing::Point(382, 65);
			this->labelMoveY->Name = L"labelMoveY";
			this->labelMoveY->Size = System::Drawing::Size(105, 17);
			this->labelMoveY->TabIndex = 4;
			this->labelMoveY->Text = L"Сдвиг по оси Y";
			// 
			// labelMoveX
			// 
			this->labelMoveX->AutoSize = true;
			this->labelMoveX->Location = System::Drawing::Point(382, 37);
			this->labelMoveX->Name = L"labelMoveX";
			this->labelMoveX->Size = System::Drawing::Size(105, 17);
			this->labelMoveX->TabIndex = 3;
			this->labelMoveX->Text = L"Сдвиг по оси X";
			// 
			// hScrollBarMoveZ
			// 
			this->hScrollBarMoveZ->LargeChange = 1;
			this->hScrollBarMoveZ->Location = System::Drawing::Point(13, 91);
			this->hScrollBarMoveZ->Name = L"hScrollBarMoveZ";
			this->hScrollBarMoveZ->Size = System::Drawing::Size(363, 21);
			this->hScrollBarMoveZ->TabIndex = 2;
			this->hScrollBarMoveZ->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBarMoveZ_Scroll);
			// 
			// hScrollBarMoveY
			// 
			this->hScrollBarMoveY->LargeChange = 1;
			this->hScrollBarMoveY->Location = System::Drawing::Point(13, 61);
			this->hScrollBarMoveY->Name = L"hScrollBarMoveY";
			this->hScrollBarMoveY->Size = System::Drawing::Size(363, 21);
			this->hScrollBarMoveY->TabIndex = 1;
			this->hScrollBarMoveY->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBarMoveY_Scroll);
			// 
			// hScrollBarMoveX
			// 
			this->hScrollBarMoveX->LargeChange = 1;
			this->hScrollBarMoveX->Location = System::Drawing::Point(13, 33);
			this->hScrollBarMoveX->Name = L"hScrollBarMoveX";
			this->hScrollBarMoveX->Size = System::Drawing::Size(363, 21);
			this->hScrollBarMoveX->TabIndex = 0;
			this->hScrollBarMoveX->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBarMoveX_Scroll);
			// 
			// groupBoxXParallelRotate
			// 
			this->groupBoxXParallelRotate->Controls->Add(this->checkBoxRotatePXCarousel);
			this->groupBoxXParallelRotate->Controls->Add(this->hScrollBarParX);
			this->groupBoxXParallelRotate->Controls->Add(this->textBoxXPcoordZ);
			this->groupBoxXParallelRotate->Controls->Add(this->textBoxXPcoordY);
			this->groupBoxXParallelRotate->Controls->Add(this->labelXParallelZcoord);
			this->groupBoxXParallelRotate->Controls->Add(this->labelXParallelYcoord);
			this->groupBoxXParallelRotate->Location = System::Drawing::Point(513, 228);
			this->groupBoxXParallelRotate->Name = L"groupBoxXParallelRotate";
			this->groupBoxXParallelRotate->Size = System::Drawing::Size(303, 129);
			this->groupBoxXParallelRotate->TabIndex = 11;
			this->groupBoxXParallelRotate->TabStop = false;
			this->groupBoxXParallelRotate->Text = L"Вращение вокруг прямой параллельной оси X";
			// 
			// checkBoxRotatePXCarousel
			// 
			this->checkBoxRotatePXCarousel->AutoSize = true;
			this->checkBoxRotatePXCarousel->Checked = true;
			this->checkBoxRotatePXCarousel->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxRotatePXCarousel->Location = System::Drawing::Point(14, 73);
			this->checkBoxRotatePXCarousel->Name = L"checkBoxRotatePXCarousel";
			this->checkBoxRotatePXCarousel->Size = System::Drawing::Size(138, 21);
			this->checkBoxRotatePXCarousel->TabIndex = 5;
			this->checkBoxRotatePXCarousel->Text = L"Режим карусели";
			this->checkBoxRotatePXCarousel->UseVisualStyleBackColor = true;
			// 
			// hScrollBarParX
			// 
			this->hScrollBarParX->LargeChange = 1;
			this->hScrollBarParX->Location = System::Drawing::Point(9, 97);
			this->hScrollBarParX->Maximum = 360;
			this->hScrollBarParX->Minimum = -360;
			this->hScrollBarParX->Name = L"hScrollBarParX";
			this->hScrollBarParX->Size = System::Drawing::Size(275, 21);
			this->hScrollBarParX->TabIndex = 4;
			this->hScrollBarParX->ValueChanged += gcnew System::EventHandler(this, &MyForm::hScrollBarParX_ValueChanged);
			// 
			// textBoxXPcoordZ
			// 
			this->textBoxXPcoordZ->Location = System::Drawing::Point(252, 51);
			this->textBoxXPcoordZ->Name = L"textBoxXPcoordZ";
			this->textBoxXPcoordZ->Size = System::Drawing::Size(45, 22);
			this->textBoxXPcoordZ->TabIndex = 3;
			this->textBoxXPcoordZ->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxXPcoordZ_TextChanged);
			// 
			// textBoxXPcoordY
			// 
			this->textBoxXPcoordY->Location = System::Drawing::Point(252, 23);
			this->textBoxXPcoordY->Name = L"textBoxXPcoordY";
			this->textBoxXPcoordY->Size = System::Drawing::Size(45, 22);
			this->textBoxXPcoordY->TabIndex = 2;
			this->textBoxXPcoordY->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxXPcoordY_TextChanged);
			// 
			// labelXParallelZcoord
			// 
			this->labelXParallelZcoord->AutoSize = true;
			this->labelXParallelZcoord->Location = System::Drawing::Point(90, 51);
			this->labelXParallelZcoord->Name = L"labelXParallelZcoord";
			this->labelXParallelZcoord->Size = System::Drawing::Size(156, 17);
			this->labelXParallelZcoord->TabIndex = 1;
			this->labelXParallelZcoord->Text = L"Z координата прямой:";
			// 
			// labelXParallelYcoord
			// 
			this->labelXParallelYcoord->AutoSize = true;
			this->labelXParallelYcoord->Location = System::Drawing::Point(90, 23);
			this->labelXParallelYcoord->Name = L"labelXParallelYcoord";
			this->labelXParallelYcoord->Size = System::Drawing::Size(156, 17);
			this->labelXParallelYcoord->TabIndex = 0;
			this->labelXParallelYcoord->Text = L"Y координата прямой:";
			// 
			// groupBoxLRotate
			// 
			this->groupBoxLRotate->Controls->Add(this->hScrollBarLRotate);
			this->groupBoxLRotate->Controls->Add(this->label_n);
			this->groupBoxLRotate->Controls->Add(this->label_m);
			this->groupBoxLRotate->Controls->Add(this->label_l);
			this->groupBoxLRotate->Controls->Add(this->label_c);
			this->groupBoxLRotate->Controls->Add(this->label_b);
			this->groupBoxLRotate->Controls->Add(this->label_a);
			this->groupBoxLRotate->Controls->Add(this->label_vec);
			this->groupBoxLRotate->Controls->Add(this->label_Ades);
			this->groupBoxLRotate->Controls->Add(this->textBox_n);
			this->groupBoxLRotate->Controls->Add(this->textBox_m);
			this->groupBoxLRotate->Controls->Add(this->textBox_l);
			this->groupBoxLRotate->Controls->Add(this->textBox_c);
			this->groupBoxLRotate->Controls->Add(this->textBox_b);
			this->groupBoxLRotate->Controls->Add(this->textBox_a);
			this->groupBoxLRotate->Location = System::Drawing::Point(822, 145);
			this->groupBoxLRotate->Name = L"groupBoxLRotate";
			this->groupBoxLRotate->Size = System::Drawing::Size(250, 212);
			this->groupBoxLRotate->TabIndex = 12;
			this->groupBoxLRotate->TabStop = false;
			this->groupBoxLRotate->Text = L"Вращение относительно произвольной прямой";
			// 
			// hScrollBarLRotate
			// 
			this->hScrollBarLRotate->LargeChange = 1;
			this->hScrollBarLRotate->Location = System::Drawing::Point(6, 180);
			this->hScrollBarLRotate->Maximum = 360;
			this->hScrollBarLRotate->Minimum = -360;
			this->hScrollBarLRotate->Name = L"hScrollBarLRotate";
			this->hScrollBarLRotate->Size = System::Drawing::Size(238, 21);
			this->hScrollBarLRotate->TabIndex = 14;
			this->hScrollBarLRotate->ValueChanged += gcnew System::EventHandler(this, &MyForm::hScrollBarLRotate_ValueChanged);
			// 
			// label_n
			// 
			this->label_n->AutoSize = true;
			this->label_n->Location = System::Drawing::Point(174, 145);
			this->label_n->Name = L"label_n";
			this->label_n->Size = System::Drawing::Size(27, 17);
			this->label_n->TabIndex = 13;
			this->label_n->Text = L"z =";
			// 
			// label_m
			// 
			this->label_m->AutoSize = true;
			this->label_m->Location = System::Drawing::Point(92, 146);
			this->label_m->Name = L"label_m";
			this->label_m->Size = System::Drawing::Size(27, 17);
			this->label_m->TabIndex = 12;
			this->label_m->Text = L"y =";
			// 
			// label_l
			// 
			this->label_l->AutoSize = true;
			this->label_l->Location = System::Drawing::Point(11, 145);
			this->label_l->Name = L"label_l";
			this->label_l->Size = System::Drawing::Size(26, 17);
			this->label_l->TabIndex = 11;
			this->label_l->Text = L"x =";
			// 
			// label_c
			// 
			this->label_c->AutoSize = true;
			this->label_c->Location = System::Drawing::Point(178, 75);
			this->label_c->Name = L"label_c";
			this->label_c->Size = System::Drawing::Size(27, 17);
			this->label_c->TabIndex = 10;
			this->label_c->Text = L"z =";
			// 
			// label_b
			// 
			this->label_b->AutoSize = true;
			this->label_b->Location = System::Drawing::Point(97, 72);
			this->label_b->Name = L"label_b";
			this->label_b->Size = System::Drawing::Size(27, 17);
			this->label_b->TabIndex = 9;
			this->label_b->Text = L"y =";
			// 
			// label_a
			// 
			this->label_a->AutoSize = true;
			this->label_a->Location = System::Drawing::Point(11, 72);
			this->label_a->Name = L"label_a";
			this->label_a->Size = System::Drawing::Size(26, 17);
			this->label_a->TabIndex = 8;
			this->label_a->Text = L"x =";
			// 
			// label_vec
			// 
			this->label_vec->AutoSize = true;
			this->label_vec->Location = System::Drawing::Point(6, 106);
			this->label_vec->Name = L"label_vec";
			this->label_vec->Size = System::Drawing::Size(199, 34);
			this->label_vec->TabIndex = 7;
			this->label_vec->Text = L"Координаты направляющего\r\nвектора:\r\n";
			// 
			// label_Ades
			// 
			this->label_Ades->AutoSize = true;
			this->label_Ades->Location = System::Drawing::Point(6, 52);
			this->label_Ades->Name = L"label_Ades";
			this->label_Ades->Size = System::Drawing::Size(149, 17);
			this->label_Ades->TabIndex = 6;
			this->label_Ades->Text = L"Координаты точки A:";
			// 
			// textBox_n
			// 
			this->textBox_n->Location = System::Drawing::Point(207, 145);
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size(37, 22);
			this->textBox_n->TabIndex = 5;
			this->textBox_n->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_n_TextChanged);
			// 
			// textBox_m
			// 
			this->textBox_m->Location = System::Drawing::Point(124, 143);
			this->textBox_m->Name = L"textBox_m";
			this->textBox_m->Size = System::Drawing::Size(37, 22);
			this->textBox_m->TabIndex = 4;
			this->textBox_m->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_m_TextChanged);
			// 
			// textBox_l
			// 
			this->textBox_l->Location = System::Drawing::Point(43, 143);
			this->textBox_l->Name = L"textBox_l";
			this->textBox_l->Size = System::Drawing::Size(37, 22);
			this->textBox_l->TabIndex = 3;
			this->textBox_l->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_l_TextChanged);
			// 
			// textBox_c
			// 
			this->textBox_c->Location = System::Drawing::Point(211, 72);
			this->textBox_c->Name = L"textBox_c";
			this->textBox_c->Size = System::Drawing::Size(37, 22);
			this->textBox_c->TabIndex = 2;
			this->textBox_c->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_c_TextChanged);
			// 
			// textBox_b
			// 
			this->textBox_b->Location = System::Drawing::Point(130, 72);
			this->textBox_b->Name = L"textBox_b";
			this->textBox_b->Size = System::Drawing::Size(37, 22);
			this->textBox_b->TabIndex = 1;
			this->textBox_b->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_b_TextChanged);
			// 
			// textBox_a
			// 
			this->textBox_a->Location = System::Drawing::Point(43, 72);
			this->textBox_a->Name = L"textBox_a";
			this->textBox_a->Size = System::Drawing::Size(37, 22);
			this->textBox_a->TabIndex = 0;
			this->textBox_a->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_a_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButtonProjZ);
			this->groupBox1->Controls->Add(this->radioButtonProjY);
			this->groupBox1->Controls->Add(this->radioButtonProjX);
			this->groupBox1->Location = System::Drawing::Point(513, 42);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(303, 123);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ортографическая проекция";
			// 
			// radioButtonProjZ
			// 
			this->radioButtonProjZ->AutoSize = true;
			this->radioButtonProjZ->Checked = true;
			this->radioButtonProjZ->Location = System::Drawing::Point(14, 30);
			this->radioButtonProjZ->Name = L"radioButtonProjZ";
			this->radioButtonProjZ->Size = System::Drawing::Size(86, 21);
			this->radioButtonProjZ->TabIndex = 3;
			this->radioButtonProjZ->TabStop = true;
			this->radioButtonProjZ->Text = L"Спереди";
			this->radioButtonProjZ->UseVisualStyleBackColor = true;
			this->radioButtonProjZ->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonProjZ_CheckedChanged);
			// 
			// radioButtonProjY
			// 
			this->radioButtonProjY->AutoSize = true;
			this->radioButtonProjY->Location = System::Drawing::Point(14, 57);
			this->radioButtonProjY->Name = L"radioButtonProjY";
			this->radioButtonProjY->Size = System::Drawing::Size(74, 21);
			this->radioButtonProjY->TabIndex = 2;
			this->radioButtonProjY->Text = L"Сверху";
			this->radioButtonProjY->UseVisualStyleBackColor = true;
			this->radioButtonProjY->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonProjY_CheckedChanged);
			// 
			// radioButtonProjX
			// 
			this->radioButtonProjX->AutoSize = true;
			this->radioButtonProjX->Location = System::Drawing::Point(14, 84);
			this->radioButtonProjX->Name = L"radioButtonProjX";
			this->radioButtonProjX->Size = System::Drawing::Size(77, 21);
			this->radioButtonProjX->TabIndex = 1;
			this->radioButtonProjX->Text = L"Справа";
			this->radioButtonProjX->UseVisualStyleBackColor = true;
			this->radioButtonProjX->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonProjX_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 949);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBoxLRotate);
			this->Controls->Add(this->groupBoxXParallelRotate);
			this->Controls->Add(this->groupBoxMove);
			this->Controls->Add(this->groupBoxProjection);
			this->Controls->Add(this->groupBoxScaling);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->groupBoxRotate);
			this->Controls->Add(this->pictureBoxForDraw);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1102, 994);
			this->MinimumSize = System::Drawing::Size(1102, 994);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Построение 3D объектов - Соловьев Андрей - БПИ122(2)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxForDraw))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxRotate->ResumeLayout(false);
			this->groupBoxRotate->PerformLayout();
			this->groupBoxRotationType->ResumeLayout(false);
			this->groupBoxRotationType->PerformLayout();
			this->groupBoxScaling->ResumeLayout(false);
			this->groupBoxProjection->ResumeLayout(false);
			this->groupBoxProjection->PerformLayout();
			this->groupBoxMove->ResumeLayout(false);
			this->groupBoxMove->PerformLayout();
			this->groupBoxXParallelRotate->ResumeLayout(false);
			this->groupBoxXParallelRotate->PerformLayout();
			this->groupBoxLRotate->ResumeLayout(false);
			this->groupBoxLRotate->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: // Метод вызова помощи по программе
		System::Void ToolStripMenuItemAbout_Click(System::Object^  sender, System::EventArgs^  e);

	private: // Методы обработки событий мыши: перемещение и вращение задается кнопками мыши
		System::Void pictureBoxForDraw_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void pictureBoxForDraw_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void pictureBoxForDraw_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

	private: // Метод вращения по оси Z при помощи "scrollBar"
		System::Void hScrollBarZ_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Метод вращения по оси Y при помощи "scrollBar"
		System::Void hScrollBarY_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Метод вращения по оси X при помощи "scrollBar"
		System::Void hScrollBarX_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Метод масштабирования пирамиды при помощи "scrollBar"
		System::Void hScrollBarS_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Инициализация "scrollBar" для вращения фигуры
		void initializeScrollsForRotate();

	public: // Метод задает фигуре начальные координаты
		void resetFigure();

	private: // Метод возвращает фигуру в исходное положение
		System::Void buttonReset_Click(System::Object^  sender, System::EventArgs^  e);	
		void resetAll();

	private: // Вращение относительно осей
		System::Void radioButtonCarousel_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Вращение относительно центра пирамиды
		System::Void radioButtonSelfRotating_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Метод копирования матрицы вершин пирамиды
		void copyVertexArray();

	private: // Инициализация матриц вращения, сдвига и масштабирования
		void initializeMatrices();

	private: // Инициализация матрицы вершин для тетраэдра
		void initializePyramid();

	private: // Метод рисования пирамиды
		void drawPyramid();

	private: // Инициализация матрицы вершин для октаэдра
		void initializeOctahedron();

	private: // Метод рисования октаэдра
		void drawOctahedron();

	private: // Инициализация матрицы вершин для икосаэдра
		void initializeIcosahedron();

	private: // Метод рисования икосаэдра
		void drawIcosahedron();

	private: // Инициализация матрицы вершин для сферы
		void initializeSphere();

	private: // Метод рисования сферы
		void drawSphere();

	private: // Инициализация матрицы вершин для тора
		void initializeTorus();

	private: // Метод рисования тора
		void drawTorus();

	private: // // Инициализация матрицы вершин для чеснока
		void initializeGarlic();

	private: // Метод рисования чеснока
		void drawGarlic();

	private: // Инициализация матрицы вершин для пружины
		void initializeSpring();

	private: // Метод рисования пружины
		void drawSpring();

	private: // Метод рисования фигуры
		void drawFigure();

	// Выбор фигуры для рисования:
	private:
		System::Void ToolStripMenuItemPyramid_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void ToolStripMenuItemSphere_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void ToolStripMenuItemTorus_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void ToolStripMenuItemOctahedron_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void ToolStripMenuItemIcosahedron_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void ToolStripMenuItemGarlic_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void ToolStripMenuItemSpring_Click(System::Object^  sender, System::EventArgs^  e);


	private: // Рисуем ортогональную проекцию
		System::Void radioButtonOP_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: // Рисуем центральную проекцию
		System::Void radioButtonCP_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Рисеум оси координат
		void drawAxes();

	private: // Метод расчета матрицы проекций
		void setProjection();

	private: // Инициализация "scroll" для перемещения фигуры
		void initializeMoveScrolls();

	private: // Обработка перемещения "scroll" для перемещения фигуры по оси X
		System::Void hScrollBarMoveX_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: // Обработка перемещения "scroll" для перемещения фигуры по оси Y
		System::Void hScrollBarMoveY_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: // Обработка перемещения "scroll" для перемещения фигуры по оси Z
		System::Void hScrollBarMoveZ_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);

	private: // Инициализация "scrollBar" для вращения фигуры относительно прямой параллельной оси X
		void initializeXRotationalScroll();

	private: // Обработка числовых значения для задания направляющего вектора прямой относительно которой будем вращать
		     // (прямая параллельная оси Х)
		System::Void textBoxXPcoordY_TextChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void textBoxXPcoordZ_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Обработка перемещения "scroll" для вращения относительно прямой параллельной оси Х
		System::Void hScrollBarParX_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Обработка перемещения "scroll" для вращения относительно произвольной прямой L
		System::Void hScrollBarLRotate_ValueChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Обработка числовых значения для задания направляющего вектора прямой относительно которой будем вращать
		System::Void textBox_a_TextChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void textBox_b_TextChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void textBox_c_TextChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void textBox_l_TextChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void textBox_m_TextChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void textBox_n_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Проверка корректности ввода чисел
		void checkLCoordinates();

	private: // Инициализация "scrollBar" для вращения фигуры относительно произвольной прямой
		void initializeLRotationalScroll();

	private: // Проекция: вид спереди
		System::Void radioButtonProjZ_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Проекция: вид сверху
		System::Void radioButtonProjY_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: // Проекция: вид справа
		System::Void radioButtonProjX_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	};

}
