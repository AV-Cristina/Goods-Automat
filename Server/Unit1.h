//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "server.h"
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TComboBox *ComboBox1;
        TButton *Button1;
        TADODataSet *ADODataSet1;
        TADOTable *ADOTable1;
        TDataSource *DataSource1;
        TADODataSet *ADODataSet2;
        TADOTable *ADOTable2;
        TDataSource *DataSource2;
        TADOConnection *ADOConnection1;
        TADOConnection *ADOConnection2;
        TButton *Button2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
       // void __fastcall BtnClick(TNavigateBtn Index);
        void __fastcall DBNavigatorClick(TObject *Sender,TNavigateBtn Button);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall OnMessage(Messages::TMessage &Message);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
