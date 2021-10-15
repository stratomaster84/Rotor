object Form1: TForm1
  Left = 205
  Top = 119
  Width = 725
  Height = 587
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Rotor Wankel'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 16
    Top = 8
    Width = 400
    Height = 400
    Color = clBtnFace
    ParentColor = False
  end
  object Label1: TLabel
    Left = 152
    Top = 408
    Width = 118
    Height = 20
    Caption = 'Вращать ротор'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 144
    Top = 456
    Width = 140
    Height = 20
    Caption = 'Увеличить статор'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 160
    Top = 504
    Width = 133
    Height = 20
    Caption = 'Увеличить Ротор'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 520
    Top = 56
    Width = 111
    Height = 20
    Caption = 'Форма ротора'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ScrollBar1: TScrollBar
    Left = 16
    Top = 432
    Width = 401
    Height = 17
    Max = 1001
    PageSize = 0
    Position = 1
    TabOrder = 0
    OnChange = ScrollBar1Change
  end
  object ScrollBar2: TScrollBar
    Left = 16
    Top = 480
    Width = 401
    Height = 17
    Max = 150
    Min = 1
    PageSize = 0
    Position = 150
    TabOrder = 1
    OnChange = ScrollBar2Change
  end
  object ScrollBar3: TScrollBar
    Left = 16
    Top = 528
    Width = 401
    Height = 17
    Max = 150
    PageSize = 0
    Position = 30
    TabOrder = 2
    OnChange = ScrollBar3Change
  end
  object RadioGroup1: TRadioGroup
    Left = 432
    Top = 304
    Width = 265
    Height = 105
    Caption = 'Заполнение статора'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemIndex = 1
    Items.Strings = (
      'Заполнять'
      'Не заполнять')
    ParentFont = False
    TabOrder = 3
    OnClick = RadioGroup1Click
  end
  object Edit1: TEdit
    Left = 432
    Top = 432
    Width = 49
    Height = 21
    ReadOnly = True
    TabOrder = 4
    Text = '0'
  end
  object RadioGroup2: TRadioGroup
    Left = 432
    Top = 120
    Width = 265
    Height = 169
    Caption = 'Форма ротора'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      'Простая (треугольная)'
      'Параболическое сглаживание'
      'Сферическое сглаживание')
    ParentFont = False
    TabOrder = 5
    OnClick = RadioGroup2Click
  end
  object ScrollBar4: TScrollBar
    Left = 432
    Top = 88
    Width = 265
    Height = 17
    PageSize = 0
    TabOrder = 6
    OnChange = ScrollBar4Change
  end
end
