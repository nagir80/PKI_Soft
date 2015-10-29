object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1057#1090#1077#1085#1076'_'#1055#1050#1048
  ClientHeight = 504
  ClientWidth = 742
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label12: TLabel
    Left = 5
    Top = 197
    Width = 46
    Height = 13
    Caption = #1063#1072#1089#1090#1086#1090#1072':'
  end
  object Label13: TLabel
    Left = 5
    Top = 226
    Width = 52
    Height = 13
    Caption = #1057#1082#1086#1088#1086#1089#1090#1100':'
  end
  object Label14: TLabel
    Left = 5
    Top = 255
    Width = 128
    Height = 13
    Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1087#1077#1088#1077#1076#1072#1095#1080' MSS:'
  end
  object Panel1: TPanel
    Left = 5
    Top = 8
    Width = 140
    Height = 117
    TabOrder = 0
    object Label1: TLabel
      Left = 7
      Top = 6
      Width = 113
      Height = 13
      Caption = #1042#1088#1077#1084#1103' '#1089#1080#1085#1093#1088#1086#1085#1080#1079#1072#1094#1080#1080':'
    end
    object Label2: TLabel
      Left = 7
      Top = 66
      Width = 66
      Height = 13
      Caption = #1042#1088#1077#1084#1103' '#1090#1077#1089#1090#1072':'
    end
    object ComboBox1: TComboBox
      Left = 7
      Top = 28
      Width = 100
      Height = 21
      TabOrder = 0
      Items.Strings = (
        '10 '#1089#1077#1082'.'
        '20 '#1089#1077#1082'.'
        '30 '#1089#1077#1082'.'
        '1 '#1084#1080#1085'.'
        '2 '#1084#1080#1085'.'
        '5 '#1084#1080#1085'.'
        '10 '#1084#1080#1085'.'
        #1053#1077' '#1086#1075#1088'.')
    end
    object ComboBox2: TComboBox
      Left = 7
      Top = 88
      Width = 100
      Height = 21
      TabOrder = 1
      Items.Strings = (
        '10 '#1089#1077#1082'.'
        '20 '#1089#1077#1082'.'
        '30 '#1089#1077#1082'.'
        '1 '#1084#1080#1085'.'
        '2 '#1084#1080#1085'.'
        '5 '#1084#1080#1085'.'
        '10 '#1084#1080#1085'.'
        #1053#1077' '#1086#1075#1088'.')
    end
  end
  object Panel2: TPanel
    Left = 5
    Top = 310
    Width = 223
    Height = 192
    TabOrder = 1
    object Panel3: TPanel
      Left = 7
      Top = 7
      Width = 207
      Height = 122
      TabOrder = 0
      object Label3: TLabel
        Left = 9
        Top = 8
        Width = 30
        Height = 13
        Caption = #1041#1080#1090#1099':'
      end
      object Label4: TLabel
        Left = 9
        Top = 96
        Width = 62
        Height = 13
        Caption = #1057#1086#1086#1073#1097#1077#1085#1080#1103':'
      end
      object Label5: TLabel
        Left = 115
        Top = 32
        Width = 30
        Height = 13
        Caption = #1058#1086#1095#1085#1086
      end
      object Label6: TLabel
        Left = 115
        Top = 59
        Width = 45
        Height = 13
        Caption = #1058#1077#1082#1091#1097#1080#1077
      end
      object Button1: TButton
        Left = 151
        Top = 0
        Width = 56
        Height = 25
        Caption = #1054#1096#1080#1073#1082#1080
        Enabled = False
        TabOrder = 0
      end
      object Edit1: TEdit
        Left = 9
        Top = 29
        Width = 100
        Height = 21
        Enabled = False
        TabOrder = 1
      end
      object Edit2: TEdit
        Left = 9
        Top = 56
        Width = 100
        Height = 21
        Enabled = False
        TabOrder = 2
      end
      object Edit3: TEdit
        Left = 77
        Top = 93
        Width = 100
        Height = 21
        Enabled = False
        TabOrder = 3
      end
    end
    object Panel4: TPanel
      Left = 8
      Top = 133
      Width = 207
      Height = 52
      TabOrder = 1
      object Label7: TLabel
        Left = 9
        Top = 2
        Width = 68
        Height = 13
        Caption = #1055#1088#1080#1085#1103#1090#1086' '#1073#1080#1090':'
      end
      object Edit4: TEdit
        Left = 9
        Top = 21
        Width = 121
        Height = 21
        Enabled = False
        TabOrder = 0
      end
    end
  end
  object Button2: TButton
    Left = 234
    Top = 425
    Width = 100
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 334
    Top = 425
    Width = 100
    Height = 25
    Caption = #1057#1090#1086#1087
    Enabled = False
    TabOrder = 3
  end
  object Button4: TButton
    Left = 431
    Top = 425
    Width = 100
    Height = 25
    Caption = #1057#1090#1072#1088#1090
    Enabled = False
    TabOrder = 4
    OnClick = Button4Click
  end
  object GroupBox1: TGroupBox
    Left = 154
    Top = 1
    Width = 329
    Height = 168
    Caption = #1052#1086#1076#1091#1083#1103#1090#1086#1088
    TabOrder = 5
    object SpeedButton1: TSpeedButton
      Left = 154
      Top = 18
      Width = 23
      Height = 22
      Caption = '-'
      Enabled = False
    end
    object SpeedButton2: TSpeedButton
      Left = 176
      Top = 18
      Width = 23
      Height = 22
      Caption = '+'
      Enabled = False
    end
    object Label8: TLabel
      Left = 232
      Top = 65
      Width = 31
      Height = 13
      Caption = 'Label8'
      Enabled = False
    end
    object Label9: TLabel
      Left = 232
      Top = 86
      Width = 31
      Height = 13
      Caption = 'Label9'
      Enabled = False
    end
    object Label10: TLabel
      Left = 7
      Top = 21
      Width = 46
      Height = 13
      Caption = #1063#1072#1089#1090#1086#1090#1072':'
    end
    object Label11: TLabel
      Left = 7
      Top = 43
      Width = 52
      Height = 13
      Caption = #1057#1082#1086#1088#1086#1089#1090#1100':'
    end
    object Label15: TLabel
      Left = 7
      Top = 65
      Width = 130
      Height = 13
      Caption = #1048#1085#1076#1077#1082#1089' '#1086#1087#1086#1088#1085#1086#1081' '#1089#1090#1072#1085#1094#1080#1080':'
    end
    object Label16: TLabel
      Left = 7
      Top = 86
      Width = 102
      Height = 13
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1089#1090#1072#1085#1094#1080#1080':'
    end
    object ComboBox3: TComboBox
      Left = 205
      Top = 18
      Width = 100
      Height = 21
      Enabled = False
      TabOrder = 0
    end
    object ComboBox4: TComboBox
      Left = 205
      Top = 40
      Width = 100
      Height = 21
      Enabled = False
      TabOrder = 1
    end
    object Button5: TButton
      Left = 131
      Top = 121
      Width = 20
      Height = 20
      Caption = '7'
      TabOrder = 2
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 150
      Top = 121
      Width = 20
      Height = 20
      Caption = '9'
      TabOrder = 3
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 169
      Top = 121
      Width = 20
      Height = 20
      Caption = '16'
      TabOrder = 4
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 188
      Top = 121
      Width = 20
      Height = 20
      Caption = '34'
      TabOrder = 5
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 207
      Top = 121
      Width = 20
      Height = 20
      Caption = '35'
      TabOrder = 6
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 226
      Top = 121
      Width = 20
      Height = 20
      Caption = '36'
      TabOrder = 7
      OnClick = Button10Click
    end
    object CheckBox1: TCheckBox
      Left = 135
      Top = 140
      Width = 15
      Height = 15
      TabOrder = 8
    end
    object CheckBox2: TCheckBox
      Left = 154
      Top = 140
      Width = 15
      Height = 15
      TabOrder = 9
    end
    object CheckBox3: TCheckBox
      Left = 173
      Top = 140
      Width = 15
      Height = 15
      TabOrder = 10
    end
    object CheckBox4: TCheckBox
      Left = 192
      Top = 140
      Width = 15
      Height = 15
      TabOrder = 11
    end
    object CheckBox5: TCheckBox
      Left = 229
      Top = 140
      Width = 15
      Height = 15
      TabOrder = 12
    end
    object CheckBox6: TCheckBox
      Left = 211
      Top = 140
      Width = 15
      Height = 15
      TabOrder = 13
    end
  end
  object GroupBox3: TGroupBox
    Left = 151
    Top = 168
    Width = 190
    Height = 136
    Caption = #1055#1077#1088#1074#1099#1081' '#1082#1072#1085#1072#1083
    TabOrder = 6
    object SpeedButton5: TSpeedButton
      Left = 3
      Top = 24
      Width = 30
      Height = 20
      AllowAllUp = True
      GroupIndex = 1
      Caption = 'Auto'
      OnClick = SpeedButton5Click
    end
    object SpeedButton6: TSpeedButton
      Left = 3
      Top = 55
      Width = 30
      Height = 20
      Caption = 'Auto'
    end
    object SpeedButton9: TSpeedButton
      Left = 26
      Top = 110
      Width = 100
      Height = 20
      Caption = #1053#1077' '#1074#1099#1076#1072#1074#1072#1090#1100' MSK'
    end
    object ComboBox7: TComboBox
      Left = 39
      Top = 28
      Width = 100
      Height = 21
      ItemIndex = 33
      TabOrder = 0
      Text = '300.0'
      Items.Strings = (
        '283.5'
        '284.0'
        '284.5'
        '285.0'
        '285.5'
        '286.0'
        '286.5'
        '287.0'
        '287.5'
        '288.0'
        '288.5'
        '289.0'
        '289.5'
        '290.0'
        '290.5'
        '291.0'
        '291.5'
        '292.0'
        '292.5'
        '293.0'
        '293.5'
        '294.0'
        '294.5'
        '295.0'
        '295.5'
        '296.0'
        '296.5'
        '297.0'
        '297.5'
        '298.0'
        '298.5'
        '299.0'
        '299.5'
        '300.0'
        '300.5'
        '301.0'
        '301.5'
        '302.0'
        '302.5'
        '303.0'
        '303.5'
        '304.0'
        '304.5'
        '305.0'
        '305.5'
        '306.0'
        '306.5'
        '307.0'
        '307.5'
        '308.0'
        '308.5'
        '309.0'
        '309.5'
        '310.0'
        '310.5'
        '311.0'
        '311.5'
        '312.0'
        '312.5'
        '313.0'
        '313.5'
        '314.0'
        '314.5'
        '315.0'
        '315.5'
        '316.0'
        '316.5'
        '317.0'
        '317.5'
        '318.0'
        '318.5'
        '319.0'
        '319.5'
        '320.0'
        '320.5'
        '321.0'
        '321.5'
        '322.0'
        '322.5'
        '323.0'
        '323.5'
        '324.0'
        '324.5'
        '325.0')
    end
    object ComboBox8: TComboBox
      Left = 39
      Top = 55
      Width = 100
      Height = 21
      ItemIndex = 0
      TabOrder = 1
      Text = '200'
      Items.Strings = (
        '200'
        '100'
        '50')
    end
    object Edit9: TEdit
      Left = 26
      Top = 84
      Width = 100
      Height = 21
      TabOrder = 2
      Text = '5'
    end
  end
  object GroupBox4: TGroupBox
    Left = 344
    Top = 168
    Width = 190
    Height = 136
    Caption = #1042#1090#1086#1088#1086#1081' '#1082#1072#1085#1072#1083
    TabOrder = 7
    object SpeedButton7: TSpeedButton
      Left = 3
      Top = 24
      Width = 30
      Height = 20
      AllowAllUp = True
      GroupIndex = 1
      Caption = 'Auto'
      OnClick = SpeedButton7Click
    end
    object SpeedButton8: TSpeedButton
      Left = 3
      Top = 55
      Width = 30
      Height = 20
      Caption = 'Auto'
    end
    object SpeedButton10: TSpeedButton
      Left = 27
      Top = 110
      Width = 100
      Height = 20
      Caption = #1053#1077' '#1074#1099#1076#1072#1074#1072#1090#1100' MSK'
    end
    object ComboBox9: TComboBox
      Left = 39
      Top = 26
      Width = 100
      Height = 21
      ItemIndex = 33
      TabOrder = 0
      Text = '300.0'
      Items.Strings = (
        '283.5'
        '284.0'
        '284.5'
        '285.0'
        '285.5'
        '286.0'
        '286.5'
        '287.0'
        '287.5'
        '288.0'
        '288.5'
        '289.0'
        '289.5'
        '290.0'
        '290.5'
        '291.0'
        '291.5'
        '292.0'
        '292.5'
        '293.0'
        '293.5'
        '294.0'
        '294.5'
        '295.0'
        '295.5'
        '296.0'
        '296.5'
        '297.0'
        '297.5'
        '298.0'
        '298.5'
        '299.0'
        '299.5'
        '300.0'
        '300.5'
        '301.0'
        '301.5'
        '302.0'
        '302.5'
        '303.0'
        '303.5'
        '304.0'
        '304.5'
        '305.0'
        '305.5'
        '306.0'
        '306.5'
        '307.0'
        '307.5'
        '308.0'
        '308.5'
        '309.0'
        '309.5'
        '310.0'
        '310.5'
        '311.0'
        '311.5'
        '312.0'
        '312.5'
        '313.0'
        '313.5'
        '314.0'
        '314.5'
        '315.0'
        '315.5'
        '316.0'
        '316.5'
        '317.0'
        '317.5'
        '318.0'
        '318.5'
        '319.0'
        '319.5'
        '320.0'
        '320.5'
        '321.0'
        '321.5'
        '322.0'
        '322.5'
        '323.0'
        '323.5'
        '324.0'
        '324.5'
        '325.0')
    end
    object ComboBox10: TComboBox
      Left = 39
      Top = 55
      Width = 100
      Height = 21
      ItemIndex = 0
      TabOrder = 1
      Text = '200'
      Items.Strings = (
        '200'
        '100'
        '50')
    end
    object Edit10: TEdit
      Left = 27
      Top = 84
      Width = 100
      Height = 21
      TabOrder = 2
      Text = '5'
    end
  end
  object Edit11: TEdit
    Left = 234
    Top = 340
    Width = 300
    Height = 21
    Enabled = False
    TabOrder = 8
  end
  object Edit12: TEdit
    Left = 234
    Top = 366
    Width = 150
    Height = 21
    Enabled = False
    TabOrder = 9
  end
  object Edit13: TEdit
    Left = 234
    Top = 388
    Width = 150
    Height = 21
    Enabled = False
    TabOrder = 10
  end
  object Edit14: TEdit
    Left = 384
    Top = 366
    Width = 150
    Height = 21
    Enabled = False
    TabOrder = 11
  end
  object Edit15: TEdit
    Left = 384
    Top = 388
    Width = 150
    Height = 21
    Enabled = False
    TabOrder = 12
  end
  object Button11: TButton
    Left = 482
    Top = 8
    Width = 49
    Height = 161
    Caption = #1042#1099#1082#1083
    Enabled = False
    TabOrder = 13
  end
  object GroupBox2: TGroupBox
    Left = 537
    Top = 8
    Width = 200
    Height = 488
    Caption = 'test'
    TabOrder = 14
    object Label17: TLabel
      Left = 12
      Top = 23
      Width = 57
      Height = 13
      Caption = #1052#1086#1076#1091#1083#1103#1090#1086#1088
    end
    object Label18: TLabel
      Left = 12
      Top = 244
      Width = 49
      Height = 13
      Caption = #1055#1088#1080#1105#1084#1085#1080#1082
    end
    object Memo1: TMemo
      Left = 12
      Top = 45
      Width = 185
      Height = 89
      TabOrder = 0
    end
    object Edit5: TEdit
      Left = 12
      Top = 140
      Width = 181
      Height = 21
      TabOrder = 1
    end
    object Button12: TButton
      Left = 12
      Top = 167
      Width = 75
      Height = 25
      Caption = #1054#1090#1087#1088#1072#1074#1080#1090#1100
      TabOrder = 2
      OnClick = Button12Click
    end
    object Memo2: TMemo
      Left = 12
      Top = 270
      Width = 185
      Height = 89
      TabOrder = 3
    end
    object Edit6: TEdit
      Left = 12
      Top = 365
      Width = 185
      Height = 21
      TabOrder = 4
    end
    object Button13: TButton
      Left = 12
      Top = 392
      Width = 75
      Height = 25
      Caption = #1054#1090#1087#1088#1072#1074#1080#1090#1100
      TabOrder = 5
      OnClick = Button13Click
    end
  end
end
