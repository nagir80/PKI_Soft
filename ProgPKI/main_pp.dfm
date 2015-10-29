object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'ProgPKI'
  ClientHeight = 577
  ClientWidth = 799
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 393
    Height = 297
    TabOrder = 0
    object Label1: TLabel
      Left = 104
      Top = 0
      Width = 160
      Height = 19
      Caption = #1057#1090#1072#1088#1090#1086#1074#1099#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 48
      Width = 112
      Height = 13
      Caption = #1055#1086#1076#1082#1083#1102#1095#1072#1090#1100#1089#1103' '#1095#1077#1088#1077#1079':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 8
      Top = 79
      Width = 90
      Height = 13
      Caption = #1057#1082#1086#1088#1086#1089#1090#1100' ('#1073#1080#1090'/c):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 8
      Top = 111
      Width = 72
      Height = 13
      Caption = #1041#1080#1090#1099' '#1076#1072#1085#1085#1099#1093':'
    end
    object Label5: TLabel
      Left = 8
      Top = 142
      Width = 52
      Height = 13
      Caption = #1063#1105#1090#1085#1086#1089#1090#1100':'
    end
    object Label6: TLabel
      Left = 8
      Top = 176
      Width = 84
      Height = 13
      Caption = #1057#1090#1086#1087#1086#1074#1099#1077' '#1073#1080#1090#1099':'
    end
    object Label7: TLabel
      Left = 8
      Top = 208
      Width = 113
      Height = 13
      Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1087#1086#1090#1086#1082#1086#1084': '
    end
    object Label8: TLabel
      Left = 334
      Top = 76
      Width = 3
      Height = 13
    end
    object Label9: TLabel
      Left = 334
      Top = 106
      Width = 3
      Height = 13
    end
    object Label10: TLabel
      Left = 343
      Top = 48
      Width = 37
      Height = 13
      Caption = 'Label10'
      Transparent = False
    end
    object Label11: TLabel
      Left = 343
      Top = 80
      Width = 37
      Height = 13
      Caption = 'Label11'
      Transparent = False
    end
    object Button2: TButton
      Left = 238
      Top = 76
      Width = 90
      Height = 25
      Caption = #1042#1085#1077#1096#1085#1080#1081' '#1060#1051#1069#1064
      TabOrder = 0
    end
    object Button3: TButton
      Left = 238
      Top = 107
      Width = 90
      Height = 25
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' Xilinx'
      TabOrder = 1
    end
    object Button4: TButton
      Left = 238
      Top = 138
      Width = 90
      Height = 25
      Caption = #1055#1088#1086#1096#1080#1074#1082#1080
      TabOrder = 2
    end
    object br_combo: TComboBox
      Left = 137
      Top = 76
      Width = 80
      Height = 21
      TabOrder = 3
      Items.Strings = (
        '600'
        '1200'
        '2400'
        '4800'
        '9600'
        '14400'
        '19200'
        '38400'
        '57600'
        '115200'
        '256400'
        '512800')
    end
    object db_combo: TComboBox
      Left = 136
      Top = 108
      Width = 81
      Height = 21
      TabOrder = 4
      Items.Strings = (
        '5'
        '6'
        '7'
        '8'
        '9')
    end
    object par_combo: TComboBox
      Left = 137
      Top = 139
      Width = 80
      Height = 21
      TabOrder = 5
      Items.Strings = (
        'None'
        'Odd'
        'Even')
    end
    object sb_combo: TComboBox
      Left = 136
      Top = 173
      Width = 81
      Height = 21
      TabOrder = 6
      Items.Strings = (
        '1'
        '1,5'
        '2')
    end
    object fc_combo: TComboBox
      Left = 137
      Top = 205
      Width = 80
      Height = 21
      TabOrder = 7
      Items.Strings = (
        'None'
        'Xon/Xoff'
        'CTS/RTC')
    end
    object Edit1: TEdit
      Left = 343
      Top = 108
      Width = 37
      Height = 21
      TabOrder = 8
    end
    object Button5: TButton
      Left = 290
      Top = 263
      Width = 90
      Height = 25
      Caption = #1042#1067#1061#1054#1044
      TabOrder = 9
    end
    object comboBox1: TComboBox
      Left = 137
      Top = 49
      Width = 80
      Height = 21
      TabOrder = 10
    end
    object Button13: TButton
      Left = 16
      Top = 263
      Width = 81
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1087#1086#1088#1090
      TabOrder = 11
      OnClick = Button13Click
    end
    object Button14: TButton
      Left = 137
      Top = 263
      Width = 81
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100' '#1087#1086#1088#1090
      TabOrder = 12
      OnClick = Button14Click
    end
    object Button1: TButton
      Left = 238
      Top = 47
      Width = 90
      Height = 25
      Caption = #1052#1086#1085#1080#1090#1086#1088
      TabOrder = 13
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 399
    Top = 0
    Width = 395
    Height = 297
    TabOrder = 1
    object Memo1: TMemo
      Left = 8
      Top = 8
      Width = 377
      Height = 249
      TabOrder = 0
    end
    object Button6: TButton
      Left = 24
      Top = 263
      Width = 75
      Height = 25
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
      TabOrder = 1
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 160
      Top = 263
      Width = 75
      Height = 25
      Caption = 'BIN-'#1092#1086#1088#1084#1072#1090
      TabOrder = 2
    end
    object Button8: TButton
      Left = 288
      Top = 263
      Width = 75
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 3
    end
  end
  object Panel5: TPanel
    Left = 399
    Top = 303
    Width = 395
    Height = 234
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object Label26: TLabel
      Left = 152
      Top = 8
      Width = 77
      Height = 19
      Caption = #1052#1054#1053#1048#1058#1054#1056
    end
    object Label27: TLabel
      Left = 24
      Top = 56
      Width = 94
      Height = 13
      Caption = #1057#1090#1072#1088#1090#1086#1074#1099#1081' '#1072#1076#1088#1077#1089':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label28: TLabel
      Left = 24
      Top = 104
      Width = 88
      Height = 13
      Caption = #1050#1086#1085#1077#1095#1085#1099#1081' '#1072#1076#1088#1077#1089':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit7: TEdit
      Left = 136
      Top = 48
      Width = 150
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object Edit8: TEdit
      Left = 136
      Top = 96
      Width = 150
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object Button9: TButton
      Left = 16
      Top = 144
      Width = 75
      Height = 25
      Caption = #1063#1080#1090#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object Button10: TButton
      Left = 112
      Top = 144
      Width = 75
      Height = 25
      Caption = #1055#1080#1089#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object Button11: TButton
      Left = 208
      Top = 144
      Width = 75
      Height = 25
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object Button12: TButton
      Left = 304
      Top = 143
      Width = 75
      Height = 25
      Caption = #1055#1088#1086#1074'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object ProgressBar1: TProgressBar
      Left = 112
      Top = 200
      Width = 169
      Height = 17
      TabOrder = 6
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 303
    Width = 393
    Height = 234
    TabOrder = 3
    object SpeedButton4: TSpeedButton
      Left = 305
      Top = 180
      Width = 23
      Height = 22
    end
    object Label16: TLabel
      Left = 100
      Top = 184
      Width = 21
      Height = 13
      Caption = 'S/N:'
    end
    object Label17: TLabel
      Left = 8
      Top = 127
      Width = 82
      Height = 13
      Caption = #1060#1072#1081#1083' '#1085#1077' '#1086#1090#1082#1088#1099#1090
    end
    object Label18: TLabel
      Left = 184
      Top = 16
      Width = 63
      Height = 13
      Caption = #1042#1077#1088#1089#1080#1103' '#1055#1050#1048':'
    end
    object Label19: TLabel
      Left = 290
      Top = 16
      Width = 15
      Height = 13
      Caption = '???'
    end
    object Label20: TLabel
      Left = 184
      Top = 35
      Width = 92
      Height = 13
      Caption = #1042#1077#1088#1089#1080#1103' '#1052#1086#1085#1080#1090#1086#1088#1072':'
    end
    object Label21: TLabel
      Left = 290
      Top = 35
      Width = 15
      Height = 13
      Caption = '???'
    end
    object Label22: TLabel
      Left = 184
      Top = 54
      Width = 52
      Height = 13
      Caption = #1042#1077#1088#1089#1080#1103' Xil:'
    end
    object Label23: TLabel
      Left = 290
      Top = 54
      Width = 15
      Height = 13
      Caption = '???'
    end
    object Label24: TLabel
      Left = 184
      Top = 73
      Width = 59
      Height = 13
      Caption = #1053#1072#1088#1072#1073#1086#1090#1082#1072':'
    end
    object Label25: TLabel
      Left = 290
      Top = 73
      Width = 15
      Height = 13
      Caption = '???'
    end
    object Panel4: TPanel
      Left = 8
      Top = 16
      Width = 97
      Height = 105
      TabOrder = 0
      object RadioButton1: TRadioButton
        Left = 8
        Top = 8
        Width = 113
        Height = 17
        Caption = 'FLASH'
        TabOrder = 0
      end
      object RadioButton2: TRadioButton
        Left = 8
        Top = 31
        Width = 113
        Height = 17
        Caption = 'EEPROM'
        TabOrder = 1
      end
      object RadioButton3: TRadioButton
        Left = 8
        Top = 54
        Width = 113
        Height = 17
        Caption = 'Xilinx'
        TabOrder = 2
      end
      object RadioButton4: TRadioButton
        Left = 8
        Top = 77
        Width = 113
        Height = 17
        Caption = 'RAM'
        TabOrder = 3
      end
    end
    object Edit6: TEdit
      Left = 127
      Top = 180
      Width = 150
      Height = 21
      TabOrder = 1
    end
  end
  object MainMenu1: TMainMenu
    Left = 768
    Top = 512
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N3: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = N3Click
      end
    end
    object N2: TMenuItem
      Caption = #1056#1077#1078#1080#1084
      object N4: TMenuItem
        Caption = #1053#1086#1088#1084#1072#1083#1100#1085#1099#1081
        RadioItem = True
      end
      object N5: TMenuItem
        Caption = #1056#1072#1089#1096#1080#1088#1077#1085#1085#1099#1081
        Checked = True
        RadioItem = True
      end
    end
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <
      item
        DisplayName = #1044#1074#1086#1080#1095#1085#1099#1077
        FileMask = '*.bin'
      end
      item
        DisplayName = #1064#1077#1089#1090#1085#1072#1076#1094#1072#1090#1077#1088#1080#1095#1085#1099#1077
        FileMask = '*.hex'
      end
      item
        DisplayName = #1042#1089#1077' '#1090#1080#1087#1099
        FileMask = '*.*'
      end>
    Options = []
    Left = 472
    Top = 552
  end
end
