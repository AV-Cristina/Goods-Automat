//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Automat.h"
#include <Math.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Customer C;
int* masId = new int [50];


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 Form1->WindowProc = OnMessage;
}


//_________________ Запуск сервера _________________________________________
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 C.Start();
}


//_________________ Прием сообщения ________________________________________
void __fastcall TForm1::OnMessage(Messages::TMessage &Message)
{
  if(Message.Msg == WM_COPYDATA)
  {
	COPYDATASTRUCT *cd;
       	cd = (COPYDATASTRUCT *) Message.LParam;

        Goods g;
        memcpy(&g, cd->lpData, cd->cbData);
        int n = StringGrid1->RowCount - 1;
        StringGrid1->RowCount++;
        StringGrid1->Cells[0][n]= g.StallNumber;
        StringGrid1->Cells[1][n]= g.Name;
        StringGrid1->Cells[2][n]= AnsiString(RoundTo(g.Price, -2));;
        StringGrid1->Cells[3][n]= g.Quantity;
        masId[n] = g.Id;
  }
  else {WndProc(Message);}
}


//_________________ Ввод оплаты ____________________________________________
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 C.InputMoney();
}


//_________________ Возврат оплаты __________________________________________
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 C.ReturnMoney();
}


//_________________ Выдача товара __________________________________________
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 C.Buying(masId);
}
//---------------------------------------------------------------------------