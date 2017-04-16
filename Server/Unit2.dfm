object Form2: TForm2
  Left = 321
  Top = 98
  Width = 561
  Height = 444
  Caption = #1047#1072#1087#1088#1086#1089#1099
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 332
    Width = 126
    Height = 13
    Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102
  end
  object Label2: TLabel
    Left = 8
    Top = 372
    Width = 119
    Height = 13
    Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1083#1086#1090#1082#1072
  end
  object Label3: TLabel
    Left = 8
    Top = 16
    Width = 166
    Height = 13
    Caption = #1059#1087#1086#1088#1103#1076#1086#1095#1080#1090#1100' '#1079#1072#1087#1080#1089#1080' '#1090#1072#1073#1083#1080#1094#1099' '#1087#1086
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 52
    Width = 537
    Height = 249
    FixedColor = clSkyBlue
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Edit1: TEdit
    Left = 148
    Top = 324
    Width = 237
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 424
    Top = 324
    Width = 117
    Height = 25
    Caption = #1055#1086#1080#1089#1082
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 148
    Top = 364
    Width = 237
    Height = 21
    TabOrder = 3
  end
  object Button2: TButton
    Left = 424
    Top = 364
    Width = 117
    Height = 25
    Caption = #1055#1086#1080#1089#1082
    TabOrder = 4
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 200
    Top = 12
    Width = 341
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 5
    OnChange = ComboBox1Change
    Items.Strings = (
      'GoodsTab.Id'
      'StallsTab.Id_'#1083#1086#1090#1082#1072
      'GoodsTab.'#1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      'GoodsTab.'#1062#1077#1085#1072
      'StallsTab.'#1050#1086#1083#1080#1095#1077#1089#1090#1074#1086)
  end
  object DataSource1: TDataSource
    Left = 8
    Top = 52
  end
  object ADOQuery1: TADOQuery
    Parameters = <>
    Left = 36
    Top = 56
  end
end
