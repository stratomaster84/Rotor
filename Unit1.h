//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <math.h>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPaintBox *PaintBox1;
        TScrollBar *ScrollBar1;
        TLabel *Label1;
        TLabel *Label2;
        TScrollBar *ScrollBar2;
        TLabel *Label3;
        TScrollBar *ScrollBar3;
        TRadioGroup *RadioGroup1;
        TEdit *Edit1;
        TRadioGroup *RadioGroup2;
        TScrollBar *ScrollBar4;
        TLabel *Label4;
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ScrollBar2Change(TObject *Sender);
        void __fastcall ScrollBar3Change(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall ScrollBar4Change(TObject *Sender);
private:	// User declarations
public:
        double _FI;
        double _Rval;
        double _Rtrengle;
        int _OblastX;
        int _OblastY;
        TPoint *_func;
        TPoint *_rotfunc;
        int _statprec;
        int _rotprec;
        bool _creation;
        Graphics::TBitmap *_Image;
		// User declarations

        __fastcall TForm1(TComponent* Owner);
        TPoint _Vector(double fi);
        void _GraphRepaint();
        void _StatorRepaint();
        void _StatorCount();
        void _RotorRepaint();
        void _ValRepaint();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 