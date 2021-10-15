//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define STATORPREC        100
#define ROTORPREC         30
#define DELTA             3
#define DEFBAR1MAX        1001
int     DEFBAR3DIV      = 100;
#define DEFBAR3MAXDIV     100
#define DEFBAR4MIN        1
#define DEFBAR4MAX        60


TColor  GRAPHFORECOLOR  = clBlack;
TColor  GRAPHBACKCOLOR  = clWhite;
TColor  STATORFORECOLOR = clRed;
TColor  STATORBACKCOLOR = clGreen;
TColor  ROTORFORECOLOR  = clBlack;
TColor  ROTORBACKCOLOR  = clRed;
TColor  VALFORECOLOR    = clBlack;
TColor  VALBACKCOLOR    = clWhite;
int     PNTWIDTH        = 2;

#define _LN4             1.38629436111989
#define _2PI             6.28318530717959
#define _2PI3            2.09439510239319
#define _SQ3_2           0.86602540378444

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


TPoint TForm1::_Vector(double fi)
{
        TPoint _tmp;

        _tmp.x = _OblastX + _Rval*sin(3*fi)+_Rtrengle*sin(fi);
        _tmp.y = _OblastY - _Rval*cos(3*fi)-_Rtrengle*cos(fi);
        return _tmp;

}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
        _GraphRepaint();
        _StatorRepaint();
        _RotorRepaint();
        _ValRepaint();
        PaintBox1->Canvas->Draw(0,0,_Image);
}
//---------------------------------------------------------------------------


void TForm1::_GraphRepaint()
{
        _Image->Canvas->Brush->Color = GRAPHBACKCOLOR;
        _Image->Canvas->Pen->Color = GRAPHFORECOLOR;
        _Image->Canvas->Rectangle(0,0,_Image->Width,_Image->Height);
        TPoint _tmp;
        _tmp.x = 0;
        _tmp.y = _OblastY;
        _Image->Canvas->PenPos = _tmp;
        _Image->Canvas->LineTo(_Image->Width,_OblastY);
        _tmp.x = _OblastX;
        _tmp.y = 0;
        _Image->Canvas->PenPos = _tmp;
        _Image->Canvas->LineTo(_OblastX,_Image->Height);
}




void TForm1::_StatorRepaint()
{
        _Image->Canvas->Pen->Color = STATORFORECOLOR;
        _Image->Canvas->Brush->Color = STATORBACKCOLOR;

        if(RadioGroup1->ItemIndex == 0)
                _Image->Canvas->Polygon(_func,_statprec-1);
        else{
                _Image->Canvas->PenPos = _func[0];
                for(int i=1;i<_statprec;i++)
                        _Image->Canvas->LineTo(_func[i].x,_func[i].y);
                _Image->Canvas->LineTo(_func[0].x,_func[0].y);
        }

}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        _creation = true;

        _OblastX = PaintBox1->Width/2;
        _OblastY = PaintBox1->Height/2;
        if(_OblastX!=_OblastY)
                _OblastX = _OblastY = _OblastX>_OblastY?_OblastY:_OblastX;
        _Image = new Graphics::TBitmap;
        _Image->Width  = _OblastX*2;
        _Image->Height = _OblastY*2;

        _statprec = STATORPREC;
        _rotprec = ROTORPREC;
        _func = new TPoint[_statprec];
        _rotfunc = new TPoint[3*_rotprec];

        _FI = 0;

        ScrollBar1->Max = DEFBAR1MAX;
        ScrollBar2->Max = _OblastY - DELTA;
        ScrollBar3->Max = DEFBAR3DIV*log(DEFBAR3MAXDIV);
        ScrollBar3->Min = DEFBAR3DIV*_LN4;
        ScrollBar4->Max = DEFBAR4MAX;
        ScrollBar4->Min = DEFBAR4MIN;

        ScrollBar1->Position = 1;
        ScrollBar2->Position = ScrollBar2->Max;
        ScrollBar3->Position = ScrollBar3->Max;
        ScrollBar4->Position = ScrollBar4->Min;


        _Rval = (double)ScrollBar2->Position/(1+exp((double)ScrollBar3->Position/DEFBAR3DIV));
        _Rtrengle = (double)ScrollBar2->Position/(1+exp(-(double)ScrollBar3->Position/DEFBAR3DIV));

        _StatorCount();
        _creation = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        delete [] _func;
        delete [] _rotfunc;
        delete _Image;
}
//---------------------------------------------------------------------------


void TForm1::_StatorCount()
{

        double _shag = _2PI/_statprec;
        double _x = 0;
        for(int i = 0;i<_statprec;i++){
                _func[i] = _Vector(_x);
                _x +=_shag;
        }
}


