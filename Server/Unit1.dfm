object Form1: TForm1
  Left = 522
  Top = 97
  Width = 562
  Height = 477
  Caption = #1057#1090#1072#1085#1094#1080#1103' '#1086#1073#1089#1083#1091#1078#1080#1074#1072#1085#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 537
    Height = 425
    Caption = #1058#1072#1073#1083#1080#1094#1072' '#1090#1086#1074#1072#1088#1086#1074
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 28
      Width = 68
      Height = 13
      Caption = #1048#1084#1103' '#1090#1072#1073#1083#1080#1094#1099
    end
    object ComboBox1: TComboBox
      Left = 100
      Top = 24
      Width = 153
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 0
      OnChange = ComboBox1Change
    end
    object Button2: TButton
      Left = 416
      Top = 20
      Width = 109
      Height = 25
      Caption = #1042#1074#1077#1089#1090#1080' '#1079#1072#1087#1088#1086#1089
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object Button1: TButton
    Left = 292
    Top = 28
    Width = 109
    Height = 25
    Caption = #1054#1090#1087#1088#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
    TabOrder = 1
    OnClick = Button1Click
  end
  object ADODataSet1: TADODataSet
    Parameters = <>
    Left = 52
    Top = 72
  end
  object ADOTable1: TADOTable
    Left = 76
    Top = 72
  end
  object DataSource1: TDataSource
    Left = 100
    Top = 72
  end
  object ADODataSet2: TADODataSet
    Parameters = <>
    Left = 52
    Top = 100
  end
  object ADOTable2: TADOTable
    Left = 80
    Top = 100
  end
  object DataSource2: TDataSource
    Left = 108
    Top = 100
  end
  object ADOConnection1: TADOConnection
    Left = 24
    Top = 72
  end
  object ADOConnection2: TADOConnection
    Left = 24
    Top = 100
  end
end
