/*#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("data.txt");

    string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    else
    {
        cout << "File could not be opened." << endl;
    }

    return 0;
} */


#include <iostream>
#include <fstream>
using namespace std;


bool isKeyword(string word) {
    string keywords[] = {"int","float","double","char","main","return","cout","cin"};

    for(int i=0;i<8;i++) {
        if(word == keywords[i])
            return true;
    }
    return false;
}


bool isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=' || ch=='<' || ch=='>');
}


bool isPunctuation(char ch) {
    return (ch=='(' || ch==')' || ch=='{' || ch=='}' || ch==',' || ch==';');
}


string verifyToken(string token) {

    if(isKeyword(token))
        return "Keyword";

    bool isNumber = true;

    for(int i=0;i<token.length();i++) {
        if(token[i]<'0' || token[i]>'9') {
            isNumber=false;
            break;
        }
    }

    if(isNumber)
        return "Constant";


    if(token[0]=='"' && token[token.length()-1]=='"')
        return "Constant";

    if((token[0]>='a' && token[0]<='z') ||
       (token[0]>='A' && token[0]<='Z') ||
        token[0]=='_')
        return "Identifier";

    return "Unknown";
}

int main() {

    ifstream MyFile("data.txt");

    if(!MyFile) {
        cout<<"File not found!";
        return 0;
    }

    string line;
    int lineNumber=1;

    cout<<"Tokens and their types:\n\n";

    while(getline(MyFile,line)) {

        cout<<"Line "<<lineNumber<<": "<<line<<endl;

        string token="";

        for(int i=0;i<line.length();i++) {

            char ch=line[i];


            if(ch=='"') {
                if(token!="") {
                    cout<<token<<" -> "<<verifyToken(token)<<endl;
                    token="";
                }

                string strToken="\"";
                i++;

                while(i<line.length() && line[i]!='"') {
                    strToken+=line[i];
                    i++;
                }

                if(i<line.length())
                    strToken+="\"";

                cout<<strToken<<" -> Constant"<<endl;
            }

            else if(ch!=' ' && !isOperator(ch) && !isPunctuation(ch)) {
                token+=ch;
            }

            else {

                if(token!="") {
                    cout<<token<<" -> "<<verifyToken(token)<<endl;
                    token="";
                }

                if(isOperator(ch) || isPunctuation(ch)) {
                    string op(1,ch);

                    if(isOperator(ch))
                        cout<<op<<" -> Operator"<<endl;
                    else
                        cout<<op<<" -> Punctuation"<<endl;
                }
            }
        }

        if(token!="") {
            cout<<token<<" -> "<<verifyToken(token)<<endl;
        }

        cout<<endl;
        lineNumber++;
    }

    MyFile.close();
    return 0;
}
