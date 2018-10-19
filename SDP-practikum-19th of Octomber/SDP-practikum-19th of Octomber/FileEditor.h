#pragma once
#include<string>
#include<fstream>
using namespace std;
class FileEditor
{
private :
	fstream file;
	int chunkSize;
public:
	FileEditor() {
		chunkSize = 0;
	}

	bool openFile(string str) {
		file.open(str, ios::in| ios::out);
		return file.is_open();
	}
	void setChunkSize(int n) {
		chunkSize = n;
	}
	int getChunkSize()const  {
		return chunkSize;
	}
	void seekToEnd() {
		file.seekg(0, ios::end);

	}
	void editNthCharInFileIfInGoodState(int n, char ch) {
		file.seekp(n, ios::beg);
		file.write(&ch, 1);
		file.seekp(0, std::ios::beg);
		file.flush();

	}
	void MuteWordInFileIfInGoodState(int n, char chMute) {
		this->seekToBeginning();
		int blackSpaceCounter =0;
		char ch;
		char ch2;
		while (blackSpaceCounter < n-1)
		{
			file.get(ch);
			file.get(ch2);
			file.putback(ch2);
			if (ch == ' ' && (ch2 != ' ') )
			{
				blackSpaceCounter++;
			}
		}
		int wordSize =0;
		file.get(ch);
		while ( ch !=' ')
		{
			wordSize++;
			file.get(ch);
		}
		int pos = file.tellg();
		pos -= wordSize;
		
		for (int i = pos -1  ; i < pos +wordSize -1 ; i++)
		{
			editNthCharInFileIfInGoodState(i, chMute);
		}
		
		file.seekp(0, std::ios::beg);
		file.flush();


		

	}
	void seekToBeginning() {
		file.clear();                 // clear fail and eof bits
		file.seekg(0, std::ios::beg);

	}
	char* getChunkIfPresent() {
		char* strBuf = new char[chunkSize+1];
		file.get(strBuf, chunkSize, EOF);
		return strBuf;
	}
	void closeFile() {
		if (file.is_open())
		{
			file.flush();
			file.close();
		}
	}

	virtual ~FileEditor() {
		this->closeFile();
	}
};

