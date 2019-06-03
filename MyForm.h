#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
#pragma comment(lib, "Ws2_32.lib") 

#pragma once

namespace clint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  inputIPv4IPToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  設定IP位置ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^  ip_address;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  段開連結ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  server_ip_show;
	private: System::Windows::Forms::Label^  label5;













	private: System::Windows::Forms::PictureBox^  pictureBox_server_connection;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  client_speed_text;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  client_direction_text;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::PictureBox^  client_auto_mode_pictureBox;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::PictureBox^  client_connection_pictureBox;
	private: System::Windows::Forms::GroupBox^  client_groupBox;
	private: System::Windows::Forms::TextBox^  control;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  state_label;




	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->inputIPv4IPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->設定IP位置ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ip_address = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->段開連結ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->server_ip_show = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_server_connection = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->client_speed_text = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->client_direction_text = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->client_auto_mode_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->client_connection_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->client_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->control = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->state_label = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_server_connection))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->client_auto_mode_pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->client_connection_pictureBox))->BeginInit();
			this->client_groupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->inputIPv4IPToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1050, 27);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// inputIPv4IPToolStripMenuItem
			// 
			this->inputIPv4IPToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			this->inputIPv4IPToolStripMenuItem->Name = L"inputIPv4IPToolStripMenuItem";
			this->inputIPv4IPToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->inputIPv4IPToolStripMenuItem->Text = L"連線";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->設定IP位置ToolStripMenuItem,
					this->toolStripMenuItem2, this->段開連結ToolStripMenuItem
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(159, 26);
			this->toolStripMenuItem1->Text = L"伺服器連接";
			// 
			// 設定IP位置ToolStripMenuItem
			// 
			this->設定IP位置ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ip_address });
			this->設定IP位置ToolStripMenuItem->Name = L"設定IP位置ToolStripMenuItem";
			this->設定IP位置ToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->設定IP位置ToolStripMenuItem->Text = L"設定IP位置";
			// 
			// ip_address
			// 
			this->ip_address->Name = L"ip_address";
			this->ip_address->Size = System::Drawing::Size(100, 27);
			this->ip_address->TextChanged += gcnew System::EventHandler(this, &MyForm::ip_address_TextChanged);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Enabled = false;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(159, 26);
			this->toolStripMenuItem2->Text = L"連接伺服器";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
			// 
			// 段開連結ToolStripMenuItem
			// 
			this->段開連結ToolStripMenuItem->Enabled = false;
			this->段開連結ToolStripMenuItem->Name = L"段開連結ToolStripMenuItem";
			this->段開連結ToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->段開連結ToolStripMenuItem->Text = L"段開連結";
			this->段開連結ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::段開連結ToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->AcceptsTab = true;
			this->textBox1->Location = System::Drawing::Point(12, 30);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(260, 418);
			this->textBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 20));
			this->label1->Location = System::Drawing::Point(401, 55);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(253, 34);
			this->label1->TabIndex = 5;
			this->label1->Text = L"伺服器連接狀態";
			// 
			// server_ip_show
			// 
			this->server_ip_show->Font = (gcnew System::Drawing::Font(L"新細明體", 15, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->server_ip_show->ForeColor = System::Drawing::Color::Blue;
			this->server_ip_show->Location = System::Drawing::Point(410, 140);
			this->server_ip_show->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->server_ip_show->Name = L"server_ip_show";
			this->server_ip_show->Size = System::Drawing::Size(273, 29);
			this->server_ip_show->TabIndex = 11;
			this->server_ip_show->Text = L"null";
			this->server_ip_show->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label5->Location = System::Drawing::Point(476, 105);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"伺服器IP位置";
			// 
			// pictureBox_server_connection
			// 
			this->pictureBox_server_connection->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_server_connection.Image")));
			this->pictureBox_server_connection->Location = System::Drawing::Point(360, 58);
			this->pictureBox_server_connection->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox_server_connection->MaximumSize = System::Drawing::Size(33, 31);
			this->pictureBox_server_connection->Name = L"pictureBox_server_connection";
			this->pictureBox_server_connection->Size = System::Drawing::Size(33, 31);
			this->pictureBox_server_connection->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_server_connection->TabIndex = 12;
			this->pictureBox_server_connection->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label2->Location = System::Drawing::Point(31, 81);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 17);
			this->label2->TabIndex = 0;
			this->label2->Text = L"車速：";
			// 
			// client_speed_text
			// 
			this->client_speed_text->AutoSize = true;
			this->client_speed_text->Location = System::Drawing::Point(106, 81);
			this->client_speed_text->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->client_speed_text->Name = L"client_speed_text";
			this->client_speed_text->Size = System::Drawing::Size(39, 15);
			this->client_speed_text->TabIndex = 1;
			this->client_speed_text->Text = L"0.000";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(194, 83);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"單位";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label6->Location = System::Drawing::Point(31, 115);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 17);
			this->label6->TabIndex = 3;
			this->label6->Text = L"方向：";
			// 
			// client_direction_text
			// 
			this->client_direction_text->AutoSize = true;
			this->client_direction_text->Location = System::Drawing::Point(106, 115);
			this->client_direction_text->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->client_direction_text->Name = L"client_direction_text";
			this->client_direction_text->Size = System::Drawing::Size(39, 15);
			this->client_direction_text->TabIndex = 4;
			this->client_direction_text->Text = L"0.000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(194, 117);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 15);
			this->label4->TabIndex = 5;
			this->label4->Text = L"單位";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label8->Location = System::Drawing::Point(31, 153);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 17);
			this->label8->TabIndex = 6;
			this->label8->Text = L"自動偵測模式：";
			// 
			// client_auto_mode_pictureBox
			// 
			this->client_auto_mode_pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"client_auto_mode_pictureBox.Image")));
			this->client_auto_mode_pictureBox->Location = System::Drawing::Point(197, 145);
			this->client_auto_mode_pictureBox->Margin = System::Windows::Forms::Padding(4);
			this->client_auto_mode_pictureBox->MaximumSize = System::Drawing::Size(33, 31);
			this->client_auto_mode_pictureBox->Name = L"client_auto_mode_pictureBox";
			this->client_auto_mode_pictureBox->Size = System::Drawing::Size(33, 31);
			this->client_auto_mode_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->client_auto_mode_pictureBox->TabIndex = 7;
			this->client_auto_mode_pictureBox->TabStop = false;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label15->Location = System::Drawing::Point(31, 47);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(127, 17);
			this->label15->TabIndex = 10;
			this->label15->Text = L"目前連線狀態：";
			// 
			// client_connection_pictureBox
			// 
			this->client_connection_pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"client_connection_pictureBox.Image")));
			this->client_connection_pictureBox->Location = System::Drawing::Point(197, 39);
			this->client_connection_pictureBox->Margin = System::Windows::Forms::Padding(4);
			this->client_connection_pictureBox->MaximumSize = System::Drawing::Size(33, 31);
			this->client_connection_pictureBox->Name = L"client_connection_pictureBox";
			this->client_connection_pictureBox->Size = System::Drawing::Size(33, 31);
			this->client_connection_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->client_connection_pictureBox->TabIndex = 11;
			this->client_connection_pictureBox->TabStop = false;
			// 
			// client_groupBox
			// 
			this->client_groupBox->Controls->Add(this->client_connection_pictureBox);
			this->client_groupBox->Controls->Add(this->label15);
			this->client_groupBox->Controls->Add(this->client_auto_mode_pictureBox);
			this->client_groupBox->Controls->Add(this->label8);
			this->client_groupBox->Controls->Add(this->label4);
			this->client_groupBox->Controls->Add(this->client_direction_text);
			this->client_groupBox->Controls->Add(this->label6);
			this->client_groupBox->Controls->Add(this->label3);
			this->client_groupBox->Controls->Add(this->client_speed_text);
			this->client_groupBox->Controls->Add(this->label2);
			this->client_groupBox->Location = System::Drawing::Point(381, 195);
			this->client_groupBox->Margin = System::Windows::Forms::Padding(4);
			this->client_groupBox->Name = L"client_groupBox";
			this->client_groupBox->Padding = System::Windows::Forms::Padding(4);
			this->client_groupBox->Size = System::Drawing::Size(273, 203);
			this->client_groupBox->TabIndex = 9;
			this->client_groupBox->TabStop = false;
			this->client_groupBox->Text = L"使用者端";
			// 
			// control
			// 
			this->control->Location = System::Drawing::Point(699, 37);
			this->control->Multiline = true;
			this->control->Name = L"control";
			this->control->ReadOnly = true;
			this->control->Size = System::Drawing::Size(322, 34);
			this->control->TabIndex = 13;
			this->control->TextChanged += gcnew System::EventHandler(this, &MyForm::control_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(695, 92);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 20);
			this->label7->TabIndex = 14;
			this->label7->Text = L"state";
			// 
			// state_label
			// 
			this->state_label->AutoSize = true;
			this->state_label->Font = (gcnew System::Drawing::Font(L"新細明體", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->state_label->Location = System::Drawing::Point(694, 123);
			this->state_label->Name = L"state_label";
			this->state_label->Size = System::Drawing::Size(68, 28);
			this->state_label->TabIndex = 15;
			this->state_label->Text = L"停止";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1050, 460);
			this->Controls->Add(this->state_label);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->control);
			this->Controls->Add(this->pictureBox_server_connection);
			this->Controls->Add(this->server_ip_show);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->client_groupBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_server_connection))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->client_auto_mode_pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->client_connection_pictureBox))->EndInit();
			this->client_groupBox->ResumeLayout(false);
			this->client_groupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ip_address_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void 段開連結ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
	private: System::Void control_TextChanged(System::Object^  sender, System::EventArgs^  e);
};
}