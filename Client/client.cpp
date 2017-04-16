#include "client.h"
#include "Automat.h"
#include "MesDescript.h"
#include <vcl.h>

//_________________ Запуск сервера _________________________________________
void Customer::Start()
{
 HWND H1 = FindWindow(0, "Станция обслуживания");
 if (H1 == NULL)  // если еще не запущено
 ShellExecute(Form1->Handle, NULL, "..\\Server\\Project1.exe", NULL, NULL, SW_SHOWNORMAL);

 Form1->GroupBox4->Visible = false;
 Form1->StringGrid1->Cells[0][0]="№ лотка";
 Form1->StringGrid1->Cells[1][0]="Наименование";
 Form1->StringGrid1->Cells[2][0]="Цена";
 Form1->StringGrid1->Cells[3][0]="Количество";
} 


//_________________ Ввод оплаты ____________________________________________
void Customer::InputMoney()
{
  for(int i=0; i<Form1->StringGrid1->RowCount - 1; i++)
    {
     if (Form1->StringGrid1->Cells[1][i] == Form1->StringGrid1->Cells[1][Form1->StringGrid1->Row] )
         {
         if (Form1->StringGrid1->Cells[0][i] == 1)
            {Form1->CheckBox1->Checked = true ;}
         if (Form1->StringGrid1->Cells[0][i] == 2)
            {Form1->CheckBox2->Checked = true ;}
         if (Form1->StringGrid1->Cells[0][i] == 3)
            {Form1->CheckBox3->Checked = true ;}
         if (Form1->StringGrid1->Cells[0][i] == 4)
            {Form1->CheckBox4->Checked = true ;}
         if (Form1->StringGrid1->Cells[0][i] == 5)
            {Form1->CheckBox5->Checked = true ;}
         }
    }
 float Price=0;
 if (Form1->Edit1->Text == "" && Form1->Edit2->Text == "")
    {MessageBox(NULL,"Вы не ввели оплату","Ошибка",MB_OK);}
 else
    {
    if (Form1->Edit2->Text == "")
       {Price = StrToInt(Form1->Edit1->Text);}       //только купюрами
    if (Form1->Edit1->Text == "")
       {Price = StrToFloat(Form1->Edit2->Text);}     //только монетами
    if (Form1->Edit1->Text != "" && Form1->Edit2->Text != "")
       {
       Price = StrToInt(Form1->Edit1->Text)+ StrToFloat(Form1->Edit2->Text);
       }

   int cur = Form1->StringGrid1->Row;

   if (Price == Form1->StringGrid1->Cells[2][cur])
       {
        Form1->GroupBox4->Visible = true;
        Form1->Edit3->Text = Price;
       }

   else {MessageBox(NULL,"Введенная оплата не соответствует цене товара","Ошибка",MB_OK);}
   }
}


//_________________ Возврат оплаты __________________________________________
void Customer::ReturnMoney()
{
 ShowMessage("Возьмите Ваши деньги");
 Form1->Edit1->Text = "";
 Form1->Edit2->Text = "";
}


//_________________ Выдача товара __________________________________________
void Customer::Buying(int* masId)
{
 Form1->Edit1->Text = "";
 Form1->Edit2->Text = "";
 Form1->GroupBox4->Visible = false;
 Form1->GroupBox1->Visible = true;
 AnsiString st_num = Form1->StringGrid1->Cells[0][Form1->StringGrid1->Row];
 ShowMessage("Возьмите Ваш товар с лотка № " + st_num );
 int q = StrToInt(Form1->StringGrid1->Cells[3][Form1->StringGrid1->Row]);
 Form1->StringGrid1->Cells[3][Form1->StringGrid1->Row] = q-1;
 //если товар закончился сообщить на станцию
 if (Form1->StringGrid1->Cells[3][Form1->StringGrid1->Row]== 0)
    {
     MSG m;
     m.wParam =  StrToInt(Form1->StringGrid1->Cells[0][Form1->StringGrid1->Row]); //№ лотка
     m.lParam = masId[Form1->StringGrid1->Row];       //id товара
     HWND H2 = FindWindow(0, "Станция обслуживания");
     if(PostMessage(H2, SM_ADD, m.wParam, m.lParam) == 0)
       {ShowMessage("Ошибка: неудалось отравить сообщение.");}
    }
 Form1->CheckBox1->Checked = false;
 Form1->CheckBox2->Checked = false;
 Form1->CheckBox3->Checked = false;
 Form1->CheckBox4->Checked = false;
 Form1->CheckBox5->Checked = false;
}
