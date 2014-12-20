/**
 * C语言词法分析
 * Usage:
 * 	$ g++ LexicalAnalysis.cpp -o lex
 * 	$ lex in.c tokens.txt table.txt //分别指定输入文件，输出token串文件，符号表文件
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
#include <cctype>
#include <map>

using namespace std;

void init(); //初始化
void get_digits(); // 读取并识别实数
bool get_comments(); // 读取并识别注释
int table_insert(); // 将标识符插入符号表
void output();//输出token串
void error(int,int,string);//错误输出

map<string, int> m; //种类码
bool notEnd = true;  // 循环标志变量
int state = 0;     // 有限自动机状态变量
int line = 0;  //  行数
int column = 0;  //  列数
int cnt_word = 0; // 单词数
int cnt_char = 0;  // 字符数

ifstream infile;
ofstream outfile;
ofstream tablefile;       // 输出符号表文件
vector<string> table;     // 符号表
string ifile, ofile, tfile; // 输入输出文件名
string buffer, token;     // 缓冲区、标记
string::iterator forward_node = buffer.end();  // 缓冲区前向指针

string file_input = "in.c"; //输入文件名
string file_output_token = "tokens.txt"; //输出token串的文件
string file_output_table = "table.txt"; //输出符号表文件

//关键字
string words[] = { "auto", "double", "int", "struct", "break", "else", "long",
		"switch", "case", "enum", "register", "typedef", "char", "extern",
		"return", "union", "const", "float", "short", "unsigned", "continue",
		"for", "signed", "void", "default", "goto", "sizeof", "volatile", "do",
		"if", "static", "while" };
//Token
class Token {
	int code; //种类码
	std::string value; //标记符
	int line; //行数
public:
	Token(int code, std::string value, int line) {
		this->code = code;
		this->line = line;
		this->value = value;
	}
	std::string toString() {
		return "( " + std::to_string(this->code) + " , " + this->value + ")";
	}
};

//token列表
vector<Token> tokens;

void init() {
	//符号表序号
	m["ID"] = 1;
	//关键字种别码
	m["auto"] = 2;
	m["double"] = 3;
	m["int"] = 4;
	m["struct"] = 5;
	m["break"] = 6;
	m["else"] = 7;
	m["long"] = 8;
	m["switch"] = 9;
	m["case"] = 10;
	m["enum"] = 11;
	m["register"] = 12;
	m["typedef"] = 13;
	m["char"] = 14;
	m["extern"] = 15;
	m["return"] = 16;
	m["union"] = 17;
	m["const"] = 18;
	m["float"] = 19;
	m["short"] = 20;
	m["unsigned"] = 21;
	m["continue"] = 22;
	m["for"] = 23;
	m["signed"] = 24;
	m["void"] = 25;
	m["default"] = 26;
	m["goto"] = 27;
	m["sizeof"] = 28;
	m["volatile"] = 29;
	m["do"] = 30;
	m["if"] = 31;
	m["static"] = 32;
	m["while"] = 33;
	m["num"] = 34; //数字常量

	//算数运算符
	m["+"] = 35;
	m["++"] = 36;
	m["-"] = 37;
	m["--"] = 38;
	m["*"] = 39;
	m["/"] = 40;
	m["%"] = 41;
	//赋值运算符
	m["="] = 42;
	m["+="] = 43;
	m["-="] = 44;
	m["*="] = 45;
	m["/="] = 46;
	m["%="] = 47;
	m["&="] = 48;
	m["|="] = 49;
	m["^="] = 50;
	//关系运算符
	m["<"] = 51;
	m["<="] = 52;
	m["=="] = 53;
	m[">="] = 54;
	m[">"] = 55;
	m["!="] = 56;
	//逻辑运算符
	m["&&"] = 57;
	m["||"] = 58;
	m["!"] = 59;
	//位运算符
	m["&"] = 60;
	m["|"] = 61;
	m["^"] = 62;
	m["~"] = 63;
	m["<<"] = 64;
	m[">>"] = 65;
	//其他符号(界限符号)
	m["->"] = 66;
	m["."] = 67;
	m["#"] = 68;
	m["{"] = 69;
	m["}"] = 70;
	m["["] = 71;
	m["]"] = 72;
	m["("] = 73;
	m[")"] = 74;
	m["?"] = 75;
	m[":"] = 76;
	m[","] = 77;
	m[";"] = 78;
	m["\\"] = 79;
	//字符常量
	m["constant_char"] = 80;
	//字符串常量
	m["constant_string"] = 81;
	//注释
	m["comments"] = 82;
}
/**
 *创建Token
 *type:Token类型
 *token:token串值
 *line:所在行
 */
