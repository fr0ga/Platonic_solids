#pragma once

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

	/// <summary>
	/// Summary for MyFormAbout
	/// </summary>
	public ref class MyFormAbout : public System::Windows::Forms::Form
	{
	public:
		MyFormAbout(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyFormAbout()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxInfo;
	protected:

	protected:

	protected:

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
			this->textBoxInfo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBoxInfo
			// 
			this->textBoxInfo->Location = System::Drawing::Point(12, 12);
			this->textBoxInfo->Multiline = true;
			this->textBoxInfo->Name = L"textBoxInfo";
			this->textBoxInfo->ReadOnly = true;
			this->textBoxInfo->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxInfo->Size = System::Drawing::Size(760, 460);
			this->textBoxInfo->TabIndex = 0;
			this->textBoxInfo->TabStop = false;
			// 
			// MyFormAbout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 500);
			this->Controls->Add(this->textBoxInfo);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(801, 545);
			this->MinimumSize = System::Drawing::Size(801, 545);
			this->Name = L"MyFormAbout";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"О программе";
			this->Load += gcnew System::EventHandler(this, &MyFormAbout::MyFormAbout_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void MyFormAbout_Load(System::Object^  sender, System::EventArgs^  e);
	};
}
