#pragma once
#include "iostream"
#include <string>
#include <Windows.h>



class Card
{
private:
	enum Elements
	{
		air,
		fire,
		ground,
		water,
		light,
		dark
	};

	enum Race
	{
		human,
		elf,
		orc,
		goblin,
		angel,
		gnoll,
		inferno,
		undead
	};

	enum ConsoleColor
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};
	
	struct Character {
		const int general;						//����������� ��������������
		int local;								//� ���������� �����������

		Character();
		~Character();
		Character(const int general, int local);

		Character& operator=( Character character);
		bool& operator==(Character character);
		bool& operator>(Character character);
		bool& operator<(Character character);
		bool& operator>=(Character character);
		bool& operator<=(Character character);
	};

	std::string Name;						//���
	const int ID;							//ID �����

	Character lvl;							//�������
	Character Rhand;						//���� ������ �����
	Character Lhand;						//���� ����� �����
	Character HP;							//���������� �����
	Character Armor;						//�����
	Character Speed;						//��������

	Race race;								//����
	Elements elements;						//������
	std::string Description;				//��������


public:

	Card();
	Card(std::string Name, const int ID, Character lvl, Character Rhand, Character Lhand, Character HP, Character Armor, Character Speed, Race race, Elements elements, std::string Description);
	Card(std::string Name, const int ID, Character lvl, Character Rhand, Character Lhand, Character HP, Character Armor, Character Speed, int race, int elements, std::string Description);
	Card(int ID);
	~Card();

	Card& operator=(Card card);
	bool& operator==(Card card);
	bool& operator<(Card card);
	bool& operator>(Card card);

	std::string race_to_string(Race race);							//������� ����� � ������
	Race string_to_Race(std::string filerace);						//������� �� string � race
	std::string elements_to_string(Elements elements);				//������� �������� � ������
	Elements string_to_Elements(std::string elements);				//������� �� string � elements

	Character *int_to_Character(int n);								//1 - lvl, 2 - Rhand, 3 - Lhand, 4 - HP, 5 - Armor, 6 - Speed
	std::string smth_to_filestring(std::string smth, int size);		//������� ����� �������������� � string � �������� �� |
	std::string Card_to_filestring();								//������� ����� � string
	std::string character_to_printstring(Character character);

	int h_to_12(std::string str, bool h);
	std::string Card_to_printstring();
	void filestring_to_Card(std::string filestring);				//������ ����� �� ������ 

	std::string getName();											//�������� ��� �����
	void setName(std::string name);									//�������� ��� �����
	std::string getDescription();
	void setDescription(std::string description);
	int getID();													//�������� ID �����
	void setID(int id);												//�������� ID �����
	Character getCharacter(Character character);					//�������� ������������� �����
	void setCharacter(Character &current, int count);				//�������� �������������� �����

	std::string get_race();
	std::string get_elem();

	void recard(std::string newName, Character newRhand, Character newLhand, Character newHP, Character newArmor, Character newSpeed, Race newrace, Elements newelements, std::string newDescription);
	void recard(std::string newName, int newRhand, int newLhand, int newHP, int newArmor, int newSpeed, int newrace, int newelements, std::string newDescription);
	void recard(std::string newName, int newRhand, int newLhand, int newHP, int newArmor, int newSpeed, Race newrace, Elements newelements, std::string newDescription);
	

	bool Card::isEmptyCharacter(Character &current);				//��������� character == NULL
	bool Card::isEmptyCard();										//��������� card == NULL

	void character_up(Character &current, int up);					//�������� �������������� �� +up
	void character_change(Character &current, int up);				//�������� �������������� �� up


};