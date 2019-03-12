#pragma once

#include <vector>
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include "Deck.h"
#include "Card.h"

class Deck
{
private:
	std::vector <Card> deck;
public:


	Card& operator[](int pos);
	Deck& operator=(Deck deck1);


	Deck();
	Deck(std::string filename);
	~Deck();

	void new_card();									//�������� ����� �����
	void delete_card(int current);						//������� �����
	int deck_size();									//���������� ���������� ����
	void shuffle();										//���������� �����
	void restore_order();								//������������ �������

	std::string deck_to_filestring();					//������� ������ � ��������� ����� ��� ������ � ����	
	void filestring_to_deck(std::string filestring);	//������� ������ �� ���������� ������ � ����� ������

	void deck_to_file(std::string filename);			//������ � ���� ��������� ����� ������
	void file_to_deck(std::string filename);			//������ �� ����� ������

};


