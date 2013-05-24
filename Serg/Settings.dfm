object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'COM PORT'
  ClientHeight = 176
  ClientWidth = 189
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 69
    Width = 52
    Height = 13
    Caption = #1057#1082#1086#1088#1086#1089#1090#1100':'
  end
  object Label2: TLabel
    Left = 8
    Top = 23
    Width = 68
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1087#1086#1088#1090#1072':'
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 88
    Width = 156
    Height = 21
    TabOrder = 0
    Text = '9600'
    Items.Strings = (
      '9600'
      '14400'
      '19200'
      '38400'
      '57600'
      '115200')
  end
  object ComboBox2: TComboBox
    Left = 8
    Top = 42
    Width = 156
    Height = 21
    TabOrder = 1
    Text = 'COM1'
  end
  object Button1: TButton
    Left = 8
    Top = 136
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 89
    Top = 136
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = Button2Click
  end
end
