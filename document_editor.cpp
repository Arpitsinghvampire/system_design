//document_editor.cpp
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class DocumentEditor{
private:
	vector<string> DocumentElements;
	string renderedDocument;
public:
	void addText(string text)
	{
		DocumentElements.push_back(text);
	}
	void addImage(string image_path)
	{
		DocumentElements.push_back(image_path);
	}

	string renderDocument()
	{
		string result ;

		for(string element  : DocumentElements)
		{
			if(element.size() > 4 &&(element.substr(element.size()-4) == ".jpg"  || element.substr(element.size()-4) == ".png"))
			{
				result += "[Image : " + element + "]" + "\n";
			}
			else
				result += element + "\n" ;
		}
		renderedDocument = result ;
		return renderedDocument;
	}

	void save_document(string file_path_chosen = "document.txt")
	{
		//so basically we need to write the elements into the path 
		ofstream fout;

		fout.open(file_path_chosen);

		for(auto elements : renderedDocument)
		{
			fout<<elements;
		}
		if(fout.is_open())
		{
			cout<<"DOCUMENT IS SUCCESSFULLY SAVED "<<endl;
		}
		fout.close();
	}

};

int main()
{
	DocumentEditor editor;
	editor.addText("HELLO WORLD THIS IS MY FIRST FILE IN THE SYSTEM DESIGN");
	editor.addImage("picture.jpg");

	editor.addText("This is the document editor");

	cout<<editor.renderDocument()<<endl;

	editor.save_document();
}
