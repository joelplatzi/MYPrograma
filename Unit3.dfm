object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 425
  ClientWidth = 667
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 16
    Width = 89
    Height = 25
    Caption = 'Invertir numero'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 121
    Top = 20
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Button2: TButton
    Left = 8
    Top = 47
    Width = 89
    Height = 25
    Caption = 'suma digitos'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 121
    Top = 47
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Button3: TButton
    Left = 8
    Top = 78
    Width = 89
    Height = 25
    Caption = 'digito mayor'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 109
    Width = 89
    Height = 25
    Caption = 'Eliminar digito Z'
    TabOrder = 5
    OnClick = Button4Click
  end
end
