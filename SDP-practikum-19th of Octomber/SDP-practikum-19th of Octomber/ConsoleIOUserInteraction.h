#pragma once
#include"FileEditor.h"
#include<iostream>
class ConsoleIOUserInteraction
{
	FileEditor* fe;
	std::string fileName;
	int chunkSize;
public:

	ConsoleIOUserInteraction(std::string _fileName, int _chunkSize) {
		fe = new FileEditor();
		fe->setChunkSize(_chunkSize);
		chunkSize = _chunkSize;
		fileName = _fileName;
		
		if (!fe->openFile(_fileName))
		{
			cerr << "error";
			
		}
		else {

		}
		

	}
	void startApplication() {
		cout << "enyer chunkSize" << endl;
		cin >> this->chunkSize;
		fe->setChunkSize(this->chunkSize);
		bool flag = true;
		char ch = 'a';
		while (flag)
		{
			cin.get(ch);
			if (ch == 'W') {
				int pos;
				cout << "Enter word position:";
				cin >> pos;
				cout << "enter muter char";
				cin >> ch;
				fe->MuteWordInFileIfInGoodState(pos, ch);
				cout << "word mutted" << endl;
			}
			if (ch == 'C') {
				int pos;
				cout << "Enter position:";
				cin >> pos;
				cout << "enter new char";
				cin >> ch;
				fe->editNthCharInFileIfInGoodState(pos, ch);
				cout << "symbol replaced" << endl;
			}
			if (ch == 'G') {
				fe->seekToEnd();
				cout << endl;
				cout << "SEEK TO END" << endl;
			}
			if (ch == 'g') {
				cin.get(ch);
				if (ch == 'g') {
					fe->seekToBeginning();
					cout << endl;
					cout << "SEEK to START " << endl;
				}
			}
			if (ch == 'q') {
				fe->closeFile();
				cout << endl;
				cout << "FILE CLOSED " << endl;
				flag = false;
			}
			else {
				if (ch != 'a')
				{
					cout << fe->getChunkIfPresent();

				}
			}
			ch = 'a';
		}

	}
	~ConsoleIOUserInteraction() {
	}
};

