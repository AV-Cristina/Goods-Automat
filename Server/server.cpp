#include <iostream.h>
#include "server.h"
#include "Unit1.h"
#include "Unit2.h"


//_________________ Cмена таблицы __________________________________________
void Staff::ViewTable()
{
 Form1->ADOTable1->Active = false;
 Form1->ADOTable1->TableName = Form1->ComboBox1->Items->Strings[Form1->ComboBox1->ItemIndex];
 Form1->ADOTable1->Active = true;
}


//_________________ Отправка данных клиенту  _______________________________
void Staff::SendData()
{
 HWND H3 = FindWindow(0, "Торговый автомат");
 COPYDATASTRUCT cd;
 Form1->DataSource2->DataSet = Form1->ADOTable2;
 Form1->ADOTable2->Active = true;
 goods g;
 Form1->ADOTable2->First();
 for (int i = 1; i<=Form1->ADOTable2->RecordCount; i++)
     {
     g.Id= Form1->ADOTable2->Fields->Fields[1]->AsInteger; //id товара
     g.StallNumber = Form1->ADOTable2->Fields->Fields[2]->AsInteger;
     g.Quantity = Form1->ADOTable2->Fields->Fields[3]->AsInteger;
     //поиск имени товара в 1й таблице по id товара из 2й
     Form1->ADOTable1->First();
     for (int j = 0; j<=Form1->ADOTable1->RecordCount; j++)
         {
         if (Form1->ADOTable1->Fields->Fields[0]->AsInteger == Form1->ADOTable2->Fields->Fields[1]->AsInteger)
             {
             char* n = new char[ Form1->ADOTable1->Fields->Fields[1]->AsString.Length() + 1 ];
             strcpy(n, Form1->ADOTable1->Fields->Fields[1]->AsString.c_str());
             strcpy(g.Name,n);
             g.Price = Form1->ADOTable1->Fields->Fields[2]->AsFloat;  //l++;
             cd.lpData=&g;
             cd.cbData= sizeof(g);
             cd.dwData=1;
             if (H3 != NULL)
         	{
                 SendMessage(H3,WM_COPYDATA, 0, (LPARAM) &cd);
        	}
             break;
             }
         else {Form1->ADOTable1->Next();}
         }
   Form1->ADOTable2->Next();
   }
}


//_________________ Oбновление БД после покупки_____________________________
void Staff::UpdateDB(int stall,  int id)
{
 Form1->ADOTable1->RecNo = id;
 Form1->ADOTable1->Edit();
 int tmp = Form1->ADOTable1->Fields->Fields[3]->AsInteger;
 Form1->ADOTable1->Fields->Fields[3]->AsInteger = tmp-1;
 Form1->ADOTable1->Post();

 Form1->ADOTable1->Active = false;
 Form1->ADOTable1->TableName = Form1->ComboBox1->Items->Strings[1];
 Form1->ADOTable1->Active = true;

 for (int i = 1; i<=Form1->ADOTable1->RecordCount; i++)
     {
     if ((Form1->ADOTable1->Fields->Fields[1]->AsInteger == id) && (Form1->ADOTable1->Fields->Fields[2]->AsInteger == stall))
        {
        Form1->ADOTable1->Edit();
        tmp = Form1->ADOTable1->Fields->Fields[3]->AsInteger;
        Form1->ADOTable1->Fields->Fields[3]->AsInteger = tmp-1;
        Form1->ADOTable1->Post();
        break;
        }
     else {Form1->ADOTable1->Next();}
     }

 Form1->ADOTable1->Active = false;
 Form1->ADOTable1->TableName = Form1->ComboBox1->Items->Strings[0];
 Form1->ADOTable1->Active = true;

 Form1->ADODataSet2->Close();
 Form1->ADODataSet2->CommandType = cmdText;
 Form1->ADODataSet2->CommandText = "SELECT * FROM GoodsTab";
 Form1->ADODataSet2->Open();

 Form1->ADOTable2->Active = false;
 Form1->ADOTable2->TableName = Form1->ComboBox1->Items->Strings[1];
 Form1->ADOTable2->Active = true;

}


//__________________ Вызов формы для ввода запроса _________________________
void Staff::InputQuery()
{
 Form2->Show();
 Form2->ADOQuery1->Connection = Form1->ADOConnection1;
 Form2->DataSource1->DataSet = Form2->ADOQuery1;
 Form2->ADOQuery1->Active = false;
 Form2->ADOQuery1->SQL->Clear();
 String sql =  "SELECT GoodsTab.Наименование, GoodsTab.Цена, StallsTab.Количество, StallsTab.Id_лотка FROM GoodsTab, StallsTab WHERE StallsTab.Id_товара = GoodsTab.Id ORDER BY GoodsTab.Id";
 Form2->ADOQuery1->SQL->Add(sql);
 Form2->ADOQuery1->Active = true;
 Form2->DBGrid1->DataSource = Form2->DataSource1;
}