void TForm1::_RotorRepaint()
{
        TPoint _tmp [3];
        int i;
        for(i=0;i<3;i++)
                _tmp[i] = _Vector(_FI + (i-1)*_2PI3);

        _Image->Canvas->Brush->Color = ROTORBACKCOLOR;
        _Image->Canvas->Pen->Color = ROTORFORECOLOR;


        if(RadioGroup2->ItemIndex == 0)
                _Image->Canvas->Polygon(_tmp,2);

        else {
                double _rotdepth = (int)(_Rtrengle*_SQ3_2*(1/sin((double)ScrollBar4->Position/360*_2PI)-tan((double)(90-ScrollBar4->Position)/360*_2PI)));

                double _diam=(double)_rotprec/sin((double)ScrollBar4->Position/360*_2PI);
                double _param = (double)_rotprec/2*tan((double)(90-ScrollBar4->Position)/360*_2PI);

                double _tan1 = atan2(-(double)(_tmp[1].x-_tmp[0].x),(double)(_tmp[1].y-_tmp[0].y));
                double _tan2 = atan2(-(double)(_tmp[2].x-_tmp[1].x),(double)(_tmp[2].y-_tmp[1].y));
                double _tan3 = atan2(-(double)(_tmp[0].x-_tmp[2].x),(double)(_tmp[0].y-_tmp[2].y));

                for(i=0;i<_rotprec;i++){
                        double _h;
                        if(RadioGroup2->ItemIndex == 1)
                                _h = (4*(double)i/(double)_rotprec*(1 - (double)i/(double)_rotprec))*_rotdepth ;
                        else
                                _h = (sqrt((_diam-2*i+_rotprec)*(_diam+2*i-_rotprec))/2-_param)*_rotdepth/(_diam/2-_param);

                        _rotfunc[i].x=_tmp[0].x+(double)(_tmp[1].x-_tmp[0].x)/_rotprec*i + _h*cos(_tan1);
                        _rotfunc[i].y=_tmp[0].y+(double)(_tmp[1].y-_tmp[0].y)/_rotprec*i + _h*sin(_tan1);

                        _rotfunc[i+_rotprec].x=_tmp[1].x+(double)(_tmp[2].x-_tmp[1].x)/_rotprec*i + _h*cos(_tan2);
                        _rotfunc[i+_rotprec].y=_tmp[1].y+(double)(_tmp[2].y-_tmp[1].y)/_rotprec*i + _h*sin(_tan2);

                        _rotfunc[i+2*_rotprec].x=_tmp[2].x+(double)(_tmp[0].x-_tmp[2].x)/_rotprec*i + _h*cos(_tan3);
                        _rotfunc[i+2*_rotprec].y=_tmp[2].y+(double)(_tmp[0].y-_tmp[2].y)/_rotprec*i + _h*sin(_tan3);
                }

                _Image->Canvas->Polygon(_rotfunc,3*_rotprec-1);
        }
}


void TForm1::_ValRepaint()
{
        _Image->Canvas->Brush->Color = VALBACKCOLOR;
        _Image->Canvas->Pen->Color = VALFORECOLOR;

        _Image->Canvas->Ellipse(_OblastX-_Rval,_OblastY-_Rval,
                                _OblastX+_Rval,_OblastY+_Rval);

        TPoint _p;
        _p.x = _OblastX + _Rval*sin(3*_FI);
        _p.y = _OblastY - _Rval*cos(3*_FI);

        _Image->Canvas->Brush->Color = VALFORECOLOR;
        _Image->Canvas->Ellipse(_p.x-PNTWIDTH,_p.y-PNTWIDTH,
                        _p.x+PNTWIDTH,_p.y+PNTWIDTH);
}
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
        if(_creation)
                return;
        if(ScrollBar1->Position == ScrollBar1->Max)
                ScrollBar1->Position = 1;
        if(ScrollBar1->Position == 0)
                ScrollBar1->Position = ScrollBar1->Max-1;

        _FI = _2PI*(double)(ScrollBar1->Position-1)/(double)(ScrollBar1->Max-2);

        Edit1->Text = IntToStr((int)(_FI/_2PI*360));
        _GraphRepaint();
        _StatorRepaint();
        _RotorRepaint();
        _ValRepaint();
        PaintBox1->Canvas->Draw(0,0,_Image);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBar2Change(TObject *Sender)
{
        if(_creation)
                return;
        _Rval = (double)ScrollBar2->Position/(1+exp((double)ScrollBar3->Position/DEFBAR3DIV));
        _Rtrengle = (double)ScrollBar2->Position/(1+exp(-(double)ScrollBar3->Position/DEFBAR3DIV));
        _StatorCount();
        _GraphRepaint();
        _StatorRepaint();
        _RotorRepaint();
        _ValRepaint();
        PaintBox1->Canvas->Draw(0,0,_Image);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBar3Change(TObject *Sender)
{
        if(_creation)
                return;
        _Rval = (double)ScrollBar2->Position/(1+exp((double)ScrollBar3->Position/DEFBAR3DIV));
        _Rtrengle = (double)ScrollBar2->Position/(1+exp(-(double)ScrollBar3->Position/DEFBAR3DIV));
        _StatorCount();
        _GraphRepaint();
        _StatorRepaint();
        _RotorRepaint();
        _ValRepaint();
        PaintBox1->Canvas->Draw(0,0,_Image);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
        _GraphRepaint();
        _StatorRepaint();
        _RotorRepaint();
        _ValRepaint();
        PaintBox1->Canvas->Draw(0,0,_Image);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
        _GraphRepaint();
        _StatorRepaint();
        _RotorRepaint();
        _ValRepaint();
        PaintBox1->Canvas->Draw(0,0,_Image);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBar4Change(TObject *Sender)
{
        _GraphRepaint();
        _StatorRepaint();
        _RotorRepaint();
        _ValRepaint();
        PaintBox1->Canvas->Draw(0,0,_Image);

}
//---------------------------------------------------------------------------

