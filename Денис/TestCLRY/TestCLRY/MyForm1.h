#pragma once
#include <math.h>
#include <string>
#include <string>
namespace TestCLRY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox0_2;
	protected:

	private: System::Windows::Forms::TextBox^ textBox0_1;
	protected:

	private: System::Windows::Forms::TextBox^ textBox0_0;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1_2;


	private: System::Windows::Forms::TextBox^ textBox1_1;

	private: System::Windows::Forms::TextBox^ textBox1_0;
	private: System::Windows::Forms::TextBox^ textBox2_2;


	private: System::Windows::Forms::TextBox^ textBox2_1;

	private: System::Windows::Forms::TextBox^ textBox2_0;
	private: System::Windows::Forms::TextBox^ textBox2;


	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox0;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox0_2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox0_1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox0_0 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1_2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1_1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1_0 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2_2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2_1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2_0 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox0 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox0_2
			// 
			this->textBox0_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox0_2->Location = System::Drawing::Point(235, 304);
			this->textBox0_2->Name = L"textBox0_2";
			this->textBox0_2->Size = System::Drawing::Size(59, 44);
			this->textBox0_2->TabIndex = 35;
			// 
			// textBox0_1
			// 
			this->textBox0_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox0_1->Location = System::Drawing::Point(235, 229);
			this->textBox0_1->Name = L"textBox0_1";
			this->textBox0_1->Size = System::Drawing::Size(59, 44);
			this->textBox0_1->TabIndex = 34;
			// 
			// textBox0_0
			// 
			this->textBox0_0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox0_0->Location = System::Drawing::Point(235, 161);
			this->textBox0_0->Name = L"textBox0_0";
			this->textBox0_0->Size = System::Drawing::Size(59, 44);
			this->textBox0_0->TabIndex = 33;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(512, 236);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 37);
			this->label9->TabIndex = 32;
			this->label9->Text = L"x3";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(512, 168);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(50, 37);
			this->label8->TabIndex = 31;
			this->label8->Text = L"x3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(512, 311);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 37);
			this->label7->TabIndex = 30;
			this->label7->Text = L"x3";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(406, 168);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 37);
			this->label6->TabIndex = 29;
			this->label6->Text = L"x2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(406, 236);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 37);
			this->label5->TabIndex = 28;
			this->label5->Text = L"x2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(406, 311);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 37);
			this->label4->TabIndex = 27;
			this->label4->Text = L"x2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(300, 311);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 37);
			this->label3->TabIndex = 26;
			this->label3->Text = L"x1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(300, 236);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 37);
			this->label2->TabIndex = 25;
			this->label2->Text = L"x1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(300, 168);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 37);
			this->label1->TabIndex = 24;
			this->label1->Text = L"x1";
			this->label1->UseWaitCursor = true;
			// 
			// textBox1_2
			// 
			this->textBox1_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_2->Location = System::Drawing::Point(341, 304);
			this->textBox1_2->Name = L"textBox1_2";
			this->textBox1_2->Size = System::Drawing::Size(59, 44);
			this->textBox1_2->TabIndex = 38;
			// 
			// textBox1_1
			// 
			this->textBox1_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_1->Location = System::Drawing::Point(341, 229);
			this->textBox1_1->Name = L"textBox1_1";
			this->textBox1_1->Size = System::Drawing::Size(59, 44);
			this->textBox1_1->TabIndex = 37;
			// 
			// textBox1_0
			// 
			this->textBox1_0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_0->Location = System::Drawing::Point(341, 161);
			this->textBox1_0->Name = L"textBox1_0";
			this->textBox1_0->Size = System::Drawing::Size(59, 44);
			this->textBox1_0->TabIndex = 36;
			// 
			// textBox2_2
			// 
			this->textBox2_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2_2->Location = System::Drawing::Point(462, 304);
			this->textBox2_2->Name = L"textBox2_2";
			this->textBox2_2->Size = System::Drawing::Size(59, 44);
			this->textBox2_2->TabIndex = 41;
			this->textBox2_2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// textBox2_1
			// 
			this->textBox2_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2_1->Location = System::Drawing::Point(462, 229);
			this->textBox2_1->Name = L"textBox2_1";
			this->textBox2_1->Size = System::Drawing::Size(59, 44);
			this->textBox2_1->TabIndex = 40;
			// 
			// textBox2_0
			// 
			this->textBox2_0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2_0->Location = System::Drawing::Point(462, 161);
			this->textBox2_0->Name = L"textBox2_0";
			this->textBox2_0->Size = System::Drawing::Size(59, 44);
			this->textBox2_0->TabIndex = 39;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(600, 305);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(59, 44);
			this->textBox2->TabIndex = 44;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(600, 229);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(59, 44);
			this->textBox1->TabIndex = 43;
			// 
			// textBox0
			// 
			this->textBox0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox0->Location = System::Drawing::Point(600, 161);
			this->textBox0->Name = L"textBox0";
			this->textBox0->Size = System::Drawing::Size(59, 44);
			this->textBox0->TabIndex = 42;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(558, 172);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(36, 37);
			this->label10->TabIndex = 45;
			this->label10->Text = L"=";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(558, 236);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(36, 37);
			this->label11->TabIndex = 46;
			this->label11->Text = L"=";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(558, 308);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 37);
			this->label12->TabIndex = 47;
			this->label12->Text = L"=";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(519, 404);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 48);
			this->button1->TabIndex = 48;
			this->button1->Text = L"Расчитать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 508);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox0);
			this->Controls->Add(this->textBox2_2);
			this->Controls->Add(this->textBox2_1);
			this->Controls->Add(this->textBox2_0);
			this->Controls->Add(this->textBox1_2);
			this->Controls->Add(this->textBox1_1);
			this->Controls->Add(this->textBox1_0);
			this->Controls->Add(this->textBox0_2);
			this->Controls->Add(this->textBox0_1);
			this->Controls->Add(this->textBox0_0);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int i, j, N, N1;
	N = 3;
	N1 = 4;
	double matrix[3][4] = { {1,1,1,3},
					  {1,1,1,3},
					  {1,1,1,3} };;
	bool check = true;

	//инициализируем
	try
	{
		
		matrix[0][0] = Convert::ToDouble(textBox0_0->Text);
		matrix[0][1] = Convert::ToDouble(textBox0_1->Text);
		matrix[0][2] = Convert::ToDouble(textBox0_2->Text);
		matrix[1][0] = Convert::ToDouble(textBox1_0->Text);
		matrix[1][1] = Convert::ToDouble(textBox1_1->Text);
		matrix[1][2] = Convert::ToDouble(textBox1_2->Text);
		matrix[2][0] = Convert::ToDouble(textBox2_0->Text);
		matrix[2][1] = Convert::ToDouble(textBox2_1->Text);
		matrix[2][2] = Convert::ToDouble(textBox2_2->Text);
		matrix[0][3] = Convert::ToDouble(textBox0->Text);
		matrix[1][3] = Convert::ToDouble(textBox1->Text);
		matrix[2][3] = Convert::ToDouble(textBox2->Text);
		
	}
	catch (FormatException^ ex)
	{
		MessageBox::Show("Произошла ошибка при записи данных!!!");
		check = false;
	}

	
	if (check)
	{
		//Метод Гаусса
		double tmp, xx[3];
		int k;

		for (i = 0; i < N; i++)
		{
			tmp = matrix[i][i];
			for (j = N; j >= i; j--)
				matrix[i][j] /= tmp;
			for (j = i + 1; j < N; j++)
			{
				tmp = matrix[j][i];
				for (k = N; k >= i; k--)
					matrix[j][k] -= tmp * matrix[i][k];
			}
		}
		/*обратный ход*/
		xx[N - 1] = matrix[N - 1][N];
		for (i = N - 2; i >= 0; i--)
		{
			xx[i] = matrix[i][N];
			for (j = i + 1; j < N; j++) xx[i] -= matrix[i][j] * xx[j];
		}

	
		MessageBox::Show("x1 = " + Convert::ToString(ceilf(xx[0] * 100) / 100) + " x2 = " + Convert::ToString(ceilf(xx[1] * 100) / 100) + " x2 = " + Convert::ToString(ceilf(xx[2] * 100) / 100) );
	}
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