void createToken(string type, string token, int line) {
	if (type.compare("num") == 0) {

		tokens.push_back(Token(m["num"], token, line));
	} else if (type.compare("ID") == 0) {

		tokens.push_back(Token(m["ID"], token, line));
	} else if (type.compare("constant_char") == 0) {

		tokens.push_back(Token(m["constant_char"], token, line));
	} else if (type.compare("constant_string") == 0) {

		tokens.push_back(Token(m["constant_string"], token, line));
	} else if (type.compare("comments") == 0) {

		tokens.push_back(Token(m["comments"], token, line));
	} else {
		tokens.push_back(Token(m[token], token, line));
	}
}
//命令参数解析
void parse(int argc, char *argv[]){
	if(argc >=2){
		file_input = argv[1];
	}
	if(argc >=3){
		file_output_token = argv[2];
	}
	if(argc >=4){
		file_output_table = argv[3];
	}
	cout<<file_input<<" "<<file_output_token<<" "<<file_output_table<<endl;
}

int main(int argc, char *argv[]) {
	init();
	parse(argc,argv);
	set<string> keywords(words, words + 32);    // 关键字集合
	char C;

//	cout << "输入源文件（回车默认使用in.c）：" << endl;
//	getline(cin, ifile);
//	if (ifile == "") {
//		ifile = "in.c";               // 回车默认
//	}
	infile.open(file_input);
	if (!infile) {
		cout << "无法打开源文件！" << endl;
		return -1;
	}
//
//	cout << "输出目标文件（回车默认使用out.txt）：" << endl;
//	getline(cin, ofile);
//	if (ofile == "") {
//		ofile = "out.txt";    // 回车默认
//	}
	outfile.open(file_output_token);
	if (!outfile) {
		cout << "无法创建目标文件！" << endl;
		return -1;
	}

//	cout << "输出符号表（回车默认使用table.txt）：" << endl;
//	getline(cin, tfile);
//	if (tfile == "") {
//		tfile = "table.txt";
//	}
	tablefile.open(file_output_table);
	if (!tablefile) {
		cout << "无法创建符号表！" << endl;
		return -1;
	}

	while (true) {
		if (forward_node == buffer.end()) {              // 读到行末
			if (getline(infile, buffer, '\n')) {    // 读到错误或EOF则返回false
				++line;                             // 读取新行
				cnt_char += column;                 // 每次换行前加上当前行的字符数
				forward_node = buffer.begin();           // 重置前向指针
				column = 0;                         // 每次新行列数清零
			} else {
				cnt_char += column;
				output();
				infile.close();
				outfile.close();
				int i = 1;                          // 将符号表写入文件
				for (vector<string>::iterator it = table.begin();
						it != table.end(); ++it) {
					tablefile << i++ << "\t" << *it << endl;
				}
				tablefile.close();
				cout << "总行数：" << line << endl;
				cout << "单词个数：" << cnt_word << endl;
				cout << "字符个数：" << cnt_char << endl;
				return 0;
			}
		}

		while ((forward_node != buffer.end()) && isspace(*forward_node)) { // 未读到缓冲区结束，则一直读到非空字符
			++forward_node;
			++column;
		}

		if (forward_node != buffer.end()) {                          // 未读到缓冲区末尾
			token = "";
			C = *forward_node;
			switch (C) {
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
				token.append(1, C);
				++forward_node;
				++column;
				while ((forward_node != buffer.end())
						&& (isalnum(*forward_node) || *forward_node == '_')) { // 合法标识符可包含下划线
					token.append(1, *forward_node++);
					++column;
				}
				if (keywords.count(token) == 0) {
					// 查关键字表
					table_insert();
					createToken("ID", token, line);
				} else {
					createToken("key", token, line);
				}
				++cnt_word;
				break;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				token.append(1, C);
				state = 1;
				++forward_node;
				++column;
				get_digits();                                     // 读取无符号实数剩余部分
				createToken("num", token, line);
				notEnd = true;
				state = 0;
				++cnt_word;
				break;

			case '+':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("arith-op", token, line);
				} else {
					if (*forward_node == '+') {
						token.append(1, *forward_node++);
						++column;
						createToken("arith-op", token, line);
					} else if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
					} else {
						createToken("arith-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '-':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("arith-op", token, line);
				} else {
					if (*forward_node == '-') {
						token.append(1, *forward_node++);
						++column;
						createToken("arith-op", token, line);
					} else if (*forward_node == '=') { // -=
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
					} else if (*forward_node == '>') {  // ->
						token.append(1, *forward_node++);
						++column;
						createToken("others", token, line);
					} else {
						createToken("arith-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '*':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("arith-op", token, line);
				} else {
					if (*forward_node == '=') {  // *=
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
					} else {
						createToken("arith-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '/':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("arith-op", token, line);
					++cnt_word;
				} else {
					if (*forward_node == '=') {                     // 除法复合赋值 /=
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
						++cnt_word;
					} else if (*forward_node == '/') {              // 单行注释，读到行末
						token.append(1, *forward_node++);
						++column;
						while (forward_node != buffer.end()) {
							token.append(1, *forward_node++);
							++column;
						}
						createToken("comments", token, line);
					} else if (*forward_node == '*') {               // 多行注释可以换行
						token.append(1, *forward_node++);
						++column;
						int ret = get_comments();
						if (ret) {
							createToken("comments", token, line);
						} else {
							infile.close();
							outfile.close();
							int i = 1;
							for (vector<string>::iterator it = table.begin();
									it != table.end(); ++it) {
								tablefile << left << i++ << "\t" << *it << endl;
							}
							tablefile.close();
							cout << "语句行数：" << line << endl;
							cout << "单词个数：" << cnt_word << endl;
							cout << "字符个数：" << cnt_char << endl;
							return 0;
						}
					} else {                                   // 除号后是其他字符，为单个除号
						createToken("arith-op", token, line);
						++cnt_word;
					}
				}
				break;

			case '%':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("arith-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
					} else {
						createToken("arith-op", token, line);

					}
				}
				++cnt_word;
				break;

			case '&':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("bit-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
					} else if (*forward_node == '&') {
						token.append(1, *forward_node++);
						++column;
						createToken("log-op", token, line);
					} else {
						createToken("bit-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '|':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("bit-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
					} else if (*forward_node == '|') {
						token.append(1, *forward_node++);
						++column;
						createToken("log-op", token, line);
					} else {
						createToken("bit-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '^':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("bit-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("asgn-op", token, line);
					} else {
						createToken("bit-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '~':
				token.append(1, C);
				++forward_node;
				++column;
				createToken("bit-op", token, line);
				++cnt_word;
				break;

			case '<':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("rel-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("rel-op", token, line);
					} else if (*forward_node == '<') {
						token.append(1, *forward_node++);
						++column;
						createToken("bit-op", token, line);
					} else {
						createToken("rel-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '=':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("asgn-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("rel-op", token, line);
					} else {
						createToken("asgn-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '>':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("rel-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("rel-op", token, line);
					} else if (*forward_node == '>') {
						token.append(1, *forward_node++);
						++column;
						createToken("bit-op", token, line);
					} else {
						createToken("rel-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '!':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					createToken("log-op", token, line);
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						createToken("rel-op", token, line);
					} else {
						createToken("log-op", token, line);
					}
				}
				++cnt_word;
				break;

			case '\"':
				token.append(1, C);
				++forward_node;
				++column;
				while (true) {
					while ((forward_node != buffer.end())
							&& (*forward_node != '\"')) {
						token.append(1, *forward_node++);
						++column;
						if (*(forward_node - 1) == '\\') {    // 如果读到'\'则后面字符为转义
							if (forward_node == buffer.end())
								break;
							else {
								token.append(1, *forward_node++);     // 多读入一个字符
								++column;
							}
						}
					}
					if (forward_node == buffer.end()) {
						error(line,column,"missing terminating \" character");
						break;
					} else {
						token.append(1, *forward_node++);
						++column;
						createToken("constant_string", token, line);
						break;
					}
				}
				++cnt_word;
				break;

			case '\'':
				token.append(1, C);
				++forward_node;
				++column;
				while ((forward_node != buffer.end()) && (*forward_node != '\'')) {
					token.append(1, *forward_node++);
					++column;
					if (*(forward_node - 1) == '\\') {        // 如果读到'\'则后面字符为转义
						if (forward_node == buffer.end())
							break;
						else {
							token.append(1, *forward_node++);      // 多读入一个字符
							++column;
						}
					}
				}
				if (forward_node == buffer.end()) {
					error(line,column,"missing terminating \' character");
				} else {
					token.append(1, *forward_node++);
					++column;
					createToken("constant_char", token, line);
				}
				++cnt_word;
				break;

			case '.':
				token.append(1, C);
				++forward_node;
				++column;
				if ((forward_node != buffer.end()) && isdigit(*forward_node)) { // 如果小数点后为数字，则转入实数识别
					token.append(1, *forward_node++);
					++column;
					state = 23;
					get_digits();
					notEnd = true;
					state = 0;
					outfile << "< num," << token << " >" << endl;
					createToken("num", token, line);
					++cnt_word;
					break;
				}
				createToken("others", token, line);
				++cnt_word;
				break;

			case '#':
			case '{':
			case '}':
			case '[':
			case ']':
			case '(':
			case ')':
			case '?':
			case ':':
			case ',':
			case ';':
			case '\\':
				token.append(1, C);
				++forward_node;
				++column;
				createToken("others", token, line);
				++cnt_word;
				break;

			default:
				++forward_node;
				++column;
				error(line,column,"invalid character");
				break;
			}
		}
	}


	return 0;
}

void output() {
	for (Token t : tokens) {
		outfile << t.toString() << endl;
	}
}

void error(int line , int column , string msg){
	outfile << "< Error(" << line << "," << column
							<< "): "<< msg <<" >" << endl;
	cout<< "< Error(" << line << "," << column
			<< "): "<< msg <<" >" << endl;
	exit(-1);
}

int table_insert() {
	vector<string>::iterator it = find(table.begin(), table.end(), token);
	if (it == table.end()) {
		table.push_back(token);
		it = find(table.begin(), table.end(), token);
	}
	return distance(table.begin(), it) + 1;
}

void get_digits()                                            // 读取实数，包含E/e指数
{
	while ((forward_node != buffer.end()) && notEnd) {
		switch (state) {
		case 1:
			if (*forward_node == '.') {
				token.append(1, *forward_node++);
				++column;
				state = 23;
			} else if (*forward_node == 'E' || *forward_node == 'e') {
				token.append(1, *forward_node++);
				++column;
				state = 4;
			} else if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 1;
			} else {
				notEnd = false;                              // 识别结束
			}
			break;
		case 23:
			if (*forward_node == 'E' || *forward_node == 'e') {
				token.append(1, *forward_node++);
				++column;
				state = 4;
			} else if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 23;
			} else {
				notEnd = false;
			}
			break;
		case 4:
			if (*forward_node == '+' || *forward_node == '-') {
				token.append(1, *forward_node++);
				++column;
				state = 6;
			} else if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 5;
			} else {
				error(line,column,"exponent has no digits");
				notEnd = false;
			}
			break;
		case 5:
			if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 5;
			} else {
				notEnd = false;
			}
			break;
		case 6:
			if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 5;
			} else {
				error(line,column,"exponent has no digits");
				notEnd = false;
			}
			break;
		default:
			break;
		}
	}
}

bool get_comments() {
	while (true) {
		while ((forward_node != buffer.end()) && (*forward_node != '*')) {
			token.append(1, *forward_node++);
			++column;
		}
		if (forward_node == buffer.end()) {                      // 一行注释结束，继续下一行
			if (getline(infile, buffer, '\n')) {             // 读到错误或EOF则返回false
				++line;
				forward_node = buffer.begin();
				column = 1;
				continue;
			} else {
				return false;
			}
		} else {                                                 // 读到注释结束符的星号
			token.append(1, *forward_node++);
			++column;
			if (forward_node == buffer.end()) {         // 若 '*/' 被换行分开，则继续读取下一行
				continue;
			} else if (*forward_node == '/') {                        // 注释结束符ok
				token.append(1, *forward_node++);
				++column;
				return true;
			} else {                                         // 星号后是其他字符，仍继续读取注释
				continue;
			}
		}
	}
}
