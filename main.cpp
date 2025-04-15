 #include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;




enum States { s, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, t,u};


int table[47][25] = { {7,2,-1,5,46,8,-1,13,14,15,16,26,17,18,24,45,33,35,37,40,43,39,11,12,46},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,2,3,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,4,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {9,4,-1,-1,3,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {9,-1,-1,9,-1,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {9,-1,-1,-1,-1,8,-1,-1,-1,-1,-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30},
                     {9,-1,-1,9,-1,9,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} ,
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,41,19,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,42,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,-1,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,2,-1,-1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1} ,
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,44,43,43,43,43},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
                     
};


bool acceptance[48] = { false, false, true, false, true, false, false, false, false, true, false,true,true,true,true,true,true,true,true,true,false,true,false,true,false,true,false,true,true,false,false,true,true,false,true,false,true,false,true,true,true,true,true,false,true,false,true,true };
string identity[48] = { "no","no","number","no","number","no","no","no","no","identifier", "no","punctuation", "punctuation", "punctuation", "punctuation", 
    "punctuation", "punctuation", "operator",  "operator",  "operator",  "no","operator",  "no","operator",   "no","operator",  "no","operator","punctuation",
     "no","no","operator","operator",   "no","operator","no","operator","no","operator",  "operator","operator",  "operator",  "operator",  "no","string","no",
      "operator", "operator"   
};

struct Keyword {
    string word;
};

Keyword keywords[] = {
    {"asm"}, {"Wagarna"}, {"new"}, {"this"}, {"auto"}, {"enum"}, {"operator"}, {"throw"}, {"Mantiqi"},
    {"explicit"}, {"private"}, {"True"}, {"break"}, {"export"}, {"protected"}, {"try"}, {"case"}, {"extern"},
    {"public"}, {"typedef"}, {"catch"}, {"False"}, {"register"}, {"typeid"}, {"Harf"}, {"Ashriya"}, {"typename"},
    {"Adadi"}, {"class"}, {"for"}, {"Wapas"}, {"union"}, {"const"}, {"dost"}, {"short"}, {"unsigned"}, {"goto"},
    {"signed"}, {"using"}, {"continue"}, {"Agar"}, {"sizeof"}, {"virtual"}, {"default"}, {"inline"}, {"static"},
    {"Khali"}, {"delete"}, {"volatile"}, {"do"}, {"long"}, {"struct"}, {"double"}, {"mutable"}, {"switch"}, {"while"},
    {"namespace"}, {"template"}, {"Marqazi"}, {"Matn"}, {"input->"}, {"output<-"}
};

void removeComments(const string &inputFile, const string &codeOutputFile, const string &commentsOutputFile) {
    ifstream inFile(inputFile);
    ofstream codeFile(codeOutputFile);
    ofstream commentFile(commentsOutputFile);

    if (!inFile || !codeFile || !commentFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    bool inBlockComment = false;

    while (getline(inFile, line)) {
        stringstream cleanLine;
        size_t i = 0;
        
        while (i < line.size()) {
            if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                
                inBlockComment = true;
                commentFile << "/*";
                i += 2;
            } 
            else if (inBlockComment && i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
               
                inBlockComment = false;
                commentFile << "*/\n";
                i += 2;
            } 
            else if (inBlockComment) {
                commentFile << line[i];
                i++;
            } 
            else if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {
                
                 commentFile << "//" << line.substr(i + 2) << endl;
                break; 
            } 
            else if (!inBlockComment) {
                
                  cleanLine << line[i];
                i++;
            }
        }

        if (!cleanLine.str().empty() && !inBlockComment) {
            codeFile << cleanLine.str() << endl;
        }
    }

    inFile.close();
    codeFile.close();
    commentFile.close();
}


int getInputType(char ch) {
    if (ch == '_') return 0;
    if (isdigit(ch)) return 1;
    if (ch == '.') return 2;
    if (ch == 'E') return 3;
    if (ch == '+') return 4;
    if (isalpha(ch)) return 5;
    
    if (ch == '(') return 7;
    if (ch == ')') return 8;
    if (ch == '}') return 9;
    if (ch == ']') return 10;
    if (ch == ':') return 11;
    if (ch == '<') return 12;
    if (ch == '>') return 13;
    if (ch == '=') return 14;
    if (ch == '%') return 15;
    if (ch == '|') return 16;
    if (ch == '&') return 17;
    if (ch == '!') return 18;
    if (ch == '*') return 19;
    if (ch == '"') return 20;
    if (ch == '/') return 21;
    if (ch == '[') return 22;
    if (ch == '{') return 23;
    if (ch == '-') return 24;
    return 6;
}


void tokenize(const string& inputFile, const string& tokenFile, const string& errorFile) {
    ifstream inFile(inputFile);
    ofstream tokenOut(tokenFile);
    ofstream errorOut(errorFile);

    if (!inFile.is_open() || !tokenOut.is_open() || !errorOut.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }

    string token;
    int state = s;
    char ch;
    while (inFile.get(ch)) {
        if (isspace(ch)&&acceptance[state]) {
            if (!token.empty()) {
               
                 if (acceptance[state]) {  
                    tokenOut << "Token: " << token <<" Type: "<<identity[state]<< endl;
                    
                }

                else {
                    if (token != " ") {
                    errorOut << "Invalid Token: " << token << endl;
                    }
                }
                token.clear();
                state = s;
            }
            continue;
        }


        int input = getInputType(ch);
        int newState = table[state][input];

        if (newState == -1) {
            
            bool isKeyword = false;
            for (const auto& kw : keywords) {
                if (token == kw.word) {
                    isKeyword = true;
                    break;
                }
            }
            if (isKeyword) {
                tokenOut << "Token: " << token << " Type: Keyword" << endl;
                token.clear();
                state = s;
                continue;
            }
            
            if (acceptance[state]) {
                tokenOut << "Token: " << token <<" Type: "<<identity[state]<< endl;
                inFile.seekg(-1, ios::cur);
               
            }
            else
            {
                
                if (token + ch != " ") {
                    errorOut << "Invalid Token: " << token + ch << endl;
                }
            }
            token.clear();
            state = s;


        }
        else {
            state = newState;
            token += ch;
        }
    }

    if (!token.empty() && acceptance[state]) {
        tokenOut << "Token: " << token  <<" Type: "<<identity[state]<< endl;
    }
    else if (!token.empty()) {
        if (token != " ") {
            errorOut << "Invalid Token: " << token << endl;
        }
    }

    inFile.close();
    tokenOut.close();
    errorOut.close();
}

int main() {
    string inputfile = "sourcecodewithcomment.txt";
    string codeOutputFile = "sourcecode.txt";
    string commentsOutputFile = "extracted_comments.txt";
    removeComments(inputfile, codeOutputFile, commentsOutputFile);

    string inputFile = "sourcecode.txt";
    string tokenFile = "token.txt";
    string errorFile = "error.txt";

    tokenize(inputFile, tokenFile, errorFile);
    cout << "Tokenization completed. Check token.txt and error.txt for results." << endl;
    return 0;
}



