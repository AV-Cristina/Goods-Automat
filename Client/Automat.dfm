object Form1: TForm1
  Left = 301
  Top = 159
  Width = 570
  Height = 505
  Caption = #1058#1086#1088#1075#1086#1074#1099#1081' '#1072#1074#1090#1086#1084#1072#1090
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
    Top = 12
    Width = 549
    Height = 61
    Caption = #1051#1086#1090#1082#1080
    TabOrder = 0
    object CheckBox1: TCheckBox
      Left = 20
      Top = 28
      Width = 33
      Height = 17
      Caption = ' 1'
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 128
      Top = 28
      Width = 37
      Height = 17
      Caption = ' 2'
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 240
      Top = 28
      Width = 37
      Height = 17
      Caption = ' 3'
      TabOrder = 2
    end
    object CheckBox4: TCheckBox
      Left = 360
      Top = 28
      Width = 37
      Height = 17
      Caption = ' 4'
      TabOrder = 3
    end
    object CheckBox5: TCheckBox
      Left = 480
      Top = 28
      Width = 41
      Height = 21
      Caption = ' 5'
      TabOrder = 4
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 84
    Width = 549
    Height = 73
    Caption = #1054#1087#1083#1072#1090#1072
    TabOrder = 1
    object Label1: TLabel
      Left = 24
      Top = 36
      Width = 40
      Height = 13
      Caption = #1050#1091#1087#1102#1088#1099
    end
    object Label2: TLabel
      Left = 216
      Top = 36
      Width = 40
      Height = 13
      Caption = #1052#1086#1085#1077#1090#1099
    end
    object Edit1: TEdit
      Left = 84
      Top = 28
      Width = 85
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 276
      Top = 28
      Width = 85
      Height = 21
      TabOrder = 1
    end
    object Button1: TButton
      Left = 432
      Top = 28
      Width = 93
      Height = 25
      Caption = #1042#1074#1086#1076' '#1086#1087#1083#1072#1090#1099
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 168
    Width = 549
    Height = 297
    Caption = #1058#1086#1074#1072#1088#1099
    TabOrder = 2
    object StringGrid1: TStringGrid
      Left = 8
      Top = 24
      Width = 529
      Height = 257
      ColCount = 4
      FixedColor = clSkyBlue
      FixedCols = 0
      RowCount = 2
      TabOrder = 0
      ColWidths = (
        93
        208
        111
        109)
    end
  end
  object GroupBox4: TGroupBox
    Left = 8
    Top = 84
    Width = 549
    Height = 73
    Caption = #1055#1086#1076#1090#1074#1077#1088#1078#1076#1077#1085#1080#1077' '#1087#1086#1082#1091#1087#1082#1080
    TabOrder = 3
    object Label3: TLabel
      Left = 20
      Top = 36
      Width = 87
      Height = 13
      Caption = #1055#1088#1080#1085#1103#1090#1072#1103' '#1086#1087#1083#1072#1090#1072
    end
    object Button2: TButton
      Left = 280
      Top = 32
      Width = 113
      Height = 25
      Caption = #1042#1099#1076#1072#1095#1072' '#1090#1086#1074#1072#1088#1072
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 420
      Top = 28
      Width = 113
      Height = 29
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1086#1087#1083#1072#1090#1099
      TabOrder = 1
      OnClick = Button3Click
    end
    object Edit3: TEdit
      Left = 128
      Top = 32
      Width = 121
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
end
