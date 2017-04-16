//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mesDescript.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

TDBGrid *Grid1;
TDBGrid *Grid2;
TADOConnection *ADOConnection1;
TADOConnection *ADOConnection2;
TADOTable *ADOTable1;
TADOTable *ADOTable2;
TDataSource *DataSource1;
TDataSource *DataSource2;
TDBNavigator *DBNavigator;

Staff  St;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 Form1->WindowProc = OnMessage;
}


//_________________ Прием сообщения (о покупке) ____________________________
void __fastcall TForm1::OnMessage(Messages::TMessage &Message)
{
 if(Message.Msg == SM_ADD)
  {
  ShowMessage("На лотке № " + IntToStr(Message.WParam)+ " отсутствует товар");
  St.UpdateDB(Message.WParam, Message.LParam);
  }
  else {WndProc(Message);}
}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 // динамическое создание компонентов
 Grid1 = new TDBGrid(Form1->GroupBox1);
 Grid1->Left = 16;
 Grid1->Top = 112;
 Grid1->Width = 500;
 Grid1->Height = 270;
 Grid1->FixedColor = clSkyBlue;
 Grid1->Parent = Form1->GroupBox1;

 Grid2 = new TDBGrid(Form1->GroupBox1);
 Grid2->Left = 16;
 Grid2->Top = 112;
 Grid2->Width = 500;
 Grid2->Height = 270;
 Grid2->Parent = Form1->GroupBox1;
 Grid2->Visible = false;

 DBNavigator = new TDBNavigator(Form1->GroupBox1);
 DBNavigator->Left = 16;
 DBNavigator->Top = 72;
 DBNavigator->Width = 500;
 DBNavigator->Height = 25;
 DBNavigator->Parent = Form1->GroupBox1;

 //-------------------- Получение директории БД  -----------------------------------
 String Dir;
 bool client = false;
 char* RealPath;
 char* CurPath = new char[GetCurrentDir().Length() + 1 ];
 strcpy(CurPath, GetCurrentDir().c_str());

 int len = GetCurrentDir().Length();

 char ch = '0'; int n = 0, l = len;
 while  (ch  != '\\')
        {ch = CurPath[l];  l--;  n++;}

 char* LastCatalog = new char[n-2];
 l = len;
 for (int i=n-2; i>=0; i--)
     {LastCatalog[i] = CurPath[l]; l--;}

 if (strcmp(LastCatalog, "Client") == 0)
    {
    client =  true;
    RealPath = new char[len - (n-2)];
    for (int i=0; i<len-(n-2); i++)
        {RealPath[i] = CurPath[i];}
    Dir = RealPath;
    }
 else {Dir = CurPath;}

 //-------------------- таблица Goods ------------------------------------------
 ADOConnection1->LoginPrompt = false;
 if (client ==  true)
 {ADOConnection1->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+Dir+"\\Server\\DB\\MyDB.mdb;"+"Mode=ReadWrite;Persist Security Info=False";}
 else
 {ADOConnection1->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+Dir+"\\DB\\MyDB.mdb;"+"Mode=ReadWrite;Persist Security Info=False";}

 ADOConnection1->Connected = true;

 ADODataSet1->Connection = ADOConnection1;

 ADOTable1->Connection = ADOConnection1;
 ADOConnection1->GetTableNames(ComboBox1->Items, false);
 ADOTable1->TableName = ComboBox1->Items->Strings[0];
 ADOTable1->Active = true;

 DataSource1->DataSet = ADOTable1;

 Grid1->DataSource = DataSource1;
 DBNavigator->DataSource = DataSource1;

 //-------------------- таблица Stall ------------------------------------------
 ADOConnection2->LoginPrompt = false;

 if (client ==  true)
 {ADOConnection2->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+Dir+"\\Server\\DB\\MyDB.mdb;"+"Mode=ReadWrite;Persist Security Info=False";}
 else
 {ADOConnection2->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+Dir+"\\DB\\MyDB.mdb;"+"Mode=ReadWrite;Persist Security Info=False";}

 ADOConnection2->Connected=true;

 ADODataSet2->Connection = ADOConnection2;

 ADOTable2->Connection = ADOConnection2;
 ADOTable2->TableName = ComboBox1->Items->Strings[1];
 ADOTable2->Active = true;

 DataSource2->DataSet = ADOTable2;

 Grid2->DataSource = DataSource2;
}


//_________________ Cмена таблицы __________________________________________
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
 St.ViewTable();
}


//_________________ Отправка данных клиенту  _______________________________
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 St.SendData();
}


//__________________ Вызов формы для ввода запроса _________________________
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 St.InputQuery();
}


//_________________ Oбновление БД __________________________________________
void __fastcall TForm1::DBNavigatorClick(TObject *Sender,TNavigateBtn Button)
{
 if (Button==nbPost)
   {
    ShowMessage("Post!");
    St.SendData();
   }
}
//---------------------------------------------------------------------------