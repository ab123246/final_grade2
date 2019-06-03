#include "MyForm.h"
#include "clintconnect.h"

clintconnect connect1;
using namespace clint;

[STAThreadAttribute]

int main(array<System::String ^> ^args) {

	omp_set_nested(1);//打開openmp 巢狀執行緒 參考資料 https://www.phototalks.idv.tw/academic/?p=1997 

	//true == 1, false == 0
	// 建立任何控制項之前，先啟用 Windows XP 視覺化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// 建立主視窗並執行
	Application::Run(gcnew MyForm());
	//結束程式執行，並回傳 0 代表程式執行正常無異狀。
	return 0;
}

System::Void clint::MyForm::ip_address_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (ip_address->Text != "")
		toolStripMenuItem2->Enabled = true;
	else
		toolStripMenuItem2->Enabled = false;
}

System::Void clint::MyForm::toolStripMenuItem2_Click(System::Object ^ sender, System::EventArgs ^ e)
{	
	char server_addr[20];
	sprintf_s(server_addr, "%s", ip_address->Text);
	pictureBox_server_connection->Image = gcnew Bitmap("images/green.png");
	client_connection_pictureBox->Image = gcnew Bitmap("images/green.png");
	//連接伺服器
	MessageBox::Show(gcnew String(server_addr));
	server_ip_show->Text = ip_address->Text;
	connect1.main_(server_addr);
	toolStripMenuItem2->Enabled = false;
	control->ReadOnly = false;
	段開連結ToolStripMenuItem->Enabled = true;
	ip_address->ReadOnly = true;
	control->ReadOnly = false;
}

System::Void clint::MyForm::段開連結ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	pictureBox_server_connection->Image = gcnew Bitmap("images/red.png");
	client_connection_pictureBox->Image = gcnew Bitmap("images/red.png");
	//段開連接
	connect1.close();
	server_ip_show->Text = "null";
	ip_address->ReadOnly = false;
	control->Text = "";
	control->ReadOnly = true;
	toolStripMenuItem2->Enabled = true;
	段開連結ToolStripMenuItem->Enabled = false;
}

System::Void clint::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	//::System::Threading::Thread^ thr1 = gcnew ::System::Threading::Thread(gcnew ::System::Threading::ThreadStart(this, &MyForm::client_connection_wait));
}

System::Void clint::MyForm::MyForm_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
{
	connect1.close();
}

System::Void clint::MyForm::control_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (control->Text == "5") {
		connect1.send_cmd("0 90 0");
		control->Text = "";
		state_label->Text = "停止";
	}else if (control->Text=="7") {
		connect1.send_cmd("1 135 0");
		control->Text = "";
		state_label->Text = "左前";
	}
	else if (control->Text == "8") {
		connect1.send_cmd("1 90 0");
		control->Text = "";
		state_label->Text = "前進";
	}
	else if (control->Text == "9") {
		connect1.send_cmd("1 45 0");
		control->Text = "";
		state_label->Text = "右前";
	}else if(control->Text == "1"){
		connect1.send_cmd("-1 135 0");
		control->Text = "";
		state_label->Text = "左後";
	}
	else if (control->Text == "2") {
		connect1.send_cmd("-1 90 0");
		control->Text = "";
		state_label->Text = "後退";
	}
	else if (control->Text == "3") {
		connect1.send_cmd("-1 45 0");
		control->Text = "";
		state_label->Text = "右後";
	}
	else if(control->Text =="4" || control->Text == "6"){
		control->Text = "";
	}
}


