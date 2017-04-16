//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}


//_________________ Упорядочить по ...  ____________________________________
void __fastcall TForm2::ComboBox1Change(TObject *Sender)
{
 Form2->ADOQuery1->Connection = Form1->ADOConnection1;
 Form2->DataSource1->DataSet = Form2->ADOQuery1;
 Form2->ADOQuery1->Active = false;
 Form2->ADOQuery1->SQL->Clear();
 String s = Form2->ComboBox1->Items->Strings[Form2->ComboBox1->ItemIndex];
 String sql = "SELECT GoodsTab.Наименование, GoodsTab.Цена, StallsTab.Количество, StallsTab.Id_лотка FROM GoodsTab, StallsTab WHERE StallsTab.Id_товара = GoodsTab.Id ORDER BY " + s;
 Form2->ADOQuery1->SQL->Add(sql);
 Form2->ADOQuery1->Active = true;
 Form2->DBGrid1->DataSource = Form2->DataSource1;
}


//_________________ Поиск по наименованию __________________________________
void __fastcall TForm2::Button1Click(TObject *Sender)
{
 char* Name = new char[Form2->Edit1->Text.Length() + 1 ];
 strcpy( Name, Form2->Edit1->Text.c_str());
 bool exist = false;
 Form1->ADOTable1->First();
 for (int i = 1; i<=Form1->ADOTable1->RecordCount; i++)
     {
     if (strcmp(Name, Form1->ADOTable1->Fields->Fields[1]->AsString.c_str()) == 0) {exist = true; break;}
     else {Form1->ADOTable1->Next();}
     }

 if (exist == true)
    {
    Form2->ADOQuery1->Connection = Form1->ADOConnection1;
    Form2->DataSource1->DataSet = Form2->ADOQuery1;
    Form2->ADOQuery1->Active = false;
    Form2->ADOQuery1->SQL->Clear();
    String n = Form2->Edit1->Text;
    String sql = "SELECT GoodsTab.Наименование, GoodsTab.Цена, StallsTab.Количество, StallsTab.Id_лотка FROM GoodsTab, StallsTab WHERE StallsTab.Id_товара = GoodsTab.Id AND GoodsTab.Наименование = \"" + n + "\"";
    Form2->ADOQuery1->SQL->Add(sql);
    Form2->ADOQuery1->Active = true;
    Form2->DBGrid1->DataSource = Form2->DataSource1;
    }
  else {MessageBox(NULL,"Этот товар отсутствует","Ошибка",MB_OK);}
}


//_________________ Поиск по номеру лотка __________________________________
void __fastcall TForm2::Button2Click(TObject *Sender)
{
 if (StrToInt(Form2->Edit2->Text)>5 || StrToInt(Form2->Edit2->Text)<0)
    {MessageBox(NULL,"Лоток с таким номером отсутствует, введите число от 1 до 5","Ошибка",MB_OK);}
 else
    {
    Form2->ADOQuery1->Connection = Form1->ADOConnection1;
    Form2->DataSource1->DataSet = Form2->ADOQuery1;
    Form2->ADOQuery1->Active = false;
    Form2->ADOQuery1->SQL->Clear();
    String num = Form2->Edit2->Text;
    String sql = "SELECT GoodsTab.Наименование, GoodsTab.Цена, StallsTab.Количество, StallsTab.Id_лотка FROM GoodsTab, StallsTab WHERE StallsTab.Id_товара = GoodsTab.Id AND StallsTab.Id_лотка = " + num;
    Form2->ADOQuery1->SQL->Add(sql);
    Form2->ADOQuery1->Active = true;
    Form2->DBGrid1->DataSource = Form2->DataSource1;
    }
}
//---------------------------------------------------------------------------