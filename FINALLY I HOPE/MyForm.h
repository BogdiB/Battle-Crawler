#pragma once
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <windows.h>

namespace FINALLYIHOPE
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}
		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MyForm()
			{
				if (components)
					delete components;
			}
		private:
			short enemyHEALTHPOINTS = 100;
			// class that manages interaction between player and enemy
			ref class entities
			{
				short HP = 100, damage = 7, critChance = 8, maxHeals = 1;
				public:
					entities() {}

					short attack() // returns damage
					{
						srand(time(NULL));
						short r = rand() % 101;
						if (r >= 0 && r <= this->critChance)
							return this->damage + 5;
						else
							return this->damage;
					}

					short heal() // returns HP after heal or -1 which means no heals left
					{
						if (this->maxHeals != 0)
						{
							srand(time(NULL));
							this->HP += 20 + (rand() % 11);
							if (this->HP > 100)
								this->HP = 100;
							--(this->maxHeals);
							return this->HP;
						}
						return -1; // output a "Heal already used!" message
					}

					short takeDamage() // returns HP left
					{
						srand(time(NULL));
						short dmg = (rand() % 7) + 5;
						this->HP -= dmg;
						if (HP < 1)
						{
							this->die();
							return 0;
						}
						else return this->HP;
					}

					void die()
					{
						this->HP = 100;
						this->maxHeals = 1;
					}

					~entities() {}
			}PLAYER;

			System::Windows::Forms::Label^ BattleCrawler;
			System::Windows::Forms::Button^ StartB;
			System::Windows::Forms::Button^ QuitB;

			System::Windows::Forms::Button^ AttackB;
			System::Windows::Forms::Button^ HealB;
			System::Windows::Forms::Button^ EscapeB;

			System::Windows::Forms::Label^ playerHP;
			System::Windows::Forms::Label^ playerTXT;
			System::Windows::Forms::Label^ playerSprite;

			System::Windows::Forms::Label^ enemyHP;
			System::Windows::Forms::Label^ enemyTXT;
			System::Windows::Forms::Label^ enemySprite;

			System::Windows::Forms::Label^ HealUsedText;

			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				this->BattleCrawler = (gcnew System::Windows::Forms::Label());
				this->StartB = (gcnew System::Windows::Forms::Button());
				this->QuitB = (gcnew System::Windows::Forms::Button());
				this->AttackB = (gcnew System::Windows::Forms::Button());
				this->HealB = (gcnew System::Windows::Forms::Button());
				this->EscapeB = (gcnew System::Windows::Forms::Button());
				this->playerHP = (gcnew System::Windows::Forms::Label());
				this->playerTXT = (gcnew System::Windows::Forms::Label());
				this->playerSprite = (gcnew System::Windows::Forms::Label());
				this->enemyHP = (gcnew System::Windows::Forms::Label());
				this->enemyTXT = (gcnew System::Windows::Forms::Label());
				this->enemySprite = (gcnew System::Windows::Forms::Label());
				this->HealUsedText = (gcnew System::Windows::Forms::Label());
				this->SuspendLayout();
				// 
				// BattleCrawler
				// 
				resources->ApplyResources(this->BattleCrawler, L"BattleCrawler");
				this->BattleCrawler->BackColor = System::Drawing::Color::Transparent;
				this->BattleCrawler->ForeColor = System::Drawing::SystemColors::Control;
				this->BattleCrawler->Name = L"BattleCrawler";
				// 
				// StartB
				// 
				this->StartB->Cursor = System::Windows::Forms::Cursors::Hand;
				resources->ApplyResources(this->StartB, L"StartB");
				this->StartB->Name = L"StartB";
				this->StartB->UseVisualStyleBackColor = true;
				this->StartB->Click += gcnew System::EventHandler(this, &MyForm::StartB_Click);
				// 
				// QuitB
				// 
				resources->ApplyResources(this->QuitB, L"QuitB");
				this->QuitB->Name = L"QuitB";
				this->QuitB->UseVisualStyleBackColor = true;
				this->QuitB->Click += gcnew System::EventHandler(this, &MyForm::QuitB_Click);
				// 
				// AttackB
				// 
				this->AttackB->BackColor = System::Drawing::Color::DarkGray;
				this->AttackB->Cursor = System::Windows::Forms::Cursors::Hand;
				resources->ApplyResources(this->AttackB, L"AttackB");
				this->AttackB->Name = L"AttackB";
				this->AttackB->UseVisualStyleBackColor = false;
				this->AttackB->Click += gcnew System::EventHandler(this, &MyForm::AttackB_Click);
				// 
				// HealB
				// 
				this->HealB->BackColor = System::Drawing::Color::DarkGray;
				this->HealB->Cursor = System::Windows::Forms::Cursors::Hand;
				resources->ApplyResources(this->HealB, L"HealB");
				this->HealB->Name = L"HealB";
				this->HealB->UseVisualStyleBackColor = false;
				this->HealB->Click += gcnew System::EventHandler(this, &MyForm::HealB_Click);
				// 
				// EscapeB
				// 
				this->EscapeB->BackColor = System::Drawing::Color::DarkGray;
				this->EscapeB->Cursor = System::Windows::Forms::Cursors::Hand;
				resources->ApplyResources(this->EscapeB, L"EscapeB");
				this->EscapeB->Name = L"EscapeB";
				this->EscapeB->UseVisualStyleBackColor = false;
				this->EscapeB->Click += gcnew System::EventHandler(this, &MyForm::EscapeB_Click);
				// 
				// playerHP
				// 
				this->playerHP->BackColor = System::Drawing::Color::DarkGray;
				this->playerHP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				resources->ApplyResources(this->playerHP, L"playerHP");
				this->playerHP->Name = L"playerHP";
				// 
				// playerTXT
				// 
				resources->ApplyResources(this->playerTXT, L"playerTXT");
				this->playerTXT->BackColor = System::Drawing::Color::DarkGray;
				this->playerTXT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->playerTXT->Name = L"playerTXT";
				// 
				// playerSprite
				// 
				this->playerSprite->BackColor = System::Drawing::Color::Transparent;
				resources->ApplyResources(this->playerSprite, L"playerSprite");
				this->playerSprite->ForeColor = System::Drawing::Color::Transparent;
				this->playerSprite->Name = L"playerSprite";
				// 
				// enemyHP
				// 
				this->enemyHP->BackColor = System::Drawing::Color::DarkGray;
				this->enemyHP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				resources->ApplyResources(this->enemyHP, L"enemyHP");
				this->enemyHP->Name = L"enemyHP";
				// 
				// enemyTXT
				// 
				resources->ApplyResources(this->enemyTXT, L"enemyTXT");
				this->enemyTXT->BackColor = System::Drawing::Color::DarkGray;
				this->enemyTXT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->enemyTXT->Name = L"enemyTXT";
				// 
				// enemySprite
				// 
				this->enemySprite->BackColor = System::Drawing::Color::Transparent;
				resources->ApplyResources(this->enemySprite, L"enemySprite");
				this->enemySprite->Name = L"enemySprite";
				// 
				// HealUsedText
				// 
				resources->ApplyResources(this->HealUsedText, L"HealUsedText");
				this->HealUsedText->BackColor = System::Drawing::Color::Transparent;
				this->HealUsedText->ForeColor = System::Drawing::Color::Red;
				this->HealUsedText->Name = L"HealUsedText";
				// 
				// MyForm
				// 
				resources->ApplyResources(this, L"$this");
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->Controls->Add(this->BattleCrawler);
				this->Controls->Add(this->StartB);
				this->Controls->Add(this->QuitB);
				this->Controls->Add(this->AttackB);
				this->Controls->Add(this->HealB);
				this->Controls->Add(this->EscapeB);
				this->Controls->Add(this->playerHP);
				this->Controls->Add(this->playerTXT);
				this->Controls->Add(this->playerSprite);
				this->Controls->Add(this->enemyHP);
				this->Controls->Add(this->enemyTXT);
				this->Controls->Add(this->enemySprite);
				this->Controls->Add(this->HealUsedText);
				this->Name = L"MyForm";
				this->ShowIcon = false;
				this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
			System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
			{
			}
			System::Void StartB_Click(System::Object^ sender, System::EventArgs^ e)
			{
				BattleCrawler->Visible = false;
				StartB->Visible = false;
				QuitB->Visible = false;

				playerHP->Visible = true;
				playerTXT->Visible = true;
				playerSprite->Visible = true;

				enemyHP->Visible = true;
				enemyTXT->Visible = true;
				enemySprite->Visible = true;

				AttackB->Visible = true;
				HealB->Visible = true;
				EscapeB->Visible = true;
			}
			System::Void QuitB_Click(System::Object^ sender, System::EventArgs^ e)
			{
			}
			System::Void AttackB_Click(System::Object^ sender, System::EventArgs^ e)
			{
				Sleep(300);
				enemyHEALTHPOINTS -= PLAYER.attack();
				if (enemyHEALTHPOINTS < 1)
				{
					enemyHP->Text = "0/100";
					enemyHEALTHPOINTS = 100;

					// you won

					BattleCrawler->Visible = true;
					StartB->Visible = true;
					QuitB->Visible = true;

					playerHP->Visible = false;
					playerTXT->Visible = false;
					playerSprite->Visible = false;

					enemyHP->Visible = false;
					enemyTXT->Visible = false;
					enemySprite->Visible = false;

					AttackB->Visible = false;
					HealB->Visible = false;
					EscapeB->Visible = false;

					HealUsedText->Visible = false;
				}
				else
				{
					char outputTXT = System::Convert::ToChar(enemyHEALTHPOINTS);
					enemyHP->Text = System::Convert::ToString(outputTXT) + "/100";

					short HP = PLAYER.takeDamage();
					if (HP < 1)
					{
						playerHP->Text = "0/100";
						enemyHEALTHPOINTS = 100;

						// you lost

						BattleCrawler->Visible = true;
						StartB->Visible = true;
						QuitB->Visible = true;

						playerHP->Visible = false;
						playerTXT->Visible = false;
						playerSprite->Visible = false;

						enemyHP->Visible = false;
						enemyTXT->Visible = false;
						enemySprite->Visible = false;

						AttackB->Visible = false;
						HealB->Visible = false;
						EscapeB->Visible = false;

						HealUsedText->Visible = false;
					}
					else
					{
						outputTXT = System::Convert::ToChar(HP);
						playerHP->Text = System::Convert::ToString(outputTXT) + "/100";
					}
				}
			}
			System::Void HealB_Click(System::Object^ sender, System::EventArgs^ e)
			{
				Sleep(300);
				short HP = PLAYER.heal();
				if (HP == -1) // if -1 then heal already used
					HealUsedText->Visible = true;
				else
				{
					char outputTXT = System::Convert::ToChar(HP);
					playerHP->Text = System::Convert::ToString(outputTXT) + "/100";

					HP = PLAYER.takeDamage();
					if (HP < 1)
					{
						playerHP->Text = "0/100";
						enemyHEALTHPOINTS = 100;

						// you lost

						BattleCrawler->Visible = true;
						StartB->Visible = true;
						QuitB->Visible = true;

						playerHP->Visible = false;
						playerTXT->Visible = false;
						playerSprite->Visible = false;

						enemyHP->Visible = false;
						enemyTXT->Visible = false;
						enemySprite->Visible = false;

						AttackB->Visible = false;
						HealB->Visible = false;
						EscapeB->Visible = false;

						HealUsedText->Visible = false;

						enemyHEALTHPOINTS = 100;
					}
					else
					{
						outputTXT = System::Convert::ToChar(HP);
						playerHP->Text = System::Convert::ToString(outputTXT) + "/100";
					}
				}
			}
			System::Void EscapeB_Click(System::Object^ sender, System::EventArgs^ e)
			{
				Sleep(300);
				PLAYER.die(); // resets HP and heal counter, also should count as loss when "escaping"
				enemyHEALTHPOINTS = 100;
				playerHP->Text = "100/100";
				enemyHP->Text = "100/100";

				BattleCrawler->Visible = true;
				StartB->Visible = true;
				QuitB->Visible = true;

				playerHP->Visible = false;
				playerTXT->Visible = false;
				playerSprite->Visible = false;

				enemyHP->Visible = false;
				enemyTXT->Visible = false;
				enemySprite->Visible = false;

				AttackB->Visible = false;
				HealB->Visible = false;
				EscapeB->Visible = false;

				HealUsedText->Visible = false;

				enemyHEALTHPOINTS = 100;
			}
	};
};
