object MainForm: TMainForm
  Left = 0
  Top = 0
  Anchors = []
  Caption = #1057#1055#1054' v1'
  ClientHeight = 589
  ClientWidth = 1135
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  DesignSize = (
    1135
    589)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 104
    Top = 441
    Width = 3
    Height = 13
    Anchors = [akLeft, akBottom]
  end
  object Button1: TButton
    AlignWithMargins = True
    Left = 11
    Top = 459
    Width = 75
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1063#1090#1077#1085#1080#1077
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 984
    Top = 741
    Width = 361
    Height = 113
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    Visible = False
  end
  object Memo2: TMemo
    Left = 968
    Top = 741
    Width = 401
    Height = 113
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
    Visible = False
  end
  object Grid1: TStringGrid
    AlignWithMargins = True
    Left = 8
    Top = 8
    Width = 305
    Height = 409
    Anchors = [akLeft, akTop, akBottom]
    ColCount = 2
    Ctl3D = False
    DefaultColWidth = 140
    FixedColor = clMenu
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goThumbTracking]
    ParentCtl3D = False
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object Chart: TChart
    AlignWithMargins = True
    Left = 328
    Top = 8
    Width = 793
    Height = 427
    Border.Style = psInsideFrame
    Border.Visible = True
    Legend.CheckBoxesStyle = cbsRadio
    Legend.LegendStyle = lsSeries
    Legend.Visible = False
    MarginUnits = muPixels
    Title.AdjustFrame = False
    Title.Alignment = taLeftJustify
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082
      '')
    Title.Visible = False
    View3D = False
    Zoom.Animated = True
    Zoom.AnimatedSteps = 12
    Zoom.Pen.Color = clBlack
    Zoom.Pen.Width = 2
    BevelOuter = bvNone
    BevelWidth = 2
    Color = clWhite
    TabOrder = 4
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColorPaletteIndex = 4
    object Series1: TLineSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      SeriesColor = clRed
      Brush.BackColor = clDefault
      LinePen.Width = 2
      LinePen.EndStyle = esSquare
      Pointer.Brush.Gradient.EndColor = clRed
      Pointer.Gradient.EndColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object ProgressBar1: TProgressBar
    AlignWithMargins = True
    Left = 104
    Top = 459
    Width = 1026
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Max = 256
    Step = 1
    TabOrder = 5
  end
  object Console: TMemo
    Left = 8
    Top = 492
    Width = 1122
    Height = 89
    Anchors = [akLeft, akRight, akBottom]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Lucida Console'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 6
  end
  object MainMenu1: TMainMenu
    Left = 48
    Top = 672
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N6: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = N6Click
      end
      object N2: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1042#1099#1081#1090#1080
        OnClick = N3Click
      end
    end
    object N4: TMenuItem
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      object COM1: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' COM'
        OnClick = COM1Click
      end
    end
    object Cghfdrf1: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N5: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
      end
    end
  end
  object Save: TSaveTextFileDialog
    Filter = '*.tx1|.tx1'
    Top = 560
  end
  object Open: TOpenTextFileDialog
    Filter = '.tx1|*.tx1'
    Left = 88
    Top = 560
  end
end
