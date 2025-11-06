object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 397
  ClientWidth = 710
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 80
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 80
    Top = 59
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object StringGrid1: TStringGrid
    Left = 192
    Top = 120
    Width = 409
    Height = 209
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 65
    Top = 93
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
  object MainMenu1: TMainMenu
    Left = 280
    Top = 24
    object matriz1: TMenuItem
      Caption = 'matriz'
      object cargarmatriz1: TMenuItem
        Caption = 'cargar_matriz'
        OnClick = cargarmatriz1Click
      end
      object cargarNivel21: TMenuItem
        Caption = 'cargarNivel2'
        OnClick = cargarNivel21Click
      end
      object pregunta11: TMenuItem
        Caption = 'pregunta1'
        OnClick = pregunta11Click
      end
    end
  end
end
