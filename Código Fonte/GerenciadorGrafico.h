#pragma once
#include <iostream>
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Objects.hpp>
#include <string>

class GerenciadorGrafico {
private:
	TCanvas* canvas;
	static GerenciadorGrafico* pGrafico;
	GerenciadorGrafico();

public:
	~GerenciadorGrafico();
	TCanvas* getCanvas() {return canvas;};
	static GerenciadorGrafico* getGerenciadorGrafico();
    void limpaJanela();
	void desenhaElemento(TImage* corpo);
	TPointF getCoorView();
	void setView(TPointF p);


};