#pragma once
#include"Controlador.h" 
#include "Archivo.h"
#include"WIN2.h"
#include "LOSE.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Nivel2
	/// </summary>
	public ref class Nivel2 : public System::Windows::Forms::Form
	{
	private:
		//Protagonista
		Abogado* prota;
		Bitmap^ bmprota;
		Bitmap^ bmcuchillo;
		Bitmap^ bmBarraDeVida;
		//Enemigos
		Bitmap^ bmRobot;
		Bitmap^ bmSoldado;
		Bitmap^ bmCivil;
		Bitmap^ bmAveEO;
		Bitmap^ bmAveOE;
		Bitmap^ bmpMap;
		//Aliado
		Bitmap^ bmpAliado1;
		Bitmap^ bmpAliado2;
		//Arbol
		Bitmap^ bmArbol;
		//Ost
		SoundPlayer^ Nivel2Ost;
		//Archivo
		Archivo* archivo;
		//Extras
		int tp;
		int pausa;
		bool nalaTrajoSemillasYVidas;
		bool nalaAtacoALosEnemigos;
		//Buffer variables
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		//Controlador
		Controlador* controlador;
		//Comentario
		Bitmap^ bmComentario;

	private: System::Windows::Forms::Timer^ TiempoJuego;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblarbolesadultos;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label11;

	public:
		Nivel2(void)
		{
			InitializeComponent();
			archivo = new Archivo();
			tp = archivo->getTiempoN2();
			pausa = 0;
			nalaTrajoSemillasYVidas = 0;
			nalaAtacoALosEnemigos = 0;
			//protagonista
			bmprota = gcnew Bitmap("sprites/leorio.png");
			bmcuchillo = gcnew Bitmap("sprites/cuchillo.png");
			bmBarraDeVida = gcnew Bitmap("sprites/LeorioVidaCompleta.png");
			bmComentario = gcnew Bitmap("sprites/bubbles.png");
			//Enemigos
			bmRobot = gcnew Bitmap("sprites/robots1.png");
			bmRobot->MakeTransparent(bmRobot->GetPixel(0, 0));
			bmSoldado = gcnew Bitmap("sprites/soldado.png");
			bmSoldado->MakeTransparent(bmSoldado->GetPixel(0, 0));
			bmCivil = gcnew Bitmap("sprites/civil1.png");
			bmAveEO = gcnew Bitmap("sprites/ave2.png");
			bmAveOE = gcnew Bitmap("sprites/ave.png");
			//Aliados
			bmpAliado1 = gcnew Bitmap("sprites/perro.png");
			bmpAliado2 = gcnew Bitmap("sprites/perro2.0.png");
			//Arbol
			bmArbol = gcnew Bitmap("sprites/arbol.png");
			//fondo
			bmpMap = gcnew Bitmap("sprites/fondo_2.png");
			controlador = new Controlador(bmprota, bmcuchillo, bmpAliado1, bmpAliado2, bmRobot, bmSoldado, bmCivil, bmBarraDeVida, bmAveEO, bmAveOE, bmComentario);
			//SoundPlayer
			Nivel2Ost = gcnew SoundPlayer("ost/CancionNivel2.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Nivel2()
		{
			if (components)
			{
				delete components;
			}
			//Protagonista
			delete prota;
			delete bmprota;
			delete bmcuchillo;
			delete bmBarraDeVida;
			//Enemigos
			delete bmRobot;
			delete bmSoldado;
			delete bmCivil;
			delete bmAveEO;
			delete bmAveOE;
			delete bmpMap;
			//Aliado
			delete bmpAliado1;
			delete bmpAliado2;
			//Arbol
			delete bmArbol;
			//Ost
			delete Nivel2Ost;
			//Archivo
			delete archivo;
			//Buffer variables
			delete g;
			delete space;
			delete buffer;
			//Controlador
			delete controlador;
			//Comentario
			delete bmComentario;
		}

	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Nivel2::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->TiempoJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblarbolesadultos = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2::timer1_Tick);
			// 
			// TiempoJuego
			// 
			this->TiempoJuego->Enabled = true;
			this->TiempoJuego->Interval = 1000;
			this->TiempoJuego->Tick += gcnew System::EventHandler(this, &Nivel2::TiempoJuego_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(416, 147);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(539, 243);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(-5, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1184, 586);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(1165, -2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(253, 583);
			this->pictureBox2->TabIndex = 11;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Nivel2::pictureBox2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(1200, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 16);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Tiempo Restante:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(1201, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 16);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Semillas:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 21);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(138, 15);
			this->label6->TabIndex = 0;
			this->label6->Text = L"T - Plantar Arboles";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(148, 15);
			this->label7->TabIndex = 1;
			this->label7->Text = L"K - Arrojar Navajas";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 79);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(184, 15);
			this->label8->TabIndex = 2;
			this->label8->Text = L"O - Nala (vidas y semillas)";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 105);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(186, 15);
			this->label9->TabIndex = 3;
			this->label9->Text = L"L - Nala (liquida enemigos)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 132);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(123, 15);
			this->label10->TabIndex = 4;
			this->label10->Text = L"P - Pausar Juego";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Minecraft", 10));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox1->Location = System::Drawing::Point(1194, 240);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(194, 148);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Comandos Especiales";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Location = System::Drawing::Point(1350, 111);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(16, 16);
			this->label5->TabIndex = 17;
			this->label5->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(1279, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 16);
			this->label3->TabIndex = 16;
			this->label3->Text = L"0";
			// 
			// lblarbolesadultos
			// 
			this->lblarbolesadultos->AutoSize = true;
			this->lblarbolesadultos->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblarbolesadultos->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->lblarbolesadultos->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblarbolesadultos->Location = System::Drawing::Point(1334, 186);
			this->lblarbolesadultos->Name = L"lblarbolesadultos";
			this->lblarbolesadultos->Size = System::Drawing::Size(16, 16);
			this->lblarbolesadultos->TabIndex = 13;
			this->lblarbolesadultos->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(1200, 186);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 16);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Arboles adultos:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Font = (gcnew System::Drawing::Font(L"Minecraft", 15));
			this->label11->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label11->Location = System::Drawing::Point(1207, 61);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(82, 20);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Stage 2";
			// 
			// Nivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1417, 576);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblarbolesadultos);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1433, 615);
			this->MinimumSize = System::Drawing::Size(1433, 615);
			this->Name = L"Nivel2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RE-FOREST: CATACLYSM";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Nivel2::Nivel2_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Nivel2::Nivel2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		g = panel1->CreateGraphics();
		space = BufferedGraphicsManager::Current;
		buffer = space->Allocate(g, panel1->ClientRectangle);

		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Colision
		if (controlador->getAbogado()->getHp() <= 0) {
			this->Close();
		}
		controlador->Colision(buffer);
		//mover
		controlador->MoverTodo(buffer, bmprota, bmcuchillo, bmpAliado1, bmpAliado2, bmRobot, bmSoldado, bmCivil, bmBarraDeVida, bmAveEO, bmAveOE, bmArbol, bmComentario);
		//dibujar
		lblarbolesadultos->Text = Convert::ToString(controlador->getCantidadArbolesCrecCompleto());
		label3->Text = Convert::ToString(controlador->getAbogado()->getSemillas());
		label5->Text = Convert::ToString(tp);
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		controlador->DibujarTodo(buffer, bmprota, bmcuchillo, bmpAliado1, bmpAliado2, bmRobot, bmSoldado, bmCivil, bmBarraDeVida, bmAveEO, bmAveOE, bmArbol, bmComentario);
		controlador->Spawn(bmRobot, bmSoldado, bmCivil);
		
		if (controlador->getCantidadArbolesCrecCompleto() >= 10)
		{
			timer1->Stop();
			TiempoJuego->Enabled = false;
			Win2^ win = gcnew Win2();
			this->Hide();
			Nivel2Ost->Stop();
			win->ShowDialog();
			this->Close();
			delete win;

		}
		if (tp <= 0 || controlador->getAbogado()->getHp() <= 0) {
			timer1->Stop();
			TiempoJuego->Enabled = false;
			Lose^ lose = gcnew Lose();
			this->Hide();
			Nivel2Ost->Stop();
			lose->ShowDialog();
			this->Close();
			delete lose;
		}
		
		buffer->Render(g);

		delete g;
		delete space;
		delete buffer;
	}
	private: System::Void Nivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left: case Keys::A:
			if (pausa != 1) {
				controlador->getAbogado()->direccion = Direcciones::Izquierda;
			}
			break;
		case Keys::Right: case Keys::D:
			if (pausa != 1) {
				controlador->getAbogado()->direccion = Direcciones::Derecha;
			}
			break;
		case Keys::K:
			if (pausa != 1) {
				if (controlador->getAbogado()->ultimaTecla == Direcciones::Derecha)
				{
					controlador->getAbogado()->direccion = Direcciones::AtaqueDerecha;
					controlador->AgregarCuchillo(bmcuchillo, 0);
				}
				else if (controlador->getAbogado()->ultimaTecla == Direcciones::Izquierda)
				{
					controlador->getAbogado()->direccion = Direcciones::AtaqueIzquierda;
					controlador->AgregarCuchillo(bmcuchillo, 1);
				}
			}
			break;

		case Keys::O:
			if (pausa != 1) {
				if (nalaTrajoSemillasYVidas == 0)
				{
					controlador->getAliado1()->setEsVisible(true);
					controlador->getAliado1()->direccion = Lo_que_hace::Se_va;
					nalaTrajoSemillasYVidas = 1;
				}
			}
			break;

		case Keys::L:
			if (pausa != 1) {
				if (nalaAtacoALosEnemigos == 0)
				{
					controlador->getAliado2()->setEsVisible(true);
					controlador->getAliado2()->direccion = Lo_que_hace::Al_Ataque;
					nalaAtacoALosEnemigos = 1;
				}
			}
			break;

		case Keys::T:
			if (pausa != 1) {
				if (controlador->getAbogado()->getSemillas() > 0) {
					controlador->getAbogado()->GastarSemillas();
					controlador->AgregarArboles(bmArbol);
				}
			}
			break;

		case Keys::P:
			pausa++;
			this->timer1->Enabled = false;
			this->TiempoJuego->Enabled = false;

			if (pausa == 1) {
				pictureBox1->Enabled = true;
				pictureBox1->Visible = true;
			}
			else if (pausa >= 2) {
				pictureBox1->Visible = false;
				this->timer1->Enabled = true;
				this->TiempoJuego->Enabled = true;
				pausa = 0;
			}
			break;

		case Keys::Escape:
			exit(0);
			break;
		}
		
	}
	private: System::Void Nivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left: case Keys::A:
			controlador->getAbogado()->direccion = Direcciones::Ninguna;
			break;
		case Keys::Right: case Keys::D:
			controlador->getAbogado()->direccion = Direcciones::Ninguna;
			break;
		}
	}
	private: System::Void Nivel2_Load(System::Object^ sender, System::EventArgs^ e) {
		Nivel2Ost->PlayLooping();
		this->timer1->Enabled = false;
		this->TiempoJuego->Enabled = false;
		MessageBox::Show("El objetivo del nivel 2 es plantar 10 arboles, ten cuidado con los enemigos que vendran ahora de ambos lados!", "Para el querido jugador:", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		this->timer1->Enabled = true;
		this->TiempoJuego->Enabled = true;

		controlador->setNivel(2);
	}
	private: System::Void Nivel2_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Nivel2Ost->Stop();
	}

private: System::Void TiempoJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
	tp--;
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
